#pragma once

#include "Masina.h"

class Coupe : public Masina
{
protected:
	bool hasRearSeats;

public:
	Coupe();
	Coupe(std::string marca, std::string model, std::string culoare, int an, double capacitate_cilindrica,
		int cai_putere, COMBUSTIBIL tip_combustibil, CUTIE_VITEZE cutie_viteze, bool hasRearSeats = true);
	Coupe(const Coupe& other);
	~Coupe();

	void afisare(std::ostream& out) const;

	Coupe& operator=(const Coupe& other);
	friend std::istream& operator>>(std::istream& in, Coupe& masina);
	friend std::ostream& operator<<(std::ostream& out, const Coupe& masina);
};