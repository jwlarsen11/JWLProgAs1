/*
	Jacob Larsen
	Program 5
*/

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int vector1[2];
int vector2[2];

int main()
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
	string fileName3 = "jlarsen_p5_out" + sel1 + sel2 + ".txt";
	file1.open(fileName1);
	file2.open(fileName2);
	file3.open(fileName3);
	if (file1.is_open())
	{
		if (file2.is_open())
		{
			file1 >> vector1[0];
			file1 >> vector1[1];
			cout << "\nVector 1: \n" << vector1[0] << endl << vector1[1] << endl;
			file2 >> vector2[0];
			file2 >> vector2[1];
			cout << "Vector 2: \n" << vector2[0] << endl << vector2[1] << endl;
			double output = (vector1[0] * vector2[0]) + (vector1[1] * vector2[1]);
			cout << "Output: \n" << output << endl;
			file3 << output << endl;
		}
		else
			cout << "File 2 didn't open :(";
	}
	else
		cout << "File 1 didn't open :(";
}