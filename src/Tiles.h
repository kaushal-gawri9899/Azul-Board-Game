#include <iostream>


#include <string>
#include <string.h>
#include "TileColour.h"
#include <vector>
#ifndef BLAH_H
#define BLAH_H

typedef char Colour;
//typedef string Colour;

class Tiles{
public:

Tiles(Colour colour);
Colour getColour();
std::string getTileDetails();
void setColour(Colour colour);

void printTile();

 private:
 Colour colour;
//  Tiles* tiles;
};

#endif

