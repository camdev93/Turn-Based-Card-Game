#pragma once
#include <string>
#include <iostream>
#include <ctime>//Contains time(0), NULL, 0;
#include <cstdlib>
#include <windows.h>

using namespace std;

//CLASSES
class Character { //Types of Charcter Cards
private:
	enum CharName { ARMOURED_KNIGHT, RONIN, SPARTAN, JEDI, VIKING, RAIDEN, LINK, CLOUD_STRIFE, NOCTIS };
	string charName[9]{ "ARMOURED KNIGHT","RONIN","SPARTAN","JEDI","VIKING","RAIDEN","LINK","CLOUD STRIFE","NOCTIS" };
public:
	string name;
	int health;
	int strength;
	//FUNCTION SELECTS NEW CARD
	void randSellect() {
		int charPU = { (rand() % 9) };
		switch (charPU) {
		case ARMOURED_KNIGHT:
			name = charName[ARMOURED_KNIGHT];
			health = 150;
			strength = 4;
			break;
		case RONIN:
			name = charName[RONIN];
			health = 150;
			strength = 2;
			break;
		case SPARTAN:
			name = charName[SPARTAN];
			health = 150;
			strength = 3;
			break;
		case JEDI:
			name = charName[JEDI];
			health = 150;
			strength = 2;
			break;
		case VIKING:
			name = charName[VIKING];
			health = 150;
			strength = 5;
			break;
		case RAIDEN:
			name = charName[RAIDEN];
			health = 150;
			strength = 6;
			break;
		case LINK:
			name = charName[LINK];
			health = 150;
			strength = 4;
			break;
		case CLOUD_STRIFE:
			name = charName[CLOUD_STRIFE];
			health = 150;
			strength = 7;
			break;
		case NOCTIS:
			name = charName[NOCTIS];
			health = 150;
			strength = 7;
			break;
		}
	}
};

class Weapon {
private:
	enum wepCard { ZWEIHANDER, KATANA, GLADIUS, LIGHTSABER, SIGURD, HFBLADE, BLADEOFEVILSBANE, BUSTERSWORD, ENGINEBLADE };
	string wepName[9]{ "ZWIEHANDER","KATANA","GLADIUS","LIGHT SABER","SIGURD","HF BLADE","BLADE OF EVIL's BANE","BUSTER SWORD","ENGINE BLADE" };
public:
	string name;
	int attack;
	int uses;
	//FUNCTION SELECTS NEW CARD
	void randSellect() {
		int wepPU = { (rand() % 9) };
		switch (wepPU) {
		case ZWEIHANDER:
			name = wepName[ZWEIHANDER];
			attack = (rand() % 48 + 25);
			uses = 2;
			break;
		case KATANA:
			name = wepName[KATANA];
			attack = (rand() % 45 + 35);
			uses = 3;
			break;
		case GLADIUS:
			name = wepName[GLADIUS];
			attack = (rand() % 44 + 29);
			uses = 4;
			break;
		case LIGHTSABER:
			name = wepName[LIGHTSABER];
			attack = (rand() % 50 + 35);
			uses = 3;
			break;
		case SIGURD:
			name = wepName[SIGURD];
			attack = (rand() % 40 + 25);
			uses = 4;
			break;
		case HFBLADE:
			name = wepName[HFBLADE];
			attack = 150;
			uses = 1;
			break;
		case BLADEOFEVILSBANE:
			name = wepName[BLADEOFEVILSBANE];
			attack = (rand() % 37 + 25);
			uses = 4;
			break;
		case BUSTERSWORD:
			name = wepName[BUSTERSWORD];
			attack = (rand() % 50 + 40);
			uses = 3;
			break;
		case ENGINEBLADE:
			name = wepName[ENGINEBLADE];
			attack = (rand() % 45 + 40);
			uses = 2;
			break;
		}
	}
};

class Upgrade {
private:
	enum upgCard { plusH, plusA, Ax2H_2, Hx2A_2, Sx2, xtraUse };
	string upgName[6]{ "+H","+A","A*2, H/2","H*2, A/2","S*2","+U" };
public:
	int upgPU, uses{};
	string name;
	//FUNCTION SELECTS NEW CARD
	int randSellect() {
		upgPU = (rand() % 6);
		switch (upgPU) {
		case plusH:
			name = upgName[plusH];
			break;
		case plusA:
			name = upgName[plusA];
			break;
		case Ax2H_2:
			name = upgName[Ax2H_2];
			break;
		case Hx2A_2:
			name = upgName[Hx2A_2];
			break;
		case Sx2:
			name = upgName[Sx2];
			break;
		case xtraUse:
			name = upgName[xtraUse];
			break;
		}
		return upgPU;
	}
};

class Player {
public:
	int lifePoints{ 1000 };
};
