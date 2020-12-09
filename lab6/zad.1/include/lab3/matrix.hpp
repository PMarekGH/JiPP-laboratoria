#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <iostream>
#include <vector>

class Matrix
{
    public:
        Matrix(unsigned int row, unsigned int col) noexcept(false);
        Matrix(unsigned int n) noexcept(false);
        Matrix(std::string filepath) noexcept(false);
        void set(unsigned int row, unsigned int column, double wartosc) noexcept(false);
        double get(unsigned int row, unsigned int column) const noexcept(false);
        Matrix add(Matrix& m2) noexcept(false);
        Matrix subtract(Matrix& m2) noexcept(false);
        Matrix multiply(Matrix& m2) noexcept(false);
        int cols() const;
        int rows() const;
        void print();
        void store(std::string filename);

        //lab5
        Matrix operator+(Matrix& m2) noexcept(false);
        Matrix operator-(Matrix& m2) noexcept(false);
        Matrix operator*(Matrix& m2) noexcept(false);
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