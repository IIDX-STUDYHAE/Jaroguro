//US�� Unsorted, SinglyLinked�� �ǹ��մϴ� S�� Sorted SinglyLinked�� �ǹ���. 
//LinkedList ���� �κ���, Unsorted Singly LinkedList�� �����Բ��� �ڵ带 �����Ͻ� ���� �������, Sorted Singly LinkedList, Sorted DoublyLinkedList�� 
// ����� ���̿���. �⺻�� �Ǵ� �κ��� ����꿡 �� �ö󰡸� �� �׷��⵵ �ϰ� UnsortedSinglyLinkedList�� ��~!���� ������ ���� ������ 
// �ƹ� �͵� ���� �ʰ� ®���ϴ�. ������ Unsorted ¥�°ź��� ���� Sorted Ÿ���� 98�� �״�� �ϰ� 2������ ��ġ�°� �� ���� �ɷȴ�ϴ�..
//10�� 25�Ͽ� ������ �ڵ� 11�� 15�Ͽ� ��������.



#include<iostream>
// �� LinkedList �� �ϳ��� �ּ�ó�� ���ִ� ������. 
//#include"USLinkedList.h"
#include"SSLinkedList.h"
#include<random>

//US��� �Ķ���Ͷ� ���� ������ �ִ� US SS�� ���� �ٲ��ָ� ���� ����. 



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
	std::uniform_int_distribution<> dis(1, 500);//�� ���� ����


	SSLinkedList S;
	for (int i = 0; i < 30; i++) {
		S.Add(dis(gen));
	}

	Print(&S);

	return 0;

}


//�� �������� �۾��� �ϸ鼭 ��̷ο��� ����, ��Ȱ�� ������ ���� Print�Լ��� �����Լ��� �������� ��Ե� �Ķ���ͷ� �޴� ���� �Լ��� ���� ������µ�,
//�Ϲ������� Copy By Value ������� �ϸ� �Ҹ��ڰ� 2�� �ߵ��Ǿ� ������ ����� ������ ó�� �޾�Ұ�, �ٸ� ���� �İ� 4�г� �ٴϴ� ģ������ ����� �� ������ �ذ��Ͽ���. 
//�׳� �ܼ��� �����ͷ� ������ �Ǵ���. 

