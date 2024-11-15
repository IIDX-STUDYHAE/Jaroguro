//US�� Unsorted, SinglyLinked�� �ǹ��մϴ�
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
	void ResetList();//list�� �����͸� �Ǿ�����. 
	//�����͸� �� ĭ �̵���Ų ������, �� ������ �ȿ� �ִ� data�� �Ķ���� �ȿ� ���� ������.
	bool GetNextItem(ItemType& item);//�����ϸ� true �����ϸ� false
private:
	NodeType* F_List;//ù��° ��
	NodeType* Cur_Pointer;//iterator
	int Length;//����� ����

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

	//list�� node�� �������� �ʴ� ���
	if (IsEmpty()) this->F_List = node;
	else {
		Cur_Pointer = F_List;
		//���� ������ node�� �̵�.
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


//�׻� ����=nullptr�� ���شٰ� ������ �ڿ�, ��ĭ�� �̵��ϴ� ������ ���� �� 
// Cur_Pointer=nullptr�̸� First�� �̲������.
void USLinkedList::ResetList() { Cur_Pointer = nullptr; }

bool USLinkedList::GetNextItem(ItemType& item) {

	if (Cur_Pointer == nullptr) { Cur_Pointer = F_List; }
	else if (Cur_Pointer->next == nullptr) return false;
	else Cur_Pointer = Cur_Pointer->next;

	//������ First���� �ƴ� null���̴�, ���� �̵� �� �������� �� ���� ����ó�� �� ���� ����.
	item = Cur_Pointer->data;
	return true;
}


#endif _USLINKEDLIST_H

