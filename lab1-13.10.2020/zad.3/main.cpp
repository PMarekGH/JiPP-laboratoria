#include <iostream>
#include <math.h>

int main(int argc, char *argv[])
{
    double waga;
    double wzrost;
    double BMI;
    std::cout << "Podaj mase ciala [kg]" << std::endl;
    std::cin >> waga;
    if(waga <= 0)
    {
        std::cout << "Waga jest nie prawidlowa";
        return 0;
    }
    std::cout << "Podaj wzrost [m]" << std::endl;
    std::cin >> wzrost;
    if(wzrost <= 0)
    {
        std::cout << "Podaj prawidlowy wzrost";
        return 0;
    }

    BMI = waga / pow(wzrost, 2);
    std::cout << "BMI wynosi " << BMI << std::endl;
    
    if(BMI < 16)
    {
        std::cout << "BMI wskazuje na wyglodzenie";
    }
    else if (BMI >= 16 && BMI < 17)
    {
        std::cout << "BMI wskazuje na wychudzenie";
    }
    else if (BMI >= 17 && BMI < 18.5)
    {
        std::cout << "BMI na niedowage";
    }
    else if (BMI >= 18.5 && BMI < 25)
    {
        std::cout << "BMI wskazuje wartosc prawidlowa";
    }
    else if (BMI >= 25 && BMI < 30)
    {
        std::cout << "BMI wskazuje na nadwage";
    }
    else if (BMI >= 30 && BMI < 35)
    {
        std::cout << "BMI wskazuje na 1 stopien otylosci";
    }
    else if (BMI >= 35 && BMI < 40)
    {
        std::cout << "BMI wskazuje na 2 stopien otylosci";
    }
    else if (BMI >= 40)
    {
        std::cout << "BMI wskazuje na skrajna otylosc";
    }

    return 0;
}