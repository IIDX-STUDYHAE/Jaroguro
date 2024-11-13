#pragma once

/*���� ������ ���� �������� �ڵ� �ִ� �� ���� CircularQue�� ����� ����.
�Ƹ� ������ ���� Stack���� ��Ʈ�� �� �϶�� ������ ������ �� ���� ������ ���� �̷��� ��. 
10�� 16�� ������ �ߴ� �� 11�� 13�Ͽ� ��������.
�Ʒ��� �����ؾ� �� ����Լ� ���.
 //m_items�� max_item������ŭ �����Ҵ�
~CircularQue(); //m_items �Ҵ� ����
bool isEmpty() const;
 bool isFull() const;
 bool EnQue(const ItemType & input);//input�� que�� ����
bool DeQue(ItemType& output);//output�� que�� ������ ���
CircularQue(const CircularQue& org);//���� ������. ���� ���� ����
CircularQue<ItemType> & operator=(const CircularQue&
org); //���� ������ ���� ���� ����
*/


template <typename T>

class CircularQue {
private: 
	T* m_item; //���� �����ϴ� �κ�
	int front;
	int rear; 
	int max;

public:
	CircularQue(int max_item = 10);
	~CircularQue();//queue�� Ǫ�� Destructor
	bool IsFull() const;
	bool IsEmpty() const;
	bool EnQue(const T& input);//input�� �ش��ϴ� ���� que�ȿ� �ֱ�. �� ������ True ����
	bool DeQue(T& output);//queue���� ���� �� ���� ����� �Ŀ� ����.
	CircularQue(const CircularQue& org);//�������縦 �����ϴ� ���� ������.
	CircularQue<T>& operator =(const CircularQue& org);//���� ������

};


template<typename T>
CircularQue<T>::CircularQue(int max_item) {
	front = max_item;
	rear = max_item;
	max = max_item + 1;
	m_item = new T[max];
}

template<typename T>
CircularQue<T>::~CircularQue() {
	delete[] m_item;

}

template<typename T>
bool CircularQue<T>::IsFull() const {
	return ((rear + 1) % max == front);// Full�� �� rear���� '������' front�� ��ġ���ٵ� rear == max-1�̸� ��������.
}

template<typename T>
bool CircularQue<T>::IsEmpty() const {
	return (front == rear);
}

//bool ������� �Լ��� �� ���ư����� ���θ� �����ϴ� ���� '����ó���� ���� �ض�'
//AI(Grok)���� ����� '�� ���� �ڵ�'�� �ƴ϶�� ��. �ᱹ �� �ڵ忡�� ó���ؾ� �� ���� ū ���ܴ� ����� �Ǽ��ε� 
//���� ���ɿ� ���� ��ġ�� ����ó���� ���ϰ� ���� �ʿ䰡 ����. �� ���� 
template<typename T>
bool CircularQue<T>::EnQue(const T& input) {
	if (IsFull()) {
		return false;
	}
	rear = (rear + 1) % max;
	m_item[rear] = input;
	return true;
}

template<typename T>
bool CircularQue<T>::DeQue(T& output) {

	if (IsEmpty()) {
		return false;
	}
	front = (front + 1) % max;
	output = m_item[front];
	return true;
}

//���⼭���� ���� �߿���. 

template<typename T>
CircularQue<T>::CircularQue(const CircularQue& org) {
	front = org.front;
	rear = org.rear;
	max = org.max;
	m_item = new T[max];
	for (int i = 0; i < max; i++) {
		m_item[i] = org.m_item[i];
	}
}

template<typename T>
CircularQue<T>& CircularQue<T>::operator= (const CircularQue& org) {

	front = org.front;
	rear = org.rear;
	max = org.max;
	m_item = new T[max];
	for (int i = 0; i < max; i++)
		m_item[i] = org.m_item[i];
	return *this;

}





