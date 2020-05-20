#pragma once

#include "Masina.h"

class HotHatch : public Masina
{
protected:
	bool spoiler;

public:
	HotHatch();
	HotHatch(std::string marca, std::string model, std::string culoare, int an, int capacitate_cilindrica,
		int cai_putere, int tip_combustibil, int cutie_viteze, bool spoiler = false);
	HotHatch(const HotHatch& other);
	~HotHatch();

	void afisare();

	HotHatch& operator=(const HotHatch& other);
	friend std::istream operator>>(std::istream& in, HotHatch& masina);
	friend std::ostream operator<<(std::istream& out, const HotHatch& masina);
};

