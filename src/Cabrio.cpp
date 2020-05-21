#include "Cabrio.h"

Cabrio::Cabrio() : Masina(), material_acoperis(-1)
{
}

Cabrio::Cabrio(std::string marca, std::string model, std::string culoare, int an, double capacitate_cilindrica, int cai_putere, COMBUSTIBIL tip_combustibil, CUTIE_VITEZE cutie_viteze, int material_acoperis)
	: Masina(marca, model, culoare, an, capacitate_cilindrica, cai_putere, tip_combustibil, cutie_viteze),
	material_acoperis(material_acoperis)
{
}

Cabrio::Cabrio(const Cabrio& other) : Masina(other)
{
	material_acoperis = other.material_acoperis;
}

Cabrio::~Cabrio()
{
	material_acoperis = -1;
}

void Cabrio::afisare(std::ostream& out) const
{
	Masina::afisare(out);
	out << "Material Acoperis: " << ((material_acoperis == 0) ? "Metalic" : "Textil") << '\n';
	out << "--------------------------------------------------------\n\n";
}

Cabrio& Cabrio::operator=(const Cabrio& other)
{
	Masina::operator=(other);
	material_acoperis = other.material_acoperis;

	return *this;
}

std::istream& operator>>(std::istream& in, Cabrio& masina)
{
	in >> static_cast<Masina&>(masina);
	std::cout << "Material Acoperis: (0 - Metalic | 1 - Textil): "; in >> masina.material_acoperis;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Cabrio& masina)
{
	masina.afisare(out);
	return out;
}
