#include "LinkList.h"

template<typename T>
LinkList<T>::LinkList() : m_head(new LinkNode<T>()), m_size(0)
{
}

template<typename T>
LinkList<T>::LinkList(T val) 
{
    m_head = new LinkNode<T>();
    m_head->next = new LinkNode<T>(val);
    m_size = 1;
}

template<typename T>
int LinkList<T>::size() const
{
    return m_size;
}

template<typename T>
void LinkList<T>::print() const
{
    if (m_size == 0) {
        ::std::cout << "Empty LinkList..." << ::std::endl;
        return;
    }

    LinkNode<T>* head = m_head;
    while(head->next) {
        head = head->next;
        ::std::cout << head->value << " ";
    }
    ::std::cout << ::std::endl;
}

template<typename T>
void LinkList<T>::insert(int pos, T val)
{
    if (pos < 0 || pos > m_size) {
        pos = m_size;
    }
    LinkNode<T>* curNode = m_head;
    LinkNode<T>* nextNode = m_head->next;
    for (int i = 0; i < pos; i++) {
        curNode = nextNode;
        nextNode = nextNode->next;
    }
    LinkNode<T>* insertNode = new LinkNode<T>(val);
    curNode->next = insertNode;
    insertNode->next = nextNode;
    m_size++;
}

template<typename T>
void LinkList<T>::insert(T val)
{
    insert(m_size, val);
}

template<typename T>
void LinkList<T>::erase(int pos)
{
    if (pos < 0 || pos > m_size) {
        ::std::cout << "Positon is out of range!" << ::std::endl;
        return;
    }
    if (m_head == NULL) {
        ::std::cout << "LinkList is Empty!" << ::std::endl;
        return;
    }
    LinkNode<T>* preNode = m_head;
    LinkNode<T>* curNode = m_head->next;
    for (int i = 0; i < pos; i++) {
        preNode = curNode;
        curNode = curNode->next;
    }
    LinkNode<T>* nextNode = curNode->next;
    delete(curNode);
    preNode->next = nextNode;
    m_size--;
}

template<typename T>
LinkNode<T>* LinkList<T>::findVal(T val)
{
    LinkNode<T>* curNode = m_head->next;
    while (curNode) {
        if (curNode->value == val) {
            return curNode;
        }
        curNode = curNode->next;
    }
    return NULL;
}

template<typename T>
void LinkList<T>::deleteAll()
{
    LinkNode<T>* curNode = m_head->next;
    while (curNode) {
        LinkNode<T>* nextNode = curNode->next;
        delete(curNode);
        curNode = nextNode;  
    }
    m_size = 0;
}