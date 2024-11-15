//US는 Unsorted, SinglyLinked를 의미합니다 S는 Sorted SinglyLinked를 의미함. 
//LinkedList 과제 부분은, Unsorted Singly LinkedList를 교수님께서 코드를 제공하신 것을 기반으로, Sorted Singly LinkedList, Sorted DoublyLinkedList를 
// 만드는 것이였음. 기본이 되는 부분이 깃허브에 안 올라가면 좀 그렇기도 하고 UnsortedSinglyLinkedList는 정~!말로 구현이 쉽기 때문에 
// 아무 것도 보지 않고 짰습니다. 정말로 Unsorted 짜는거보다 보고 Sorted 타이핑 98퍼 그대로 하고 2퍼정도 고치는게 더 오래 걸렸답니다..
//10월 25일에 진행한 코드 11월 15일에 리마스터.



#include<iostream>
// 두 LinkedList 중 하나는 주석처리 해주는 쪽으로. 
//#include"USLinkedList.h"
#include"SSLinkedList.h"
#include<random>

//US용과 파라미터랑 내부 변수에 있는 US SS만 서로 바꿔주면 범용 가능. 



void Print(SSLinkedList* SS) {
	SS->ResetList();
	ItemType T;
	while (SS->GetNextItem(T)) {
		std::cout << T << '\t';
	}

}



int main() {
	std::random_device R;
	std::mt19937 gen(R());
	std::uniform_int_distribution<> dis(1, 500);//값 임의 조정


	SSLinkedList S;
	for (int i = 0; i < 30; i++) {
		S.Add(dis(gen));
	}

	Print(&S);

	return 0;

}


//이 리마스터 작업을 하면서 흥미로웠던 점은, 원활한 검증을 위해 Print함수를 메인함수에 넣으려고 어떻게든 파라미터로 받는 식의 함수를 대충 만들었는데,
//일반적으로 Copy By Value 방식으로 하면 소멸자가 2번 발동되어 문제가 생기는 현상을 처음 겪어보았고, 다른 대학 컴공 4학년 다니는 친구한테 물어보며 이 문제를 해결하였다. 
//그냥 단순히 포인터로 받으면 되더라. 

