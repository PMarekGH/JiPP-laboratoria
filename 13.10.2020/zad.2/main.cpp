#include <iostream>
#include <string>

bool jestPalindromem(std::string napis);

int main(int argc, char *argv[])
{
    std::string napis;
    int length;

    if(argc == 1)
    {
        std::cout << "Nie podano argumentu!" << std::endl;
        return 0;
    }

    if(jestPalindromem(argv[1]))
    {
        std::cout << "Napis jest palindromem";
    }
    else
    {
        std::cout << "Napis nie jest palindromem";
    }
    

    return 0;
}

bool jestPalindromem(std::string napis)
{
    if(napis.length() % 2 == 0)
        {
            for(int i = 0; i < napis.length() / 2; i++)
            {
                if(napis[i] != napis[napis.length() - i - 1])
                {
                    return 0; // Zwraca 0 gdy napis jest palindromem
                }
                return 1;     // Zwraca 1 gdy napis jest palindromem
            }
        }
    else
        {
            for(int i = 0; i < napis.length() / 2; i++)
            {
                if(napis[i] != napis[napis.length() - i - 1])
                {
                    return 0; 
                }
                return 1;
            }
        }
        return 0;
}
