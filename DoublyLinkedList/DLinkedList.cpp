//DoublyLinkedList. 기본적으로 이왕 포인터도 많은거 Sorted로 하는게?
//과제로 진행할 때 내용은 'Singly LinkedList'를 기반으로 Doubly 구현해보고, 대신 이터레이터에 대한 힌트를 주는 구조였음.
//이번 장은 10월 25일에 진행한 과제를 11월 16일에 리마스터하였으며, 리마스터 과정에서 테스팅 코드를 위한 Print함수를 만들려다 보니까, 내가 제출한 과제에 예외처리가 어느 정도 엉망으로 되어있단 사실을 알게 됐음 ㅠㅠㅠㅠ
//그래서 모든 예외처리를 깔끔하게 하는데 약 4시간을 썼고, 자고 일어나서 Print함수를 또 갈아엎고 이 Print함수를 만드는 다양한 방법들 중 무슨 방법을 쓸지 고민하며 약 2시간을 더 소비하였음. 하아 





#include<iostream>
#include"DIterator.h"
#include<random>





// 항상 '순서'를 엄청 중요하게 생각하고, 순서가 왜 이런 순서가 나오는지 주기적으로 생각해줘야
// DoublyLinkedList는 병합 등 값들 간의 처리를 할 때 너무 예외처리할 내용이 많아, 맨 처음노드와 맨 뒤 노드를 비어있는 상태로 둠.
DoublyLinkedList::DoublyLinkedList() {
    Length = 0;
    DoublyNodeType* first = new DoublyNodeType;
    DoublyNodeType* last = new DoublyNodeType;
    first->front = nullptr;
    first->back = last;
    F_List = first;
    last->front = first;
    last->back = nullptr;
    L_List = last; // L_List 초기화 추가
    // ItemType이 무엇인지에 따른, 최소값과 최대값 을 직접써주면 좋음. 지금의 경우엔 인트니까 . 꼭 의미 없는 값임을 인지해야.
    F_List->data = -2147483647;
    L_List->data = +2147483647;
}

DoublyLinkedList::~DoublyLinkedList() { makeEmpty(); }

DoublyIterator DoublyLinkedList::CreateIterator() {
    return DoublyIterator(*this);
}

// LinkedList를 활용할 때, 포인터 자체의 메모리 크기 때문에 만들어야 할 노드의 양이 많아지면 자연스레 다른 구조에 비해 이점이 없어짐.

bool DoublyLinkedList::IsFull() {
    return (sizeof(DoublyNodeType) * (Length + 2) > 8192);
    //Full에 해당하는 값은 임의로 만들 수 있고, 논리적으로 저 값보다 약간 오버했을 때는 크게 문제삼지 않음.
    //가끔 값이 너무 많을 시에 메모리할당 실패 문제가 생길 수 있고,그럴 때는 그냥 다른 자료구조를 쓰는게.. 
}

void DoublyLinkedList::makeEmpty() {
    DoublyNodeType* tempptr;
    while (F_List->back != L_List) {
        tempptr = F_List;
        F_List = F_List->back;
        delete tempptr;
    }
    //while문 실행 후 F_List값은 data가 비어있는 맨앞값, L_List 맨뒤값
    F_List->data = -2147483647;//값을 임의로 초기화해줘야. F_List의 값에 접근하는 동작 조심해가며 안 만들어 주면 의미없는 값임.
    F_List->front = nullptr;//dangling pointer현상 방지
    L_List->front = F_List;
}

void DoublyLinkedList::Add(ItemType item) {
    DoublyNodeType* newitem = new DoublyNodeType;
    newitem->data = item;
    newitem->front = nullptr;
    newitem->back = nullptr;
    if (IsFull()) throw("너무 많은 값을 DoublyLinkedList에 집어넣었습니다.");

    else if (IsEmpty()) {
        newitem->front = F_List;
        newitem->back = L_List;
        F_List->back = newitem;
        L_List->front = newitem;
    }
    else {
        DoublyIterator iterator = CreateIterator();
        ItemType now;
        while (true) {
            if (!iterator.NextNotNull()) {
                // 마지막 노드에 도달한 경우
                L_List->front->back = newitem;
                newitem->back = L_List;
                newitem->front = L_List->front;
                L_List->front = newitem;
                break;
            }
            now = iterator.Next();
            if (now > item) {
                DoublyNodeType* location = iterator.GetCurrentNode();
                newitem->back = location;
                newitem->front = location->front;
                location->front->back = newitem;
                location->front = newitem;
                break;
            }
        }
    }
    Length++;
}

// 값을 지울 수 있으면 return 1 없으면 return 0
int DoublyLinkedList::Delete(ItemType item) {
    if (IsEmpty()) return 0;

    ItemType now;
    DoublyIterator iterator = CreateIterator(); // iterator 선언
    while (iterator.NextNotNull()) {
        now = iterator.Next(); // 이터레이터 한 칸 이동시키는 연산 겸함
        if (now == item) {
            DoublyNodeType* location = iterator.GetCurrentNode();
            location->back->front = location->front;
            location->front->back = location->back;
            delete location;
            Length--;
            return 1;
        }
        else if (now > item) return 0; // 아이템 존재 x.
    }
    return 0;
}



//Print함수 짜는데에 2시간이 넘게 걸렸다.. 정확히는 마지막 더미데이터에 대한 예외처리와 이를 'private'를 private으로써 남기는 코드를 짜되 private한 값을 어느 정도 터치하고 싶단 생각이 들었고
//그거에 대해서 인터넷도 많이 찾아보고 AI한테도 물어보고 했는데 결국 더미에 대해서는 후행적으로 가라로 지우는게 맞다고 생각이 된다. 
//후기:온갖 값에 대한 가능성에 따른 예외처리 해줄 것들이 너무 많았다. 아직 코딩 초급자라 내가 깔끔한 비상구에 대해 잘 모르는 경향도 있고. 그래도 깨지고 부셔지고 싶다.

inline void Print(DoublyLinkedList* D) {
    DoublyIterator iter = D->CreateIterator();
    ItemType T;
    //iter.First에 대해서는 dummy 확실히 안 나옴. 
    std::cout << iter.First() << " ";

    while (iter.NextNotNull()) {
        T = iter.Next();
        //근데 전반적으로 '마지막 전 값'에 대한 멤버함수를 하나 만들면 만들어봤자 활용도가 적어서 오히려 이런 식의 예외처리를 고려할 수 있다. 하드하게 더미값에 각 변수타입별 최대값과 최소값을 상징적으로 넣어준 느낌인데, 그때그때 바꿔서 쓰면 될듯.
        if(T!= 2147483647) std::cout << T << " ";
    }

    

}




int main() {
	std::random_device R;
	std::mt19937 gen(R());
	std::uniform_int_distribution<> dis(1, 200);//값 임의 조정


	DoublyLinkedList S;
	for (int i = 0; i < 15; i++) {
		S.Add(dis(gen));
	}


    Print(&S);
    

   


    

	return 0;

}
