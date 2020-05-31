#include "CircleLinkList.h"

template<typename T>
CircleLinkList<T>::CircleLinkList() : m_head(new LinkNode<T>()), m_size(0)
{
}

template<typename T>
CircleLinkList<T>::CircleLinkList(T val) 
{
    m_head = new LinkNode<T>();
    m_head->next = new LinkNode<T>(val);
    m_head->next->next = m_head->next;
    m_size = 1;
}

template<typename T>
int CircleLinkList<T>::size() const
{
    return m_size;
}

template<typename T>
void CircleLinkList<T>::print(int times) const
{
    if (m_size == 0) {
        ::std::cout << "Empty CircleLinkList..." << ::std::endl;
        return;
    }

    LinkNode<T>* head = m_head;
    for (int i = 0; i < times * m_size; i++) {
        head = head->next;
        ::std::cout << head->value << " ";
    }
    ::std::cout << ::std::endl;
}

template<typename T>
void CircleLinkList<T>::insert(int pos, T val)
{
    LinkNode<T>* insertNode = new LinkNode<T>(val);
    
    if (m_size == 0) {
        m_head->next = insertNode;
        m_head->next->next = m_head->next;
        m_size++;
        return;
    }
    while (pos < 0) {
        pos += m_size;
    }
    LinkNode<T>* curNode = m_head;
    LinkNode<T>* nextNode = m_head->next;
    for (int i = 0; i < pos; i++) {
        curNode = nextNode;
        nextNode = nextNode->next;
    }
    curNode->next = insertNode;
    insertNode->next = nextNode;
    m_size++;
}

template<typename T>
void CircleLinkList<T>::insert(T val)
{
    insert(m_size, val);
}

template<typename T>
void CircleLinkList<T>::erase(int pos)
{
    while (pos <= 0) {
        pos += m_size;
    }
    while (pos > m_size) {
        pos -= m_size;
    }
    if (m_size == 0) {
        ::std::cout << "Empty CircleLinkList" << ::std::cout;
    }
    LinkNode<T>* preNode = m_head;
    LinkNode<T>* curNode = m_head->next;
    for (int i = 0; i < pos; i++) {
        preNode = curNode;
        curNode = curNode->next;
    }
    LinkNode<T>* nextNode = curNode->next;
    if (curNode == m_head->next) {
        m_head->next = nextNode;
    }
    delete(curNode);
    preNode->next = nextNode;
    m_size--;
}

template<typename T>
int CircleLinkList<T>::erase(int startPos, int pos)
{
    int realPos = (startPos + pos) % m_size;
    erase(realPos);
    return realPos;
}

template<typename T>
LinkNode<T>* CircleLinkList<T>::findVal(T val)
{
    LinkNode<T>* curNode = m_head->next;
    for (int i = 0; i < m_size; i++) {
        if (curNode->value == val) {
            return curNode;
        }
        curNode = curNode->next;
    }
    return NULL;
}

template<typename T>
void CircleLinkList<T>::deleteAll()
{
    LinkNode<T>* curNode = m_head->next;
    for (int i = 0; i < m_size; i++) {
        LinkNode<T>* nextNode = curNode->next;
        delete(curNode);
        curNode = nextNode;  
    }
    m_size = 0;
}