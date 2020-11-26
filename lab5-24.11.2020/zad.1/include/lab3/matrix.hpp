#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <iostream>

class Matrix
{
    public:
        Matrix(unsigned int row, unsigned int col);
        Matrix(unsigned int n);
        Matrix(std::string filepath);
        void set(unsigned int row, unsigned int column, double wartosc);
        double get(unsigned int row, unsigned int column);
        Matrix add(Matrix& m2);
        Matrix subtract(Matrix& m2);
        Matrix multiply(Matrix& m2);
        int cols();
        int rows();
        void print();
        void store(std::string filename);

        //lab5
        Matrix operator+(Matrix& m2);
        Matrix operator-(Matrix& m2);
        Matrix operator*(Matrix& m2);
        friend std::ostream& operator<<(std::ostream& os, const Matrix &m);
        friend std::istream& operator>>(std::istream& is, const Matrix &m);
        bool operator==(Matrix& m2);
        double* operator[](unsigned int i);

    private:
        double** data = nullptr;
        int rowCount;
        int colCount;

};

#endif