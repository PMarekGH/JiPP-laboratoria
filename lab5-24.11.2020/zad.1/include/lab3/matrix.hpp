#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <iostream>
#include <vector>

class Matrix
{
    public:
        Matrix(unsigned int row, unsigned int col);
        Matrix(unsigned int n);
        Matrix(std::string filepath);
        void set(unsigned int row, unsigned int column, double wartosc);
        double get(unsigned int row, unsigned int column) const;
        Matrix add(Matrix& m2);
        Matrix subtract(Matrix& m2);
        Matrix multiply(Matrix& m2);
        int cols() const;
        int rows() const;
        void print();
        void store(std::string filename);

        //lab5
        Matrix operator+(Matrix& m2);
        Matrix operator-(Matrix& m2);
        Matrix operator*(Matrix& m2);
        friend std::ostream& operator<<(std::ostream& os, const Matrix &m);
        friend std::istream& operator>>(std::istream& is, const Matrix &m);
        bool operator==(Matrix& m2);
        std::vector<double> operator[](unsigned int i);

    private:
        double** data = nullptr;
        int rowCount;
        int colCount;

};

#endif