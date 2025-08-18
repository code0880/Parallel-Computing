// Write an open mp pgm to transform each element with
// a[i] = 3 * a[i] +2
// using hash pragma omp parallel for schedule (dynamic, 2) then switch to (static, 2)

#include <stdio.h>
#include <omp.h>

#define SIZE 6

int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};

    printf("Original array:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Using dynamic scheduling (chunk size 2):\n");
#pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = 3 * a[i] + 2;
        printf("Thread %d processed element %d\n", omp_get_thread_num(), i);
    }

    printf("\nArray after dynamic scheduling:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        a[i] = i + 1;
    }

    printf("Using static scheduling (chunk size 2):\n");
#pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = 3 * a[i] + 2;
        printf("Thread %d processed element %d\n", omp_get_thread_num(), i);
    }

    printf("Array after static scheduling:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
