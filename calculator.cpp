#include "calculator.h"
#include <bits/stdc++.h>
double calculator::calculate(string s)
{
    stack<char> operators;  // 运算符的栈
    stack<double> operands; // 运算数的栈
    for (char c : s)
    {
        if (c == ' ')
        {
            // 跳过空格
            continue;
        }
        if (isdigit(c))
        {
            operands.push(c - '0');
        }
        else if (c == '(')
        {
            // 左括号，进入运算符栈
            operators.push(c);
        }
        else if (c == ')')
        {
            double res = 0;
            while (!operators.empty())
            {
                char opt = operators.top();
                operators.pop();
                if (opt == '(')
                    break;
                if (operators.empty())
                {
                    cout << "invalid expression" << endl;
                    return 0;
                }
                // 弹出两个数字来应付当前运算符
                double num1 = operands.top();
                operands.pop();
                double num2 = operands.top();
                operands.pop();
                res += applyOperatorOnOperand(num2, num1, opt);
            }
            operands.push(res);
        }
        else if (c == '!')
        {
            // 单独处理只需要一个操作数的阶乘运算符
            double num = operands.top();
            operands.pop();
            num = factorial(num);
            operands.push(num);
        }
        else
        {
            if (operators.empty())
            {
                operators.push(c);
                continue;
            }
            int cmp = cmpSuperiority(c, operators.top());
            switch (cmp)
            {
            case 1:
                // 优先级更大
                operators.push(c);
                break;
            default:
                /*
                优先级相同或者更低，要做的事都是一样的，将前面优先级更高的运算符代表的运算先做了
                然后将结果压栈即可
                */
                double num1 = operands.top();
                operands.pop();
                double num2 = operands.top();
                operands.pop();
                char opt = operators.top();
                operators.pop();
                operands.push(applyOperatorOnOperand(num2, num1, opt));
                // 添加当前运算符
                operators.push(c);
                break;
            }
        }
    }
    // 把剩余的表达式计算完毕
    while (!operators.empty())
    {
        double num1 = operands.top();
        operands.pop();
        double num2 = operands.top();
        operands.pop();
        char opt = operators.top();
        operators.pop();
        operands.push(applyOperatorOnOperand(num2, num1, opt));
    }

    // 如果表达式合法，那么结果运算数的栈只会有最终结果这一个数字
    return operands.top();
}
double calculator::applyOperatorOnOperand(double num1, double num2, char opt)
{
    switch (opt)
    {
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':
        return num1 / num2;
        break;
    default:
        cout << "invalid operator, error\n";
        break;
    }
    return 0;
}
int calculator::cmpSuperiority(char a, char b)
{
    // 定义运算符的优先级
    int priorityA = 0;
    int priorityB = 0;

    // 设置运算符优先级
    if (a == '+' || a == '-')
    {
        priorityA = 1;
    }
    else if (a == '*' || a == '/')
    {
        priorityA = 2;
    }
    else if (a == '!')
    {
        priorityA = 3; // 阶乘运算符优先级较高
    }

    if (b == '+' || b == '-')
    {
        priorityB = 1;
    }
    else if (b == '*' || b == '/')
    {
        priorityB = 2;
    }
    else if (b == '!')
    {
        priorityB = 3; // 阶乘运算符优先级较高
    }

    // 比较优先级并返回结果
    if (priorityA < priorityB)
    {
        return -1; // a的优先级低于b
    }
    else if (priorityA > priorityB)
    {
        return 1; // a的优先级高于b
    }
    else
    {
        return 0; // a和b的优先级相同
    }
}
double calculator::factorial(double n)
{
    // 计算阶乘
    double result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= (double)i;
    }
    return result;
}