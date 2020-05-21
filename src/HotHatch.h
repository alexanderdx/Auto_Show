#pragma once

#include "Masina.h"

class HotHatch : public Masina
{
protected:
	bool spoiler;

public:
	HotHatch();
	HotHatch(std::string marca, std::string model, std::string culoare, int an, double capacitate_cilindrica, 
		int cai_putere, COMBUSTIBIL tip_combustibil, CUTIE_VITEZE cutie_viteze, bool spoiler);
	HotHatch(const HotHatch& other);
	~HotHatch();

	void afisare(std::ostream& out) const;

	HotHatch& operator=(const HotHatch& other);
	friend std::istream& operator>>(std::istream& in, HotHatch& masina);
	friend std::ostream& operator<<(std::ostream& out, const HotHatch& masina);
};

