#include <iostream>
#include <random>
#include "lab3/matrix.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Matrix m1(4, 5);
    for(int i = 0; i < m1.rows(); i++)
    {
        for(int j = 0; j < m1.cols(); j++)
        {
            m1.set(i, j, rand()%100);
        }
    }
    Matrix m2(5);
    for(int i = 0; i < m2.rows(); i++)
    {
        for(int j = 0; j < m2.cols(); j++)
        {
            m2.set(i, j, rand()%100);
        }
    }
    Matrix m3("../util/Macierz3.txt"); // Macierz 5x5

    std::cout << "Macierz m1: " << std::endl;
    m1.print();
    std::cout << "Macierz m2: " << std::endl;
    m2.print();
    std::cout << "Macierz m3: " << std::endl;
    m3.print();

    m1.set(1, 3, 456);
    std::cout << "Macierz m1 po metodzie set(1,3,456): " << std::endl;
    std::cout << "m1 (1,3) = " << m1.get(1, 3) << std::endl;

    Matrix m4 = m2.add(m3);
    std::cout << "m4 = m2 + m3:";
    m4.print();

    Matrix m5 = m4.subtract(m2);
    std::cout << "m5 = m4 - m2";
    m5.print();

    Matrix m6 = m1.multiply(m2);
    std::cout << "m6 = m1 * m2";
    m6.print();
    std::cout << "Macierz 6: kolumny:  " << m6.cols() <<", wiersze: " << m6.rows() << std::endl;

    m6.store("../util/Macierz6.txt");

    return 0;
}
