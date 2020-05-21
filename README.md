# Targ Masini Sport - Tema 3 POO
144 - Dumea Alexandru-Gabriel

## Tema Nr. 5
În luna mai se organizează târgul mașinilor sport, astfel ca pasionatii se pot delecta cu modele din clasa COUPE, HOT-HATCH (modele hatckback de clasa mica și compacta cu motoare performante ce au la bază modele obișnuite), CABRIO(modele decapotabile cu acoperiș metalic sau din material textil) și SUPERSPORT(masini de viteza gen Audi R8, Bugatti Veyron, Lexus LF-A, etc.). O parte din masinile supersport poate să fie vânduta chiar în cadrul expozitiei, dacă se tranzacția se face cu plata pe loc.

Structura de date: ```vector``` sau ```list <pair<masina, preț>>``` (se rețin mașinile vândute și prețul de vanzare, daca masina nu a fost vanduta prețul este -1)

Cerința suplimentară:
- Să se adauge toate campurile relevante pentru modelarea acestei probleme.
- Să se construiască clasa template Expoziție care sa conțină nr total de mașini expuse (incrementat automat) și un vector de obiecte de tipul unei mașini, alocat dinamic. 
- Să se  construiască o specializare pentru tipul SUPERSPORT care sa conțină nr total de masini supersport expuse (decrementat automat la vanzarea unei mașini), nr de mașini vândute (incrementat automat) și doi vectori de pointeri la obiecte de tip mașina supersport, două structuri alocate dinamic, prin care să se gestioneze automobilele din stoc și cele vandute. Sa se supraincarce operatorul -= care sa actualizeze datele din clasa la vanzarea unei mașini.
