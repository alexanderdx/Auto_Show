#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

#include "MyExceptions.h"

enum COMBUSTIBIL {
	Benzina,
	Motorina,
	Hibrid,
	Electric,
	None
};

enum CUTIE_VITEZE {
	Manuala,
	Convertizor,
	Secventiala,
	DSG,
	CVT,
	Null
};

const std::vector<std::string> Combustibil = {
	"Benzina",
	"Motorina",
	"Hibrid",
	"Electric"
};

const std::vector<std::string> Cutie = {
	"Manuala",
	"Convertizor",
	"Secventiala",
	"DSG",
	"CVT"
};


class Masina
{
protected:
	std::string marca;
	std::string model;
	std::string culoare;

	int an;
	double capacitate_cilindrica;
	int cai_putere;
	COMBUSTIBIL tip_combustibil;
	CUTIE_VITEZE cutie_viteze;

	static int countMasini;
	int id;
public:
	Masina();
	Masina(std::string marca, std::string model, std::string culoare, int an, double capacitate_cilindrica,
		   int cai_putere, COMBUSTIBIL tip_combustibil, CUTIE_VITEZE cutie_viteze);
	Masina(const Masina& other);
	virtual ~Masina();

	virtual void afisare(std::ostream& out) const;
	static int getNrMasini() { return countMasini; }

	Masina& operator=(const Masina& other);
	friend std::istream& operator>>(std::istream& in, Masina& masina);
	friend std::ostream& operator<<(std::ostream& out, const Masina& masina);
};




