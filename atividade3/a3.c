#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int rank, size, ierr;
	int left, right;
	int tag = 1;
	char sendmessage[] = "Hello";
	char getmessage[6];
	MPI_Status rstatus;

	ierr = MPI_Init(&argc, &argv);				
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	left  = rank - 1;
	right = rank + 1;
	if(left < 0) left = MPI_PROC_NULL;
	if(right == size) right = MPI_PROC_NULL;

	ierr = MPI_Ssend(sendmessage, 6, MPI_CHAR, 
				right, tag, MPI_COMM_WORLD);

	ierr = MPI_Recv(getmessage, 6, MPI_CHAR, 
				left, tag, MPI_COMM_WORLD, &rstatus);

	if(rank == 0)
		printf("%d: Sent <%s> to %d\n",
				rank, sendmessage, right);
	else if (rank == size - 1)
		printf("%d: Got <%s> from %d\n",
				rank, getmessage, left);
	else
		printf("%d: Sent <%s> to %d and got <%s> from %d\n",
				rank, sendmessage, right, getmessage, left);

	ierr = MPI_Finalize();

	return 0;
}
