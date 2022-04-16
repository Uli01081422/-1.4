#include "Matrix.h"
void Matrix::create() {
	this->p = new double* [rows];
	for (int i = 0; i < rows; i++)
		p[i] = new double[cols];

}

void Matrix::full()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			p[i][j] = -9 + rand() % (10 - (-9) + 1);
}

void Matrix::init(int rows_, int cols_, double** a)
{
	rows = rows_;
	cols = cols_;
	p = a;
}



void Matrix::read()
{
	cout << "row = "; cin >> rows;
	cout << "cols = "; cin >> cols;
	create();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> p[i][j];
		}
	}
}

void Matrix::display()
{
	for (int i = 0; i < rows; i++) {
		cout << "|";
		for (int j = 0; j < cols; j++) {
			cout << setw(4) << p[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;

}

void Matrix::sum(double a)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			p[i][j] += a;
		}
	}
}

void Matrix::riz(double a)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			p[i][j] -= a;
		}
	}
}

void Matrix::mult(double a)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			p[i][j] *= a;
		}
	}
}

void Matrix::div(double a)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			p[i][j] /= a;
		}
	}
}

string Matrix::u_check()
{
	bool is;
	if (rows == cols) {
		is == true;
		return "square";
	}
	if (zero(*this)) {
		return "zero";
	}
	if (one(*this)) {
		return "one";
	}
	if (diag(*this)) {
		return "diag";
	}
	if (uppr_t(*this)) {
		return "uppr_t";
	}
	if (down_t(*this)) {
		return "down_t";
	}
	if (sim(*this)) {
		return "sim";
	}
	return "none";


}

bool is_equal(Matrix a, Matrix b)
{
	if (!(a.cols == b.cols && a.rows == b.rows)) {
		return 0;
	}
	else {
		for (int i = 0; i < a.rows; i++) {
			for (int j = 0; j < a.cols; j++) {
				if (!(a.p[i][j] == b.p[i][j])) {
					return 0;
				}
			}
		}
	}
	return 1;
}

bool not_equal(Matrix a, Matrix b) {
	return !(is_equal(a, b));
}

Matrix mat_sum(Matrix a, Matrix b)
{
	Matrix rez;
	if (!(a.cols == b.cols && a.rows == b.rows)) {
		cout << "Sum is imposible" << endl;
	}
	else {
		rez.cols = a.cols;
		rez.rows = a.rows;
		rez.create();
		for (int i = 0; i < a.rows; i++) {
			for (int j = 0; j < a.cols; j++) {
				rez.p[i][j] = a.p[i][j] + b.p[i][j];
			}
		}
	}
	return rez;
}

Matrix mat_riz(Matrix a, Matrix b)
{
	Matrix rez;
	if (!(a.cols == b.cols && a.rows == b.rows)) {
		cout << "Ris is imposible" << endl;
	}
	else {
		rez.cols = a.cols;
		rez.rows = a.rows;
		rez.create();
		for (int i = 0; i < a.rows; i++) {
			for (int j = 0; j < a.cols; j++) {
				rez.p[i][j] = a.p[i][j] - b.p[i][j];
			}
		}
	}
	return rez;
}

Matrix mat_mult(Matrix a, Matrix b)
{
	Matrix rez;
	double d;
	if (!(a.cols == b.rows)) {
		cout << "Mult is imposible" << endl;
	}
	else {
		rez.rows = a.rows;
		rez.cols = b.cols;
		rez.create();
		for (int i = 0; i < rez.rows; i++) {
			for (int j = 0; j < rez.cols; j++) {
				rez.p[i][j] = 0;

				for (int k = 0; k < rez.rows; k++) {
					rez.p[i][j] += a.p[i][k] * b.p[k][j];
				}

			}
		}
	}
	return rez;
}

Matrix mat_div(Matrix a, Matrix b)
{
	Matrix rez;
	double d;
	if (!(a.cols == b.rows)) {
		cout << "Div is imposible" << endl;
	}
	else {
		rez.rows = a.rows;
		rez.cols = b.cols;
		rez.create();
		for (int i = 0; i < rez.rows; i++) {
			for (int j = 0; j < rez.cols; j++) {
				rez.p[i][j] = 0;

				for (int k = 0; k < rez.rows; k++) {
					rez.p[i][j] += a.p[i][k] / b.p[k][j];
				}

			}
		}
	}
	return rez;
}

bool zero(Matrix a)
{
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			if (a.p[i][j] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

bool one(Matrix a)
{
	for (int i = 0; i < a.rows; i++) {
		if (a.p[i][i] != 1) {
			return 0;
		}
	}
	return 1;
}

bool diag(Matrix a)
{
	for (int i = 0; i < a.rows; i++) {
		if (a.p[i][i] == 0) {
			return 0;
		}
	}
	return 1;
}

bool uppr_t(Matrix a)
{
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			if (a.p[i][j] != 0) {
				return 0;
			}
		}
		i++;
	}
	return 1;
}

bool down_t(Matrix a)
{

	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			if (a.p[j][i] != 0) {
				return 0;
			}
		}
		i++;
	}
	return 1;
}

bool sim(Matrix a)
{
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			if (a.p[j][i] != a.p[i][j]) {
				return 0;
			}
		}
		i++;
	}
	return 1;
}
