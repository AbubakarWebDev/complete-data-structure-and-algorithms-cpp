/*******************************************************************
Stack Application:
1) What is Prefix, Infix & Postfix Expressions? Why do we need them?
3) Infix to Prefix Conversion using Stack Data Structure.
5) Prefix to Infix Conversion using Stack Data Structure.
2) Infix to Postfix Conversion using Stack Data Structure.
4) Postfix to Infix Conversion using Stack Data Structure.
6) Postfix to Prefix Conversion using Stack Data Structure.
7) Prefix to Postfix Conversion using Stack Data Structure.

What is an Expression?
An Expression is a combination of symbols that can be numbers (constants), variables, operations, symbols of grouping and other punctuation written is a specific format/way.

Depending on how the expression is written, we can classify it into 3 categories:
1) Prefix:
An expression is called the prefix expression if the operator appears in the expression before the operands. Simply of the form (operator operand1 operand2). E.g. +AB
2) Infix:
An expression is called the infix expression if the operator appears in the expression in between the operands. Simply of the form (operand1 operator operand2). E.g. A+B
3) Postfix:
An expression is called the postfix expression if the operator appears in the expression after the operands. Simply of the form (operand1 operand2 operator). E.g. AB+

Order of Operations(Operator Precedence):
1) Parentheses: {}, [], ()
2) Exponents(Right to Left): A^B, 2^3^4
3) Multiplication & Division(Left to Right): A*B/C
4) Addition & Subtraction(Left to Right): A + B – C

Associativity:
Associativity describes the rule where operators with the same precedence appear in an expression. For example, in expression a + b − c, both + and – have the same precedence, then which part of the expression will be evaluated first, is determined by associativity of those operators.

Why do we need 3 different expressions?
Infix expressions are human readable but not efficient for machine reading
Prefix and Postfix do not need the concept of precedence & associativity hence it becomes highly efficient to parse expressions in prefix or postfix formats.
******************************************************************/


#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(stack<char> stk, string infix)
{
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        if (isOperand(infix[i]))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            stk.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }
            if (stk.top() == '(')
            {
                stk.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (stk.empty())
            {
                stk.push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > precedence(stk.top()))
                {
                    stk.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(stk.top())) && (infix[i] == '^'))
                {
                    stk.push(infix[i]);
                }
                else
                {
                    while ((!stk.empty()) && (precedence(infix[i]) <= precedence(stk.top())))
                    {
                        postfix += stk.top();
                        stk.pop();
                    }
                    stk.push(infix[i]);
                }
            }
        }
    }
    while (!stk.empty())
    {
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}

string infixToPrefix(stack<char> stk, string infix)
{
    string prefix = "";
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    for (int i = 0; i < infix.length(); i++)
    {
        if (isOperand(infix[i]))
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            stk.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                prefix += stk.top();
                stk.pop();
            }
            if (stk.top() == '(')
            {
                stk.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (stk.empty())
            {
                stk.push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > precedence(stk.top()))
                {
                    stk.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(stk.top())) && (infix[i] == '^'))
                {
                    while ((precedence(infix[i]) == precedence(stk.top())) && (infix[i] == '^'))
                    {
                        prefix += stk.top();
                        stk.pop();
                    }
                    stk.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(stk.top()))
                {
                    stk.push(infix[i]);
                }
                else
                {
                    while ((!stk.empty()) && (precedence(infix[i]) < precedence(stk.top())))
                    {
                        prefix += stk.top();
                        stk.pop();
                    }
                    stk.push(infix[i]);
                }
            }
        }
    }
    while (!stk.empty())
    {
        prefix += stk.top();
        stk.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string postfixToInfix(stack<string> stk, string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string operandChar(1, postfix[i]); // Calling String Constructor
            stk.push(operandChar);
        }
        else if (isOperator(postfix[i]))
        {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            stk.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }
    return stk.top();
}

string prefixToInfix(stack<string> stk, string prefix)
{
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            string operandChar(1, prefix[i]); // Calling String Constructor
            stk.push(operandChar);
        }
        else if (isOperator(prefix[i]))
        {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            stk.push("(" + op1 + prefix[i] + op2 + ")");
        }
    }
    return stk.top();
}

