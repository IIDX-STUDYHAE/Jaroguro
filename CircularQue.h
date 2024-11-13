#pragma once

/*수업 과제는 따로 교수님이 코드 주는 것 없이 CircularQue를 만들기 였음.
아마 이전에 만든 Stack에서 힌트를 얻어서 하라는 취지의 과제인 것 같고 수행할 때도 이렇게 함. 
10월 16일 새벽에 했던 것 11월 13일에 리마스터.
아래는 구현해야 할 멤버함수 목록.
 //m_items에 max_item개수만큼 동적할당
~CircularQue(); //m_items 할당 해제
bool isEmpty() const;
 bool isFull() const;
 bool EnQue(const ItemType & input);//input을 que에 삽입
bool DeQue(ItemType& output);//output에 que의 데이터 출력
CircularQue(const CircularQue& org);//복사 생성자. 깊은 복사 진행
CircularQue<ItemType> & operator=(const CircularQue&
org); //대입 연산자 깊은 복사 진행
*/


template <typename T>

class CircularQue {
private: 
	T* m_item; //값을 저장하는 부분
	int front;
	int rear; 
	int max;

public:
	CircularQue(int max_item = 10);
	~CircularQue();//queue를 푸는 Destructor
	bool IsFull() const;
	bool IsEmpty() const;
	bool EnQue(const T& input);//input에 해당하는 값을 que안에 넣기. 잘 들어갔으면 True 리턴
	bool DeQue(T& output);//queue에서 뺴야 할 값을 출력한 후에 없앰.
	CircularQue(const CircularQue& org);//깊은복사를 진행하는 복사 생성자.
	CircularQue<T>& operator =(const CircularQue& org);//대입 연산자

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
	return ((rear + 1) % max == front);// Full일 때 rear값의 '다음에' front가 위치할텐데 rear == max-1이면 문제생김.
}

template<typename T>
bool CircularQue<T>::IsEmpty() const {
	return (front == rear);
}

//bool 방식으로 함수가 잘 돌아갔는지 여부를 리턴하는 것은 '예외처리는 따로 해라'
//AI(Grok)한테 물어보니 '안 좋은 코드'는 아니라고 함. 결국 이 코드에서 처리해야 할 가장 큰 예외는 사용자 실수인데 
//굳이 성능에 영향 미치는 예외처리를 강하게 해줄 필요가 없다. 는 입장 
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

//여기서부터 정말 중요함. 

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





