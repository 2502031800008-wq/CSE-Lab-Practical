**AIM:** Implement a stack using an array with operations PUSH, POP, PEEP, CHANGE and DISPLAY.

### Program

```c
#include <stdio.h>
#define SIZE 4

int stack[SIZE];
int top = -1;

void push()
{
    int value;

    if (top == SIZE - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    stack[++top] = value;
    printf("Element pushed successfully.\n");
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return;
    }

    printf("Popped element: %d\n", stack[top--]);
}

void peep()
{
    int position;

    printf("Enter position from top: ");
    scanf("%d", &position);

    if (position < 1 || position > top + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Element: %d\n", stack[top - position + 1]);
}

void change()
{
    int position, value;

    printf("Enter position from top: ");
    scanf("%d", &position);

    if (position < 1 || position > top + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    stack[top - position + 1] = value;
    printf("Element changed successfully.\n");
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. CHANGE\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peep();
                break;

            case 4:
                change();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
```

### Sample Output

```text
--- STACK MENU ---
1. PUSH
2. POP
3. PEEP
4. CHANGE
5. DISPLAY
6. EXIT
Enter your choice: 1
Enter value: 10
Element pushed successfully.

Enter your choice: 1
Enter value: 20
Element pushed successfully.

Enter your choice: 5
Stack elements (top to bottom):
20
10

Enter your choice: 2
Popped element: 20
```

**Result:** Stack operations PUSH, POP, PEEP, CHANGE and DISPLAY were implemented successfully using an array.
