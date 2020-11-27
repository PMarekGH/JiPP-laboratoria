#include <iostream>
#include <random>
#include <lab3/matrix.hpp>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    bool wartosc;
    std::vector<double> wiersz;

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
    wartosc = m1==m2;
    std::cout << "m1==m2" << std:: endl << wartosc << std::endl;
    wartosc = m1==m1;
    std::cout << "m1==m1" << std:: endl << wartosc << std::endl;
    std::cout << "m3[0]" << std::endl;
    wiersz = m3[0];
    for(int i = 0; i < m3.cols(); i++)
    {
        std::cout << wiersz[i] << " ";
    }
    std::cout << std::endl;

    std::ofstream file("../util/test.txt", std::ios::out);
    file << m1;
    file.close();

    Matrix m4("../util/test.txt");
    std::cout << "m4: " << std::endl;
    std::cout << m4 << std::endl;

    return 0;
}
