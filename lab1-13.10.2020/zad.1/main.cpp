#include <iostream>

int main(int argc, char *argv[])
{
    int* args = (int*)malloc((argc-1) * sizeof(int));
    if(argc == 1)
    {
        std::cout << "Argumenty nie zostały podane" << std::endl;
        return 0;
    }

    for(int i = 1; i < argc; i++)
    {
        args[i-1] = atoi(argv[i]);
    }

    for(int i = 0; i < argc - 2; i++)
    {
        for(int j = 0; j < argc - i - 2; j++)
        {
            if(args[j]>args[j+1])
            {
                int temp=args[j];
                args[j]=args[j+1];
                args[j+1]=temp;
            }
        }
    }
    
    std::cout << "out: ";
    for(int i = 0; i < argc-1; i++)
    {
        std::cout << args[i] << " ";
    }
    return 0;
}
