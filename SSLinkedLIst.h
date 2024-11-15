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
	//���� �޸� �̷��ſ� ������ ���� �ʴ´� �����Ͽ� ���� ���ϰ��� �ʿ� �������� �� ��° �ڸ����ٰ� �־������� �����ϰ���
	int Add(ItemType item);
	void ResetList();//iterator null�� reset.
	bool GetNextItem(ItemType& item);//++iterator�� ���ҵ� ����. �����ϸ� true ����(������ ���� ��ġ)�ϸ� false
	
public:
	NodeType* F_List;//ù ��尪
	NodeType* Cur_Pointer;//���ͷ�����
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

//��������� '�� ��°�� �־����� �˷��ִ� �͵� ���� ���� ���� ����???
int SSLinkedList::Add(ItemType item) {
	ResetList();

	NodeType* newitem = new NodeType;
	NodeType* preitem;
	ItemType dummy;

	int C = 0;

	newitem->data = item;
	newitem->next = nullptr;


	//�� �տ� �־�� �� ��쿡 ���� ����ó��
	if (IsEmpty()) F_List = newitem;

	else if (F_List->data >= item) {
		newitem->next = F_List;
		F_List = newitem;
	}

	else {
		while (1) {
			preitem = Cur_Pointer;
			GetNextItem(dummy);//�̰� ������ 1ĭ �̵� ������ ����. �����ϸ鼭 ���ÿ� ���嵵 �ʿ�.
			C++;//�����Ͱ� �� ĭ �̵��Ͽ���.
			if (dummy > item)
			{
				newitem->next = Cur_Pointer;
				preitem->next = newitem;
				//dangling pointer ������ ��Ÿ�� ������ ���� ����. 
				//DoublyLinkedList���� ���� �ϳ��ϳ� �߿��ϴ� �̸� ���� ������ ���� �����غ��� �͵� ��������
				break;
			}
			else if (Cur_Pointer->next == nullptr) //�� �ڿ� �ִ� ���ܻ�Ȳ
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