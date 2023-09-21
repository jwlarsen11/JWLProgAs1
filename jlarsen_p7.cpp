/*
	Jacob Larsen
	Program 7
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace std;
using namespace Eigen;

void dotProduct();
void transpose();

//must include these because vectors from files breaks the library :(
//(it works once then throws unresolvable error)
//(trust me I literally searched for 3 hours -_-)
int vector1[2];
int vector2[2];

int main()
{
	dotProduct();
	transpose();
}

void dotProduct()
{
	cout << "Please input 2 letters (r,s,u,v,& w) to take the dot product of\n";
	string sel1; //first selection
	string sel2; //second selection
	cin >> sel1;
	cout << "You have selected vector " << sel1 << ", please enter another letter\n";
	cin >> sel2;
	cout << "You have selected vector " << sel2 << endl;

	ifstream file1;
	ifstream file2;
	ofstream file3;
	string fileName1 = sel1 + ".txt";
	string fileName2 = sel2 + ".txt";
	file1.open(fileName1);
	file2.open(fileName2);
	if (file1.is_open())
	{
		if (file2.is_open())
		{
			
			int v11;
			int v12;
			file1 >> v11;
			file1 >> v12;
			Vector2d v1(v11, v12);
			cout << "Vector 1:\n";
			cout << v1;

			int v21;
			int v22;
			file2 >> v21;
			file2 >> v22;
			Vector2d v2(v21, v22);
			cout << "\nVector 2:\n";
			cout << v2;

			double output = v1.dot(v2);

			string fileName3 = "jlarsen_p7_outD" + sel1 + sel2 + ".txt";
			file3.open(fileName3);

			cout << "\nOutput:\n";
			cout << output << endl;
			file3 << output;

			file1.close();
			file2.close();
			file3.close();
		}
		else
			cout << "File 2 not open";
	}
	else
		cout << "File 2 not open";
}

void transpose()
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
	string outputFileName = "jlarsen_p7_outT" + to_string(sel1) + ".txt";
	ofstream outputFile;
	outputFile.open(outputFileName);

	MatrixXd m1 = MatrixXd::Zero(sizeX, sizeY);
	MatrixXd m2 = MatrixXd::Zero(sizeY, sizeX);

	if (file1.is_open())
	{
		for (int row = 0; row < sizeX; row++)
			for (int col = 0; col < sizeY; col++)
			{
				float cell;
				file1 >> cell;
				m1(row, col) = cell;
			}
		file1.close();
		m2 = m1.transpose();
		cout << "Starting Matrix:\n";
		cout << m1;
		cout << "\nTransposed Matrix:\n";
		cout << m2;
	}
	else
		cout << "file didn't open :(";
}