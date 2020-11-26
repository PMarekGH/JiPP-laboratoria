#include <iostream>
#include <random>
#include <lab3/matrix.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    double* ptr;

    Matrix m1(5, 5);
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

    std::cout << "m1 + m2" << std::endl << m1+m2 << std::endl;
    std::cout << "m1-m2" << std::endl << m1-m2 << std::endl;
    std::cout << "m1*m2" << std::endl << m1*m2 << std::endl;
    std::cout << "m3" << std::endl << m3 << std::endl;
    bool wartosc = m1==m2;
    std::cout << "m1==m2" << std:: endl << wartosc << std::endl;
    std::cout << "m3[0]" << std::endl;
    ptr = m3[0]; //TODO: nie dziala
    //TODO: FILE* file <<
    for(int i = 0; i < m1.cols(); i++)
    {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
