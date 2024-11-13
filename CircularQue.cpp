#include<iostream>
#include"CircularQue.h"
//과제 최초로할 때 만들었던 테스트 코드


template <typename T>
void EnQueControl(CircularQue<T>& Q, int m) {
	int n;
	for (int i = 1; i <= m; i++) {
		std::cout << i << "번째 입력입니다. 입력 횟수는 " << m - i + 1 << "번 남았습니다.";
		std::cin >> n;

		if (!IsFull())Q.EnQue(n);
		else throw("지금 Que가 꽉 찼습니다. 확인 부탁드립니다.");
	}

}
template <typename T>
void DeQueControl(CircularQue<T>& Q, int m) {
	int n;
	for (int i = 1; i <= m; i++) {
		Q.DeQue(n);
		std::cout << "값은 " << n << "입니다. " << i << "번째 출력입니다. 출력 횟수는 " << m - i << "번 남았습니다." << std::endl;

		if (!IsEmpty())Q.DeQue(n);
		else throw("지금 Que가 비어 있습니다. 확인 부탁드립니다.");
	}


}

int main() {
	CircularQue<int> C;//크기가 10짜리 CircularQue로 정의됨. 원을 그려보며 생각해보기. 

	EnQueControl(C, 8);//0~7 8
	DeQueControl(C, 4);//4~7 4
	EnQueControl(C, 5);//4~9~0~2 9
	DeQueControl(C, 7);//1~2 2
	EnQueControl(C, 5);//1~7 7
	DeQueControl(C, 4);//5~7 3
	EnQueControl(C, 6);//5~9~0~3 9
	DeQueControl(C, 9);// Empty 0 
}