#include <iostream>

/*

    Program sprawdza, czy podane liczby są skojarzone.
    Przykladowe liczby skojarzone: 140, 195.
*/

int main()
{
    int x, y;
    int suma1 = 0, suma2 = 0;
    std::cout << "Podaj 2 liczby:" << std::endl;
    while(true)
    {
        std::cin >> x;
        std::cin >> y;
        if(x <= 1 || y <= 1)
        {
            std::cout << "Liczby musza byc wieksze od 1" << std::endl;
        }
        else
        {
            break;
        }
    }

    for(int i = 1; i < x; i++)
    {
        if(x % i == 0) suma1 += i;
    }

    for(int i = 1; i < y; i++)
    {
        if(y % i == 0) suma2 += i;
    }
    if(suma1 == y + 1 && suma2 == x + 1)
    {
        std::cout << "Podane liczby sa skojarzone" << std::endl;
    }
    else
    {
        std::cout << "Podane liczby nie sa skojarzone" << std::endl;
    }
    

    return 0;
}