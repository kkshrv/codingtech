#include "mathcustom.h"

Vector::Vector(int dim, double* rawValues)
{
	this->dimension = dim;
	this->values = rawValues;
}

bool checkV(Vector* first, Vector& second) {
	return first->getDimension() == second.getDimension();
}

Vector* Vector::operator=(const Vector& other)
{
	this->dimension = other.dimension;
	this->values = other.values;
	return this;
}

Vector Vector::operator+(Vector& other)
{
	if (checkV(this, other)) {
		Vector temp = Vector(this->dimension, new double[this->dimension]);
		for (int i = 0; i < this->dimension; i++)
			temp.values[i] = this->values[i] + other.values[i];
		return temp;
	}
	throw "Invalid dimension of second Vector";
}

Vector Vector::operator- (Vector& other)
{
	if (this == nullptr) {
		Vector temp = Vector(other.dimension, new double[other.dimension]);
		for (int i = 0; i < other.dimension; i++)
			temp.values[i] = 0 - other.values[i];
		return temp;
	}
	if (checkV(this, other)) {
		Vector temp = Vector(this->dimension, new double[this->dimension]);
		for (int i = 0; i < this->dimension; i++)
			temp.values[i] = this->values[i] - other.values[i];
		return temp;
	}
	throw "Invalid dimension of second Vector";
}

Vector Vector::multiply(double coefficient)
{
	Vector temp = Vector(dimension, values);
	for (int i = 0; i < dimension; i++)
		temp.values[i] *= coefficient;
	return temp;
}

double Vector::operator* (Vector& other)
{
	if (checkV(this, other)) {
		double temp = 0;
		for (int i = 0; i < this->dimension; i++)
			temp += this->values[i] * other.values[i];
		return temp;
	}
	throw "Invalid dimension of second Vector";
}

bool Vector::operator== (Vector& other)
{
	if (checkV(this, other)) {
		for (int i = 0; i < this->dimension; i++)
			if (this->values[i] != other.values[i])
				return false;
		return true;
	}
	throw "Invalid dimension of second Vector";
}

bool Vector::operator!= (Vector& other)
{
	if (checkV(this, other)) {
		for (int i = 0; i < this->dimension; i++)
			if (this->values[i] != other.values[i])
				return true;
		return false;
	}
	throw "Invalid dimension of second Vector";
}

bool Vector::operator< (Vector& other)
{
	int length1 = 0; int length2 = 0;
	if (checkV(this, other)) {
		for (int i = 0; i < this->dimension; i++){
			length1 += this -> values[i]*values[i];
			length2 += other.values[i]*other.values[i];
		}
		if (length1 < length2)
			return true;
		return false;
	}
	throw "Invalid dimension of second Vector";
}

bool Vector::operator> (Vector& other)
{
	int length1 = 0; int length2 = 0;
	if (checkV(this, other)) {
		for (int i = 0; i < this->dimension; i++){
			length1 += this -> values[i]*values[i];
			length2 += other.values[i]*other.values[i];
		}
		if (length1 > length2)
			return true;
		return false;
	}
	throw "Invalid dimension of second Vector";
}

bool Vector::operator>= (Vector& other)
{
	int length1 = 0; int length2 = 0;
	if (checkV(this, other)) {
		for (int i = 0; i < this->dimension; i++){
			length1 += this -> values[i]*values[i];
			length2 += other.values[i]*other.values[i];
		}
		if (length1 >= length2)
			return true;
		return false;
	}
	throw "Invalid dimension of second Vector";
}

bool Vector::operator<= (Vector& other)
{
	int length1 = 0; int length2 = 0;
	if (checkV(this, other)) {
		for (int i = 0; i < this->dimension; i++){
			length1 += this -> values[i]*values[i];
			length2 += other.values[i]*other.values[i];
		}
		if (length1 <= length2)
			return true;
		return false;
	}
	throw "Invalid dimension of second Vector";
}

int Vector::getDimension()
{
	return this->dimension;
}

