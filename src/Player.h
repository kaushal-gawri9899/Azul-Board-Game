#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Factory.h"


using namespace std;

class Player
{
public:

Player(string name, int points);
string getName();
void setName(string name);
int getPoints();
void setPoints(int points);
int tilesinhand();
LinkedList returnlist();
void fillHand(Factory* factory);
void winner(Player* player1,Player* player2);
void updatePoints(int val);
void savePlayer(string filename);
std::fstream& GotoLine(std::fstream& file, unsigned int num);
void loadName(string filename);
void loadName2(string filename);
void loadPoints1(string filename);
void loadPoints2(string filename);
void setloadPoints1(int loadPoints1);
void setloadPoints2(int loadPoints2);
int getLoadPoints1();
int getLoadPoints2();
void setFirstPlayer(int firstPlayer);
int getFirstPlayer();



private:

string name;
int points;
int firstPlayer;

 LinkedList * list = new LinkedList();
};