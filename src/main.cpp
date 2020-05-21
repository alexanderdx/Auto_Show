
#include "Masina.h"
#include "Coupe.h"
#include "HotHatch.h"
#include "Cabrio.h"
#include "Supersport.h"
#include "Expozitie.h"
#include <fstream>

void PrintMenu()
{
    std::cout << "\n------------------ MENIU ------------------------\n";
    std::cout << "1. Creati o expozitie noua.\n";
    std::cout << "2. Introduceti o masina in expozitie.\n";
    std::cout << "3. Afisati expozitia.\n";
    std::cout << "4. Afisati expozitia masinilor supersport.\n";
    std::cout << "5. Achizitionati o masina supersport.\n";
    std::cout << "6. EXIT\n\n";

}

int main()
{
    std::ifstream fin("Masini.txt");

    Expozitie<Masina> expo;
    Expozitie<Supersport> expoSupersport;

    do {
        PrintMenu();
        
        int op;
        std::cin >> op;

        if (op == 1) {
            expo = Expozitie<Masina>();
            expoSupersport = Expozitie<Supersport>();
        }
        else if (op == 2) {
            std::cout << "\nIntroduceti tipul masinii (0 - COUPE | 1 - HOTHATCH | 2 - CABRIO | 3 - SUPERSPORT): ";
            int tip;
            do {
                try {
                    std::cin >> tip;
                    if (tip < 0 || tip > 3)
                        throw InvalidCarType();
                    else break;
                }
                catch (const std::exception& e) {
                    std::cout << e.what();
                    continue;
                }
            } while (true);

            if (tip == 0) {
                Coupe* c = new Coupe;
                std::cin >> *c;
                expo.insert(c);
            }
            else if (tip == 1) {
                HotHatch* h = new HotHatch;
                std::cin >> *h;
                expo.insert(h);
            }
            else if (tip == 2) {
                Cabrio* cb = new Cabrio;
                std::cin >> *cb;
                expo.insert(cb);
            }
            else if (tip == 3) {
                Supersport* s = new Supersport;
                std::cin >> *s;
                expo.insert(s);
                expoSupersport.insert(s);
            }
        }
        else if (op == 3) {
            std::cout << expo;
        }
        else if (op == 4) {
            std::cout << expoSupersport;
        }
        else if (op == 5) {
            int tries = 3;
            int id;
            do {
                std::cout << "\nIntroduceti ID-ul masinii dorite: ";
                std::cin >> id;
                if (!expoSupersport.exists(id))
                    std::cout << "ID-ul introdus nu exista! Incercati din nou...";
                else break;
            } while (--tries);

            expoSupersport -= id;
        }
        else break;
    } while (true);

    return 0;
}
