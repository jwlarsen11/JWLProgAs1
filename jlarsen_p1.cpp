/*
	Jacob Larsen
	Program 1
*/

#include <iostream>
#include <fstream>

using namespace std;

#define Jacob 5
#define Larsen 6

void matrix1();
void matrix2();
void matrix3();
void matrix4();

int main()
{
	matrix1();
	cout << "\n";
	matrix2();
	cout << "\n";
	matrix3();
	cout << "\n";
	matrix4();
}

void matrix1()
{
	int index = 1;
	int mat1[Larsen][Jacob];

	cout << "Matrix1\nJacob = 5\nLarsen = 6\n";
	ofstream myfile;
	myfile.open("jlarsen_mat1.txt");
	for (int row = 0; row < Larsen; row++)
	{
		for (int col = 0; col < Jacob; col++)
		{
			mat1[row][col] = index;
			cout << mat1[row][col] << " ";
			myfile << mat1[row][col] << " ";
			index += 1;
		}
		cout << "\n";
		myfile << "\n";
	}
	myfile.close();
}

void matrix2()
{
	int index = 2;
	int mat1[Larsen][Jacob];

	cout << "Matrix2\nJacob = 5\nLarsen = 6\n";
	ofstream myfile;
	myfile.open("jlarsen_mat2.txt");

	for (int col = 0; col < Jacob; col++)
	{
		for (int row = 0; row < Larsen; row++)
		{
			mat1[row][col] = index;
			index += 3;
		}
	}

	for (int x = 0; x < Larsen; x++)
	{
		for (int y = 0; y < Jacob; y++)
		{
			cout << mat1[x][y] << " ";
			myfile << mat1[x][y] << " ";
		}
		cout << "\n";
		myfile << "\n";
	}

	myfile.close();
}

void matrix3()
{
	int index = 10;
	int mat1[2][4];

	cout << "Matrix3\n";
	ofstream myfile;
	myfile.open("jlarsen_mat3.txt");
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			mat1[row][col] = index;
			cout << mat1[row][col] << " ";
			myfile << mat1[row][col] << " ";
			index -= 2;
		}
		cout << "\n";
		myfile << "\n";
	}
	myfile.close();
}

void matrix4()
{
	double index = -6;
	double mat1[4][2];

	cout << "Matrix4\n";
	ofstream myfile;
	myfile.open("jlarsen_mat4.txt");

	for (int col = 0; col < 2; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			mat1[row][col] = index;
			index += 1.5;
		}
	}

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			cout << mat1[x][y] << " ";
			myfile << mat1[x][y] << " ";
		}
		cout << "\n";
		myfile << "\n";
	}

	myfile.close();
}