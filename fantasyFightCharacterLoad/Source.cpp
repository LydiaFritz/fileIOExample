#include "Weapon.h"
#include "Player.h"
#include <iostream>
#include <fstream>


using namespace std;

void savePlayer(Player p);
Player * createPlayer();
Player * readPlayer();
int menu();

int main() {

	Player * me;
	int selection = menu();
	if (selection == 1) {
		string n;
		cout << "Enter the name for your player: ";
		cin >> n;
		me = new Player(n);
		Weapon w3("Damp Toast", 1);
		if (me->addWeapon(w3)) {
			cout << "Weapon successfully added" << endl;
		}
		else {
			cout << "Max number of weapons exceeded - cannot add new weapon" << endl;
		}
	}
	else {
		//load player
		me = readPlayer();
	}

	cout << me->toString() << endl;

	savePlayer(*me);

	return 0;
}

int menu() {
	cout << "Would you like to create a new player or continue your last game?\n";
	cout << "Enter 1 to create new player or 2 to continue last game: ";
	int choice;
	cin >> choice;
	return choice;
}

void savePlayer(Player p)
{
	//write player p to a file
	ofstream fout;
	fout.open("gameData.dat");
	//fout.open("gameData.dat" , std::ofstream::app);
	if (!fout) {
		cerr << "File not found" << endl;
	}
	else {
		cout << "success" << endl;
		//write the player to the file
		fout << p.getName() << "\n";
		Weapon * weapons = p.getPlayerWeapons();
		for (int i = 0; i < p.getNumWeapons(); i++) {
			fout << weapons[i].getName() << "\n" << weapons[i].getDamage() << "\n";
		}
		//add delimit character
		//fout << "|" << endl;
		fout.close();
	}

}

Player * createPlayer()
{
	Player * p = new Player("Gregor");
	

	//adding weapons
	Weapon w1("Wabbajack", 10);
	if (p->addWeapon(w1)) {
		cout << "Weapon successfully added" << endl;
	}
	else {
		cout << "Max number of weapons exceeded - cannot add new weapon" << endl;
	}
	/*Weapon w2("Magic Sword", 7);
	if (p->addWeapon(w2)) {
		cout << "Weapon successfully added" << endl;
	}
	else {
		cout << "Max number of weapons exceeded - cannot add new weapon" << endl;
	}*/
	Weapon w3("Damp Toast", 1);
	if (p->addWeapon(w3)) {
		cout << "Weapon successfully added" << endl;
	}
	else {
		cout << "Max number of weapons exceeded - cannot add new weapon" << endl;
	}
	//if (p->addWeapon(w3)) {
	//	cout << "Weapon successfully added" << endl;
	//}
	//else {
	//	cout << "Max number of weapons exceeded - cannot add new weapon" << endl;
	//}
	return p;
}

Player * readPlayer()
{
	Player * p = nullptr;
	ifstream fin("gameData.dat");
	if (!fin)
		exit(1);
	string name;
	string weapon;
	int damage;
	while (fin >> name) {
		//create the player
		p = new Player(name);
		//try to get a weapon
		while (!getline(fin, weapon)) {
				
			getline(fin, weapon);
			if (weapon == "|")
				break;
			//there was a weapon, so read the damage
			fin >> damage;
			//make the weapon
			Weapon * w = new Weapon(weapon, damage);
			p->addWeapon(*w);
			
		}
		
	}
	fin.close();
	return p;
}
