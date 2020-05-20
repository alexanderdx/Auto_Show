#pragma once

#include "Masina.h"

class Coupe : public Masina
{
protected:
	bool hasRearSeats;

public:
	Coupe();
	Coupe(std::string marca, std::string model, std::string culoare, int an, int capacitate_cilindrica,
		int cai_putere, int tip_combustibil, int cutie_viteze, bool hasRearSeats = true);
	Coupe(const Coupe& other);
	~Coupe();

	void afisare();

	Coupe& operator=(const Coupe& other);
	friend std::istream operator>>(std::istream& in, Coupe& masina);
	friend std::ostream operator<<(std::istream& out, const Coupe& masina);
};