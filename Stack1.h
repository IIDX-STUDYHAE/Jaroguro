#pragma once


/*예제 3번 하나의 배열을 이용하여, 두 개의 스택을 구현하는 double stack클래스를 작성하세요.
첫 번째 스택은 1000이하의 수를 저장합니다.
두 번째 스택은 1000을 넘는 수를 저장합니다.
Double stack의 최대 아이템 저장 갯수는 200입니다.
각 스택의 개수는 정해지지 않았습니다.  
1000이하의 수로 200개를 저장할 수 있고, 1000이하의 수가 하나도 없을 수도 있습니다.
Push 할 때 값을 비교하여 0번부터 채워 넣거나, 199번부터 채워 넣습니다.
Pop, Top 연산은 생략하세요.
2개의 flag를(top을 기록하는 변수) 사용해서 stack을 관리합니다.
Print 멤버함수를 추가로 만들어서 모든 Stack 의 값을 오름차순으로 pop합니다. 
*/


const int MAX_ITEMS = 200; //용량


class DoubleStack {
public:
	DoubleStack();//Constructor
	bool IsFull()const;
	bool smallEmpty()const;//작은 값을 입력받는 부분이 비었나?
	bool bigEmpty() const;//큰 값을 입력받는 부분이 비었나?
	void Push(int item);//조건문으로, 2 track을 후행적으로 나눠야.
	void Print();//문제 막줄 'Stack'으로써의 최소한의 identity.

private:
	int small;
	int big;
	int items[MAX_ITEMS];
};