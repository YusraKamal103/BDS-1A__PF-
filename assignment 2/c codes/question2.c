/*
programmer: Yusra Kamal
Section: BDS-1A
Roll NO: 26K-2518
Assignment: 2
Question: 2
Topic: returns the sum of proper divisors of x

*/



#include <stdio.h>


int sumProperDivisors(int x)
{
    int sum = 1, i;           /* 1 divides every x > 1 */
    if (x <= 1) return 0;

    for (i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            sum += i;
            if (i != x / i)       
                sum += x / i;
        }//end if
    }//end for
    return sum;
}

int main(void)
{
    int n, a, b, count = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Amicable pairs up to %d:\n", n);

    for (a = 2; a <= n; a++)
    {
        b = sumProperDivisors(a);

        if (b > a && b <= n && sumProperDivisors(b) == a)
        {
            printf("(%d, %d)\n", a, b);
            count++;
        }//end if
    }//end for

    if (count == 0)
        printf("No amicable pairs found up to %d.\n", n);
    else
        printf("Total pairs found: %d\n", count);

    return 0;
}
