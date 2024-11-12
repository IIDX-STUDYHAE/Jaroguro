// 24.10.12�� �ߴ� �ڵ�, 24.11.12�� �� �� ���ƺ�. 
// ���� ���� �� �������� ���Ͽ� ������ ���� ���� �ڵ忡 �ش��ϴ� �κп� ���ؼ��� �Ϸ翡 1~2���� �ø� ����. 



#include<iostream>
#include "Stack1.h"

DoubleStack::DoubleStack() {
	small = -1;
	big = 200;
	for (int i = 0; i < 200; i++) {
		items[i] = 0;
	}
	//item�� �ʱ�ȭ�� ��, ���� 0�� �־��ִ� ���� �����غ���. �̷��� �ݺ��� ������ �ʴ� ����� ���� �ѵ� ���� �������̶� ���� ����.
	//������ �ʹ� �������� �����̱� �ѵ� �츮�� �����ϴ°Ŵϱ� fm�� �߱��ؾ�. �ʱ�ȭ �� ���൵ �������� �ǹ� ���� ����������.. 
}


bool DoubleStack::smallEmpty() const { return (small == -1); }
bool DoubleStack::bigEmpty() const { return (big == 200); }
bool DoubleStack::IsFull() const { return (small + 1 == big); }
//�� �κп��� ������ ������ ������, ���� 1���� ���ͷ����͸� 2�� ���������� ���� �� �ȴ�.


void DoubleStack::Push(int newItem) {
	if (IsFull()) throw ("���� ������ ���� ���� ���ֽ��ϴ�.");
	if (newItem <= 1000) {
		small++;
		items[small] = newItem;//���� �����ڸ� ���� �� �ٷ� �ٲ� ���� ����.
		
	}
	else if (newItem > 1000)/*else�� �ᵵ ��.*/ {
		big--;
		items[big] = newItem; 
		
	}


}


void DoubleStack::Print() {
	
	while (!smallEmpty()) {
		std::cout << small + 1 << "��° ���� " << items[small] << std::endl;
		small--;
	}
	while (!bigEmpty()) {
		std::cout << big + 1 << "��° ���� " << items[big] << std::endl;
		big++;
	}
}





/*���� Stack�� �ƴϰ� �Ǿ� ������ ������ �Ǳ� ������ �̹� Stack���ν��� ����� ���� �Ҿ��⵵ �߰�,
Pop ���� ���� ������ ������ �ڵ�?�� §�ٸ�
void DoubleStack::Print() {
	int S = small;
	int B = big;
	while (S!=-1) {
		std::cout << S + 1 << "��° ���� " << items[S] << std::endl;
		S--;
	}
	while (B!=200) {
		std::cout << B + 1 << "��° ���� " << items[B] << std::endl;
	}
}*/

//main���� ����.

#include<random>

int main() {
	std::random_device R;
	std::mt19937 gen(R());
	std::uniform_int_distribution<> dis(1, 2000);//�� ���� ����


	DoubleStack D;
	for (int i = 0; i < 50; i++) {
		D.Push(dis(gen));
	}
	D.Print();


	return 0;
}
