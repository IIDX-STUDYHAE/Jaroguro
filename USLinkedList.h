//US는 Unsorted, SinglyLinked를 의미합니다
#ifndef _USLINKEDLIST_H
#define _USLINKEDLIST_H
#include"nodeType.h"


class USLinkedList {
public:
	USLinkedList() : F_List(nullptr), Cur_Pointer(nullptr), Length(0) {}//constructor
	~USLinkedList();

	void MakeEmpty();
	bool IsEmpty() { return Length == 0; }
	int GetLength() const { return Length; }
	void Add(ItemType item);
	void ResetList();//list의 포인터를 맨앞으로. 
	//포인터를 한 칸 이동시킨 다음에, 그 포인터 안에 있는 data를 파라미터 안에 넣은 변수로.
	bool GetNextItem(ItemType& item);//성공하면 true 실패하면 false
private:
	NodeType* F_List;//첫번째 값
	NodeType* Cur_Pointer;//iterator
	int Length;//노드의 개수

};



USLinkedList::~USLinkedList() { MakeEmpty(); }

void USLinkedList::MakeEmpty() {
	NodeType* tempPtr;

	while (F_List->next != nullptr) {
		tempPtr = F_List;
		F_List = F_List->next;
		delete tempPtr;
	}
	tempPtr = F_List;
	delete tempPtr;
	Length = 0;

}

void USLinkedList::Add(ItemType item) {
	ResetList();

	NodeType* node = new NodeType;
	bool Found = false;

	node->data = item;
	node->next = nullptr;

	//list에 node가 존재하지 않는 경우
	if (IsEmpty()) this->F_List = node;
	else {
		Cur_Pointer = F_List;
		//가장 마지막 node로 이동.
		while (1) {


			if (Cur_Pointer->next == nullptr) {
				Cur_Pointer->next = node;
				break;
			}
			Cur_Pointer = Cur_Pointer->next;
		}
	}
	Length++;
}


//항상 리셋=nullptr로 해준다고 생각한 뒤에, 한칸씩 이동하는 동작을 취할 때 
// Cur_Pointer=nullptr이면 First로 이끌어줘야.
void USLinkedList::ResetList() { Cur_Pointer = nullptr; }

bool USLinkedList::GetNextItem(ItemType& item) {

	if (Cur_Pointer == nullptr) { Cur_Pointer = F_List; }
	else if (Cur_Pointer->next == nullptr) return false;
	else Cur_Pointer = Cur_Pointer->next;

	//리셋이 First값이 아닌 null값이니, 먼저 이동 후 값배출할 때 따로 예외처리 할 것이 없음.
	item = Cur_Pointer->data;
	return true;
}


#endif _USLINKEDLIST_H

