#include "Masina.h"

int Masina::countMasini = 0;

Masina::Masina() : marca(""), model(""), culoare(""), an(1970), capacitate_cilindrica(0.0), cai_putere(0), tip_combustibil(COMBUSTIBIL::None), cutie_viteze(CUTIE_VITEZE::Null)
{
	id = ++countMasini;
}

Masina::Masina(std::string marca, std::string model, std::string culoare, int an, double capacitate_cilindrica, int cai_putere, COMBUSTIBIL tip_combustibil, CUTIE_VITEZE cutie_viteze)
	: marca(marca), model(model), culoare(culoare), an(an), capacitate_cilindrica(capacitate_cilindrica), cai_putere(cai_putere), tip_combustibil(tip_combustibil), cutie_viteze(cutie_viteze)
{
	id = ++countMasini;
}

Masina::Masina(const Masina& other)
{
	 marca = other.marca;
	 model = other.model;
	 culoare = other.culoare;

	an = other.an;
	capacitate_cilindrica = other.capacitate_cilindrica;
	cai_putere = other.cai_putere;
	tip_combustibil = other.tip_combustibil;
	cutie_viteze = other.cutie_viteze;

	countMasini++;
}

Masina::~Masina()
{
	marca = "";
	model = "";
	culoare = "";

	an = 0;
	capacitate_cilindrica = 0;
	cai_putere = 0;
	tip_combustibil = COMBUSTIBIL::None;
	cutie_viteze = CUTIE_VITEZE::Null;

	countMasini--;
}

void Masina::afisare(std::ostream& out) const
{
	out << "\n\n------------------ MASINA NR. " << id << " ------------------------\n";
	out << "Marca: " << marca << '\n';
	out << "Model: " << model << '\n';
	out << "Culoare: " << culoare << '\n';
	out << "An: " << an << '\n';
	out << "Capacitate Cilindrica: " << std::fixed << std::setprecision(1) << capacitate_cilindrica << '\n';
	out << "Cai Putere: " << cai_putere<< '\n';
	out << "Tip Combustibil: " << Combustibil[tip_combustibil] << '\n';
	out << "Cutie de Viteze: " << Cutie[cutie_viteze] << '\n';
	out << "--------------------------------------------------------\n\n";
}

Masina& Masina::operator=(const Masina& other)
{
	marca = other.marca;
	model = other.model;
	culoare = other.culoare;

	an = other.an;
	capacitate_cilindrica = other.capacitate_cilindrica;
	cai_putere = other.cai_putere;
	tip_combustibil = other.tip_combustibil;
	cutie_viteze = other.cutie_viteze;

	return *this;
}

std::istream& operator>>(std::istream& in, Masina& masina)
{
	std::cout << "\n\n------------ INTRODUCERE MASINA NOUA -------------\n";
	std::cout << "Marca: "; in >> masina.marca;
	std::cout << "Model: "; in >> masina.model;
	std::cout << "Culoare: "; in >> masina.culoare;
	std::cout << "An: "; in >> masina.an;
	std::cout << "Capacitate Cilindrica: "; in >> masina.capacitate_cilindrica;
	std::cout << "Cai Putere: "; in >> masina.cai_putere;

	int c;
	while (true) {
		try {
			std::cout << "Tip Combustibil\n(0 - Benzina | 1 - Motorina | 2 - Hibrid | 3 - Electric): "; in >> c;
			if (c < 0 || c > 3)
				throw InvalidCombustibil();
			else break;
		}
		catch (const InvalidCombustibil& e) {
			std::cout << e.what();
			continue;
		}
	}
	masina.tip_combustibil = static_cast<COMBUSTIBIL>(c);

	while (true) {
		try {
			std::cout << "Cutie de Viteze:\n(0 - Manuala | 1 - Convertizor | 2 - Secventiala | 3 - DSG | 4 - CVT): "; in >> c;
			if (c < 0 || c > 4)
				throw InvalidCutieViteze();
			else break;
		}
		catch (const std::exception& e) {
			std::cout << e.what();
			continue;
		}
	}
	
	masina.cutie_viteze = static_cast<CUTIE_VITEZE>(c);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Masina& masina)
{
	masina.afisare(out);
	return out;
}
