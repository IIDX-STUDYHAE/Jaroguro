#pragma once


/*예제 4번: 일반적인 Stack에 파라미터로 값을 받아서 값을 치환하는 함수를 작성하여라.
oldItem과 newItem을 파라미터로 받고, oldItem을 전부 newItem으로 바꿔버리는 ReplaceItem함수를 작성해보기
*/


const int MAX_ITEMS = 200; //용량


class StackType {
private:
	int top;
	int items[MAX_ITEMS];

public:
	StackType();//Constructor
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(int item);//Add newitem to the top of the stack
	void Pop();//Removes top item from the stack.
	int Top();//Return a copy of top item on the stack.
	void ReplaceItem(int o, int n);//우선 멤버함수로 만들어보기.
};

