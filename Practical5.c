**AIM:** Implement a queue using an array with operations INSERT (enqueue), DELETE (dequeue) and DISPLAY.

### Program

```c
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if (rear == SIZE - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    queue[++rear] = value;

    printf("Element inserted successfully.\n");
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. INSERT (Enqueue)\n");
        printf("2. DELETE (Dequeue)\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
```

### Sample Output

```text
--- QUEUE MENU ---
1. INSERT (Enqueue)
2. DELETE (Dequeue)
3. DISPLAY
4. EXIT

Enter your choice: 1
Enter value to insert: 10
Element inserted successfully.

Enter your choice: 1
Enter value to insert: 20
Element inserted successfully.

Enter your choice: 3
Queue elements: 10 20

Enter your choice: 2
Deleted element: 10

Enter your choice: 3
Queue elements: 20
```

### Result
The queue operations INSERT, DELETE and DISPLAY were implemented successfully using an array.
