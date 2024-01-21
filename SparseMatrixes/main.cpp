#include <iostream>
#include "SparceMatrix.h"
#include <chrono>
using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::nanoseconds;

void isTranspose(SparceMatrix& matrix) {

	//Empty


}


int main()
{
	SparceMatrix matrix;


	matrix.generateMatrix();

	matrix.print_matrix();

	if (matrix.isSparceMatrix())
	{
		cout << "This is a sparce matrix..." << endl << endl;
		cout << "The number of zeros: " << matrix.get_zeroTerms() << endl;
		cout << "The number of nonzero: " << matrix.get_terms() << endl;
		cout << "The capacity of the vector: " << matrix.get_capacity() << endl;
	}
	else {
		cout << "This is not a sparce matrix..." << endl;
		cout << "The number of zeros: " << matrix.get_zeroTerms() << endl;
		cout << "The number of nonzero: " << matrix.get_terms() << endl;
		cout << "The capacity of the vector: " << matrix.get_capacity() << endl;
	}

	cout << "----------------------------------" << endl;

	//Measure performans
	auto t1 = high_resolution_clock::now();
	matrix.Transpose();
	auto t2 = high_resolution_clock::now();

	matrix.PrintTransposeMatrix();

	cout << endl;

	auto nanoint1 = duration_cast<nanoseconds>(t2 - t1);
	cout << nanoint1.count() << "ns" << endl;

	matrix.printMsg();

	return 0;
}