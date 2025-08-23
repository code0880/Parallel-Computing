/*
Modify the pgm to find the largest prime number less than n.
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
int isPrime(int num)
{
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;
    for (int i = 3; i < sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    printf("Enter upper limit :");
    scanf("%d", &n);
    if (n <= 2)
    {
        printf("There is no prime number less than 2");
        return 0;
    }
    int largePrime = 2;
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i))
            largePrime = i;
    }
    printf("Larget prime number %d", largePrime);
    return 0;
}