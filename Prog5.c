// OpenMP program to transform array elements: a[i] = 3 * a[i] + 2
// Using #pragma omp parallel for with dynamic and static scheduling

#include <stdio.h>
#include <omp.h>

#define SIZE 20

int main() {
    int a[SIZE];
    int i;
    
    // Initialize array
    for (i = 0; i < SIZE; i++) {
        a[i] = i + 1;
    }
    
    printf("Original array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    
    // Transform array using dynamic scheduling (chunk size 2)
    printf("Using dynamic scheduling (chunk size 2):\n");
    #pragma omp parallel for schedule(dynamic, 2)
    for (i = 0; i < SIZE; i++) {
        a[i] = 3 * a[i] + 2;
        printf("Thread %d processed element %d\n", omp_get_thread_num(), i);
    }
    
    printf("\nArray after dynamic scheduling:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    
    // Reset array for static scheduling demonstration
    for (i = 0; i < SIZE; i++) {
        a[i] = i + 1;
    }
    
    // Transform array using static scheduling (chunk size 2)
    printf("Using static scheduling (chunk size 2):\n");
    #pragma omp parallel for schedule(static, 2)
    for (i = 0; i < SIZE; i++) {
        a[i] = 3 * a[i] + 2;
        printf("Thread %d processed element %d\n", omp_get_thread_num(), i);
    }
    
    printf("\nArray after static scheduling:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}
