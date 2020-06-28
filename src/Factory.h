#ifndef ASSIGN2_H
#define ASSIGN2_H

#include <iostream>
#include "LinkedList.h"
#include "Bag.h"
// #include "Tiles.h"


class Factory{ 
public:

Factory();
void fillFactory(Bag* tileBag);
void fillFactoryTwoCentre(Bag* tileBag);
//For three Players
void fillFactoryForThree(Bag* tileBag);
void fillFactoryForThreeCentreTwo(Bag* tileBag);
//For four Players
void fillFactoryForFour(Bag* tileBag);
void fillFactoryForFourCentreTwo(Bag* tileBag);

LinkedList* getList();
void addFactory(Factory *factory);




//changes
int getSize(int numofCentreFactory,int numOfPlayers);
//changes
//For three Players
int getSizeForThree();
//For Four Players
int getSizeForFour();
//void Shuffle();
//changes
void print(int centrefactory);
//For three players
//changes
void printFactoryForThree(int centreFactory);
//For four Players
//changes
void printFactoryForFour(int centreFactory);
//std::string returnAsString();
//changes
std::string returnAsString(int numOfPlayers, int numOfCentreFactory);
void getElementAtIndex(Factory *factory,int index,Tiles* tile);
//changes
void removeElement(int i,char colour, int centreFactory, int numOfPlayers);
//chnages
int getNumberTiles(int index,char tile, int numOfCentreFactory);
//For three Players
//changes
int getNumberTilesForThree(int index, char tile, int numOfCentreFactory);
//For Four Players
//changes
int getNumberTilesForFour(int index, char tile, int numOfCentreFactory);

// void loadFactory(std::string* factoryStrings);

//changes
void loadFactoryFromFile(std::string *factoryStrings, int numOfPlayers, int numOfCentreFactory);

//changes
void addLoadedFactory(int i, std::string *factoryStrings, LinkedList* factory[]);

void changeTiles(char tiles,int i, int numOfCentreFactory);
void placeTileInZero(char tile,int numOfCentreFactory);
// void fillStatic();
//changes
void deleteAll(int i, int numberOfCentreFactory);
void addRemainingTiles(int index, char selectedColour, int numOfCentreFactory);
//For three Players
//void addRemainingTilesForThree(int index, char selectedColour);
//changes
void addRemainingTilesForThree(int index, char selectedColour, int numOfCentreFactory);
//For four Players
// void addRemainingTilesForFour(int index, char selectedColour);
//changes
void addRemainingTilesForFour(int index, char selectedColour, int numOfCentreFactory);

//changes
int getTotalSize(int numofCenterFactory, int numOfPlayers);
//changes
// bool firstPlayerTileExsists(int numOfCenterFactory, int fcatoryIndex);
//changes
bool firstPlayerTileExsists(int numOfCenterFactory, int factoryIndex, int numOfPlayer);

int numOfFactories(int numOfPlayers, int numOfCentreFactories);

private:
LinkedList* l1;
LinkedList* l2;
LinkedList* l3;
LinkedList* l4;
LinkedList* l5;
LinkedList* l6;
//For three players
LinkedList* l7;
LinkedList* l8;

//For four players
LinkedList* l9;
LinkedList* l10;
LinkedList* l11;
// LinkedList* factories;
int num;
LinkedList* factory[5];
// LinkedList* Loadfactory[5];
// LinkedList* test[6];
// int random(int min, int max);



};
#endif