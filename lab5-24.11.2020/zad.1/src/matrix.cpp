#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <lab3/matrix.hpp>

Matrix::Matrix(unsigned int row, unsigned int col)
{
    rowCount = row;
    colCount = col;
    Matrix::data = (double **)malloc(row * sizeof(double));
    for(int i = 0; i < row; i++)
    {
        Matrix::data[i] = (double*)malloc(col * sizeof(double));
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(unsigned int n)
{
    rowCount = n;
    colCount = n;
    Matrix::data = (double **)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++)
    {
        Matrix::data[i] = (double*)malloc(n * sizeof(double));
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(std::string filepath)
{
    std::ifstream file(filepath, std::ios::in);
    if (file.fail()) 
    {
        std::cout <<"Blad przy otwieraniu pliku!" << std::endl;
        exit(EXIT_FAILURE);
    }
    file >> rowCount;
    file >> colCount;
    Matrix::data = (double **)malloc(rowCount * sizeof(double));
    for(int i = 0; i < rowCount; i++)
    {
        Matrix::data[i] = (double*)malloc(colCount * sizeof(double));
    }

    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < colCount; j++)
        {
            file >> data[i][j];
        }
    }
    file.close();
}

void Matrix::set(unsigned int row, unsigned int column, double value)
{
    data[row][column] = value;
}

double Matrix::get(unsigned int row, unsigned int column)
{
    return data[row][column];
}

Matrix Matrix::add(Matrix& m2)
{
    if(rowCount != m2.rowCount || colCount != m2.colCount)
    {
        std::cout << std::endl << "Nie mozna dodac. Macierze maja rozne wymiary!" << std::endl;
        Matrix m3(rowCount, colCount);
        for(int i = 0; i < rowCount; i++)
        {
            for(int j = 0; j < colCount; j++)
            {
                m3.set(i, j, -1);
            }
        }
        return m3;
    }

    Matrix m3(rowCount, colCount);
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < colCount; j++)
        {
            m3.data[i][j] = data[i][j] + m2.data[i][j];
        }
    }

    return m3;
}

Matrix Matrix::subtract(Matrix& m2)
{
    if(rowCount != m2.rowCount || colCount != m2.colCount)
    {
        std::cout << std::endl << "Nie mozna odjac. Macierze maja rozne wymiary!" << std::endl;
        Matrix m3(rowCount, colCount);
        for(int i = 0; i < rowCount; i++)
        {
            for(int j = 0; j < colCount; j++)
            {
                m3.set(i, j, -1);
            }
        }
        return m3;
    }

    Matrix m3(rowCount, colCount);
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < colCount; j++)
        {
            m3.data[i][j] = data[i][j] - m2.data[i][j];
        }
    }
    return m3;
}

Matrix Matrix::multiply(Matrix& m2)
{
    if(colCount != m2.rowCount)
    {
        std::cout << std::endl << "Liczba kolumn pierwszej macierzy nie jest rowna liczbie wierszy drugiej!" << std::endl;
        Matrix m3(rowCount, colCount);
        for(int i = 0; i < rowCount; i++)
        {
            for(int j = 0; j < colCount; j++)
            {
                m3.set(i, j, -1);
            }
        }
        return m3;
    }

    Matrix m3(rowCount, m2.colCount);
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < m2.colCount; j++)
        {
            for(int k = 0; k < colCount; k++)
            {
                m3.data[i][j] += data[i][k] * m2.data[k][j];
            }
        }
    }
    return m3;
}

int Matrix::cols()
{
    return colCount;
}

int Matrix::rows()
{
    return rowCount;
}

void Matrix::print()
{
    std::cout << std::endl;
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < colCount; j++)
        {
            std::cout << std::setw(5) << data[i][j] <<  " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::store(std::string filename)
{  
    std::ofstream file(filename, std::ios::out);
    file << rowCount << " " << colCount << std::endl;
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < colCount; j++)
        {
            file << data[i][j];
            file << " ";
        }
        file << std::endl;
    }

    file.close();
}

Matrix Matrix::operator+(Matrix& m2)
{
    if(rowCount != m2.rowCount || colCount != m2.colCount)
    {
        std::cout << std::endl << "Nie mozna dodac. Macierze maja rozne wymiary!" << std::endl;
        Matrix m3(rowCount, colCount);
        for(int i = 0; i < rowCount; i++)
        {
            for(int j = 0; j < colCount; j++)
            {
                m3.set(i, j, -1);
            }
        }
        return m3;
    }

    Matrix m3(rowCount, colCount);
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < colCount; j++)
        {
            m3.data[i][j] = data[i][j] + m2.data[i][j];
        }
    }

    return m3;
}

Matrix Matrix::operator-(Matrix& m2)
{
    if(rowCount != m2.rowCount || colCount != m2.colCount)
    {
        std::cout << std::endl << "Nie mozna odjac. Macierze maja rozne wymiary!" << std::endl;
        Matrix m3(rowCount, colCount);
        for(int i = 0; i < rowCount; i++)
        {
            for(int j = 0; j < colCount; j++)
            {
                m3.set(i, j, -1);
            }
        }
        return m3;
    }

    Matrix m3(rowCount, colCount);
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < colCount; j++)
        {
            m3.data[i][j] = data[i][j] - m2.data[i][j];
        }
    }
    return m3;
}

Matrix Matrix::operator*(Matrix& m2)
{
    if(colCount != m2.rowCount)
    {
        std::cout << std::endl << "Liczba kolumn pierwszej macierzy nie jest rowna liczbie wierszy drugiej!" << std::endl;
        Matrix m3(rowCount, colCount);
        for(int i = 0; i < rowCount; i++)
        {
            for(int j = 0; j < colCount; j++)
            {
                m3.set(i, j, -1);
            }
        }
        return m3;
    }

    Matrix m3(rowCount, m2.colCount);
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < m2.colCount; j++)
        {
            for(int k = 0; k < colCount; k++)
            {
                m3.data[i][j] += data[i][k] * m2.data[k][j];
            }
        }
    }
    return m3;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    for(int i = 0; i < m.rowCount; i++)
    {
        for(int j = 0; j < m.colCount; j++)
        {
            os << std::setw(5) << m.data[i][j] <<  " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, const Matrix& m) //fix
{
    for(int i = 0; i < m.rowCount; i++)
    {
        std::cout << "Podaj elementy wiersza " << i+1 << " z " << m.rowCount << std::endl;
        for(int j = 0; j < m.colCount; j++)
        {
            std::cout << "Kolumna " << i+1 << " z " << m.colCount << std::endl;
            is >> m.data[i][j];
        }
    }
    return is;
}

bool Matrix::operator==(Matrix& m2)
{
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < colCount; j++)
        {
            if(data[i][j] != m2.data[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}

double* Matrix::operator[](unsigned int i)
{
    double* ptr = (double *)malloc(sizeof(double) * colCount);
    for(int j = 0; j < colCount; j++)
    {
        ptr[j] = get(i, j);
        ptr++;
    }
    return ptr;
}