#include <mpi.h>
#include <iostream>
#include <string.h>

using namespace std;

void task0(int *custNum, MPI_Comm communicator)
{
	int destination = 3;
	char taskOutput[50];
	int context = 7;
	cout << "Peel and cut onion" << endl;
	strcpy (taskOutput, "Onion rings");
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}

void task1(int *custNum, MPI_Comm communicator)
{
	int destination = 3;
	char taskOutput[50];
	int context = 7;
	cout << "Peel and cut garlic" << endl;
	strcpy (taskOutput, "Minced garlic");
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);	
}

void task2(int *custNum, MPI_Comm communicator)
{
	int destination = 3;
	char taskOutput[50];
	int context = 7;
	cout << "Panaskan minyak" << endl;
	strcpy (taskOutput, "Minyak panas");
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}

typedef void(*TaskType)(int *custNum, MPI_Comm communicator);
TaskType taskList[] = {task0, task1, task2};

int main (int argc, char ** argv)
{
	MPI_Init (&argc, &argv);

	int rank;
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);
	int custNum[] = {0} ;
	
	
	if(rank == 4)
	{
		custNum[0] = rank-1;
	}
	
	MPI_Bcast(custNum, 1, MPI_INT, 4, MPI_COMM_WORLD);
	
	if (rank == 0)
	{
		taskList[0](custNum, MPI_COMM_WORLD);
		
	} else if (rank == 1)
	{
		taskList[1](custNum, MPI_COMM_WORLD);
		
	} else if (rank == 2)
	{
		taskList[2](custNum, MPI_COMM_WORLD);
		
	} else if (rank == 3)
	{
		int context = 7;
		char taskInput[3][50];
		MPI_Status stat;
		for (int source=0; source<=2; source++)
		{
			MPI_Recv(taskInput[source], 50, MPI_CHAR, source, context, MPI_COMM_WORLD, &stat);
		}
		
		for (int i=0; i<3; i++) cout << "Mix: " << taskInput[i] << endl;
	}
	
	MPI_Finalize();
	return 0;
}
