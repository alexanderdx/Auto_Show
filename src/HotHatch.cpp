#include "HotHatch.h"

HotHatch::HotHatch() : Masina(), spoiler(0)
{
}

HotHatch::HotHatch(std::string marca, std::string model, std::string culoare, int an, double capacitate_cilindrica, int cai_putere, COMBUSTIBIL tip_combustibil, CUTIE_VITEZE cutie_viteze, bool spoiler)
	: Masina(marca, model, culoare, an, capacitate_cilindrica, cai_putere, tip_combustibil, cutie_viteze),
	spoiler(spoiler)
{
}

HotHatch::HotHatch(const HotHatch& other) : Masina(other)
{
	spoiler = other.spoiler;
}

HotHatch::~HotHatch()
{
	spoiler = 0;
}

void HotHatch::afisare(std::ostream& out) const
{
	Masina::afisare(out);
	out << "Spoiler: " << ((spoiler == true) ? "Da" : "Nu") << '\n';
	out << "--------------------------------------------------------\n\n";
}

HotHatch& HotHatch::operator=(const HotHatch& other)
{
	Masina::operator=(other);
	spoiler = other.spoiler;

	return *this;
}

std::istream& operator>>(std::istream& in, HotHatch& masina)
{
	in >> static_cast<Masina&>(masina);
	std::cout << "Are Spoiler?: (1/0 - Da/Nu): "; in >> masina.spoiler;
	return in;
}

std::ostream& operator<<(std::ostream& out, const HotHatch& masina)
{
	masina.afisare(out);
	return out;
}
