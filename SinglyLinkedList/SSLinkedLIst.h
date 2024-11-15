#ifndef _SSLINKEDLIST_H
#define _SSLINKEDLIST_H
#include"nodeType.h"



class SSLinkedList {

public:
	SSLinkedList() : F_List(nullptr), Cur_Pointer(nullptr), Length(0) {}//constructor
	~SSLinkedList();
	void MakeEmpty();
	bool IsEmpty() { return Length == 0; }
	int GetLength() const;//howmany??
	//따로 메모리 이런거에 제약이 오지 않는단 가정하에 따로 리턴값은 필요 없겠지만 몇 번째 자리에다가 넣었는지를 리턴하겠음
	int Add(ItemType item);
	void ResetList();//iterator null로 reset.
	bool GetNextItem(ItemType& item);//++iterator의 역할도 겸함. 성공하면 true 실패(마지막 값에 위치)하면 false
	
public:
	NodeType* F_List;//첫 노드값
	NodeType* Cur_Pointer;//이터레이터
	int Length;

};


SSLinkedList::~SSLinkedList() { MakeEmpty(); }

void SSLinkedList::MakeEmpty() {
	NodeType* tempptr;
	while (F_List ->next != nullptr) {
		tempptr = F_List;
		F_List = F_List->next;
		delete tempptr;
	}
	tempptr = F_List;
	delete tempptr;
	Length = 0;
}

int SSLinkedList::GetLength() const {
	return Length;
}

//결과값으로 '몇 번째에 넣었는지 알려주는 것도 가끔 쓸모가 있을 수도???
int SSLinkedList::Add(ItemType item) {
	ResetList();

	NodeType* newitem = new NodeType;
	NodeType* preitem;
	ItemType dummy;

	int C = 0;

	newitem->data = item;
	newitem->next = nullptr;


	//맨 앞에 넣어야 할 경우에 대해 예외처리
	if (IsEmpty()) F_List = newitem;

	else if (F_List->data >= item) {
		newitem->next = F_List;
		F_List = newitem;
	}

	else {
		while (1) {
			preitem = Cur_Pointer;
			GetNextItem(dummy);//이게 포인터 1칸 이동 연산을 겸함. 연산하면서 동시에 저장도 필요.
			C++;//포인터가 한 칸 이동하였음.
			if (dummy > item)
			{
				newitem->next = Cur_Pointer;
				preitem->next = newitem;
				//dangling pointer 현상이 나타날 걱정이 정말 적다. 
				//DoublyLinkedList에선 순서 하나하나 중요하니 미리 논리적 괜찮은 순서 생각해보는 것도 괜찮은듯
				break;
			}
			else if (Cur_Pointer->next == nullptr) //맨 뒤에 넣는 예외상황
			{
				Cur_Pointer->next = newitem;
				break;
			}
		}
	}

	Length++;
	return C;
}


void SSLinkedList::ResetList() { Cur_Pointer = nullptr; }



bool SSLinkedList::GetNextItem(ItemType& item) {

	
	if (Cur_Pointer == nullptr) Cur_Pointer = F_List;
	else if (Cur_Pointer->next == nullptr) return false;
	else Cur_Pointer = Cur_Pointer->next;

	item = Cur_Pointer->data;
	return true;
}

#endif _SSLINKEDLIST_H
