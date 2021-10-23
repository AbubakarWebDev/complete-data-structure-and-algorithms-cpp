/*******************************************************************
Steps to Manually Convert Prefix to Infix Expressions:
1) Start Looking from left to right  till you get first instance if 1 operator followed by 2 operands.
2) Convert that to infix notation and assume/substitute it with a temporary Variable.  
3) Proceed forward from there to right or start again if end of expression is arrived.
4) Perform step 2 and 3 again.

For Example: Convert the Following prefix Expression to Infix: - + a * bc / de

Step 1: Start Looking from left to right till you get first instance if 1 operator followed by 2 operands:
- + a (*bc) / de
According to the step 1 we looking from left to right and find steric operartor that follow by 2 operands.


Step 2: Convert that to infix notation and assume/substitute it with a temporary Variable:
- + a X1 / de        // X1 = b * c
According to the step 2 we convert the first prefix sub expression to infix expression and assign variable.


Step 3: Proceed forward from there to right or start again if end of expression is arrived:
- + a X1 X2        // X2 = d / e
According to the step 3 we looking from left to right and find '/' operartor that followed by 2 operands.


Step 4: Perform step 2 and 3 again and again till the whole expression is solved:
- X3 X2        // X3 = a + X1
According to the step 4 we looking from left to right and find '+' operartor that followed by 2 operands.


Step 5: Perform step 2 and 3 again and again till the whole expression is solved:
X3 - X2
According to the step 5 we looking from left to right and find '-' operartor that followed by 2 operands.


Step 6: Re-Subtitute the temporary placeholders with their original values:
a + (b * c) - d / e
So According to the step 6 we Re-Subtitute All the temporary placeholders with their original values.
----------------------------------------------------------------------------------------

Steps to Convert Prefix to infix using stack data structures:
1) Scan PREFIX expression from RIGHT to LEFT or Reverse the PREFIX expression.
2) IF the incoming symbol is a OPERAND, PUSH it onto the Stack.
3) IF the incoming symbol is a OPERATOR, POP 2 OPERANDs from the Stack, ADD fix this incoming OPERATOR in between the 2 OPERANDs, ADD ‘(‘ & ‘)’ to the start & end of the whole expression & PUSH this whole new expression string back into the Stack.
4) At the end POP and PRINT the full INFIX expression from the Stack.
----------------------------------------------------------------------------------------

PSEUDOCODE for Converting Prefix to infix expressions using stack data structures:

FUNCTION  prefixtoInfix(stack, prefix)
    FOR LOOP (i = prefix.length - 1; i >= 0; i--)
        IF CHECK_OPERAND(prefix[i])
            THEN stack.push(prefix[i])
        ELSEIF CHECK_OPERATOR(prefix[i]) 
            character op1 = stack.top()
            stack.pop()
            character op2 = stack.top()
            stack.pop()
            String exp = '(' + op1 + prefix[i] + op2 + ')'
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

string prefixToInfix(stack <string> stk, string prefix)
{
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            string operandChar(1, prefix[i]);  // Calling String Constructor
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

int main()
{
    // Clearing Console Screen
    system("cls");

    // Variable Decelarations
    string infix_exp, prefix_exp;
    stack<string> stk;

    // Inputting Infix Expression From user:
    cout << "Enter a Prefix Expression: ";
    cin >> prefix_exp;

    // Showing Results
    cout << "\nPREFIX EXPRESSION: " << prefix_exp;
    infix_exp = prefixToInfix(stk, prefix_exp);
    cout << "\n\nINFIX EXPRESSION: " << infix_exp << "\n";

    return 0;
}

/***************************************************************
 * Examples of all type of Expressions for testing this program:
 * Postfix Expression: ab+c-def^^*g/
 * Prefix Expression: /*-+abc^d^efg
 * Infix Expression: ((a+b-c)*d^e^f)/g
 ***************************************************************/