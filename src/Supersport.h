#pragma once

#include "Masina.h"

class Supersport : public Masina
{
protected:
	bool fibra_carbon;

public:
	Supersport();
	Supersport(std::string marca, std::string model, std::string culoare, int an, int capacitate_cilindrica,
		int cai_putere, int tip_combustibil, int cutie_viteze, bool fibra_carbon);
	Supersport(const Supersport& other);
	~Supersport();

	void afisare();

	Supersport& operator=(const Supersport& other);
	friend std::istream operator>>(std::istream& in, Supersport& masina);
	friend std::ostream operator<<(std::istream& out, const Supersport& masina);
};