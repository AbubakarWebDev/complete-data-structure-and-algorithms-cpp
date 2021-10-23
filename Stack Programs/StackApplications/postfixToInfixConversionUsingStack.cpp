/*******************************************************************
Steps to Manually Convert postfix to Infix Expressions:
1) Start Looking from right to left till you get first instance if 1 operator followed by 2 operands.
2) Convert that to infix notation and assume/substitute it with a temporary Variable.  
3) Proceed forward from there to right or start again if end of expression is arrived.
4) Perform step 2 and 3 again.

For Example: Convert the Following postfix Expression to Infix: abc * + de / -

Step 1: Start Looking from right to left till you get first instance if 1 operator followed by 2 operands:
abc* + (de/) -
According to the step 1 we looking from right to left and find '/' operartor that follow by 2 operands.


Step 2: Convert that to infix notation and assume/substitute it with a temporary Variable:
abc * + X1 -       // X1 = d / e
According to the step 2 we convert the first postfix sub expression to infix expression and assign variable.


Step 3: Proceed forward from there to right or start again if end of expression is arrived and repeat step 2:
a X2 + X1 -       // X2 = b * c
According to the step 3 we looking from right to left and find steric operartor that followed by 2 operands.


Step 4: Perform step 2 and 3 again and again till the whole expression is solved:
X3 X1 -       // X3 = a + X2
According to the step 4 we looking from right to left and find '+' operartor that followed by 2 operands.


Step 5: Perform step 2 and 3 again and again till the whole expression is solved:
X3 - X1
According to the step 5 we looking from right to left and find '-' operartor that followed by 2 operands.


Step 6: Re-Subtitute the temporary placeholders with their original values:
a + (b * c) - d / e
So According to the step 6 we Re-Subtitute All the temporary placeholders with their original values.
----------------------------------------------------------------------------------------

Steps to Convert postfix to infix using stack data structures:
1) Scan postfix expression from LEFT to RIGHT.
2) IF the incoming symbol is a OPERAND, PUSH it onto the Stack.
3) IF the incoming symbol is a OPERATOR, POP 2 OPERANDs from the Stack, ADD fix this incoming OPERATOR in between the 2 OPERANDs, ADD ‘(‘ & ‘)’ to the start & end of the whole expression & PUSH this whole new expression string back into the Stack.
4) At the end POP and PRINT the full INFIX expression from the Stack.
----------------------------------------------------------------------------------------

PSEUDOCODE for Converting postfix to infix expressions using stack data structures:

FUNCTION  postfixtoInfix(stack, postfix)

    FOR LOOP (i = 0; i < postfix.length; i++)
        IF CHECK_OPERAND(postfix[i])
            THEN stack.push(postfix[i])
        ELSEIF CHECK_OPERATOR(postfix[i]) 
            character op1 = stack.top()
            stack.pop()
            character op2 = stack.top()
            stack.pop()
            String exp = '(' + op2 + postfix[i] + op1 + ')'
            stack.push(exp)
        ENDIF
    END FOR LOOP

    RETURN stack.top()
END FUNCTION

******************************************************************/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

string postfixToInfix(stack <string> stk, string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string operandChar(1, postfix[i]);  // Calling String Constructor
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

int main()
{
    // Clearing Console Screen
    system("cls");

    // Variable Decelarations
    string infix_exp, postfix_exp;
    stack<string> stk;

    // Inputting Infix Expression From user:
    cout << "Enter a Postfix Expression: ";
    cin >> postfix_exp;

    // Showing Results
    cout << "\nPOSTFIX EXPRESSION: " << postfix_exp;
    infix_exp = postfixToInfix(stk, postfix_exp);
    cout << "\n\nINFIX EXPRESSION: " << infix_exp << "\n";

    return 0;
}

/***************************************************************
 * Examples of all type of Expressions for testing this program:
 * Postfix Expression: ab+c-def^^*g/
 * Prefix Expression: /*-+abc^d^efg
 * Infix Expression: ((a+b-c)*d^e^f)/g
 ***************************************************************/