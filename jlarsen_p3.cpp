/*
	Jacob Larsen
	Program 3
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

	if (sizeY1 == sizeX2)
	{
		file1.open(fileName1);
		string outputFileName = "jlarsen_p3_out" + to_string(sel1) + to_string(sel2) + ".txt";
		ofstream outputFile;
		outputFile.open(outputFileName);
		if (file1.is_open())
		{
			file2.open(fileName2);
			if (file2.is_open())
			{
				cout << "Matrix1:\n";
				for (int i = 0; i < sizeX1; i++)
				{
					for (int j = 0; j < sizeY1; j++)
					{
						file1 >> matrix1[i][j];
						cout << matrix1[i][j] << " ";
					}
					cout << "\n";
				}
				file1.close();

				cout << "Matrix2:\n";
				for (int i = 0; i < sizeX2; i++)
				{
					for (int j = 0; j < sizeY2; j++)
					{
						file2 >> matrix2[i][j];
						cout << matrix2[i][j] << " ";
					}
					cout << "\n";
				}
				file2.close();

				int sizeX = sizeX1;
				int sizeY = sizeY2;
				int sizeZ = sizeY1;

				double outMatrix[4][4];

				cout << "output matrix:\n";
				for (int i = 0; i < sizeX; i++)
				{
					for (int j = 0; j < sizeY; j++)
					{
						for (int k = 0; k < sizeZ; k++)
						{
							outMatrix[i][j] += ((double)matrix1[i][k] * (double)matrix2[k][j]);
							cout << outMatrix[i][j] << " ";
							outputFile << outMatrix[i][j] << " ";
						}
					}
					cout << "\n";
					outputFile << "\n";
				}
			}
			else
			{
				cout << "file not opened :(";
			}
		}
		else
		{
			cout << "file not opened :(";
		}
	}
	else
	{
		cout << "These matrices cannot be multiplied (in this order) :(";
		exit;
	}
}