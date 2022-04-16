#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Matrix
{
private:
    int rows, cols;
    double** p;
public:
    void create();
    void full();

    void init(int rows_, int cols_, double** a);

    void read();
    void display();

    void set_rows(int row) { rows = row; }
    void set_cols(int col) { cols = col; }
    double get_elem(int col, int row) { return p[row][col]; }
    void set_elem(int col, int row, double a) { p[row][col] = a; }

    int get_rows() { return rows; }
    int get_cols() { return cols; }

    void set_mat(double** a) { p = a; }
    double** get_mat() { return p; }

    void sum(double a);
    void riz(double a);
    void mult(double a);
    void div(double a);

    friend bool is_equal(Matrix a, Matrix b);
    friend bool not_equal(Matrix a, Matrix b);

    string u_check();

    friend Matrix mat_sum(Matrix a, Matrix b);
    friend Matrix mat_riz(Matrix a, Matrix b);
    friend Matrix mat_mult(Matrix a, Matrix b);
    friend Matrix mat_div(Matrix a, Matrix b);

    friend bool zero(Matrix a);
    friend bool one(Matrix a);
    friend bool diag(Matrix a);
    friend bool uppr_t(Matrix a);
    friend bool down_t(Matrix a);
    friend bool sim(Matrix a);

};

