
#include "Masina.h"
#include <fstream>

int main()
{
    std::ifstream fin("Masini.txt");

    Masina* masini[2];

    for (int i = 0; i < 2; ++i)
    {   
        masini[i] = new Masina();

        fin >> *masini[i];
    }
    for (int i = 0; i < 2; ++i)
        std::cout << *masini[i];
    return 0;
}
