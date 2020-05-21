#pragma once

#include "Masina.h"

class Cabrio : public Masina
{
protected:
	int material_acoperis; // 0 - metalic || 1 - textil

public:
	Cabrio();
	Cabrio(std::string marca, std::string model, std::string culoare, int an, double capacitate_cilindrica, 
		int cai_putere, COMBUSTIBIL tip_combustibil, CUTIE_VITEZE cutie_viteze, int material_acoperis);
	Cabrio(const Cabrio& other);
	~Cabrio();

	void afisare(std::ostream& out) const;

	Cabrio& operator=(const Cabrio& other);
	friend std::istream& operator>>(std::istream& in, Cabrio& masina);
	friend std::ostream& operator<<(std::ostream& out, const Cabrio& masina);
};