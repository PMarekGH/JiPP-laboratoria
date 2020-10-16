#include <iostream>
#include <iomanip>

/*

 |x1   y1   z1|
 |x2   y2   z2|

 */

using namespace std;

struct Macierz
{
    double x1, x2, y1, y2, z1, z2;

    Macierz operator+(const Macierz& mac)
    {
        x1 += mac.x1;
        x2 += mac.x2;
        y1 += mac.y1;
        y2 += mac.y2;
        z1 += mac.z1;
        z2 += mac.z2;
        return *this;
    }
};

void macierzInit(Macierz* mat)
{
    cin >> mat->x1;
    cin >> mat->y1;
    cin >> mat->z1;
    cin >> mat->x2;
    cin >> mat->y2;
    cin >> mat->z2;
}

void wyswietlMacierz(Macierz* mat)
{
    cout << "|   " << mat->x1 << "   " << mat->y1 << "   " << mat->z1 << "   |" << endl;
    cout << "|   " << mat->x2 << "   " << mat->y2 << "   " << mat->z2 << "   |" << endl << endl;
}

int main()
{
    Macierz mac1, mac2, mac3;
    cout << "Podaj dane macierzy 1:" << endl;
    macierzInit(&mac1);
    wyswietlMacierz(&mac1);
    cout << "Podaj dane macierzy 2:" << endl;
    macierzInit(&mac2);
    wyswietlMacierz(&mac2);

    mac3 = mac1 + mac2;
    wyswietlMacierz(&mac3);
    

    return 0;
}