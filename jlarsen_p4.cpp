/*
	Jacob Larsen
	Program 4
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace std;

#define MAXBUFSIZE  ((int) 1e6)
MatrixXd readMatrix(const char* filename);

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
	int sizeX1 = 0;
	int sizeY1 = 0;
	int sizeX2 = 0;
	int sizeY2 = 0;

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

    cout << "Matrix 1:\n";

    MatrixXd m1 = MatrixXd::Zero(sizeX1, sizeY1);
	file1.open(fileName1);
    if (file1.is_open())
    {
        for (int row = 0; row < sizeX1; row++)
            for (int col = 0; col < sizeY1; col++)
            {
				float cell;
                file1 >> cell;
                m1(row, col) = cell;
            }
        file1.close();
    }
	else
	{
		cout << "file no open :(";
	}
    cout << "Matrix1 = " << endl << m1 << endl;

	MatrixXd m2 = MatrixXd::Zero(sizeX2, sizeY2);
	file2.open(fileName2);
	if (file2.is_open())
	{
		for (int row = 0; row < sizeX2; row++)
			for (int col = 0; col < sizeY2; col++)
			{
				float cell;
				file2 >> cell;
				m2(row, col) = cell;
			}
		file2.close();
	}
	else
	{
		cout << "file no open :(";
	}
	cout << "Matrix2 = " << endl << m2 << endl;

	if (X.x() == Y.x() && X.y() == Y.y())
	{
		string outputFileName = "jlarsen_p4_out" + to_string(sel1) + to_string(sel2) + "A.txt";
		ofstream outputFile;
		outputFile.open(outputFileName);
		cout << "Output Matrix Addition = \n" << m1 + m2 << endl;
		outputFile << X + Y << endl;
		outputFile.close();
	}
	else
	{
		cout << "These matrices are not able to be added";
	}

	
	if (X.y() != Y.x())
	{
		cout << "Matrices are not able to be multiplied";
	}
	else
	{
		string outputFileName = "jlarsen_p4_out" + to_string(sel1) + to_string(sel2) + "M.txt";
		ofstream outputFile;
		outputFile.open(outputFileName);
		cout << "Output Matrix Multiplication = \n" << X * Y << endl;
		outputFile << X * Y << endl;
		outputFile.close();
	}
}

