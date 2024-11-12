#pragma once


/*���� 4��: �Ϲ����� Stack�� �Ķ���ͷ� ���� �޾Ƽ� ���� ġȯ�ϴ� �Լ��� �ۼ��Ͽ���.
oldItem�� newItem�� �Ķ���ͷ� �ް�, oldItem�� ���� newItem���� �ٲ������ ReplaceItem�Լ��� �ۼ��غ���
*/


const int MAX_ITEMS = 200; //�뷮


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
	void ReplaceItem(int o, int n);//�켱 ����Լ��� ������.
};

