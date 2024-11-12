#include<iostream>
#include"Stack2.h"




StackType::StackType() {
	top = -1;
	for (int i = 0; i < 200; i++) {
		items[i] = 0;
	}//�ʱ�ȭ �� ���൵ ���ۿ��� ���� ���� �ѵ� �츮�� �����ϴ°Ŵϱ� �������� fm �߱�.
}

bool StackType::IsEmpty() const { return (top == -1); }
bool StackType::IsFull() const { return (top == MAX_ITEMS - 1); }
void StackType::Push(int newitem) {
	if (IsFull()) throw("������ ���� á���ϴ�!");
	top++;
	items[top] = newitem;
}

void StackType::Pop()
{
	if (IsEmpty())throw ("Stack�� ��� �־, ������ ���� �����ϴ�.");
	top--;
}

int StackType::Top()
{
	if (IsEmpty())
		throw("Stack�� ��� �־, �����帱 ���� �����ϴ�.");
	return items[top];
}

void StackType::ReplaceItem(int olditem, int newitem) {
	int k;
	std::unique_ptr<StackType> S(new StackType());//Stack�� ���� ���� ó���Ϸ��� ���纻�� ����� ���� �ʼ�. 

	while (IsEmpty() != 1) {
		k = Top();
		
		if (k == olditem) {
			k = newitem;
		}
		S->Push(k);
		Pop();
	}
	//S�� ġȯ�� ������ Stack�� �������, �̰� �������� �ִµ� 2�� 180�� ������ ���� ���� �����ϱ� 
	// ���ſ� �� �κ��� �ణ �������� �߾��µ�, �� �� ���������? 1�� ���̿� �����ߴ�
	while (S->IsEmpty() != 1) {
		k = S->Top();
		Push(k);
		S->Pop();
	}
	//���� ���������� 3 7 4 2 1 7 4 0 3 7 �� stack�� 7->9�� ġȯ���ָ� 
	//S���� �ؿ� �� �������� ���̴ϱ� 9 3 0 4 9 1 2 4 9 3 ���·� ������ �ǰ�, �̰� �� ����� ���� ���ÿ� ������
	//���� ���õ� �ؿ� �� �������� ���̴ϱ� 3 9 4 2 1 9 4 0 3 9 �� ��. 

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

