//============================================================================
// Name        : Matrix.cpp
// Author      : barsik.marsik.11@gmail.com
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Matrix {
public:
	Matrix() {
		Rows = 0;
		Cols = 0;
	}
	Matrix(int new_rows, int new_cols) {
		Reset (new_rows, new_cols);
	}
	void Reset(int new_rows, int new_cols) {
		if (new_rows < 0) {
			throw out_of_range("The number of rows is less than zero");
		}
		if (new_cols <0) {
			throw out_of_range("The number of cols is less than zero");
		}
		if (new_rows == 0 || new_cols == 0) {
			new_rows = new_cols = 0;
		}
		Rows = new_rows;
		Cols = new_cols;
		Elements.assign(new_rows, vector<int>(new_cols));
	}
	int At(int row, int col) const {
		return Elements.at(row).at(col);
	}
	int& At(int row, int col) {
		return Elements.at(row).at(col);
	}
	int GetNumRows() const {
		return Rows;
	}
	int GetNumColumns() const {
		return Cols;
	}
private:
	int Rows;
	int Cols;
	vector<vector<int>> Elements;
};
istream& operator>>(istream& stream, Matrix& matrix) {
	int rows, cols;
	stream >> rows >> cols;
	matrix.Reset(rows, cols);
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			stream >> matrix.At(i,j);
		}
	}
	return stream;
}
ostream& operator<<(ostream& stream, const Matrix& matrix) {
	int rows = matrix.GetNumRows();
	int cols = matrix.GetNumColumns();
	stream << rows << " " << cols << endl;
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			if(j > 0) {
				stream << " ";
			}
			stream << matrix.At(i,j);
		}
		stream << endl;
	}
	return stream;
}
bool operator==(const Matrix& matrix_A, const Matrix& matrix_B) {
	if(matrix_A.GetNumRows() != matrix_B.GetNumRows()) {
		return false;
	}
	if(matrix_A.GetNumColumns() != matrix_B.GetNumColumns()) {
		return false;
	}
	for(int i=0; i<matrix_A.GetNumRows(); i++) {
		for(int j=0; j<matrix_A.GetNumColumns(); j++) {
			if(matrix_A.At(i,j) != matrix_B.At(i,j)) {
				return false;
			}
		}
	}
	return true;
}
Matrix operator+(const Matrix& matrix_A, const Matrix& matrix_B) {
	if(matrix_A.GetNumRows() != matrix_B.GetNumRows()) {
		throw invalid_argument("Mismatched number of rows");
	}
	if(matrix_A.GetNumColumns() != matrix_B.GetNumColumns()) {
		throw invalid_argument("Mismatched number of columns");
	}
	Matrix matrix_C(matrix_A.GetNumRows(), matrix_A.GetNumColumns());
	for(int i=0; i<matrix_A.GetNumRows(); i++) {
		for(int j=0; j<matrix_A.GetNumColumns(); j++) {
			matrix_C.At(i,j) = matrix_A.At(i,j) + matrix_B.At(i,j);
		}
	}
	return matrix_C;
}
int main() {
	Matrix one;
	Matrix two;
	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}
