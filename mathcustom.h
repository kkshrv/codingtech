// #include <iostream>

// using namespace std;

// class Vectoror
// {
//     private:
//         int dimension; 
//         double* coordinates;
//         int number;
//     public:
//         static int count;
//         Vectoror(int dim, double* coordinates, int num);
//         ~Vectoror();
//         void status();
//         void multiply(double k);
// };


#include <iostream>
#include <math.h>

class Vector {
	public:
		int dimension;
		double* values;
		Vector(int dim, double* rawValues);
		Vector* operator= (const Vector& other);
		Vector operator+ (Vector& other);
		Vector operator- (Vector& other);
		Vector multiply(double coefficient);
		double operator* (Vector& other);
		bool operator== (Vector& other);
		bool operator!= (Vector& other);
		bool operator< (Vector& other);
		bool operator> (Vector& other);
		bool operator>= (Vector& other);
		bool operator<= (Vector& other);
		int getDimension();
		void print();

};

class Matrix {
	private:
		int ROWS;
		int COLS;
		double** values;
	public:
		Matrix(int rows, int columns, double** values);
		Matrix* operator= (Matrix& other);
		Matrix operator+ (Matrix& other);
		Matrix operator- (Matrix& other);
		Matrix operator* (Matrix& other);
		Matrix multiply(int coefficient);
		Matrix operator* (Vector& Vector);
		void print();
		int getRows();
		int getCols();
};

double** arraytoPointer(int rows, int columns, double inputValues[]);