#ifndef WEAPON_H
#define WEAPON_H

#include <string>

using namespace std;

class Weapon {
private:
	string name;
	int damage;
public:
	Weapon() {
		name = "generic";
		damage = 0;
	}

	Weapon(string n, int d) :name(n), damage(d) {}

	//copy constructor
	Weapon(const Weapon & w) {
		name = w.name;
		damage = w.damage;
	}

	int getDamage() { return damage; }

	string getName() { return name; }

	string toString() {
		string str = "Weapon: \"" + name + "\" damage: " + to_string(damage);
		
		return str;
	}

};
#endif