void Vector::print()
{
	for (int i = 0; i < this->dimension; i++) {
		std::cout << this->values[i] << "\t";
	}
	std::cout << std::endl << std::endl;
}

void Matrix::print()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			std::cout << values[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Matrix::Matrix(int rows, int columns, double** values)
{
	this->ROWS = rows;
	this->COLS = columns;
	this->values = new double*[ROWS];
        for (int i = 0; i < ROWS; i++) 
		{
            this->values[i] = new double[COLS];
            for (int j = 0; j < COLS; j++)
                this->values[i][j] = values[i][j];
		}
}

bool checkM(Matrix* first, Matrix& second)
{
	return (first->getRows() == second.getRows()) && (first->getCols() == second.getCols());
}

Matrix* Matrix::operator=(Matrix& other)
{	
	this->values = other.values;
	this->ROWS = other.ROWS;
	this->COLS = other.COLS;
	return this;
}

Matrix Matrix::operator+(Matrix& other)
{
	if (checkM(this, other)) {
		double** temp = new double*[ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			temp[i] = new double[COLS];
			for (int j = 0; j < COLS; j++)
				temp[i][j] = this->values[i][j] + other.values[i][j];
		}
		return Matrix(ROWS, COLS, temp);
	}
	throw "Invalid dimension of the second Matrix";
}

Matrix Matrix::operator- (Matrix& other)
{
	if (this == nullptr) {
		double** temp = new double*[ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			temp[i] = new double[COLS];
			for (int j = 0; j < COLS; j++)
				temp[i][j] = 0 - other.values[i][j];
		}
		return Matrix(ROWS, COLS, temp);
	}
	if (checkM(this, other)) {
		double** temp = new double*[ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			temp[i] = new double[COLS];
			for (int j = 0; j < COLS; j++)
				temp[i][j] = this->values[i][j] - other.values[i][j];
		}
		return Matrix(ROWS, COLS, temp);
	}
	throw "Invalid dimension of the second Matrix";
}

Matrix Matrix::operator* (Matrix& other)
{
	if (this->COLS == other.ROWS)
	{
		double** temp = new double*[ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			temp[i] = new double[other.COLS];
			for (int j = 0; j < other.COLS; j++)
			{
				temp[i][j] = 0;
				for (int k = 0; k < COLS; k++)
					temp[i][j] += this->values[i][k] * other.values[k][j];
			}
		}
		return Matrix(ROWS, other.COLS, temp);
	}
	throw "Invalid dimensions for multiplication";
}

Matrix Matrix::multiply(int coefficient)
{
	double** temp = new double*[ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		temp[i] = new double[COLS];
		for (int j = 0; j < COLS; j++)
			temp[i][j] = this->values[i][j] * coefficient;
	}
	return Matrix(ROWS, COLS, temp);
}

Matrix Matrix::operator* (Vector& vector)
{
	if (COLS == vector.getDimension()) // если вектор - вектор-столбец
	{
		double** temp = new double*[ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			temp[i] = new double[1];
			temp[i][0] = 0;
			for (int k = 0; k < COLS; k++)
			{
				temp[i][0] += this->values[i][k] * vector.values[k]; // что если values - private?
			}
		}
		return Matrix(ROWS, 1, temp);
	}
	if (ROWS == vector.getDimension()) // если матрица - вектор-столбец
	{
		double** temp = new double*[ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			temp[i] = new double[vector.getDimension()];
			for (int k = 0; k < vector.getDimension(); k++)
			{
				temp[i][k] = this->values[i][0] * vector.values[k];
			}
		}
		return Matrix(ROWS, vector.getDimension(), temp);
	}
	throw "Invalid dimensions of the objects";
}

int Matrix::getRows()
{
	return this->ROWS;
}

int Matrix::getCols()
{
	return this->COLS;
}

double** arraytoPointer(int rows, int columns, double inputValues[])
{
	double** values = new double*[rows];
	int k = 0;
		for (int i = 0; i < rows; i++)
		{
			values[i] = new double[columns];
			for (int j = 0; j < columns; j++)
			{
				values[i][j] = inputValues[k];
				k++;
			}
		}
	return values;
}
