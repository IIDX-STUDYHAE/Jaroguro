#include<iostream>
#include"CircularQue.h"
//���� ���ʷ��� �� ������� �׽�Ʈ �ڵ�


template <typename T>
void EnQueControl(CircularQue<T>& Q, int m) {
	int n;
	for (int i = 1; i <= m; i++) {
		std::cout << i << "��° �Է��Դϴ�. �Է� Ƚ���� " << m - i + 1 << "�� ���ҽ��ϴ�.";
		std::cin >> n;

		if (!IsFull())Q.EnQue(n);
		else throw("���� Que�� �� á���ϴ�. Ȯ�� ��Ź�帳�ϴ�.");
	}

}
template <typename T>
void DeQueControl(CircularQue<T>& Q, int m) {
	int n;
	for (int i = 1; i <= m; i++) {
		Q.DeQue(n);
		std::cout << "���� " << n << "�Դϴ�. " << i << "��° ����Դϴ�. ��� Ƚ���� " << m - i << "�� ���ҽ��ϴ�." << std::endl;

		if (!IsEmpty())Q.DeQue(n);
		else throw("���� Que�� ��� �ֽ��ϴ�. Ȯ�� ��Ź�帳�ϴ�.");
	}


}

int main() {
	CircularQue<int> C;//ũ�Ⱑ 10¥�� CircularQue�� ���ǵ�. ���� �׷����� �����غ���. 

	EnQueControl(C, 8);//0~7 8
	DeQueControl(C, 4);//4~7 4
	EnQueControl(C, 5);//4~9~0~2 9
	DeQueControl(C, 7);//1~2 2
	EnQueControl(C, 5);//1~7 7
	DeQueControl(C, 4);//5~7 3
	EnQueControl(C, 6);//5~9~0~3 9
	DeQueControl(C, 9);// Empty 0 
}