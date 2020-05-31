#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <iostream>

template<typename T>
struct LinkNode {
    LinkNode() : value(), next(NULL) {};
    LinkNode(T val) : value(val), next(NULL) {};
    T value;
    LinkNode* next;
};

template<typename T>
class LinkList {
public:
    LinkList();
    LinkList(T val);
    
    int size() const;
    void print() const;
    void insert(int pos, T val);
    void insert(T val);
    void erase(int pos);
    LinkNode<T>* findVal(T val);
    void deleteAll();

private:
    LinkNode<T>* m_head;
    int m_size;
};

#endif

