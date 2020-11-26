#ifndef MATRIX_H
#define MATRIX_H

#include <string>

class Matrix
{
    public:
        Matrix(int row, int col);
        Matrix(int n);
        Matrix(std::string filepath);
        void set(int row, int column, double wartosc);
        double get(int row, int column);
        Matrix add(Matrix m2);
        Matrix subtract(Matrix m2);
        Matrix multiply(Matrix m2);
        int cols();
        int rows();
        void print();
        void store(std::string filename);
    private:
        double** data = nullptr;
        int rowCount;
        int colCount;

};

#endif