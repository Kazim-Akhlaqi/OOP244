/**********************************************************
// OOP244 Workshop 7: Derived Classes
// file SuperHero.h
// Version: at_home
// Date July/16/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

// TODO: header file guard
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

// TODO: add namespace here
namespace sict {

	// TODO: Derive the SuperHero class from Hero class
	class SuperHero : public Hero {

	private:
		// SuperHero additional private data members
		int _superHeroAttackBonus;
		int _SuperHeroDefendStrength;

	public:

		// SuperHero constructors
		SuperHero();
		SuperHero(const char* superHeroName, int SuperHeroHealth, int SuperHeroAttackStrength, int superHeroAttackBonus, int SuperHeroDefendStrength);

		// SuperHero member functions
		int attackStrength() const;
		int defend() const;
	};

	//a non-friend helper operator which supports SuperHero class
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif
