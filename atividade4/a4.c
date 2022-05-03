#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int rank, size, ierr;
	int master = 0, left, right;
	int tag = 1;
	char sendmessage[] = "Hello";
	char getmessage[6];
	MPI_Status rstatus;

	ierr = MPI_Init(&argc, &argv);				
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	left  = rank - 1;
	right = rank + 1;
	if(rank == master) left = size - 1;
	if(rank == size-1) right = master;

	ierr = MPI_Send(sendmessage, 6, MPI_CHAR, right, tag, MPI_COMM_WORLD);
	ierr = MPI_Recv(getmessage, 6, MPI_CHAR, left, tag, MPI_COMM_WORLD, &rstatus);

	printf("%d: Sent <%s> to %d and got <%s> from %d\n", rank, sendmessage, right, getmessage, left);

	ierr = MPI_Finalize();
	
	return 0;
}
