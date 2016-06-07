#include <mpi.h>
#include <iostream>
#include <string.h>

using namespace std;

//Encryption process [caesar]
string caesar_encrypt(char src[100], int key, int dist)
{
    for (int i=0; i < dist; i++)
    {
        if (src[i] >= 'A' && src[i] <= 'Z')
        {
            src[i] = (char)(((src[i] + key - 'A' + 26) % 26) + 'A');
        }
        else if (src[i] >= 'a' && src[i] <= 'z')
        {
            src[i] = (char)(((src[i] + key - 'a' + 26) % 26) + 'a');
        }
    }
    
    return src;
}

/*-------------------------------------ROT0------------------------------------------*/
void rot0(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 0;
	int dist = strlen (plaintext);	

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT1------------------------------------------*/
void rot1(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 1;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT2------------------------------------------*/
void rot2(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 2;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT3------------------------------------------*/
void rot3(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 3;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT4------------------------------------------*/
void rot4(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 4;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT5------------------------------------------*/
void rot5(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 5;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT6------------------------------------------*/
void rot6(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 6;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT7------------------------------------------*/
void rot7(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 7;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT8------------------------------------------*/
void rot8(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 8;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT9------------------------------------------*/
void rot9(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 9;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT10------------------------------------------*/
void rot10(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 10;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT11------------------------------------------*/
void rot11(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 11;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT12------------------------------------------*/
void rot12(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 12;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT13------------------------------------------*/
void rot13(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 13;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT14------------------------------------------*/
void rot14(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 14;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT15------------------------------------------*/
void rot15(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 15;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT16------------------------------------------*/
void rot16(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 16;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT17------------------------------------------*/
void rot17(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 17;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT18------------------------------------------*/
void rot18(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 18;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT19------------------------------------------*/
void rot19(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 19;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT20------------------------------------------*/
void rot20(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 20;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT21------------------------------------------*/
void rot21(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 21;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT22------------------------------------------*/
void rot22(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 22;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT23------------------------------------------*/
void rot23(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 23;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT24------------------------------------------*/
void rot24(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 24;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*-------------------------------------ROT25------------------------------------------*/
void rot25(int *custNum, MPI_Comm communicator,char plaintext[])
{
	int key = 25;
	int dist = strlen (plaintext);

	int destination = 26;
	char taskOutput[50];
	int context = 7;
	cout << "Rot" << key << endl;
	string encrypted = caesar_encrypt(plaintext, key, dist);
	
	strcpy (taskOutput, encrypted.c_str());
	MPI_Send(taskOutput, 50, MPI_CHAR, destination, context, communicator);
}
/*------------------------------------------------------------------------------------*/

typedef void(*TaskType)(int *custNum, MPI_Comm communicator, char plaintext[]);
TaskType taskList[] = {rot0,rot1,rot2,rot3,rot4,rot5,rot6,rot7,rot8,rot9,rot10,rot11,
			rot12,rot13,rot14,rot15,rot16,rot17,rot18,rot19,rot20,rot21,
			rot22,rot23,rot24,rot25};

int main (int argc, char * argv[])
{
	MPI_Init (&argc, &argv);
	
	char ptext[50];
	strcpy(ptext,argv[1]);
	
	int rank;
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);
	int custNum[] = {0} ;
	
	custNum[0] = rank-1;
	
	MPI_Bcast(custNum, 1, MPI_INT, 4, MPI_COMM_WORLD);
	
	switch(rank)
	{
		case 0:	taskList[0](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 1:	taskList[1](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 2:	taskList[2](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 3:	taskList[3](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 4:	taskList[4](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 5:	taskList[5](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 6:	taskList[6](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 7:	taskList[7](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 8:	taskList[8](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 9:	taskList[9](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 10:taskList[10](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 11:taskList[11](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 12:taskList[12](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 13:taskList[13](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 14:taskList[14](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 15:taskList[15](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 16:taskList[16](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 17:taskList[17](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 18:taskList[18](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 19:taskList[19](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 20:taskList[20](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 21:taskList[21](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 22:taskList[22](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 23:taskList[23](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 24:taskList[24](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 25:taskList[25](custNum, MPI_COMM_WORLD,ptext);
			break;

		case 26:int context = 7;
			int totalsource = 26;
			char taskInput[26][50];
			MPI_Status stat;
			for (int source=0; source<totalsource; source++)
			{
				MPI_Recv(taskInput[source], 50, MPI_CHAR, source, context, MPI_COMM_WORLD, &stat);
			}
		
			for (int i=0; i<totalsource; i++)
				cout<<"Rot"<<i<<" [ciphertext]: " << taskInput[i] << endl;
			
			break;
	}

	MPI_Finalize();
	return 0;
}
