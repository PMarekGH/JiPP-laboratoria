#include <iostream>

using namespace std;

double licz(double a, double& b)
{
    double temp;
    temp = a * b;
    b += a;
    return temp;
}

int main(int argc, char *argv[])
{
    double a, b, iloczyn;
    cout << "Podaj pierwsza liczbe:" << endl;
    cin >> a;
    cout << "Podaj druga liczbe: " << endl;
    cin >> b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "-----" << endl;
    iloczyn = licz(a, b);
    cout << "iloczyn = " << iloczyn << endl;
    cout << "suma = " << b << endl;

    return 0;
}
