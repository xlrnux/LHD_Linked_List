//
// Created by xlrnux on 19. 6. 8.
//

#ifndef LHD_LINKED_LIST_LINKEDLIST_H
#define LHD_LINKED_LIST_LINKEDLIST_H

typedef int iter;

template <class T>
class LinkedList{
public:
    static const int MAXSIZE = 30000;
private:
    typedef struct tagNode{
        T val;
        iter prev; // prev idx
        iter next; // next idx
    }tagNode;
    tagNode Node[MAXSIZE+2];
    int _size = 0;
    iter pos = 0;
    iter Head = MAXSIZE;
    iter Tail= MAXSIZE + 1;
    void Link(iter prev, iter next){
        Node[prev].next = pos;
        Node[pos].prev = prev;
        Node[pos].next = next;
        Node[next].prev = pos;
    }
    void UnLink(iter target){
        iter prev = Node[target].prev;
        iter next = Node[target].next; // Tail

        Node[prev].next = next; Node[next].prev = prev;
        Node[target].prev = Node[target].next = target;
    }

public:
    void clear(){
        pos = 0;
        _size = 0;
        Head = MAXSIZE;
        Tail = MAXSIZE + 1;
        Node[Head].next = Tail;
        Node[Tail].prev = Head;
    }
    LinkedList(){
        clear();
    }
    void push_back(T newVal){
        if(_size == 0) clear();

        iter prev = Node[Tail].prev;
        iter next = Node[prev].next; // New Tail

        Node[pos].val = newVal;

        Link(prev, next);
        ++pos; ++_size;
    }

    void push_front(T newVal){
        if(_size == 0) push_back(newVal);

        iter next = Node[Head].next;
        iter prev = Node[next].prev; // New Head

        Node[pos].val = newVal;

        Link(prev, next);
        ++pos;++_size;
    }

    void pop_back(){
        if(_size <= 0 ) return;
        iter target = Node[Tail].prev; // Last Node
        UnLink(target);
        --_size;
    }

    void pop_front(){
        if(_size <= 0 ) return;
        iter target = Node[Head].next; // First Node
        UnLink(target);
        --_size;
    }

    void erase(iter target){
        if(_size <= 0) return;
        if(target == Head || target == Tail) return;
        if(Node[target].next == target) return;

        UnLink(target);
        --_size;
    }

    iter begin(){
        //if(_size == 0) return -12489123; // 런타임 에러 발생시키기
        return Node[Head].next;
    }

    iter end(){
        //if(_size == 0) return -968549; // 런타임 에러 발생시키기
        return Tail;
    }

    T front(){
        if(_size == 0) return 0;
        iter target = Node[Head].next;
        return Node[target].val;
    }

    T back(){
        if(_size == 0) return 0;
        iter target = Node[Tail].prev;
        return Node[target].val;
    }
    iter getNext(iter it){
        if( it == Tail ) return Tail;
        return Node[it].next;
    }

    iter getPrev(iter it){
        if(it == Head) return Head;
        return Node[it].prev;
    }

    T at(iter it){
        return Node[it].val;
    }

    int size(){
        return _size;
    }

    bool empty(){
        return (_size == 0);
    }

};


#endif //LHD_LINKED_LIST_LINKEDLIST_H
