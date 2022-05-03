#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int rank, size, ierr;
	int master = 0, tag = 1;
	int circle_count = 0, n_points = 1e+9;
	double pi, erro;
	MPI_Status rstatus;

	srand(time(NULL));

	ierr = MPI_Init(&argc, &argv);				
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	double x, y, tmp;
	double sendn_points, recvn_points, sendcircle_count = 0, recvcircle_count;
	int i;

	if(rank == master) {
		sendn_points = n_points/size;

		for(i = 1; i < size; i++) {
			MPI_Ssend(&sendn_points, 1, MPI_DOUBLE, i, tag, MPI_COMM_WORLD);
			MPI_Recv(&recvcircle_count, 1, MPI_DOUBLE, i, tag, MPI_COMM_WORLD, &rstatus);
			circle_count += recvcircle_count;
		}
		
		for(i = 1; i < sendn_points; i++) {
			x = ((rand() % 200)/100.0) - 1;
			y = ((rand() % 200)/100.0) - 1;
			tmp = x*x + y*y;
			if(tmp <= 1) circle_count++;
		}

		pi = 4.0*circle_count/n_points;
		erro=fabs(M_PI-pi);

		printf("\n Valor obtido de PI: \t%lf", pi);
		printf("\n Valor de PI(math.h): \t%lf", M_PI);
		printf("\n Erro: \t\t\t%lf", erro);
	}
	else {
		MPI_Recv(&recvn_points, 1, MPI_DOUBLE, master, tag, MPI_COMM_WORLD, &rstatus);

		for(i = 1; i < recvn_points; i++) {
			x = ((rand() % 200)/100.0) - 1;
			y = ((rand() % 200)/100.0) - 1;
			tmp = x*x + y*y;
			if(tmp <= 1) sendcircle_count++;
		}

		MPI_Ssend(&sendcircle_count, 1, MPI_DOUBLE, master, tag, MPI_COMM_WORLD);
	}
	
	ierr = MPI_Finalize();
	
	return 0;
}
