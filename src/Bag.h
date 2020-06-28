
#ifndef ASSIGN2_BAG_H
#define ASSIGN2_BAG_H

#include <cstdlib>
#include "LinkedList.h"
#include "Tiles.h"

class Bag{
public:
Bag(int numOfTiles);

void fillBag();
void Shuffle();
Node* pickFromBag();
LinkedList* getList();
int getSize();
int random(int min, int max);
void saveBag(std::string filename);
//void removeFromBag(Tiles* tile);
std::string returnAsString() ;

private:
LinkedList* tiles;
int numOfTiles;

};

#endif