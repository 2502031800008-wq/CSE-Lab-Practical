**Aim:** Develop a program to perform insertion, deletion, searching, and traversal operations on arrays.

**Program:**

```c
#include <stdio.h>

int main()
{
    int a[100], n, i, choice, pos, value, key, found;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    do
    {
        printf("\n1. Traversal");
        printf("\n2. Insertion");
        printf("\n3. Deletion");
        printf("\n4. Searching");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Array elements: ");
                for (i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;

            case 2:
                if (n >= 100)
                {
                    printf("Array is full.\n");
                    break;
                }

                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);

                if (pos < 1 || pos > n + 1)
                {
                    printf("Invalid position.\n");
                    break;
                }

                printf("Enter value: ");
                scanf("%d", &value);

                for (i = n; i >= pos; i--)
                {
                    a[i] = a[i - 1];
                }

                a[pos - 1] = value;
                n++;

                printf("Element inserted successfully.\n");
                break;

            case 3:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);

                if (pos < 1 || pos > n)
                {
                    printf("Invalid position.\n");
                    break;
                }

                for (i = pos - 1; i < n - 1; i++)
                {
                    a[i] = a[i + 1];
                }

                n--;

                printf("Element deleted successfully.\n");
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);

                found = 0;

                for (i = 0; i < n; i++)
                {
                    if (a[i] == key)
                    {
                        printf("Element found at position %d\n", i + 1);
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Element not found.\n");
                }
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
```

**Output (Example):**

```text
Enter number of elements: 5
Enter array elements:
10 20 30 40 50

1. Traversal
2. Insertion
3. Deletion
4. Searching
5. Exit
Enter your choice: 1
Array elements: 10 20 30 40 50

Enter your choice: 4
Enter element to search: 30
Element found at position 3
```

**Time Complexity:**
- Traversal: O(n)
- Insertion: O(n)
- Deletion: O(n)
- Searching: O(n)
