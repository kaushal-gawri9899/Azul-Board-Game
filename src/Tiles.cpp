#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Tiles.h"
#include <vector>

using namespace std;


Tiles::Tiles(Colour colour){
    this->colour = colour;
}

Colour Tiles::getColour(){
    return this->colour;
}

void Tiles::printTile(){
    if(colour=='R'){
     cout<<"\033[1m\033[31m"<<colour<<"\033[0m";
    }
    if(colour=='Y'){
     cout<<"\033[1m\033[33m"<<colour<<"\033[0m";
    }
    if(colour=='U'){
      cout<<"\033[1m\033[35m"<<colour<<"\033[0m";
    }
    if(colour=='L'){
      cout<<"\033[1m\033[36m"<<colour<<"\033[0m";
    }
    if(colour=='B'){
       cout<<"\033[1m\033[34m"<<colour<<"\033[0m";
    }
    if(colour=='O'){
       cout<<"\033[1m\033[32m"<<colour<<"\033[0m";
    }
    if(colour=='F'){
      cout<<"\033[1m\033[37m"<<colour<<"\033[0m";
    }
   
}

string Tiles::getTileDetails(){
    return "colour";
}

void Tiles::setColour(Colour colour){
    this->colour = colour;
}



    







