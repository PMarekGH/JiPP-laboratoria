#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <lab3/matrix.hpp>

#include <lab3/sqlite3.h>


Matrix::Matrix(int row, int col)
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

Matrix::Matrix(int n)
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

void Matrix::set(int row, int column, double value)
{
    data[row][column] = value;
}

double Matrix::get(int row, int column)
{
    return data[row][column];
}

Matrix Matrix::add(Matrix m2)
{
    if(rowCount != m2.rowCount || colCount != m2.colCount)
    {
        std::cout << std::endl << "Nie mozna dodac. Macierze maja rozne wymiary!" << std::endl;
        return 0;
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

Matrix Matrix::subtract(Matrix m2)
{
    if(rowCount != m2.rowCount || colCount != m2.colCount)
    {
        std::cout << std::endl << "Nie mozna odjac. Macierze maja rozne wymiary!" << std::endl;
        return 0;
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

Matrix Matrix::multiply(Matrix m2)
{
    if(colCount != m2.rowCount)
    {
        std::cout << std::endl << "Liczba kolumn pierwszej macierzy nie jest rowna liczbie wierszy drugiej!" << std::endl;
        return 0;
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

void Matrix::storeDB(std::string filename)
{
    sqlite3 *db;          // struktura bazy danych
    int test;             // zwracany status po wykonaniu kazdego polecenia
    char *error;          // komunikat zwrotny w przypadku wystapienia bledu
    std::string dane;          // dane do drugiej kwerendy
    unsigned char *bajty; // zamiana elementow macierzy na postac binarna
    std::stringstream strumien;
    char bajt[3];

     const char *kwerenda_1 =
        "CREATE TABLE IF NOT EXISTS macierze ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "cols INTEGER NOT NULL, "
        "rows INTEGER NOT NULL, "
        "cells BLOB NOT NULL"
        ");";

    const char *kwerenda_2 =
        "INSERT INTO macierze "
        "(cols, rows, cells) "
        "VALUES ";

    test = sqlite3_open(filename.c_str(), &db);

    if (test != SQLITE_OK)
    {
      std::cout << "Nie udalo sie otworzyc bazy danych \"" << filename << "\"!" << std::endl;
      return;
    }

     test = sqlite3_exec(db, kwerenda_1, NULL, NULL, &error);

    if (test != SQLITE_OK)
    {
      sqlite3_close(db);

      std::cout << "Error: " << error << std::endl;

      return;
    }

    strumien << kwerenda_2 << "(" << colCount << ", " << rowCount << ", x'";

    // zamieniamy tablice DOUBLE na strumien bajtow

    for (int i = 0; i < rowCount; i++)
    {
      for (int j = 0; j < colCount; j++)
      {
        bajty = (unsigned char *)&(data[i][j]);

        for (int k = 0; k < sizeof(double); k++)
        {
          sprintf(bajt, "%02X", bajty[k]);
          strumien << bajt;
        }
      }
    }

    strumien << "');";

    std::cout << "Wykonujemy kwerende: " << strumien.str() << std::endl;
    test = sqlite3_exec(db, strumien.str().c_str(), NULL, NULL, &error);

    if (test != SQLITE_OK)
    {
      sqlite3_close(db);

      std::cout << "Blad dodawania rekordu!" << std::endl;
      std::cout << "Error: " << error << std::endl;

      return;
    }

    // zamykamy plik z baza danych
    sqlite3_close(db);



}