#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>

template <typename T>
struct StackNode {
    StackNode() : value(T()), next(NULL) 
    {}

    StackNode(T val) : value(val), next(NULL) 
    {}
    T value;
    StackNode* next;
};

template <typename T>
class StackList {
public:
    StackList();
    StackList(T val);
    ~StackList();

    // 栈元素个数
    int size() const;
    bool isEmpty() const;
    // 入栈
    void push(T value);
    // 栈顶元素
    T top();
    // 出栈
    T pop();
    // 清空栈
    void clear();

private:
    StackNode<T>* m_head;
    int m_size;
};


#endif