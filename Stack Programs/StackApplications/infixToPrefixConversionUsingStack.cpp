/*******************************************************************
Steps to Manually Convert Infix to Prefix:
1) Apply appropriate brackets/paranthesis to expression by the operator precedence and associativity rules.
2) Start by Converting Inner most sub expression to prefix and name it with temporary placeholder.
3) Repeat step 2 on other larger sub expression till with full expression is solved. Re-Subtitute the temporary placeholders with their original values. 

For Example: Convert the Following Infix Expression to Prefix: a + b * c - d / e

Step 1: Applying by the operator precedence and associativity rules:
[a + (b * c) - (d / e)]
So According to the step 1 the precedence of * and / are same. So we use left to right associativity here.


Step 2: Start by Converting Inner most sub expression to prefix and name it with temporary placeholder:
[a + X1 - X2]       // X1 = '*bc'  X2 = '/de'
So According to the step 2 we solved the above expression from left to right and assigns placeholder.


Step 3: Repeat step 2 on other larger sub expression till with full expression is solved:
[X3 - X2]       // X3 = '+aX1'
So According to the step 3 we solved the above expression from left to right and assigns placeholder.


Step 4: Repeat step 2 on other larger sub expression till with full expression is solved:
[-X3X2]       // X3 = '+aX1'
So According to the step 4 we solved the above expression completely from left to right.


Step 5: Re-Subtitute the temporary placeholders with their original values:
-+a*bc/de
So According to the step 5 we Re-Subtitute All the temporary placeholders with their original values.
----------------------------------------------------------------------------------------

Steps to Convert Infix to Prefix using stack data structures:
1) Reverse infix expression & swap ‘(‘ to ”)’ and ‘)’ to ”(‘
2) Scan Expression from Left to Right.
3) Print OPERANDs as the arrive.
4) IF incoming SYMBOL is ‘(‘ then PUSH it onto Stack.
5) IF incoming SYMBOL is ‘)’ then we POP the stack and print all the stack values till stacks gets empty OR  ‘(‘ is found. If ‘(‘ is found then POP it but never print it.
6) If OPERATOR arrives & Stack is empty, push this operator onto the stack.
7) IF incoming OPERATOR has HIGHER precedence than the TOP of the Stack, push incoming OPERATOR on stack. IF the TOP of stack is ‘(‘ PUSH incoming OPERATOR on Stack.
8) IF incoming OPERATOR has LOWER precedence than the TOP of the Stack, then POP and print the TOP. Then compares the incoming OPERATOR With the NEW TOP of stack.
9) IF incoming OPERATOR has EQUAL precedence than the TOP of Stack then push the incoming OPERATOR on stack. Else IF incoming OPERATOR has EQUAL precedence than the TOP of the Stack and the incoming OPERATOR is equal to '^', then POP and print the TOP till this conditon is true.
11) At the end of Expression, POP & print all OPERATORS from the stack and reverse the output string again.
----------------------------------------------------------------------------------------

PSEUDOCODE for Converting Infix to Prefix expressions using stack data structures:

FUNCTION  infixToPrefix(stack, infix)
    
    Declare Variable: String prefix
    infix = reverse(infix)

    FOR LOOP (i = 0; i < infix.length; i++)
        IF infix[i] == '('
            THEN infix[i] = ')'
        ELSEIF infix[i] == ')'
            THEN infix[i] = '('

        IF CHECK_OPERAND(infix[i])
            THEN prefix += infix[i]
        ELSEIF infix[i] == '('
            THEN stack.push(infix[i])
        ELSEIF infix[i] == ')'
            WHILE LOOP (!stack.isEmpty() AND stk.top() != '(')
                prefix += stk.top()
                stack.pop()
            END WHILE
        ELSEIF CHECK_OPERATOR(infix[i]) 
            IF Stack.isEmpty()
                THEN stack.push(infix[i])
            ELSEIF !Stack.isEmpty()
                IF PRECEDENCE(infix[i]) > PRECEDENCE(stack.top)
                    THEN stack.push(infix[i])
                ELSEIF (PRECEDENCE(infix[i]) == PRECEDENCE(stack.top))
                    THEN stack.push(infix[i])
                ELSEIF (PRECEDENCE(infix[i]) == PRECEDENCE(stack.top)) && (infix[i] == '^')
                    WHILE LOOP ((precedence(infix[i]) == precedence(stk.top())) && (infix[i] == '^'))
                        prefix += stack.top()
                        stack.pop()
                    END WHILE
                    stack.push(infix[i])
                ELSE 
                    WHILE LOOP (!Stack.isEmpty()) && (PRECEDENCE(infix[i]) <= PRECEDENCE(stack.top))
                        prefix += stack.top()
                        stack.pop()
                    END WHILE
                    stack.push(infix[i])
                ENDIF
            ENDIF
        ENDIF
    END FOR LOOP

    WHILE LOOP (!Stack.isEmpty())
        prefix += stack.top()
        stack.pop()
    END WHILE

    prefix = reverse(prefix)

    RETURN prefix
END FUNCTION

******************************************************************/

#include <iostream>
#include <stack>
#include <string>
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

int main()
{
    // Clearing Console Screen
    system("cls");

    // Variable Decelarations
    string infix_exp, prefix_exp;
    stack<char> stk;

    // Inputting Infix Expression From user:
    cout << "Enter a Infix Expression: ";
    cin >> infix_exp;

    // Showing Results
    cout << "\nINFIX EXPRESSION: " << infix_exp;
    prefix_exp = infixToPrefix(stk, infix_exp);
    cout << "\n\nPREFIX EXPRESSION: " << prefix_exp << "\n";

    return 0;
}

/***************************************************************
 * Examples of all type of Expressions for testing this program:
 * Postfix Expression: ab+c-def^^*g/
 * Prefix Expression: /*-+abc^d^efg
 * Infix Expression: ((a+b-c)*d^e^f)/g
 ***************************************************************/