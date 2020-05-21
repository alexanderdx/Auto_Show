#pragma once

#include "Masina.h"

class Supersport : public Masina
{
protected:
	bool fibra_carbon;

public:
	Supersport();
	Supersport(std::string marca, std::string model, std::string culoare, int an, double capacitate_cilindrica, 
		int cai_putere, COMBUSTIBIL tip_combustibil, CUTIE_VITEZE cutie_viteze, int fibra_carbon);
	Supersport(const Supersport& other);
	~Supersport();

	void afisare(std::ostream& out) const;

	Supersport& operator=(const Supersport& other);
	friend std::istream& operator>>(std::istream& in, Supersport& masina);
	friend std::ostream& operator<<(std::ostream& out, const Supersport& masina);
};