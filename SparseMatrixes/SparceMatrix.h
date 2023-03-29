#pragma once
#include <iostream>
#include<cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

class SparceMatrix
{
private:

	vector <vector<int>>vec;
	int rows;
	int cols;
	int terms;
	int capacity;
	int zeroTerms;

	void set_rows(int rows) { this->rows = rows; }
	void set_cols(int cols) { this->cols = cols; }

	/*Transpose of vector vec*/

	vector <vector<int>>vecTs;

	void generateTranspose(vector<vector<int>>& Triplet);

public:


	bool isSparceMatrix();


	void generateMatrix();

	SparceMatrix();

	void print_matrix()
	{
		cout << "Array: " << endl;

		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec[i].size(); j++) {

				cout << vec[i][j] << " ";

			}
			cout << endl;
		}
		cout << endl;
	}

	int get_terms() { return terms; }
	int get_zeroTerms() { return zeroTerms; }
	int get_capacity() { return capacity; }

	/*-------------------------------------------*/

	void Transpose();

	void PrintTransposeMatrix();

	bool checkIf_it_is_Transpose();

	void sort(vector<vector<int>>& Triplet);


};