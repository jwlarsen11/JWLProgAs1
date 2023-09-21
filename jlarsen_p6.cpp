/*
	Jacob Larsen
	Program 6
*/

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

double matrix1[6][5];
double matrix2[6][6];

int main()
{
	cout << "Please input a number (1-4) to transpose\n";
	int sel1 = 0; //first selection
	cin >> sel1;

	ifstream file1;
	string fileName1;
	int sizeX; 
	int sizeY; 
	switch (sel1)
	{
	case 1:
		fileName1 = "jlarsen_mat1.txt";
		sizeX = 6;
		sizeY = 5;
		break;
	case 2:
		fileName1 = "jlarsen_mat2.txt";
		sizeX = 6;
		sizeY = 5;
		break;
	case 3:
		fileName1 = "jlarsen_mat3.txt";
		sizeX = 2;
		sizeY = 4;
		break;
	case 4:
		fileName1 = "jlarsen_mat4.txt";
		sizeX = 4;
		sizeY = 2;
		break;
	}

	file1.open(fileName1);
	string outputFileName = "jlarsen_p6_mat" + to_string(sel1) + ".txt";
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
		cout << "\nOutput Matrix:\n";
		for (int i = 0; i < sizeY; i++)
		{
			for (int j = 0; j < sizeX; j++)
			{
				matrix2[i][j] = matrix1[j][i];
				cout << matrix2[i][j] << " ";
				outputFile << matrix2[i][j] << " ";
			}
			cout << "\n";
			outputFile << "\n";
		}
		outputFile.close();
	}
	else
	{
		cout << "file not opened :(";
	}
}