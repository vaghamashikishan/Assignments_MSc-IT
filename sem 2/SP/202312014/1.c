#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void fib(int n)
{
    int a = 0;
    int b = 1;
    int c;
    printf("Fibonaaci sequence : ");
    while (n--)
    {
        printf("%d, ", a);
        int temp = b;
        b = a + b;
        a = temp;
    }
    printf("\n");
}

void factorial(int n)
{
    int ans = 1;
    printf("Factorial : ");
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    printf("%d\n", ans);
}

void len(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        n = n / 10;
        cnt++;
    }

    printf("Length : %d\n", cnt);
}

int main()
{
    void (*funcPointer[])(int) = {fib, factorial, len};
    int choice;
    printf("Enter 1 for fibbonacci function.\n");
    printf("Enter 2 for factorial function.\n");
    printf("Enter 3 for len function.\n");
    printf("Enter 0 for EXIT.\n");
    while (true)
    {
        scanf("%d", &choice);
        if (choice)
        {
            int num;
            printf("Enter the number:- ");
            scanf("%d", &num);
            funcPointer[choice - 1](num);
        }
        if (choice == 0)
        {
            break;
        }
    }

    return 0;
}