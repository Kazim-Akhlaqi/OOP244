/**********************************************************
// OOP244 Workshop 7: Derived Classes
// file Hero.h
// Version: in_lab
// Date July/12/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

// TODO: header file guard
#ifndef HERO_H
#define HERO_H

// TODO: add namespace here
namespace sict {

	// TODO: initialize max_rounds to 100
	const int max_rounds = 100;

	// TODO: define the Hero class
	class Hero {

		char _heroName[41];
		int _heroHealth;
		int _heroAttackStrength;

	public:

		// constructors
		Hero();
		Hero(const char* HeroName, int heroHealth, int heroAttackStrength);
		
		// member functions
		void operator-=(int heroAttackStrength);
		bool isAlive() const;
		int attackStrength() const;
		bool isEmpty() const;
		const char* getName() const;

		// friend helper function
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

		//a non-friend helper function
		const Hero& operator*(const Hero& first, const Hero& second);
}

#endif 