/**********************************************************
// OOP244 Workshop 7: Derived Classes
// file Hero.cpp
// Version: at_home
// Date July/16/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include "Hero.h"
#define _CRT_SECURE_NO_WARNINGS

// TODO: namespace
using namespace std;

// TODO: namespace sict
namespace sict {

	// Default constructor
	Hero::Hero() {
		_heroName[0] = '\0';
		_heroHealth = 0;
		_heroAttackStrength = 0;
	}

	// Constructor
	Hero::Hero(const char* HeroName, int heroHealth, int heroAttackStrength) {

		if (HeroName != nullptr && HeroName[0] != '\0' && heroHealth > 0 && heroAttackStrength > 0) {

			strcpy(_heroName, HeroName);
			_heroHealth = heroHealth;
			_heroAttackStrength = heroAttackStrength;
		}
		else
		{
			*this = Hero();
		}
	}

	// an overloaded operator that receives an attack strength 
	void Hero::operator-=(int heroAttackStrength)
	{
		if (heroAttackStrength > 0 && _heroHealth > 0)
		{
			_heroHealth -= heroAttackStrength;

			if (_heroHealth < 0)
			{
				_heroHealth = 0;
			}
		}
	}

	// Returns true if object is alive
	bool Hero::isAlive() const
	{
		bool alive;
		if (_heroHealth > 0) {
			alive = true;
		}
		else {
			alive = false;
		}
		return alive;
	}

	// return the attack strength of current object
	int Hero::attackStrength() const {
		if (_heroAttackStrength > 0)
			return _heroAttackStrength;
		else
			return 0;
	}

	// return the hero name
	const char* Hero::getName() const
	{
		return _heroName;
	}

	// check for safe epmty state
	bool Hero::isEmpty() const {

		bool empty;

		if (_heroName[0] == '\0' && _heroAttackStrength == 0 && _heroHealth == 0) {
			empty = true;
		}
		else {
			empty = false;
		}
		return empty;
	}

	// a friend helper function that inserts the name of hero into stream os 
	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		if (hero.isEmpty()) {
			os << "No hero";
		}
		else
		{
			os << hero._heroName;
		}
		return os;
	}

	// a non-friend helper function that returns
	// an unmodifiable reference to the winner 
	const Hero& operator*(const Hero& first, const Hero& second)
	{
		Hero leftHero = first;
		Hero rightHero = second;
		Hero winner;
		int round = 0;

		cout << "Ancient Battle! " << first.getName() << " vs " << second.getName();

		while (round < max_rounds && (leftHero.isAlive() && rightHero.isAlive())) {

			leftHero -= rightHero.attackStrength();
			rightHero -= leftHero.attackStrength();
			round++;
		}

		bool draw = leftHero.isAlive() && rightHero.isAlive();

		if (draw){
			winner = leftHero;
			cout << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return first;
		} else if (!leftHero.isAlive()){
			winner = rightHero;
			cout << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return second;
		} else if (!rightHero.isAlive()){
			winner = leftHero;
			cout << " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return first;
		} else {
			return first;
		}
	}
}