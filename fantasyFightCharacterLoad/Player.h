#ifndef PLAYER_H
#define PLAYER_H

#include <string>


#include "Weapon.h"

using namespace std;

class Player {
private:
	Weapon weapons[3];
	int weaponCt;
	string name;
public:
	Player() {
		name = "generic";
		weaponCt = 0;
	}
	
	Player(string n) :name(n), weaponCt(0) {}
	
	bool addWeapon(Weapon w) {
		if (weaponCt == 3) {
			return false;
		}
		weapons[weaponCt++] = w;
		return true;
	}

	string toString() {
		string str = "Player: \"" + name + "\"\n";
		for (int i = 0; i < weaponCt; i++) {
			str += "\t" + weapons[i].toString() + "\n";
		}
		return str;
	}

	string getName() { return name; }
	
	Weapon * getPlayerWeapons() {
		//copy the weapons to a new list
		Weapon * w = new Weapon[weaponCt];
		for (int i = 0; i < weaponCt; i++) {
			Weapon copy(weapons[i]);
			w[i] = copy;
		}
		return w;
	}

	int getNumWeapons() {
		return weaponCt;
	}
};

#endif
