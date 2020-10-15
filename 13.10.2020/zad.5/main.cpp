#include <iostream>

/*

 |x1   x2|
 |y1   y2|
 |z1   z2|

 */

struct Macierz
{
    double x1, x2, y1, y2, z1, z2;

    Macierz operator+(const Macierz& mac)
    {
        x1 += mac.x1;
        x2 += mac.x1;
        y1 += mac.x1;
        y2 += mac.x1;
        z1 += mac.x1;
        z2 += mac.x1;
        return *this;
    }
};

void MacierzInit(Macierz* mat)
{
    std::cout << "Podaj dane: " << std::endl;
    std::cin >> mat->x1;
    std::cin >> mat->x2;
    std::cin >> mat->y1;
    std::cin >> mat->y2;
    std::cin >> mat->z1;
    std::cin >> mat->z2;
}

int main()
{
    Macierz mac1, mac2;
    MacierzInit(&mac1);
    MacierzInit(&mac2);
    

    return 0;
}