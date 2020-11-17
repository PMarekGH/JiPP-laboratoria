#include <iostream>

using namespace std;

void zamien(int* a, int* b)
{
    if(*a > *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main(int argc, char *argv[])
{
    int a, b;
    cout << "Podaj pierwsza liczbe:" << endl;
    cin >> a;
    cout << "Podaj druga liczbe: " << endl;
    cin >> b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "-----" << endl;
    zamien(&a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
