#ifndef _CIRCLELINKLIST_H_
#define _CIRCLELINKLIST_H_

#include <iostream>

template<typename T>
struct LinkNode {
    LinkNode() : value(), next(NULL) {};
    LinkNode(T val) : value(val), next(NULL) {};
    T value;
    LinkNode* next;
};

template<typename T>
class CircleLinkList {
public:
    CircleLinkList();
    CircleLinkList(T val);
    
    int size() const;
    void print(int times) const;
    void insert(int pos, T val);
    void insert(T val);
    void erase(int pos);
    int erase(int startPos, int pos);
    LinkNode<T>* findVal(T val);
    void deleteAll();

private:
    LinkNode<T>* m_head;
    int m_size;
};

#endif