string postfixToPrefix(stack<string> stk, string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string operandChar(1, postfix[i]); // Calling String Constructor
            stk.push(operandChar);
        }
        else if (isOperator(postfix[i]))
        {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            stk.push(postfix[i] + op2 + op1);
        }
    }
    return stk.top();
}

string prefixToPostfix(stack<string> stk, string prefix)
{
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            string operandChar(1, prefix[i]); // Calling String Constructor
            stk.push(operandChar);
        }
        else if (isOperator(prefix[i]))
        {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            stk.push(op1 + op2 + prefix[i]);
        }
    }
    return stk.top();
}

void mainMenu()
{
    bool check = true;
    string prefix_exp, postfix_exp, infix_exp;
    int choice;
    stack<char> stk1;
    stack<string> stk2;

    while (check)
    {
        system("cls");
        cout << "\n\n|============= ALL STACK APPLICATIONS =============|\n"
             << "Please Select Your Favourite Stack Applications With the Given Options: \n"
             << "1 : Convert Your Infix Expression To Postfix Expression\n"
             << "2 : Convert Your Infix Expression To Prefix Expression\n"
             << "3 : Convert Your Postfix Expression To Infix Expression\n"
             << "4 : Convert Your Prefix Expression To Infix Expression\n"
             << "5 : Convert Your Postfix Expression To Prefix Expression\n"
             << "6 : Convert Your Prefix Expression To Postfix Expression\n"
             << "7 : Exit Application\n"
             << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            cout << "Enter a Infix Expression: ";
            cin >> infix_exp;

            cout << "\nINFIX EXPRESSION: " << infix_exp;
            postfix_exp = infixToPostfix(stk1, infix_exp);
            cout << "\n\nPOSTFIX EXPRESSION: " << postfix_exp << "\n";
            break;

        case 2:
            system("cls");
            cout << "Enter a Infix Expression: ";
            cin >> infix_exp;

            cout << "\nINFIX EXPRESSION: " << infix_exp;
            prefix_exp = infixToPrefix(stk1, infix_exp);
            cout << "\n\nPREFIX EXPRESSION: " << prefix_exp << "\n";
            break;

        case 3:
            system("cls");
            cout << "Enter a Postfix Expression: ";
            cin >> postfix_exp;

            cout << "\nPOSTFIX EXPRESSION: " << postfix_exp;
            infix_exp = postfixToInfix(stk2, postfix_exp);
            cout << "\n\nINFIX EXPRESSION: " << infix_exp << "\n";
            break;

        case 4:
            system("cls");
            cout << "Enter a Prefix Expression: ";
            cin >> prefix_exp;

            cout << "\nPREFIX EXPRESSION: " << prefix_exp;
            infix_exp = prefixToInfix(stk2, prefix_exp);
            cout << "\n\nINFIX EXPRESSION: " << infix_exp << "\n";
            break;

        case 5:
            system("cls");
            cout << "Enter a Postfix Expression: ";
            cin >> postfix_exp;

            cout << "\nPOSTFIX EXPRESSION: " << postfix_exp;
            prefix_exp = postfixToPrefix(stk2, postfix_exp);
            cout << "\n\nPREFIX EXPRESSION: " << prefix_exp << "\n";
            break;

        case 6:
            system("cls");
            cout << "Enter a Prefix Expression: ";
            cin >> prefix_exp;

            cout << "\nPREFIX EXPRESSION: " << prefix_exp;
            postfix_exp = prefixToPostfix(stk2, prefix_exp);
            cout << "\n\nPOSTFIX EXPRESSION: " << postfix_exp << "\n";
            break;

        case 7:

            check = false;
            cout << "\nThank You Very Much For Using This Application\n";
            break;

        default:
            cout << "Error : Invalid Value Detected!\n";
            break;
        }

        cout << "\n";
        system("pause");
    }
}

int main()
{
    mainMenu();
    return 0;
}


/***************************************************************
 * Examples of all type of Expressions for testing this program:
 * Postfix Expression: ab+c-def^^*g/
 * Prefix Expression: /*-+abc^d^efg
 * Infix Expression: ((a+b-c)*d^e^f)/g
 ***************************************************************/