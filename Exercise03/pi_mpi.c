#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int rank, size;
    long long tosses = 10000000; // 10 million
    long long local_tosses;
    long long local_hits = 0;
    long long total_hits = 0;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    local_tosses = tosses / size;

    unsigned int seed = time(NULL) + rank;

    for(long long i = 0; i < local_tosses; i++)
    {
        double x = (double)rand_r(&seed) / RAND_MAX;
        double y = (double)rand_r(&seed) / RAND_MAX;

        if((x * x + y * y) <= 1.0)
        {
            local_hits++;
        }
    }

    MPI_Reduce(
        &local_hits,
        &total_hits,
        1,
        MPI_LONG_LONG,
        MPI_SUM,
        0,
        MPI_COMM_WORLD
    );

    if(rank == 0)
    {
        double pi = 4.0 * total_hits / tosses;

        printf("Total Tosses = %lld\n", tosses);
        printf("Points Inside Circle = %lld\n", total_hits);
        printf("Estimated PI = %.10f\n", pi);
    }

    MPI_Finalize();
    return 0;
}