#pragma once


/*���� 3�� �ϳ��� �迭�� �̿��Ͽ�, �� ���� ������ �����ϴ� double stackŬ������ �ۼ��ϼ���.
ù ��° ������ 1000������ ���� �����մϴ�.
�� ��° ������ 1000�� �Ѵ� ���� �����մϴ�.
Double stack�� �ִ� ������ ���� ������ 200�Դϴ�.
�� ������ ������ �������� �ʾҽ��ϴ�.  
1000������ ���� 200���� ������ �� �ְ�, 1000������ ���� �ϳ��� ���� ���� �ֽ��ϴ�.
Push �� �� ���� ���Ͽ� 0������ ä�� �ְų�, 199������ ä�� �ֽ��ϴ�.
Pop, Top ������ �����ϼ���.
2���� flag��(top�� ����ϴ� ����) ����ؼ� stack�� �����մϴ�.
Print ����Լ��� �߰��� ���� ��� Stack �� ���� ������������ pop�մϴ�. 
*/


const int MAX_ITEMS = 200; //�뷮


class DoubleStack {
public:
	DoubleStack();//Constructor
	bool IsFull()const;
	bool smallEmpty()const;//���� ���� �Է¹޴� �κ��� �����?
	bool bigEmpty() const;//ū ���� �Է¹޴� �κ��� �����?
	void Push(int item);//���ǹ�����, 2 track�� ���������� ������.
	void Print();//���� ���� 'Stack'���ν��� �ּ����� identity.

private:
	int small;
	int big;
	int items[MAX_ITEMS];
};