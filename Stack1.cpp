// 24.10.12에 했던 코드, 24.11.12에 한 번 돌아봄. 
// 수업 과제 중 교수님이 파일에 제공한 것이 없는 코드에 해당하는 부분에 대해서만 하루에 1~2개씩 올릴 예정. 



#include<iostream>
#include "Stack1.h"

DoubleStack::DoubleStack() {
	small = -1;
	big = 200;
	for (int i = 0; i < 200; i++) {
		items[i] = 0;
	}
	//item을 초기화할 때, 전부 0을 넣어주는 법을 생각해봐야. 이렇게 반복문 굴리지 않는 방법도 많긴 한데 제일 직관적이란 장점 있음.
	//연산이 너무 많아져서 문제이긴 한데 우리는 공부하는거니까 fm을 추구해야. 초기화 안 해줘도 논리적으로 의미 없는 값들이지만.. 
}


bool DoubleStack::smallEmpty() const { return (small == -1); }
bool DoubleStack::bigEmpty() const { return (big == 200); }
bool DoubleStack::IsFull() const { return (small + 1 == big); }
//이 부분에서 생각할 여지가 많은데, 동작 1번에 이터레이터를 2번 움직여서는 절대 안 된다.


void DoubleStack::Push(int newItem) {
	if (IsFull()) throw ("지금 스택의 값이 가득 차있습니다.");
	if (newItem <= 1000) {
		small++;
		items[small] = newItem;//전위 연산자를 통해 한 줄로 바꿀 수도 있음.
		
	}
	else if (newItem > 1000)/*else를 써도 됨.*/ {
		big--;
		items[big] = newItem; 
		
	}


}


void DoubleStack::Print() {
	
	while (!smallEmpty()) {
		std::cout << small + 1 << "번째 값은 " << items[small] << std::endl;
		small--;
	}
	while (!bigEmpty()) {
		std::cout << big + 1 << "번째 값은 " << items[big] << std::endl;
		big++;
	}
}





/*뭔가 Stack이 아니게 되어 버리는 느낌이 되긴 하지만 이미 Stack으로써의 기능을 많이 잃었기도 했고,
Pop 없이 값만 내놓는 검증용 코드?를 짠다면
void DoubleStack::Print() {
	int S = small;
	int B = big;
	while (S!=-1) {
		std::cout << S + 1 << "번째 값은 " << items[S] << std::endl;
		S--;
	}
	while (B!=200) {
		std::cout << B + 1 << "번째 값은 " << items[B] << std::endl;
	}
}*/

//main에서 검증.

#include<random>

int main() {
	std::random_device R;
	std::mt19937 gen(R());
	std::uniform_int_distribution<> dis(1, 2000);//값 임의 조정


	DoubleStack D;
	for (int i = 0; i < 50; i++) {
		D.Push(dis(gen));
	}
	D.Print();


	return 0;
}
