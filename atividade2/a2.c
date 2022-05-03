#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int rank, size, ierr;							/* Inicia rank, quantidade de cores e erro */
	int left, right;								/* Inicia processo a esquerda e a direita */
	int tag = 1;									/* Inicia tag */
	double msgsent, msgrcvd;						/* Mensagem a ser enviada e a ser recebida */
	MPI_Status rstatus;								/* Status da informação de MPI_Recv */

	ierr = MPI_Init(&argc, &argv);					/* Inicia ambiente paralelo MPI */
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);	/* Retorna numero de processo (mpirun -np XX) */
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);	/* Identifica o processo dentro de size */

	left = rank-1;									/* Esquerda da posição rank */
	if(left < 0) left = MPI_PROC_NULL;				/* Se rank for master não há ninguém a esquerda */
	right = rank+1;									/* Direita da posição rank */
	if(right == size) right = MPI_PROC_NULL;		/* Se rank for o último proc não há ninguém a direita */

	msgsent = rank*rank;							/* Mensagem a ser enviada */
	msgrcvd = -999;									/* Mensagem a ser recebida */

	ierr = MPI_Ssend(&msgsent, 1, MPI_DOUBLE, 
			right, tag, MPI_COMM_WORLD);			/* Envia de forma síncrona msgsent para right */
	ierr = MPI_Recv(&msgrcvd, 1, MPI_DOUBLE, 
			left, tag, MPI_COMM_WORLD, &rstatus);	/* Recebe msgrcvd de left e checa status */

	printf("%d: Sent %lf and got %lf\n",			/* Printa */
		 rank, msgsent, msgrcvd);

	ierr = MPI_Finalize();							/* Finaliza ambiente paralelo MPI */
	return 0;										
}
