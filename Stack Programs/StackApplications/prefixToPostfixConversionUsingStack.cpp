/*******************************************************************
Steps to Manually Convert Prefix to postfix:
1) Start Looking from left to right till you get first instance if 1 operator followed by 2 operands.
2) Convert that to postfix notation and assume/substitute it with a temporary Variable.
3) Proceed forward from there to right or start again if end of expression is arrived.
4) Perform step 2 and 3 again.

For Example: Convert the Following prefix Expression to postfix: / * - + abc ^ d ^ efg

Step 1: Start Looking from left to right till you get first instance if 1 operator followed by 2 operands:
/ * - (+ ab)c ^ d ^ efg
According to the step 1 we looking from left to right and find '+' operartor that follow by 2 operands.


Step 2: Convert that to postfix notation and assume/substitute it with a temporary Variable:
/ * - X1 c ^ d ^ efg        // X1 = ab+
According to the step 2 we convert the first prefix sub expression to postfix expression and assign variable.


Step 3: Proceed forward from there to right or start again if end of expression is arrived:
/ * X2 ^ d ^ efg        // X2 = X1c-
According to the step 3 we looking from left to right and find '-' operartor that followed by 2 operands.


Step 4: Perform step 2 and 3 again and again till the whole expression is solved:
/ * X2 ^ d X3 g        // X3 = ef^
According to the step 4 we looking from left to right and find '^' operartor that followed by 2 operands.


Step 5: Perform step 2 and 3 again and again till the whole expression is solved:
/ * X2 X4 g        // X4 = dX3^
According to the step 5 we looking from left to right and find '^' operartor that followed by 2 operands.


Step 6: Perform step 2 and 3 again and again till the whole expression is solved:
/ X5 g        // X5 = X2X4*
According to the step 6 we looking from left to right and find steric operartor that followed by 2 operands.


Step 7: Perform step 2 and 3 again and again till the whole expression is solved:
X5 g /        
According to the step 7 we looking from left to right and find '/' operartor that followed by 2 operands.


Step 6: Re-Subtitute the temporary placeholders with their original values:
ab + c - def ^ ^ * g /     
So According to the step 6 we Re-Subtitute All the temporary placeholders with their original values.
----------------------------------------------------------------------------------------

Steps to Convert Prefix to postfix using stack data structures:
1) Scan PREFIX expression from RIGHT to LEFT OR Reverse the Expression.
2) IF the incoming symbol is a OPERAND, PUSH it onto the Stack.
3) IF the incoming symbol is a OPERATOR, POP 2 OPERANDs from the Stack, ADD fix this incoming OPERATOR at the end of the 2 OPERANDs, PUSH this whole expression string back into the Stack.
4) At the end POP and PRINT the full POSTFIX expression from the Stack.
----------------------------------------------------------------------------------------

PSEUDOCODE for Converting Prefix to postfix expressions using stack data structures:

FUNCTION  postfixtoPrefix(stack, postfix)

    FOR LOOP (i = 0; i < postfix.length; i++)
        IF CHECK_OPERAND(postfix[i])
            THEN stack.push(postfix[i])
        ELSEIF CHECK_OPERATOR(postfix[i])
            character op1 = stack.top()
            stack.pop()
            character op2 = stack.top()
            stack.pop()
            String exp = postfix[i] + op2 + op1
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

string prefixToPostfix(stack <string> stk, string prefix)
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
            stk.push(op1 + op2 + prefix[i]);
        }
    }
    return stk.top();
}

int main()
{
    // Clearing Console Screen
    system("cls");

    // Variable Decelarations
    string prefix_exp, postfix_exp;
    stack <string> stk;

    // Inputting Prefix Expression From user:
    cout << "Enter a Prefix Expression: ";
    cin >> prefix_exp;

    // Showing Results
    cout << "\nPREFIX EXPRESSION: " << prefix_exp;
    postfix_exp = prefixToPostfix(stk, prefix_exp);
    cout << "\n\nPOSTFIX EXPRESSION: " << postfix_exp << "\n";

    return 0;
}

/***************************************************************
 * Examples of all type of Expressions for testing this program:
 * Postfix Expression: ab+c-def^^*g/
 * Prefix Expression: /*-+abc^d^efg
 * Infix Expression: ((a+b-c)*d^e^f)/g
 ***************************************************************/