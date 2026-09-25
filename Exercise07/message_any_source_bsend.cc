#include <mpi.h>
#include <iostream>

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int number;

    int buffer_size =
        sizeof(int) + MPI_BSEND_OVERHEAD;

    char *buffer = new char[buffer_size];

    MPI_Buffer_attach(buffer, buffer_size);

    if(rank == 0)
    {
        number = 42;

        MPI_Bsend(
            &number,
            1,
            MPI_INT,
            1,
            0,
            MPI_COMM_WORLD);

        std::cout
            << "Process 0 sent "
            << number
            << std::endl;
    }

    else if(rank == 1)
    {
        MPI_Recv(
            &number,
            1,
            MPI_INT,
            MPI_ANY_SOURCE,
            0,
            MPI_COMM_WORLD,
            MPI_STATUS_IGNORE);

        std::cout
            << "Process 1 received "
            << number
            << std::endl;
    }

    MPI_Buffer_detach(&buffer, &buffer_size);

    delete[] buffer;

    MPI_Finalize();
    return 0;
}