#include <iostream>
#include <string>
#include <iomanip>
#include "Matrix.h"

using namespace std;

void create(int** a, int col, int row, int l, int h) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = l + rand() % (h - l + 1);
}


int main() {
	Matrix a;
	Matrix b;
	Matrix c;

	a.read();
	a.display();
	b.read();
	b.display();
	c = mat_mult(a, b);
	cout << "multyply:\n";
	c.display();

	a.full();
	a.display();
	b.full();
	b.display();
	c = mat_div(a, b);
	cout << "divide:\n";
	c.display();


	a.full();
	a.display();
	b.full();
	b.display();
	c = mat_sum(a, b);
	cout << "sum:\n";
	c.display();

	a.full();
	a.display();
	b.full();
	b.display();
	c = mat_riz(a, b);
	cout << "riz:\n";
	c.display();

	a.sum(4);
	cout << "sum + 4:\n";
	a.display();

	a.riz(4);
	cout << "riz - 4:\n";
	a.display();

	a.mult(4);
	cout << "mult 4:\n";
	a.display();

	a.div(4);
	cout << "div 4:\n";
	a.display();

	cout << "a is equal b = " << is_equal(a, b) << endl;
	cout << a.u_check();
}
