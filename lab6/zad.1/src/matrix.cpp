#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <lab3/matrix.hpp>

Matrix::Matrix(unsigned int row, unsigned int col)
{
    try
    {
        if(row == 0 || col == 0)
        {
            throw std::invalid_argument("Invalid argument.\n");
        }
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

    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

Matrix::Matrix(unsigned int n)
{
    try
    {
        if(n == 0)
        {
            throw std::invalid_argument("Invalid argument.\n");
        }
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

    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

Matrix::Matrix(std::string filepath)
{
    try
    {   
        std::ifstream file(filepath, std::ios::in);
        if (file.fail()) 
        {
            throw std::runtime_error("File doesn't exist.\n");
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
    catch(const std::runtime_error& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Matrix::set(unsigned int row, unsigned int column, double value)
{
    try
    {
        if(rows() < row || cols() < column)
            throw std::out_of_range("Incorrect row or column number.\n");
        data[row][column] = value;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

double Matrix::get(unsigned int row, unsigned int column) const
{
    try
    {
        if(rows() < row || cols() < column)
            throw std::out_of_range("Incorrect row or column number.\n");
        return data[row][column];
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 0;
    }
    
}

Matrix Matrix::add(Matrix& m2)
{
    try
    {
        if(rowCount != m2.rowCount || colCount != m2.colCount)
        {
            throw std::invalid_argument("Invalid argument.\n");
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

    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
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
    
}

Matrix Matrix::subtract(Matrix& m2)
{
    try
    {
        if(rowCount != m2.rowCount || colCount != m2.colCount)
        {
            throw std::invalid_argument("Invalid argument.\n");
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

    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
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
    
}

Matrix Matrix::multiply(Matrix& m2)
{
    try
    {     
        if(colCount != m2.rowCount)
        {
            throw std::invalid_argument("Invalid argument.\n");
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

    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
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
}

int Matrix::cols() const
{
    return colCount;
}

int Matrix::rows() const
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
    try
    {   
        if(rowCount != m2.rowCount || colCount != m2.colCount)
        {
            throw std::invalid_argument("Nie mozna dodac. Macierze maja rozne wymiary. \n");
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

    catch (const std::invalid_argument& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
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
}

Matrix Matrix::operator-(Matrix& m2)
{
    try
    {
    
        if(rowCount != m2.rowCount || colCount != m2.colCount)
        {
            throw std::invalid_argument("Nie mozna odjac. Macierze maja rozne wymiary. \n");
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

    catch (const std::invalid_argument& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
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
}

Matrix Matrix::operator*(Matrix& m2)
{
    try
    {
    
        if(colCount != m2.rowCount)
        {
            throw std::invalid_argument("Nie mozna pomnozyc. Macierze maja niepoprawne wymiary. \n");
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

    catch (const std::invalid_argument& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
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
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    os << m.rows() << " " << m.cols() << std::endl;
    for(int i = 0; i < m.rowCount; i++)
    {
        for(int j = 0; j < m.colCount; j++)
        {
            os << std::setw(5) << m.get(i, j) <<  " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, const Matrix& m)
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
                return false;
            }
        }
    }

    return true;
}

std::vector<double> Matrix::operator[](unsigned int i)
{
    std::vector<double> wiersz;
    for(int j = 0; j < colCount; j++)
    {
        wiersz.push_back(get(i, j));
    }
    return wiersz;
}