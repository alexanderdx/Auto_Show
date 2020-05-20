#pragma once

#include "Masina.h"

class Cabrio : public Masina
{
protected:
	int material_acoperis; // 0 - metalic || 1 - textil

public:
	Cabrio();
	Cabrio(std::string marca, std::string model, std::string culoare, int an, int capacitate_cilindrica,
		int cai_putere, int tip_combustibil, int cutie_viteze, int material_acoperis);
	Cabrio(const Cabrio& other);
	~Cabrio();

	void afisare();

	Cabrio& operator=(const Cabrio& other);
	friend std::istream operator>>(std::istream& in, Cabrio& masina);
	friend std::ostream operator<<(std::istream& out, const Cabrio& masina);
};