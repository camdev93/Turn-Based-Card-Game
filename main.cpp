#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include "Header.h"
#include "Classes.h"
#include "Tutorial.h"

using namespace std;

// GLOBAL VARIABLES
enum upgCard { plusH, plusA, Ax2H_2, Hx2A_2, Sx2, xtraUse };

//MAIN
int main() {
	bool gameOver{false};
	srand(time(NULL));
	cout << "welcome to swordCards" << endl;
	cout << "" << endl;
	cout << "press enter..." << endl;
	cin.get();

	//QUICK TUTORIAL   (in tutorial "Tutorial.h")
	tutorial();

	//GAME LOOP
		char playAgain;
	do {
			bool youWin{}, oppWins{}, charChange{};
			Player p1, cpu;

			// NEW GAME
		do{
			// keeping track of total matches played.
			extern void ref(int& value);
			extern int* p1Rec[];
			extern int* cpuRec[];
			
			// displays players total wins/loses record at beginning of second match.
			if ((*p1Rec[0] || *p1Rec[1]) || (*cpuRec[0] || *cpuRec[1]) != 0) {
				cout << "" << endl;
				cout << "" << endl;
				cout << "PLAYER ONE" << endl;
				cout << "wins: " << *p1Rec[0] << endl;
				cout << "loses: " << *p1Rec[1] << endl;
				cout << "" << endl;
				cout << "OPPONENT" << endl;
				cout << "wins: " << *cpuRec[0] << endl;
				cout << "loses: " << *cpuRec[1] << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
				
			//PLAYABLE CARD OBJECTS
			Character p1char, cpuchar;
			Weapon p1wep, cpuwep;
			Upgrade p1upg, cpuupg;

				//WILL DISPLAY FOR NEW CARDS
				typewriter("DEALING CARDS OUT...",100);
				
				//player selection
				p1char.randSellect();
				p1wep.randSellect();
				
				//computer selection
				cpuchar.randSellect();
				cpuwep.randSellect();

				cin.get();
				// DISPLAY PLAYER & COMPUTER NEW CARDS
				cout << "its " << p1char.name << " holding a " << p1wep.name << " vs " << cpuchar.name << " holding a " << cpuwep.name << endl;
				cout << "YOUR HEALTH: " << p1char.health << "                         " << "OPPONENT HEALTH: " << cpuchar.health << endl;
				cout << "YOUR STRENGTH: " << p1char.strength << "                         " << "OPPONENT STRENGTH: ?" << endl;
				cout << "YOUR WEAPON ATTACK: " << p1wep.attack << "                         " << "OPPONENT WEAPON ATTACK: ?" << endl;
				cin.get();

			//MATCH/BATTLE LOOP
			charChange = false;
			do {
				//               YOUR TURN
				cout << "its your turn" << endl;
				cout << "attack or upgrade? a/u" << endl;
				char aORu;
				cin >> aORu;
				switch (aORu) {
				case 'a':
					//        (ATTACK FUNCTION HERE)
					cout << p1char.name << " uses " << p1wep.name << " to attack " << cpuchar.name << endl;

					cpuchar.health -= (p1wep.attack + p1char.strength);
					p1wep.uses -= 1;
				
					cout << cpuchar.name << "'s health: " << cpuchar.health << endl;
						
					cout << "your " << p1wep.name << " has " << p1wep.uses << " uses remaining." << endl;

					cin.get();
					break;
				case 'u':
					cout << p1char.name << " draws for an upgrade card " << endl;
					//         (UPGRADE FUNCTION HERE)
					p1upg.randSellect();
					switch (p1upg.upgPU) {

					case plusH:
						cout << "you picked up a " << p1upg.name << ". your character health will be increased by 30." << endl;
						p1char.health += 30;
						cout << "your health: " << p1char.health << endl;
						cin.get();
						break;


					case plusA:
						cout << "you picked up a " << p1upg.name << ". your weapon attack will be increased by 10." << endl;
						p1wep.attack += 10;
						cout << "your attack: " << p1wep.attack << endl;
						cin.get();
						break;


					case Ax2H_2:
						cout << "you picked up a " << p1upg.name << ". your attack will be doubled and health will be slashed in half." << endl;
						p1char.health -= (p1char.health / 2);
						p1wep.attack += p1wep.attack;
						cout << "your health: " << p1char.health << endl;
						cout << "your attack: " << p1wep.attack << endl;
						cin.get();
						break;


					case Hx2A_2:
						cout << "you picked up a " << p1upg.name << ". your health will be doubled and attack will be slashed in half." << endl;
						p1wep.attack -= (p1wep.attack / 2);
						p1char.health += p1char.health;
						cout << "your health: " << p1char.health << endl;
						cout << "your attack: " << p1wep.attack << endl;
						cin.get();
						break;


					case Sx2:
						cout << "you picked up a " << p1upg.name << ". your strength will be doubled." << endl;
						p1char.strength += p1char.strength;
						cout << "your strength: " << p1char.strength << endl;
						cin.get();
						break;


					case xtraUse:
						cout << "you picked up a " << p1upg.name << ". your weapon will be given 1 extra use." << endl;
						p1wep.uses += 1;
						cout << "your weapon uses: " << p1wep.uses << endl;
						cin.get();
						break;
					}
					break;					
				}

				//cpu health check 
				if (cpuchar.health <= NULL) {
					cout << cpuchar.name << "'s health is 0" << endl;
					charChange = true;
					youWin = true;
					oppWins = false;
					cin.get();
					break;
				}//player weapon check	
				else if (p1wep.uses == 0) {
					// when weapon uses run out choose new weapon
				p1wep.randSellect();
				cout << "you now hold a "; typewriter(p1wep.name, 100);
				}

				cin.get();

				//                   OPPONENTS TURN
				cout << "its your opponents turn" << endl;
				// ATTACK PROBABILITY 2:1
				switch ((rand() % 3+1)) {
				case 1://ATTACK
					cout << cpuchar.name << " uses " << cpuwep.name << " to attack " << p1char.name << endl;
					p1char.health -= (cpuwep.attack + cpuchar.strength);
					cpuwep.uses -= 1;

					cout << p1char.name << "'s health: " << p1char.health << endl;

					cout << "opponents " << cpuwep.name << " has " << cpuwep.uses << " uses remaining." << endl;

					cin.get();
					break;
				case 2://ATTACK
					cout << cpuchar.name << " uses " << cpuwep.name << " to attack " << p1char.name << endl;
					p1char.health -= (cpuwep.attack + cpuchar.strength);
					cpuwep.uses -= 1;

					cout << p1char.name << "'s health: " << p1char.health << endl;

					cout << "opponents " << cpuwep.name << " has " << cpuwep.uses << " uses remaining." << endl;

					cin.get();
					break;
				case 3://UPGRADE
					cout << cpuchar.name << " draws for an upgrade card" << endl;
					//         (UPGRADE FUNCTION HERE)
					cpuupg.randSellect();
					switch (cpuupg.upgPU) {

					case plusH:
						cout << "opponent picked up a " << cpuupg.name << ". opponent character health will be increased by 30." << endl;
						cpuchar.health += 30;
						cout << "opponent health: " << cpuchar.health << endl;
						cin.get();
						break;


					case plusA:
						cout << "opponent picked up a " << cpuupg.name << ". opponent weapon attack will be increased by 10." << endl;
						cpuwep.attack += 10;
						cout << "opponent attack: " << cpuwep.attack << endl;
						cin.get();
						break;


					case Ax2H_2:
						cout << "opponent picked up a " << cpuupg.name << ". opponent attack will be doubled and health will be slashed in half." << endl;
						cpuchar.health -= ( cpuchar.health / 2);
						cpuwep.attack += cpuwep.attack;
						cout << "opponent health: " << cpuchar.health << endl;
						cout << "opponent attack: " << cpuwep.attack << endl;
						cin.get();
						break;


					case Hx2A_2:
						cout << "opponent picked up a " << cpuupg.name << ". opponent health will be doubled and attack will be slashed in half." << endl;
						cpuwep.attack -= (cpuwep.attack / 2);
						cpuchar.health += cpuchar.health;
						cout << "opponent health: " << cpuchar.health << endl;
						cout << "opponent attack: " << cpuwep.attack << endl;
						cin.get();
						break;


					case Sx2:
						cout << "opponent picked up a " << cpuupg.name << ". opponent strength will be doubled." << endl;
						cpuchar.strength += cpuchar.strength;
						cout << "opponent strength: " << cpuchar.strength << endl;
						cin.get();
						break;


					case xtraUse:
						cout << "opponent picked up a " << cpuupg.name << ". opponents weapon will be given 1 extra use." << endl;
						cpuwep.uses += 1;
						cout << "opponent weapon uses: " << cpuwep.uses << endl;
						cin.get();
						break;
					}

					break;
					
				}

				//player health check
				if (p1char.health <= NULL) {
					cout << p1char.name << "'s health is 0" << endl;
					charChange = true;
					youWin = false;
					oppWins = true;
					cin.get();
					break;
				}//cpu weapon check	
					if (cpuwep.uses == 0) {
						// NEW Weapon cpuwep;
						cpuwep.randSellect();
						cout << "opponent weapon uses have run out" << endl;
						typewriter("opponent now holds a " + cpuwep.name, 100);
						cin.get();						
					}
			} while (charChange == false);

			//  MATCH LOSE PENALTY
			if (youWin == true) {

				// total matches played incremented HERE.
				ref(*cpuRec[1]);
				ref(*p1Rec[0]);


				cpu.lifePoints -= 350;
				cout << "opponent -350 lifepoints" << endl;
				cout << " opponents lifePoints: " << cpu.lifePoints << endl;
				//  lifePoint check
				if (cpu.lifePoints <= 0) {
					cout << "YOU WIN. game over" << endl;
					gameOver = true;
					cin.get();
				}
			}
			//MATCH LOSE PENALTY
			else if (oppWins == true) {

				// total matches played incremented HERE.
				ref(*cpuRec[0]);
				ref(*p1Rec[1]);


				p1.lifePoints -= 350;
				cout << "player -350 lifepoints" << endl;
				cout << "your lifePoints: " << p1.lifePoints << endl;
				cin.get();
				//  lifePoint check
				if (p1.lifePoints <= 0) {
					cout << "YOU LOSE. game over" << endl;
					gameOver = true;
					cin.get();
				}
			}
			
			

		} while (gameOver == false);
			cout << "wanna play again? type 'y' OR 'n'" << endl;
			// if yess loops back to top.
			cin >> playAgain;
	} while (playAgain == 'y');
	cout << "goodbye" << endl;
	cin.get();
	//ENDS HERE
}