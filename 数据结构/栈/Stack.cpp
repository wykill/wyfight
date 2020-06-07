#include "Stack.h"

template <typename T>
StackList<T>::StackList() : m_head(new StackNode<T>()), m_size(0)
{
}

template <typename T>
StackList<T>::StackList(T val) : m_head(new StackNode<T>(val)), m_size(0)
{
}

template <typename T>
StackList<T>::~StackList()
{
    try {
        clear();
    } catch(...) {
        ::std::cout << "Err when deconstruct Stack" << ::std::endl;
    }
    if (m_head != NULL) {
        delete(m_head);
        m_head = NULL;
    }
}

template <typename T>
int StackList<T>::size() const
{
    return m_size;
}

template <typename T>
bool StackList<T>::isEmpty() const
{
    return m_size == 0;
}

template <typename T>
void StackList<T>::push(T val)
{
    if (m_head == NULL) {
        throw "Err, Stack Head is NULL";
    }

    StackNode<T>* newNode = new StackNode<T>(val);
    StackNode<T>* nextNode = m_head->next;
    m_head->next = newNode;
    newNode->next = nextNode;
    m_size++;
}

template <typename T>
T StackList<T>::top()
{
    if (m_head == NULL) {
        throw "Err, Stack Head is NULL";
    }
    if (m_head->next == NULL) {
        throw "Err, Stack is Empty";
    }
    return m_head->next->value;
}

template <typename T>
T StackList<T>::pop()
{
    if (m_head == NULL) {
        throw "Err, Stack Head is NULL";
    }
    if (m_head->next == NULL) {
        throw "Err, Stack is Empty";
    }

    StackNode<T>* topNode = m_head->next;
    int result = topNode->value;
    m_head->next = topNode->next;
    delete(topNode);
    topNode = NULL;
    m_size--;

    return result;
}

template <typename T>
void StackList<T>::clear()
{
    if (m_head == NULL) {
        throw "Err, Stack Head is NULL";
    }

    while (m_head->next)
    {
        StackNode<T>* curNode = m_head->next;
        StackNode<T>* nextNode = curNode->next;
        delete(curNode);
        m_head->next = nextNode;
    }
    m_size = 0; 
}