#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int rank, size, ierr;								/* Inicia rank, quantidade de cores e erro */
	int sendto, recvfrom;								/* Envia para sendto e recebe de recvfrom */
	int ourtag=1;										/* Inicia tag */
	char sendmessage[]="Hello";							/* Mensagem a ser enviada */
	char getmessage[6];									/* Mensagem a ser recebida */
	MPI_Status rstatus;									/* Status da informação de MPI_Recv */

	ierr = MPI_Init(&argc, &argv);						/* Inicia ambiente paralelo MPI */
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);		/* Retorna numero de processo (mpirun -np XX) */
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);		/* Identifica o processo dentro de size */
	
	if(rank == 0) {										/* Se rank == master */
		sendto = 1;										/* Manda para proc 1 */
		ierr = MPI_Ssend(sendmessage, 6, MPI_CHAR,
		 sendto, ourtag, MPI_COMM_WORLD);				/* Manda de forma síncrona sendmessage para sendto (proc 1) */
							
		printf("%d: Sent message <%s>\n",
					rank, sendmessage);					/* Printa */
	} else if (rank == 1) {								/* Se rank == proc 1 */
		recvfrom = 0;									/* Recebe mensagem do master */
		ierr = MPI_Recv(getmessage, 6, MPI_CHAR,
			recvfrom, ourtag, MPI_COMM_WORLD, &rstatus);/* Recebe getmessage de recvfrom (master) */
		printf("%d: Got message <%s>\n",
			rank, getmessage);							/* Printa */
	}

	ierr = MPI_Finalize();								/* Finaliza ambiente paralelo MPI */
	return 0;
}
