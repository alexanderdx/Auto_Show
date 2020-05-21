#include "Coupe.h"

Coupe::Coupe() : Masina(), hasRearSeats(0)
{
	
}

Coupe::Coupe(std::string marca, std::string model, std::string culoare, int an, double capacitate_cilindrica, int cai_putere, COMBUSTIBIL tip_combustibil, CUTIE_VITEZE cutie_viteze, bool hasRearSeats)
	: Masina(marca, model, culoare, an, capacitate_cilindrica, cai_putere, tip_combustibil, cutie_viteze),
	hasRearSeats(hasRearSeats)
{

}

Coupe::Coupe(const Coupe& other) : Masina(other)
{
	hasRearSeats = other.hasRearSeats;
}

Coupe::~Coupe()
{
	hasRearSeats = 0;
}

void Coupe::afisare(std::ostream& out) const
{
	Masina::afisare(out);
	out << "Scaune spate: " << ((hasRearSeats == true) ? "Da" : "Nu") << '\n';
	out << "--------------------------------------------------------\n\n";
}

Coupe& Coupe::operator=(const Coupe& other)
{
	Masina::operator=(other);
	hasRearSeats = other.hasRearSeats;

	return *this;
}

std::istream& operator>>(std::istream& in, Coupe& masina)
{
	in >> static_cast<Masina&>(masina);
	std::cout << "Are Scaune Spate?: (1/0 - Da/Nu): "; in >> masina.hasRearSeats;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Coupe& masina)
{
	masina.afisare(out);
	return out;
}
