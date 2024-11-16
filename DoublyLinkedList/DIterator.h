#ifndef DITERATOR_H
#define DITERATOR_H

class DoublyLinkedList;
struct DoublyNodeType;
#include"DLinkedList.h"

class DoublyIterator {
    friend class DoublyLinkedList;

public:
    DoublyIterator(const DoublyLinkedList& list) : List(list), Cur_Pointer(list.F_List) {};
    bool NotNull() { return Cur_Pointer != nullptr; }//지금이 nullptr 상태인가?
    bool NextNotNull() { return (Cur_Pointer!= List.L_List); }//지금 DoublyLinkedList의 마지막 더미값에 위치한거?
    ItemType First();//첫 원소로 iterator을 이동시킨 후에, 그 값을 리턴해줌
    ItemType Next();//다음 노드로 iterator가 이동하고 그 노드의 결과값을 리턴해줌
    DoublyNodeType* GetCurrentNode() { return Cur_Pointer; }//현재 자신의 노드에 해당하는 주소값을 리턴.
private:
    const DoublyLinkedList& List;
    DoublyNodeType* Cur_Pointer;
};

ItemType DoublyIterator::First() {
    while (Cur_Pointer->front != nullptr) Cur_Pointer = Cur_Pointer->front;//맨 앞까지 가 주고, 반복문 나가서 뒤로 한 칸
    Cur_Pointer = Cur_Pointer->back;
    return Cur_Pointer->data;
}

ItemType DoublyIterator::Next() {
    if (NextNotNull()) {
        Cur_Pointer = Cur_Pointer->back;
        return Cur_Pointer->data;
    }
    else {
        throw("Iterator가 마지막 dummy값을 가리킵니다.");
    }
   
}

#endif 
