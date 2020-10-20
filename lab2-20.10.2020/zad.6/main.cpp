#include <iostream>
#include <algorithm>

    namespace std
    {
        template < typename T >
        void swap( T * a, T * b ) // Przeciążenie funkcji swap, aby mogła brać jako argumenty wskaźniki.
        {
            T temp;
            temp = *a;
            *a = *b;
            *b = temp;
        }
    }

using namespace std;

int main(int argc, char *argv[])
{
    double a, b;
    cout << "Podaj pierwsza liczbe:" << endl;
    cin >> a;
    cout << "Podaj druga liczbe: " << endl;
    cin >> b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "-----" << endl;
    swap(&a, &b); // Funkcja jest generyczna, argumenty mogą być dowolnych typów.
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
