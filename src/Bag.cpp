#include "Bag.h"
#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>
#include <fstream>
//#include <limits.h>
#include <chrono>
using std::ofstream;
using namespace std;

Bag::Bag(int numOfTiles)
{
    if(numOfTiles==6){
    this->numOfTiles = 6;
    }
    else{
        this->numOfTiles=5;
    }
    tiles = new LinkedList();
}

//Fills the bag with different tiles
//total of 100 tiles in the bag initially if num of tiles =5
//else 120 tiles
void Bag::fillBag()
{
    tiles = new LinkedList();

    Tiles *t;
    for(int i = 0; i < 20; i++) {
        t = new Tiles(Red);
        tiles->addNode(t);
    }

    for(int i = 0; i < 20; i++) {
        t = new Tiles(Yellow);
        tiles->addNode(t);
    }

    for(int i = 0; i < 20; i++) {
        t = new Tiles(DarkBlue);
        tiles->addNode(t);
    }

    for(int i = 0; i < 20; i++) {
        t = new Tiles(LightBlue);
        tiles->addNode(t);
    }

    for(int i = 0; i < 20; i++) {
        t = new Tiles(Black);
        tiles->addNode(t);
    }

    if(this->numOfTiles==6){
        for(int i=0; i<20; i++){
        t = new Tiles(Orange);
        tiles->addNode(t);
        }
    }
}

//shuuffles the bag by calling the random function 
//you need to shuffle the bag before filling the factories
void Bag::Shuffle()
{
    if(this->numOfTiles == 6){
    
    for (int i = 0; i < 120; ++i)
    {
        int rand = random(0, 119);

        if (rand == 0)
        {
            tiles->addBack(tiles->findNode(rand)->getTile());
            tiles->deleteFront();
        }
        else
        {
            tiles->addBack(tiles->findNode(rand)->getTile());
            tiles->deleteFront();
        }
    }
    }
    else{
        
    
    for (int i = 0; i < 100; ++i)
    {
        int rand = random(0, 99);

        if (rand == 0)
        {
            tiles->addBack(tiles->findNode(rand)->getTile());
            tiles->deleteFront();
        }
        else
        {
            tiles->addBack(tiles->findNode(rand)->getTile());
            tiles->deleteFront();
        }
    }
 
    }

}

//used to pick a particular tile from the bag
Node *Bag::pickFromBag()
{
    Node *add = tiles->findNode(0);
    tiles->deleteFront();
    return add;
}

//return the tiles in the bags
LinkedList *Bag::getList()
{
    return tiles;
}

//returns the size of the bag
int Bag::getSize()
{
    return tiles->returnSize();
}

//used to increase the randomness of tiles in the bag
int Bag::random(int min, int max)
{

      auto t = std::chrono::high_resolution_clock::now().time_since_epoch().count();
 //   auto t = 1590069381;
    std::mt19937 e;
    e.seed(static_cast<unsigned int>(t));
     std::uniform_int_distribution<int> uniform_dist(min, max);

 
    int secret =0;
    for (int i = 0; i != max; ++i)
    {
     secret = uniform_dist(e);
    }
    return secret;
}

//used to save the bag to the .txt file
void Bag::saveBag(std::string filename){
    ofstream of;

    of.open(filename, std::ios::app);
    of << "#TileBag" << '\n';
    for (int i = 0; i < 3; i++)
    {
        for (int i = 0; i < 6; i++)
        {
                for(int j=0; j<6; j++){
                of<<tiles->findNode(j)->getTile()->getColour();
                }
        }
        
    }
    of<<"\n";
    of.close();

}


//returns the string storing the tiles(char) present in the bags
//used while loading from a .txt file
std::string Bag::returnAsString() {

    std::string bagString = ""; 

    for(int i = 0; i < getSize(); i++) {
        bagString += getList()->findNode(i)->getTile()->getColour();
    }
    
    if(bagString.length() == 0){
        return "_";
    }
    return bagString;
}