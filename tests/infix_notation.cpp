#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include "infix_notation.h"


enum struct TokenType
{
    TT_NUMBER,
    TT_OPERATION,
    TT_END
};

enum struct Operation
{
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV
};

void SkipWhitespace(std::istream &istrm)
{
    while (isspace(istrm.peek()))
    {
        istrm.get();
    }
}

TokenType GetNextTokenType(std::istream &istrm)
{
    SkipWhitespace(istrm);

    if (istrm.eof())
    {
        return TokenType::TT_END;
    }

    switch (istrm.peek())
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return TokenType::TT_OPERATION;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return TokenType::TT_NUMBER;


        default:
            throw std::logic_error("Bad token in stream");
    }
}

Operation GetOperation(std::istream &istrm)
{
    switch (istrm.get())
    {
        case '+':
            return Operation::OP_ADD;
        case '-':
            return Operation::OP_SUB;
        case '*':
            return Operation::OP_MUL;
        case '/':
            return Operation::OP_DIV;

        default:
            throw std::logic_error("Bad operation in stream");
    }
}

Int GetNumber(std::istream &istrm)
{
    Int value = 0;
    char c = istrm.peek();
    while (isdigit(c))
    {
        c = istrm.get();
        value = value * 10 + (c - '0');
        c = istrm.peek();
    }

    return value;
}

Int EvalOperation(Operation op, Int l, Int r)
{
    switch (op)
    {
        case Operation::OP_ADD:
            return l + r;
        case Operation::OP_SUB:
            return l - r;
        case Operation::OP_MUL:
            return l * r;
        case Operation::OP_DIV:
            return l / r;
        default:
            throw std::logic_error("Enum switch reached default, how come?");
    }
}

Int GetPriorOper(Operation o)
{
    switch (o)
    {
        case Operation::OP_ADD:
        case Operation::OP_SUB:
            return 1;

        case Operation::OP_MUL:
        case Operation::OP_DIV:
            return 2;

        default:
            throw std::logic_error("Something unexpected in GetPriorOper");
    }
}

void Reduce(std::stack<Operation> &oper,
            std::stack<Int> &value,
            Operation o)
{
    if (oper.empty())
    {
        oper.push(o);
        return;
    }
    Operation top_op = oper.top();
    Int pr_top = GetPriorOper(top_op);
    Int pr_cur = GetPriorOper(o);
    if ((pr_top > pr_cur) || (pr_top == 1 && pr_cur == 1))
    {
        if (value.size() < 2)
        {
            throw std::logic_error("Something unexpected in Reduce");
        }
        while (value.size() >= 2)
        {
            top_op = oper.top();
            Int r = value.top();
            value.pop();
            Int l = value.top();
            value.pop();
            Int new_value = EvalOperation(top_op, l, r);
            oper.pop();
            value.push(new_value);

        }
    }
    oper.push(o);
}

Int InfixNotationExpr(std::istream &istrm)
{
    std::stack<Operation> oper;
    std::stack<Int> value;

    Int answer = 0;
    TokenType prev_token = TokenType::TT_OPERATION;

    while (true)
    {
        TokenType next;
        next = GetNextTokenType(istrm);

        if (next == TokenType::TT_OPERATION)
        {
            if (prev_token == TokenType::TT_OPERATION)
            {
                throw std::logic_error("Two operations in row");
            }
            Operation o = GetOperation(istrm);
            Reduce(oper, value, o);
            prev_token = TokenType::TT_OPERATION;
        }

        else if (next == TokenType::TT_NUMBER)
        {
            if (prev_token == TokenType::TT_NUMBER)
            {
                throw std::logic_error("Two numbers in row");
            }
            Int new_value = GetNumber(istrm);
            value.push(new_value);
            prev_token = TokenType::TT_NUMBER;
        }

        else if (next == TokenType::TT_END)
        {
            break;
        }

        else
        {
            throw std::logic_error("Default case triggered in enum switch");
        }
    }

    Reduce(oper, value, Operation::OP_ADD);
    value.push(0);
    if (value.size() != 2 || oper.size() != 1)
    {
        throw std::logic_error("Something wrong in the end");
    }
    Int r = value.top();
    value.pop();
    Int l = value.top();
    value.pop();
    Operation o = oper.top();
    oper.pop();
    answer = EvalOperation(o, l, r);

    return answer;
}

int main()
{
    std::string s = "10 / 2 + 2 * 2 * 2 - 1";
    std::istringstream iss(s);
    std::cout << InfixNotationExpr(iss) << std::endl;
}

