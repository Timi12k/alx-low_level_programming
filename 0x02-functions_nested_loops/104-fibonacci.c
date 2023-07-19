#include <stdio.h>

void print_fibonacci_numbers(int n)
{
    unsigned long prev = 1, current = 2, next;

    if (n >= 1)
        printf("%lu", prev);

    for (int i = 1; i < n; i++)
    {
        printf(", %lu", current);
        next = prev + current;
        prev = current;
        current = next;
    }

    printf("\n");
}

int main()
{
    print_fibonacci_numbers(98);
    return 0;
}
