/*
	Jacob Larsen
	Program 2
*/

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

double matrix1[6][5];
double matrix2[6][5];

int main()
{
	cout << "Please input 2 numbers (1-4) to add matrices 1-4\n";
	int sel1 = 0; //first selection
	int sel2 = 0; //second selection
	cin >> sel1;
	cout << "You have selected Matrix " << sel1 << ", please enter another number 1-4\n";
	cin >> sel2;

	ifstream file1;
	ifstream file2;
	string fileName1;
	string fileName2;
	int sizeX1; //size of matrix 1 x
	int sizeY1; //size of matrix 1 y
	int sizeX2; //size of matrix 2 x
	int sizeY2; //size of matrix 2 y
	switch (sel1)
	{
	case 1:
		fileName1 = "jlarsen_mat1.txt";
		sizeX1 = 6;
		sizeY1 = 5;
		break;
	case 2:
		fileName1 = "jlarsen_mat2.txt";
		sizeX1 = 6;
		sizeY1 = 5;
		break;
	case 3:
		fileName1 = "jlarsen_mat3.txt";
		sizeX1 = 2;
		sizeY1 = 4;
		break;
	case 4:
		fileName1 = "jlarsen_mat4.txt";
		sizeX1 = 4;
		sizeY1 = 2;
		break;
	}

	switch (sel2)
	{
	case 1:
		fileName2 = "jlarsen_mat1.txt";
		sizeX2 = 6;
		sizeY2 = 5;
		break;
	case 2:
		fileName2 = "jlarsen_mat2.txt";
		sizeX2 = 6;
		sizeY2 = 5;
		break;
	case 3:
		fileName2 = "jlarsen_mat3.txt";
		sizeX2 = 2;
		sizeY2 = 4;
		break;
	case 4:
		fileName2 = "jlarsen_mat4.txt";
		sizeX2 = 4;
		sizeY2 = 2;
		break;
	}
	if (sizeX1 == sizeX2 && sizeY1 == sizeY2)
	{
		file1.open(fileName1);
		int sizeX = sizeX1;
		int sizeY = sizeY1;
		string outputFileName = "jlarsen_p2_out" + to_string(sel1) + to_string(sel2) + ".txt";
		ofstream outputFile;
		outputFile.open(outputFileName);
		if (file1.is_open())
		{
			cout << "Matrix 1:\n";
			for (int i = 0; i < sizeX; i++)
			{
				for (int j = 0; j < sizeY; j++)
				{
					file1 >> matrix1[i][j];
					cout << matrix1[i][j] << " ";
				}
				cout << "\n";
			}
			file1.close();
		}
		else
		{
			cout << "file not opened :(";
		}

		if (sel1 == sel2)
		{
			cout << "Matrix 2:\n";
			for (int i = 0; i < sizeX; i++)
			{
				for (int j = 0; j < sizeY; j++)
				{
					cout << matrix1[i][j] << " ";
				}
				cout << "\n";
			}

			int outMatrix[6][5];
			cout << "output matrix:\n";
			for (int i = 0; i < sizeX; i++)
			{
				for (int j = 0; j < sizeY; j++)
				{
					outMatrix[i][j] = matrix1[i][j] + matrix1[i][j];
					cout << outMatrix[i][j] << " ";
					outputFile << outMatrix[i][j] << " ";
				}
				cout << "\n";
				outputFile << "\n";
			}
		}
		else
		{
			file2.open(fileName2);
			if (file2.is_open())
			{
				cout << "Matrix 2:\n";
				for (int i = 0; i < sizeX; i++)
				{
					for (int j = 0; j < sizeY; j++)
					{
						file2 >> matrix2[i][j];
						cout << matrix2[i][j] << " ";
					}
					cout << "\n";
				}
				file2.close();
			}
			else
			{
				cout << "file not opened :(";
			}
			int outMatrix[6][5];
			cout << "output matrix:\n";
			for (int i = 0; i < sizeX2; i++)
			{
				for (int j = 0; j < sizeY2; j++)
				{
					outMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
					cout << outMatrix[i][j] << " ";
					outputFile << outMatrix[i][j] << " ";
				}
				cout << "\n";
				outputFile << "\n";
			}
		}
		
	}
	else
	{
		cout << "These matrices are not the same size :(";
		exit;
	}
}