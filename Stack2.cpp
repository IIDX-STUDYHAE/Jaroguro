#include<iostream>
#include"Stack2.h"




StackType::StackType() {
	top = -1;
	for (int i = 0; i < 200; i++) {
		items[i] = 0;
	}//초기화 안 해줘도 동작에는 문제 없긴 한데 우리는 공부하는거니까 논리적으로 fm 추구.
}

bool StackType::IsEmpty() const { return (top == -1); }
bool StackType::IsFull() const { return (top == MAX_ITEMS - 1); }
void StackType::Push(int newitem) {
	if (IsFull()) throw("스택이 가득 찼습니다!");
	top++;
	items[top] = newitem;
}

void StackType::Pop()
{
	if (IsEmpty())throw ("Stack이 비어 있어서, 내보낼 값이 없습니다.");
	top--;
}

int StackType::Top()
{
	if (IsEmpty())
		throw("Stack이 비어 있어서, 보여드릴 값이 없습니다.");
	return items[top];
}

void StackType::ReplaceItem(int olditem, int newitem) {
	int k;
	std::unique_ptr<StackType> S(new StackType());//Stack의 깊은 값을 처리하려면 복사본을 만드는 과정 필수. 

	while (IsEmpty() != 1) {
		k = Top();
		
		if (k == olditem) {
			k = newitem;
		}
		S->Push(k);
		Pop();
	}
	//S에 치환된 버전의 Stack을 만들었고, 이건 뒤집혀져 있는데 2번 180도 돌리면 원래 상이 나오니까 
	// 과거엔 이 부분을 약간 엉망으로 했었는데, 좀 더 깔끔해진듯? 1달 사이에 성장했다
	while (S->IsEmpty() != 1) {
		k = S->Top();
		Push(k);
		S->Pop();
	}
	//예로 위에서부터 3 7 4 2 1 7 4 0 3 7 인 stack을 7->9로 치환해주면 
	//S에는 밑에 맨 위값부터 쌓이니까 9 3 0 4 9 1 2 4 9 3 형태로 저장이 되고, 이걸 또 뒤집어서 원래 스택에 넣으면
	//원래 스택도 밑에 맨 위값부터 샇이니까 3 9 4 2 1 9 4 0 3 9 가 됨. 

}


int main() {
	StackType st;
	st.Push(8);
	st.Push(3);
	st.Push(9);
	st.Push(8);
	st.Push(3);
	st.Push(7);
	st.Push(5);
	st.Push(3);

	st.ReplaceItem(3, 5);

	while (st.IsEmpty() != 1) {
		std::cout << st.Top() << std::endl;
		st.Pop();
	}

}

