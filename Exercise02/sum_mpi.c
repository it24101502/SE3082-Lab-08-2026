#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rank, size;
    long long local_sum = 0;
    long long global_sum = 0;

    const long long N = 10000000;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long long start = (rank * N) / size + 1;
    long long end = ((rank + 1) * N) / size;

    for(long long i = start; i <= end; i++)
    {
        local_sum += i;
    }

    MPI_Reduce(&local_sum,
               &global_sum,
               1,
               MPI_LONG_LONG,
               MPI_SUM,
               0,
               MPI_COMM_WORLD);

    printf("Process %d calculated local sum = %lld\n",
           rank,
           local_sum);

    if(rank == 0)
    {
        printf("\nFinal Sum from 1 to %lld = %lld\n",
               N,
               global_sum);
    }

    MPI_Finalize();

    return 0;
}