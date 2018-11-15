/**********************************************************
// OOP244 Workshop 7: Derived Classes
// file SuperHero.cpp
// Version: at_home
// Date July/16/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

#include <iostream>
#include "SuperHero.h"
#define _CRT_SECURE_NO_WARNINGS

// TODO: namespace std
using namespace std;

// TODO: namespace sict
namespace sict {

	// Default constructor
	SuperHero::SuperHero(): Hero(){
		_superHeroAttackBonus = 0;
		_SuperHeroDefendStrength = 0;
	}

	SuperHero::SuperHero(const char* superHeroName, int SuperHeroHealth, int SuperHeroAttackStrength,
		int superHeroAttackBonus, int SuperHeroDefendStrength) : Hero(superHeroName, SuperHeroHealth, SuperHeroAttackStrength){
			_superHeroAttackBonus = superHeroAttackBonus;
			_SuperHeroDefendStrength = SuperHeroDefendStrength;
	}

	// SuperHero member functions
	int SuperHero::attackStrength() const {
		if (Hero::attackStrength() > 0) {
			return  Hero::attackStrength() + _superHeroAttackBonus;
		} else {
			return 0;
		}
	}

	int SuperHero::defend() const {
		if (_SuperHeroDefendStrength > 0) {
			return _SuperHeroDefendStrength;
		} else {
			return 0;
		}
	}

	//a non-friend helper operator which supports SuperHero class
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{
		SuperHero leftSuperHero = first;
		SuperHero rightSuperHero = second;
		SuperHero winner;
		int round = 0;

		cout << "Super Fight! " << first.getName() << " vs " << second.getName();

		while (round < max_rounds && (leftSuperHero.isAlive() && rightSuperHero.isAlive())){
			leftSuperHero -= rightSuperHero.attackStrength() - leftSuperHero.defend();
			rightSuperHero -= leftSuperHero.attackStrength() - rightSuperHero.defend();
			round++;
		}

		bool draw = leftSuperHero.isAlive() && rightSuperHero.isAlive();

		if (draw){
			winner = leftSuperHero;
			cout << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return first;
		} else if (!leftSuperHero.isAlive()){
			winner = rightSuperHero;
			cout << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return second;
		} else if (!rightSuperHero.isAlive()){
			winner = leftSuperHero;
			cout << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return first;
		} else {
			return first;
		}
	}


}