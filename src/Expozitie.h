#pragma once

#include <vector>
#include "Masina.h"
#include "Supersport.h"
#include "MyExceptions.h"

template <class T>
class Expozitie
{
private:
	std::vector<T*> masini;
	int nrMasini;
public:
	Expozitie() : nrMasini(0), masini(std::vector<T*>()) {}
	~Expozitie() {
		masini.clear();
	}

	void insert(T* masina)
	{
		masini.push_back(masina);
		nrMasini++;
	}

	friend std::istream& operator>>(std::istream& in, T* masina);
	friend std::ostream& operator<<(std::ostream& out, const Expozitie<T>& expo)
	{
		out << "\n\n================= EXPOZITIE GENERALA ===================\n";
		for (typename std::vector<T*>::const_iterator it = expo.masini.begin(); it != expo.masini.end(); ++it)
			out << **it;

		out << "========================================================\n";
		return out;
	}

};


template<>
class Expozitie<Supersport>
{
private:
	int nrMasiniSupersport;
	int nrVanduteSupersport;
	std::vector<Supersport*> stoc;
	std::vector<Supersport*> vandute;

public:
	Expozitie() : nrMasiniSupersport(0), nrVanduteSupersport(0) {}
	~Expozitie() {
		stoc.clear();
		vandute.clear();
		nrMasiniSupersport = 0;
		nrVanduteSupersport = 0;
	}

	void insert(Supersport* masina)
	{
		stoc.push_back(masina);
		nrMasiniSupersport++;
	}

	bool exists(int id)
	{
		for (auto it = stoc.begin(); it != stoc.end(); it++)
			if ((*it)->getID() == id)
				return true;

		return false;
	}

	Expozitie& operator-=(int id)
	{
		for (auto it = stoc.begin(); it != stoc.end(); it++)
			if ((*it)->getID() == id) {
				vandute.push_back(*it);
				stoc.erase(it);
				nrMasiniSupersport--;
				nrVanduteSupersport++;
				break;
			}

		return *this;
	}

	friend std::istream& operator>>(std::istream& in, Supersport* masina);
	friend std::ostream& operator<<(std::ostream& out, const Expozitie<Supersport>& expo)
	{
		out << "\n\n================= EXPOZITIE SUPERSPORT =================\n\n";
		out << "Masini Supersport pe stoc: " << expo.nrMasiniSupersport << '\n';
		for (auto it : expo.stoc)
			out << *it;

		out << "Masini Supersport vandute: " << expo.nrVanduteSupersport<< '\n';
		for (auto it : expo.vandute)
			out << *it;

		out << "=========================================================\n";
		return out;
	}
};
