#pragma once

#include <stack>
#include <string>

class RPN
{
private:
    std::stack<int> numbers;
    bool isOperator(char c) const;
    bool isValidNumber(char c) const;
    void performOperation(char op);

public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    int evaluate(const std::string& expression);
};