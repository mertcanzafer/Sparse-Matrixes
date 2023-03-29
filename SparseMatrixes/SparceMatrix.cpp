#include "SparceMatrix.h"

bool SparceMatrix::isSparceMatrix()
{
	//Zero Counter var : to count zeros in this matrix
	int zeroCounter{};

	//Non Zero Counter var: to count non zero numbers in the matrix
	int NonZeroCounter{};


	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] == 0)
				zeroCounter++;
			else NonZeroCounter++;
		}
	}

	terms = NonZeroCounter;
	zeroTerms = zeroCounter;
	if (zeroCounter > NonZeroCounter) return true;

	else {
		return false;
	}

}

void SparceMatrix::generateMatrix()
{
	srand(static_cast <unsigned int> (time(0)));

	double zero_prob = 0.65;
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++) {

			if (rand() / (double)RAND_MAX < zero_prob) {
				vec[i][j] = 0;
			}
			else {
				vec[i][j] = rand() % 100;
			}

		}
	}

	capacity = vec.capacity();

}

SparceMatrix::SparceMatrix()
{
	rows = 0;
	cols = 0;
	capacity = 0;
	cout << "Enter rows and cols for the matrix: ";
	cin >> rows >> cols;
	try {
		set_rows(rows);
		set_cols(cols);
		if (rows * cols < 0) throw - 1;
		vec.resize(rows, vector<int>(cols));
		vecTs.resize(cols, vector<int>(rows));

	}
	catch (int& expt) {
		cout << "Sizes are invalid!!!!!" << endl;
		exit(0);
	}


}

void SparceMatrix::Transpose()
{

	vector<vector<int>> Triplet;
	Triplet.resize(terms + 1, vector<int>(3));
	//Pushing information to Triplet vector from original matrix

	Triplet[0][0] = rows;
	Triplet[0][1] = cols;
	Triplet[0][2] = terms;

	int k{ 1 };

	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] != 0)
			{
				Triplet[k][0] = i;
				Triplet[k][1] = j;
				Triplet[k][2] = vec[i][j];

				k++;
			}
		}

	}

	/*Sorting the Triplet using sort()*/

	sort(Triplet);

	//Transpose operation


	for (size_t i = 0; i < terms + 1; i++)
	{
		int swap = Triplet[i][0];
		Triplet[i][0] = Triplet[i][1];
		Triplet[i][1] = swap;

	}


	generateTranspose(Triplet);

}

void SparceMatrix::PrintTransposeMatrix()
{

	cout << "Transpose: " << endl;

	for (int i = 0; i < vecTs.size(); i++)
	{
		for (int j = 0; j < vecTs[i].size(); j++) {

			cout << vecTs[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;


}

bool SparceMatrix::checkIf_it_is_Transpose()
{
	return false;
}

void SparceMatrix::sort(vector<vector<int>>& Triplet)
{

	int* TempLoc = new int;

	*TempLoc = Triplet[0][1];

	Triplet[0][1] = -1;

	for (size_t i = 1; i < terms + 1; i++)
	{
		int key = Triplet[i][1];
		int key2 = Triplet[i][0];
		int key3 = Triplet[i][2];
		size_t j = i - 1;

		while (j >= 0 && key < Triplet[j][1])
		{
			Triplet[j + 1][1] = Triplet[j][1];
			Triplet[j + 1][0] = Triplet[j][0];
			Triplet[j + 1][2] = Triplet[j][2];
			j--;
		}
		Triplet[j + 1][1] = key;
		Triplet[j + 1][0] = key2;
		Triplet[j + 1][2] = key3;
	}

	Triplet[0][1] = *TempLoc;

	delete TempLoc;
}

void SparceMatrix::generateTranspose(vector<vector<int>>& Triplet)
{
	for (size_t i = 1; i < terms + 1; i++)
	{
		vecTs[Triplet[i][0]][Triplet[i][1]] = Triplet[i][2];
	}

}
