#include "RPN.hpp"
#include <stdexcept>

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) : numbers(other.numbers) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other) {
        numbers = other.numbers;
    }
    return *this;
}

bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isValidNumber(char c) const
{
    return c >= '0' && c <= '9';
}

void RPN::performOperation(char op)
{
    if (numbers.size() < 2) {
        throw std::runtime_error("Error");
    }

    int b = numbers.top();
    numbers.pop();
    int a = numbers.top();
    numbers.pop();

    switch (op) {
        case '+':
            numbers.push(a + b);
            break;
        case '-':
            numbers.push(a - b);
            break;
        case '*':
            numbers.push(a * b);
            break;
        case '/':
            if (b == 0) throw std::runtime_error("Error: Division by zero");
            numbers.push(a / b);
            break;
    }
}

int RPN::evaluate(const std::string& expression)
{
    numbers = std::stack<int>();

    for (size_t i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') continue;
        
        if (isValidNumber(expression[i])) {
            int num = expression[i] - '0';
            if (num >= 10) throw std::runtime_error("Error");
            numbers.push(num);
        }
        else if (isOperator(expression[i])) {
            performOperation(expression[i]);
        }
        else {
            throw std::runtime_error("Error");
        }
    }

    if (numbers.size() != 1) {
        throw std::runtime_error("Error");
    }

    return numbers.top();
}