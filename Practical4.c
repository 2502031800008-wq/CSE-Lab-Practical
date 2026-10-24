**AIM:** Implement a program to convert infix notation to postfix notation using stack.

### Program

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}

int precedence(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;

    return 0;
}

int main()
{
    char infix[100], postfix[100];
    char x;
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        x = infix[i];

        if (isalnum((unsigned char)x))
        {
            postfix[j++] = x;
        }
        else if (x == '(')
        {
            push(x);
        }
        else if (x == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && stack[top] != '(' &&
                  (precedence(stack[top]) > precedence(x) ||
                  (precedence(stack[top]) == precedence(x) && x != '^')))
            {
                postfix[j++] = pop();
            }

            push(x);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
```

### Sample Output

```text
Enter infix expression: A+B*C
Postfix expression: ABC*+
```

### Result

The program converts an infix expression into a postfix expression using a stack.
