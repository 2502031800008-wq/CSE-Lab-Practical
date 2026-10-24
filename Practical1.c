```c
#include <stdio.h>

void call_by_value(int x, int y);
void call_by_reference(int *x, int *y);

int main()
{
    int a = 10, b = 20;

    printf("Values of a and b before function call: a = %d, b = %d\n", a, b);

    call_by_value(a, b);
    printf("After call by value: a = %d, b = %d\n", a, b);

    call_by_reference(&a, &b);
    printf("After call by reference: a = %d, b = %d\n", a, b);

    return 0;
}

void call_by_value(int x, int y)
{
    x = x + 5;
    y = y + 5;

    printf("Inside call by value: x = %d, y = %d\n", x, y);
}

void call_by_reference(int *x, int *y)
{
    *x = *x + 5;
    *y = *y + 5;

    printf("Inside call by reference: x = %d, y = %d\n", *x, *y);
}
```
