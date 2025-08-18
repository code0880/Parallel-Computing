// Write open mp pgm which launches a parallel region and it has each thread.
// Print it's id & team size.

#include <stdio.h>
#include <omp.h>

int main() {
    omp_set_num_threads(4);
    
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int team_size = omp_get_num_threads();
        #pragma omp critical
        printf(" %d out of %d threads. \n", thread_id, team_size);
    }
    
    return 0;
}
