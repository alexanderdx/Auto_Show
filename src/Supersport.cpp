#include "Supersport.h"

Supersport::Supersport() : Masina(), fibra_carbon(0)
{
}

Supersport::Supersport(std::string marca, std::string model, std::string culoare, int an, double capacitate_cilindrica, int cai_putere, COMBUSTIBIL tip_combustibil, CUTIE_VITEZE cutie_viteze, int fibra_carbon)
	: Masina(marca, model, culoare, an, capacitate_cilindrica, cai_putere, tip_combustibil, cutie_viteze),
	fibra_carbon(fibra_carbon)
{
}

Supersport::Supersport(const Supersport& other) : Masina(other)
{
	fibra_carbon = other.fibra_carbon;
}

Supersport::~Supersport()
{
	fibra_carbon = -1;
}

void Supersport::afisare(std::ostream& out) const
{
	Masina::afisare(out);
	out << "Elemente din fibra de carbon: " << ((fibra_carbon == true) ? "Da" : "Nu") << '\n';
	out << "--------------------------------------------------------\n\n";
}

Supersport& Supersport::operator=(const Supersport& other)
{
	Masina::operator=(other);
	fibra_carbon = other.fibra_carbon;

	return *this;
}

std::istream& operator>>(std::istream& in, Supersport& masina)
{
	in >> static_cast<Masina&>(masina);
	std::cout << "Include elemente din fibra de carbon?: (1/0 - Da/Nu): "; in >> masina.fibra_carbon;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Supersport& masina)
{
	masina.afisare(out);
	return out;
}
