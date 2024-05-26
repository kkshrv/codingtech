#include <typeinfo>
#include "mathcustom.h"
#include <iostream>

using namespace std;


int main()
{
	Vector first = Vector(3, new double[3] {1, 2, 3});
	Vector second = Vector(3, new double[3] {3, 2, 1});
	(first + second).print();
	(first - second).print();
	cout << first * second << endl << endl;
	(first.multiply(5)).print();
	double values[9] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
	double** inputValues = arraytoPointer(3, 3, values);
	Matrix m1(3, 3, inputValues);
	Matrix m2(3, 3, inputValues);
	(m1+m2).print();
	(m1-m2).print();
	(m1*m2).print();
	(m1.multiply(3)).print();
	(m1 * first).print();
	double values1[3] = {1, 2, 3};
	double** inputValues1 = arraytoPointer(3, 1, values1);
	Matrix m3(3, 1, inputValues1);
	(m3 * second).print();
	m1 = m3;
	m1.print();
	first = second;
	first.print();
}