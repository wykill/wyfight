#include "Stack.cpp"
#include <iostream>
#include <list>

void test01()
{
    ::std::cout << "test01......." << ::std::endl;
    StackList<int> stack;
    for (int i = 0; i < 10; i++) {
        stack.push(i);
    }
    ::std::cout << stack.size() << ::std::endl;

    while (stack.size() != 0) {
        int val = stack.top();
        stack.pop();
        ::std::cout << val << " ";
    }
    ::std::cout << ::std::endl;

    ::std::cout << stack.size() << ::std::endl;
    try {
        stack.pop();
    } catch (::std::string const& e) {
        ::std::cout << e << ::std::endl;
    } catch (const char* e) {
        ::std::cout << "const char* e is " << e << ::std::endl;
    }
    stack.clear();
}

// () recognize
void parenTest()
{
    ::std::cout << "parenTest......." << ::std::endl;
    ::std::string const& str = "1 + (3 + (3 * (4 + 5) / 2)";
    StackList<char> stack;
    ::std::cout << str << ::std::endl;
    ::std::list<int> errPos;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            stack.push(str[i]);
            errPos.push_back(i);
            continue;
        }
        if (str[i] == ')') {
            if (stack.size() == 0) {
                errPos.push_back(i);
                break;
            }
            stack.pop();
            errPos.pop_back();
        }
    }
    if (errPos.size() == 0) {
        ::std::cout << "Correct Expression!" << ::std::endl;
        return;
    }
    for (int i = 0; i < str.size(); i++) {
        if (::std::find(errPos.begin(), errPos.end(), i) != errPos.end()) {
            ::std::cout << "A";
            continue;
        }
        ::std::cout << " ";
    }
    ::std::cout << ::std::endl;
    // ::std::cout << "size of stack is " << stack.size() << ::std::endl;
    stack.clear();
}

bool isEmpty(char ch)
{
    return ch == ' ';
}

bool isNum(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool isLeft(char ch)
{
    return ch == '(';
}

bool isRight(char ch)
{
    return ch == ')';
}

int getPriority(char ch)
{
    if (ch == '*' || ch == '/') {
        return 2;
    }
    if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

::std::string MidToPostFix(::std::string const& str)
{
    // ::std::string const& str = "1 + (3 - 2 * 1) * 8 / (4 + 2)";
    ::std::string resultStr;
    ::std::cout << "MidFixStr is " << str << ::std::endl;
    ::std::cout << "After transfer to PostFix: " << ::std::endl;
    StackList<char> stack;
    int errPos = -1;
    for (int i = 0; i < str.size(); i++) {
        if (isNum(str[i])) {
            resultStr += str[i];
            ::std::cout << str[i];
            continue;
        }
        if (isEmpty(str[i])) {
            continue;
        }
        if (isLeft(str[i])) {
            stack.push(str[i]);
            continue;
        }
        if (isRight(str[i])) {
            while (stack.size() != 0) {
                char popVal = stack.pop();
                if (popVal == '(') {
                    break;
                }
                ::std::cout << popVal;
                resultStr += popVal;
            }
            continue;
        }
        // 处理符号
        if (stack.isEmpty() || isLeft(stack.top())) {
            stack.push(str[i]);
            continue;
        }
        int topElePrio = getPriority(stack.top());
        int priority = getPriority(str[i]);
        // ::std::cout << "topEle: " << stack.top() << ::std::endl;
        // ::std::cout << "str[i]: " << str[i] << ::std::endl;
        if (priority <= topElePrio) {
            resultStr += stack.top();
            ::std::cout << stack.pop();
        }
        stack.push(str[i]);
    }
    while (stack.size() != 0) {
        resultStr += stack.top();
        ::std::cout << stack.pop();

    }
    ::std::cout << ::std::endl;
    return resultStr;
}

void getNum(int& firstNum, int& secondNum, StackList<int>& stack)
{
    secondNum = stack.pop();
    firstNum = stack.pop();
}

int getPostStrResult(::std::string const& str)
{
    StackList<int> stack;
    for (int i = 0; i < str.size(); i++) {
        if (isNum(str[i])) {
            stack.push(str[i] - '0');
            continue;
        }
        int secondNum, firstNum;
        int resultNum;
        switch (str[i]) {
            case '*' : 
                getNum(firstNum, secondNum, stack);
                resultNum = firstNum * secondNum;
                break;
            case '/' :
                getNum(firstNum, secondNum, stack);
                resultNum = firstNum / secondNum;
                break;
            case '+' :
                getNum(firstNum, secondNum, stack);
                resultNum = firstNum + secondNum;
                break;
            case '-' :
                getNum(firstNum, secondNum, stack);
                resultNum = firstNum - secondNum;
                break;
            default :
                break;
        }
        stack.push(resultNum);
    }

    while (stack.size() == 1) {
        return stack.pop();
    }
    return 0;
}



int main()
{
    ::std::string const& str = "1 + (3 - 2 * 1) * 8 / (4 + 2)";
    ::std::string const& str2 = "1 + (5 * 8 / 2) - 3";
    ::std::string postStr("");
    int result;
    // test01();
    // parenTest();
    postStr = MidToPostFix(str2);
    ::std::cout << "PostStr is " << postStr << ::std::endl;
    result = getPostStrResult(postStr);
    ::std::cout << "ResultNum is " << result << ::std::endl;
    return 0;
}