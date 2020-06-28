#include <random>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include "Factory.h"
#include <chrono>
#include <iostream>
#include <sstream>

#define numFactory 4

using namespace std;

//constructor that initialize the linkedlists
Factory::Factory()
{
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    
    //for three players
    l7 = new LinkedList();
    l8 = new LinkedList();

    //for four players
    l9 = new LinkedList();
    l10 = new LinkedList();
    l11 = new LinkedList();
}

//fills factory for 2 players and 1 centre using the tile bag
void Factory::fillFactory(Bag* tileBag){
    // Bag *b = new Bag();

    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    l1->addNode(new Tiles(firstplayer));

    Tiles* t = nullptr;
   
    for(int i = 1; i < 6; i++){
        for(int j = 0; j < 4; j++){
                if(tileBag->getList()->findNode(0)){
            char tile = tileBag->getList()->findNode(0)->getTile()->getColour();
            tileBag->getList()->deleteNode(0);
               
            if(tile == 'R'){
                t = new Tiles(Red);
            }
            else if(tile == 'B'){
                t = new Tiles(DarkBlue);
            }
            else if(tile == 'Y'){
                t = new Tiles(Yellow);
            }
            else if(tile == 'U'){
                t = new Tiles(Black);
            }
            else if(tile == 'L'){
                t = new Tiles(LightBlue);
            }
            else if(tile == 'O'){
                t = new Tiles(Orange);
            }
            factory[i]->addNode(t);
        }
        else{
            return;
        }
        }
    }

}

//fills factory for two centre factory using the tile bag
void Factory::fillFactoryTwoCentre(Bag* tileBag){
    
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    l7 = new LinkedList();
    LinkedList* factory[7] = {l1,l2,l3,l4,l5,l6,l7};
    l1->addNode(new Tiles(firstplayer));
    //l2->addNode(new Tiles(firstplayer));

    Tiles* t = nullptr;
   
    for(int i = 2; i < 7; i++){
      
        for(int j = 0; j < 4; j++){
                if(tileBag->getList()->findNode(0)){
            char tile = tileBag->getList()->findNode(0)->getTile()->getColour();
            tileBag->getList()->deleteNode(0);
               
            if(tile == 'R'){
                t = new Tiles(Red);
            }
            else if(tile == 'B'){
                t = new Tiles(DarkBlue);
            }
            else if(tile == 'Y'){
                t = new Tiles(Yellow);
            }
            else if(tile == 'U'){
                t = new Tiles(Black);
            }
            else if(tile == 'L'){
                t = new Tiles(LightBlue);
            }
            else if(tile == 'O'){
                t = new Tiles(Orange);
            }
            factory[i]->addNode(t);
        }
        else{
            return;
        }
        }
    }

}

//fills factory for 3 players and 1 centre factory using tilebag
void Factory::fillFactoryForThree(Bag* tileBag){
    // Bag *b = new Bag();
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    //For three players
    l7 = new LinkedList();
    l8 = new LinkedList(); 
    LinkedList* factory[8] = {l1,l2,l3,l4,l5,l6,l7,l8};
    l1->addNode(new Tiles(firstplayer));

    Tiles* t = nullptr;
   
    for(int i = 1; i < 8; i++){
        for(int j = 0; j < 4; j++){

                //changing form i*j to 4 as when bag size is reduced it will throw a nullptr
                //was never checked earlier
                if(tileBag->getList()->findNode(0)!=nullptr){
                   
            char tile = tileBag->getList()->findNode(0)->getTile()->getColour();
            tileBag->getList()->deleteNode(0);
               
            if(tile == 'R'){
                t = new Tiles(Red);
            }
            else if(tile == 'B'){
                t = new Tiles(DarkBlue);
            }
            else if(tile == 'Y'){
                t = new Tiles(Yellow);
            }
            else if(tile == 'U'){
                t = new Tiles(Black);
            }
            else if(tile == 'L'){
                t = new Tiles(LightBlue);
            }
            else if(tile == 'O'){
                t = new Tiles(Orange);
            }
            factory[i]->addNode(t);    
              }
        else{       
            return;
             }
        }
        }
    

}

//fills factory for three players using two centre factory with the tile bag
void Factory::fillFactoryForThreeCentreTwo(Bag* tileBag){
    //Centre factory
    l1 = new LinkedList();
    l2 = new LinkedList();
    //
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    //For three players
    l7 = new LinkedList();
    l8 = new LinkedList(); 
    l9 = new LinkedList();
    LinkedList* factory[9] = {l1,l2,l3,l4,l5,l6,l7,l8,l9};
    l1->addNode(new Tiles(firstplayer));
    //l2->addNode(new Tiles(firstplayer));
    Tiles* t = nullptr;
   
   //changed i from 1 to 2 and i<8 to i<9
    for(int i = 2; i < 9; i++){
        for(int j = 0; j < 4; j++){
              //changing from i*j to 4  
            if(tileBag->getList()->findNode(0)!=nullptr){  
            char tile = tileBag->getList()->findNode(0)->getTile()->getColour();
            tileBag->getList()->deleteNode(0);
               
            if(tile == 'R'){
                t = new Tiles(Red);
            }
            else if(tile == 'B'){
                t = new Tiles(DarkBlue);
            }
            else if(tile == 'Y'){
                t = new Tiles(Yellow);
            }
            else if(tile == 'U'){
                t = new Tiles(Black);
            }
            else if(tile == 'L'){
                t = new Tiles(LightBlue);
            }
            else if(tile == 'O'){
                t = new Tiles(Orange);
            }
            factory[i]->addNode(t);
        }
        else{
            return;
        }

    }
    }

}

//Filling the factory for four player and 1 centre factory using tilebag
void Factory::fillFactoryForFour(Bag* tileBag){
    // Bag *b = new Bag();
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    //For three players
    l7 = new LinkedList();
    l8 = new LinkedList(); 
    //For Four Players
    l9 = new LinkedList();
    l10 = new LinkedList();
    LinkedList* factory[10] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10};
    l1->addNode(new Tiles(firstplayer));

    Tiles* t = nullptr;
   //i<10 for 4 players as there will be 9+1 factories
    for(int i = 1; i < 10; i++){
        for(int j = 0; j < 4; j++){
                //changing from i*j to 4
             if(tileBag->getList()->findNode(0)!=nullptr){   
            char tile = tileBag->getList()->findNode(0)->getTile()->getColour();
            tileBag->getList()->deleteNode(0);
               
            if(tile == 'R'){
                t = new Tiles(Red);
            }
            else if(tile == 'B'){
                t = new Tiles(DarkBlue);
            }
            else if(tile == 'Y'){
                t = new Tiles(Yellow);
            }
            else if(tile == 'U'){
                t = new Tiles(Black);
            }
            else if(tile == 'L'){
                t = new Tiles(LightBlue);
            }
            else if(tile == 'O'){
                t = new Tiles(Orange);
            }
            factory[i]->addNode(t);
        }
        else{
            return;
        }
    }

}
}

//filling the factory using four player and two centre for the bag
void Factory::fillFactoryForFourCentreTwo(Bag* tileBag){
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    //For three players
    l7 = new LinkedList();
    l8 = new LinkedList(); 
    //For Four Players
    l9 = new LinkedList();
    l10 = new LinkedList();
    l11 = new LinkedList();
    LinkedList* factory[11] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11};
    l1->addNode(new Tiles(firstplayer));
    //l2->addNode(new Tiles(firstplayer));
    Tiles* t = nullptr;
   //i<11 for 4 players as there will be 9+2 factories(i starts from 2)
    for(int i = 2; i < 11; i++){
        for(int j = 0; j < 4; j++){
                //changing from i*j to 4 
             if(tileBag->getList()->findNode(0)!=nullptr){ 
            char tile = tileBag->getList()->findNode(0)->getTile()->getColour();
            tileBag->getList()->deleteNode(0);
               
            if(tile == 'R'){
                t = new Tiles(Red);
            }
            else if(tile == 'B'){
                t = new Tiles(DarkBlue);
            }
            else if(tile == 'Y'){
                t = new Tiles(Yellow);
            }
            else if(tile == 'U'){
                t = new Tiles(Black);
            }
            else if(tile == 'L'){
                t = new Tiles(LightBlue);
            }
            else if(tile == 'O'){
                t = new Tiles(Orange);
            }
            factory[i]->addNode(t);
        }
        else
        {
            return;
        }
        
        }
    }
}

//returns the factories for 2 player
LinkedList *Factory::getList()
{
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};

    for (int i = 0; i < 6; i++)
    {
        return factory[i];
    }
    return nullptr;
}

//Places the tile on the centre factory automatically if centre factory is 1
//asks for user input for two centre factories
void Factory::placeTileInZero(char tile,int numOfCentreFactory){
    

    //Changes 
    int centreFactory;
    if(numOfCentreFactory==2){
    cout<<"On which centre factory would you like to place the different Tile?(0 or 1)? \n";
    cout<<"The tile to be placed is "<<tile<<"\n";
    cout<<"> ";
    cin>>centreFactory;
    while(centreFactory>1){
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Wrong Input!";
        cout<<"On which centre factory would you like to place the different Tile?(0 or 1)? \n";
        cout<<"> ";
        cin>>centreFactory; 
    }
    if(centreFactory==0){
    LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    if(tile == 'U'){
        factory[0]->addNode(new Tiles(Black));
    }
    else if(tile == 'R'){
        factory[0]->addNode(new Tiles(Red));
    }
    else if(tile == 'B'){
        factory[0]->addNode(new Tiles(DarkBlue));
    }
    else if(tile == 'L'){
        factory[0]->addNode(new Tiles(LightBlue));
    }
    else if(tile == 'Y'){
        factory[0]->addNode(new Tiles(Yellow));
    }
    else if(tile == 'O'){
        factory[0]->addNode(new Tiles(Orange));
    }
    }
    else{
        LinkedList* factory[7] = {l1,l2,l3,l4,l5,l6,l7};
    if(tile == 'U'){
        factory[1]->addNode(new Tiles(Black));
    }
    else if(tile == 'R'){
        factory[1]->addNode(new Tiles(Red));
    }
    else if(tile == 'B'){
        factory[1]->addNode(new Tiles(DarkBlue));
    }
    else if(tile == 'L'){
        factory[1]->addNode(new Tiles(LightBlue));
    }
    else if(tile == 'Y'){
        factory[1]->addNode(new Tiles(Yellow));
    }
    else if(tile == 'O'){
        factory[1]->addNode(new Tiles(Orange));
    }
    }
    }
    else{
         LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    if(tile == 'U'){
        factory[0]->addNode(new Tiles(Black));
    }
    else if(tile == 'R'){
        factory[0]->addNode(new Tiles(Red));
    }
    else if(tile == 'B'){
        factory[0]->addNode(new Tiles(DarkBlue));
    }
    else if(tile == 'L'){
        factory[0]->addNode(new Tiles(LightBlue));
    }
    else if(tile == 'Y'){
        factory[0]->addNode(new Tiles(Yellow));
    }
    else if(tile == 'O'){
        factory[0]->addNode(new Tiles(Orange));
    }
    }

}


//a function that invokes the method to place the tile at centre factory after every turn for two player
void Factory::addRemainingTiles(int index, char selectedColour, int numOfCentreFactory){
    
    if(numOfCentreFactory==1){
    LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    for(int i = 0; i < factory[index]->returnSize(); i++){
        char tileColour = factory[index]->findNode(i)->getTile()->getColour(); 

        if(tileColour != selectedColour) {
            placeTileInZero(tileColour,numOfCentreFactory);
        }
    }

    factory[index]->deleteAll();
    }
    else{
        LinkedList* factory[7] = {l1,l2,l3,l4,l5,l6,l7};
         for(int i = 0; i < factory[index]->returnSize(); i++){
        char tileColour = factory[index]->findNode(i)->getTile()->getColour(); 
        if(tileColour != selectedColour) {
            placeTileInZero(tileColour,numOfCentreFactory);
        }
    }

    factory[index]->deleteAll();
    }

}

//a function that invokes the method to place the tile at centre factory after every turn for three player
void Factory::addRemainingTilesForThree(int index, char selectedColour, int numOfCentreFactory){
    if(numOfCentreFactory==1){
    LinkedList* factory[8] = {l1,l2,l3,l4,l5,l6,l7,l8};
    for(int i = 0; i < factory[index]->returnSize(); i++){
        char tileColour = factory[index]->findNode(i)->getTile()->getColour(); 
        if(tileColour != selectedColour) {
            placeTileInZero(tileColour,numOfCentreFactory);
        }
    }

    factory[index]->deleteAll();
    }
    if(numOfCentreFactory==2){
         LinkedList* factory[9] = {l1,l2,l3,l4,l5,l6,l7,l8,l9};
    for(int i = 0; i < factory[index]->returnSize(); i++){
        char tileColour = factory[index]->findNode(i)->getTile()->getColour(); 
        if(tileColour != selectedColour) {
            placeTileInZero(tileColour,numOfCentreFactory);
        }
    }
    factory[index]->deleteAll();
    }
    
}

//a function that invokes the method to place the tile at centre factory after every turn for four player
void Factory::addRemainingTilesForFour(int index, char selectedColour, int numOfCentreFactory){
   
   // cout<<"Crashes here";
    if(numOfCentreFactory==1){
    LinkedList* factory[10] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10};
    for(int i = 0; i < factory[index]->returnSize(); i++){
        char tileColour = factory[index]->findNode(i)->getTile()->getColour(); 
        if(tileColour != selectedColour) {
            placeTileInZero(tileColour,numOfCentreFactory);
        }
    }

    factory[index]->deleteAll();
    }
    if(numOfCentreFactory==2){
    LinkedList* factory[11] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11};
    for(int i = 0; i < factory[index]->returnSize(); i++){
        char tileColour = factory[index]->findNode(i)->getTile()->getColour(); 
        if(tileColour != selectedColour) {
            placeTileInZero(tileColour,numOfCentreFactory);
        }
    }

    factory[index]->deleteAll();
    }

}

//returns the given number of tiles in a particular factory for 2 player
int Factory::getNumberTiles(int index, char tile, int numOfCentreFactory){
   
   if(numOfCentreFactory==1){
    int count = 0;

    LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    for(int i = 0; i < factory[index]->returnSize(); i++){
        if(factory[index]->findNode(i)->getTile()->getColour() == tile) {
            count++;
        }

    }
    return count;
   }
   else
   {
        int count = 0;

    LinkedList* factory[7] = {l1,l2,l3,l4,l5,l6,l7};
    for(int i = 0; i < factory[index]->returnSize(); i++){
        if(factory[index]->findNode(i)->getTile()->getColour() == tile) {
            count++;
        }

    }
    return count;
   }
   
}


//returns the given number of tiles in a particular factory for 3 player
int Factory::getNumberTilesForThree(int index, char tile, int numOfCentreFactory){
   
    if(numOfCentreFactory==1){
    int count = 0;

    LinkedList* factory[8] = {l1,l2,l3,l4,l5,l6,l7,l8};
    for(int i = 0; i < factory[index]->returnSize(); i++){
        if(factory[index]->findNode(i)->getTile()->getColour() == tile) {
            count++;
        }

    }
    return count;
    }
    else{
        int count = 0;

    LinkedList* factory[9] = {l1,l2,l3,l4,l5,l6,l7,l8,l9};
    for(int i = 0; i < factory[index]->returnSize(); i++){
        if(factory[index]->findNode(i)->getTile()->getColour() == tile) {
            count++;
        }

    }
    return count;
    }

}

//returns the given number of tiles in a particular factory for 4 player
int Factory::getNumberTilesForFour(int index, char tile, int numOfCentreFactory){
   

    if(numOfCentreFactory==1){
    int count = 0;


    LinkedList* factory[10] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10};
    for(int i = 0; i < factory[index]->returnSize(); i++){
        if(factory[index]->findNode(i)->getTile()->getColour() == tile) {
            count++;
        }

    }
    return count;
    }
    else
    {
        int count = 0;
    LinkedList* factory[11] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11};
    for(int i = 0; i < factory[index]->returnSize(); i++){
        if(factory[index]->findNode(i)->getTile()->getColour() == tile) {
            count++;
        }

    }
    return count;
    }
    

}

//changes the empty tiles to '.'
void Factory::changeTiles(char tiles,int i, int numOfCentreFactory){
    int count = getNumberTiles(i,tiles,numOfCentreFactory);
    int newCount = 0;
    LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    if(factory[i]!=nullptr){
        for(int p=0; p<factory[i]->returnSize();p++){
            if(factory[i]->findNode(p)->getTile()->getColour() == tiles && newCount < count ){
                    factory[i]->findNode(p)->getTile()->setColour(notile);
                    newCount++;
            }
        }
    }
}

//checks for the firsplayer tile on the centre factory
bool Factory::firstPlayerTileExsists(int numOfCentreFactory, int factoryIndex, int numOfPlayer){

 LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
 if(factory[0]->returnSize()!=0){
    if(factoryIndex==0 && factory[0]->findNode(0)->getTile()->getColour() == 'F'){
        return true;
    }
    if(factoryIndex==1 && factory[1]->findNode(0)->getTile()->getColour()=='F'){
        return true;
    }
 }

    return false;
}

//returns the size of a factory
int Factory::getSize(int numOfCentreFactory, int numOfPlayers)
{
    if(numOfCentreFactory==1 && numOfPlayers==2){
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    for (int i = 0; i < 6; i++)
    {
        return factory[i]->returnSize();
    }
    }
    if(numOfCentreFactory==2 && numOfPlayers==2){
        LinkedList *factory[7] = {l1, l2, l3, l4, l5, l6, l7};
    for (int i = 0; i < 7; i++)
    {
        if(factory[i]->returnSize()!=0){
        return factory[i]->returnSize();
        }
        else
        {
            //check already made in mainGame
        }
        
    }
    }
    if(numOfCentreFactory==1 && numOfPlayers==3){
  LinkedList *factory[8] = {l1, l2, l3, l4, l5, l6, l7,l8};
    for (int i = 0; i < 8; i++)
    {
        if(factory[i]->returnSize()!=0){
        return factory[i]->returnSize();
        }
        else
        {
           // check already made in mainGame
        }
        
    }

    }
      if(numOfCentreFactory==2 && numOfPlayers==3){
  LinkedList *factory[9] = {l1, l2, l3, l4, l5, l6, l7,l8,l9};
    for (int i = 0; i < 9; i++)
    {
        if(factory[i]->returnSize()!=0){
        return factory[i]->returnSize();
        }
        else
        {
            //check already made in mainGame
        }
        
    }

    }

    if(numOfCentreFactory==1 && numOfPlayers==4){
        LinkedList* factory[10] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10};
        for (int i = 0; i < 10; i++)
    {
        if(factory[i]->returnSize()!=0){
        return factory[i]->returnSize();
        }
        else
        {
           // check already made in mainGame
        }
        
    }
    }
     if(numOfCentreFactory==2 && numOfPlayers==4){
        LinkedList* factory[11] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11};
        for (int i = 0; i < 11; i++)
    {
        if(factory[i]->returnSize()!=0){
        return factory[i]->returnSize();
        }
        else
        {
           // check already made in mainGame
        }
        
    }
    }

    return 0;
    
}

//prints the factory for two players
void Factory::print(int centreFactory)
{
    
    int sizeOfFactory = centreFactory-1;
    if(sizeOfFactory==0){
        LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    for (int p = 0; p < 6+sizeOfFactory; p++)
    {
        std::cout << p << ": ";
        factory[p]->printLine();
    }
    }
    else if(sizeOfFactory==1){
          LinkedList *factory[7] = {l1, l2, l3, l4, l5, l6, l7};
    for (int p = 0; p < 6+sizeOfFactory; p++)
    {
        std::cout << p << ": ";
        factory[p]->printLine();
    }
    }
    
}
// Return factory size for 3 players
int Factory::getSizeForThree()
{
    LinkedList *factory[8] = {l1, l2, l3, l4, l5, l6, l7,l8};
    for (int i = 0; i < 8; i++)
    {
        return factory[i]->returnSize();
    }
    return 0;
}


//print factory for 3 players
void Factory::printFactoryForThree(int centreFactory){
    int sizeofFactory = centreFactory -1;
    if(centreFactory==1){
    LinkedList* factory[8] = {l1,l2,l3,l4,l5,l6,l7,l8};
    for(int p=0; p<8+sizeofFactory; p++){
        std::cout<< p <<":";
        factory[p]->printLine();

    }
    }
    else {
         LinkedList* factory[9] = {l1,l2,l3,l4,l5,l6,l7,l8,l9};
    for(int p=0; p<8+sizeofFactory; p++){
        std::cout<< p <<":";
        factory[p]->printLine();

    }
    }

}

//Return factory size for 4 players
int Factory::getSizeForFour()
{
    LinkedList *factory[10] = {l1, l2, l3, l4, l5, l6, l7,l8,l9,l10};
    for (int i = 0; i < 10; i++)
    {
        return factory[i]->returnSize();
    }
    return 0;
}

//print factory for four players
void Factory::printFactoryForFour(int centreFactory){
    
    int sizeOfFactory = centreFactory-1;
    if(centreFactory==1){
    LinkedList* factory[10] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10};
    for(int p=0; p<10+sizeOfFactory; p++){
        std::cout<< p <<":";
        factory[p]->printLine();

    }
    }
    else if(centreFactory==2){
         LinkedList* factory[11] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11};
    for(int p=0; p<10+sizeOfFactory; p++){
        std::cout<< p <<":";
        factory[p]->printLine();

    }

    }
}


//stores the factories in a string and returns it
std::string Factory::returnAsString(int numOfPlayers, int numOfCentreFactory){

    if(numOfPlayers==2 && numOfCentreFactory==2){
         LinkedList *factory[7] = {l1, l2, l3, l4, l5, l6,l7};
    std::string factoryString = "";      
    for (int p = 0; p < 7; p++)
    {
        factoryString += factory[p]->returnAsString();
    }
    return factoryString;
    }
    if(numOfPlayers==3 && numOfCentreFactory==1){
         LinkedList *factory[8] = {l1, l2, l3, l4, l5, l6,l7,l8};
    std::string factoryString = "";      
    for (int p = 0; p < 8; p++)
    {
        factoryString += factory[p]->returnAsString();
    }
    return factoryString;
    }
    
    if(numOfPlayers==3 && numOfCentreFactory==2){
         LinkedList *factory[9] = {l1, l2, l3, l4, l5, l6,l7,l8,l9};
    std::string factoryString = "";      
    for (int p = 0; p < 9; p++)
    {
        factoryString += factory[p]->returnAsString();
    }
    return factoryString;
    }
    if(numOfPlayers==4 && numOfCentreFactory==1){
         LinkedList *factory[10] = {l1, l2, l3, l4, l5, l6,l7,l8,l9,l10};
    std::string factoryString = "";      
    for (int p = 0; p < 10; p++)
    {
        factoryString += factory[p]->returnAsString();
    }
    return factoryString;
    }
    if(numOfPlayers==4 && numOfCentreFactory==2){
         LinkedList *factory[11] = {l1, l2, l3, l4, l5, l6,l7,l8,l9,l10,l11};
    std::string factoryString = "";      
    for (int p = 0; p < 11; p++)
    {
        factoryString += factory[p]->returnAsString();
    }
    return factoryString;
    }
    else{
            LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    std::string factoryString = "";      
    for (int p = 0; p < 6; p++)
    {
        factoryString += factory[p]->returnAsString();
    }
    return factoryString;
    }
}


//checks for a element at particular index
void Factory::getElementAtIndex(Factory *fact, int index,Tiles* tile)
{
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    factory[index]->getElement(fact->getList(), index,tile);
}


//removes the tiles from the factories
void Factory::removeElement(int i, char colour, int numOfcentreFactory, int numOfPlayers){
  
    if(numOfcentreFactory==1 && numOfPlayers==2){
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    factory[i]->removeElement(colour);
    }
    if(numOfcentreFactory==2 && numOfPlayers==2){
        LinkedList *factorynew[7] = {l1,l2,l3,l4,l5,l6,l7};
        factorynew[i]->removeElement(colour);
    }
    if(numOfcentreFactory==1 && numOfPlayers==3){
         LinkedList *factorynew[8] = {l1,l2,l3,l4,l5,l6,l7,l8};
         factorynew[i]->removeElement(colour);
    } 
    if(numOfcentreFactory==2 && numOfPlayers==3){
        LinkedList *factorynew[9] = {l1,l2,l3,l4,l5,l6,l7,l8,l9};
         factorynew[i]->removeElement(colour);
    }
    if(numOfcentreFactory==1 && numOfPlayers ==4 ){
        LinkedList *factorynew[10] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10};
         factorynew[i]->removeElement(colour);
    }
    if(numOfcentreFactory==2 && numOfPlayers ==4 ){
        LinkedList *factorynew[11] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11};
         factorynew[i]->removeElement(colour);
    }
    else
    {
        /* code */
        //DO NOT WORRY ABOUT THIS -> NO OTHER TEST CASE POSSIBLE AS IMPOSSIBLE VALUES ALREADY CHECKED
    }
    
}

//completely empties the factory, delete all the tiles
void Factory::deleteAll(int i, int numOfCentreFactory){
    if(numOfCentreFactory==1){
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    factory[i]->deleteAll();
    }
    else{
        LinkedList *factory[7] = {l1, l2, l3, l4, l5, l6, l7};
        factory[i]->deleteAll();
    }
    
}

//Used to load the factory for different number of players and different centre factories
//six different cases
void Factory::loadFactoryFromFile(std::string *factoryStrings, int numOfPlayers, int numOfCentreFactory){
 
 if(numOfPlayers==2 && numOfCentreFactory==2){
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    l7 = new LinkedList();
    LinkedList* factory[7] = {l1,l2,l3,l4,l5,l6,l7};
     int x =7;
    addLoadedFactory(x,factoryStrings,factory);
   
 }

 if(numOfPlayers==3 && numOfCentreFactory==1){
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    l7 = new LinkedList();
    l8 = new LinkedList();
    LinkedList* factory[8] = {l1,l2,l3,l4,l5,l6,l7,l8};

    int x = 8;
    addLoadedFactory(x,factoryStrings,factory);
 }
  if(numOfPlayers==3 && numOfCentreFactory==2){
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    l7 = new LinkedList();
    l8 = new LinkedList();
    l9 = new LinkedList();
    LinkedList* factory[9] = {l1,l2,l3,l4,l5,l6,l7,l8,l9};
     int x = 9;
    addLoadedFactory(x,factoryStrings,factory);
 }
 if(numOfPlayers==4 && numOfCentreFactory==1){
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    l7 = new LinkedList();
    l8 = new LinkedList();
    l9 = new LinkedList();
    l10 = new LinkedList();
    LinkedList* factory[10] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10};
     int x = 10;
    addLoadedFactory(x,factoryStrings,factory);
    
 }
 if(numOfPlayers==4 && numOfCentreFactory==2){
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    l7 = new LinkedList();
    l8 = new LinkedList();
    l9 = new LinkedList();
    l10 = new LinkedList();
    l11 = new LinkedList();
    LinkedList* factory[11] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11};
    int x = 11;
    addLoadedFactory(x,factoryStrings,factory);
    
 }
 else{
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};;
    int x = 6;
    addLoadedFactory(x,factoryStrings,factory);

 }

}

//common function to load factories for different cases
void Factory::addLoadedFactory(int x, std::string *factoryStrings, LinkedList* newfactory[]){

    Tiles* t;
    for(int i = 0; i < x; i++) {
        cout<<factoryStrings[i];
        std::string line = factoryStrings[i];
        for(unsigned j = 0; j < line.length(); j++) {
            char tile = line.at(j);
            if(tile == 'F') {
                t = new Tiles(firstplayer);
                newfactory[i]->addNode(t);
            }

            else if(tile == 'R'){
                t = new Tiles(Red);
                newfactory[i]->addNode(t);
            }
            else if(tile == 'B'){
                t = new Tiles(DarkBlue);
                newfactory[i]->addNode(t);
            }
            else if(tile == 'Y'){
                t = new Tiles(Yellow);
                newfactory[i]->addNode(t);
            }
            else if(tile == 'U'){
                t = new Tiles(Black);
                newfactory[i]->addNode(t);
            }
            else if(tile == 'L'){
                t = new Tiles(LightBlue);
                newfactory[i]->addNode(t);
            }
            else if(tile== 'O'){
                t = new Tiles(Orange);
                newfactory[i]->addNode(t);
                
            }
        }
    }

}
   
//returns the total size of the factory
int Factory::getTotalSize(int numOfCentreFactory, int numOfPlayers){

    if(numOfCentreFactory==1 && numOfPlayers==2){
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    int totalSize = 0;
    for(int i = 0 ; i < 6; i++){
        if(factory[i] != NULL){
            totalSize += factory[i]->returnSize();
        }
       
    }
    return totalSize;
    }
    if(numOfCentreFactory==2 && numOfPlayers==2)
    {
        LinkedList *factory[7] = {l1, l2, l3, l4, l5, l6, l7};
    int totalSize = 0;
    for(int i = 0 ; i < 7; i++){
        if(factory[i] != NULL){
            totalSize += factory[i]->returnSize();
        }
       
    }
    return totalSize;
    }
    if(numOfCentreFactory==1 && numOfPlayers==3){
          LinkedList *factory[8] = {l1, l2, l3, l4, l5, l6, l7,l8};
    int totalSize = 0;
    for(int i = 0 ; i < 8; i++){
        if(factory[i] != NULL){
            totalSize += factory[i]->returnSize();
        }
       
    }
    return totalSize;
    }
    if(numOfCentreFactory==2 && numOfPlayers==3){
         LinkedList *factory[9] = {l1, l2, l3, l4, l5, l6, l7,l8,l9};
    int totalSize = 0;
    for(int i = 0 ; i < 9; i++){
        if(factory[i] != NULL){
            totalSize += factory[i]->returnSize();
        }
       
    }
    return totalSize;
    }
    if(numOfCentreFactory==1 && numOfPlayers==4){
         LinkedList *factory[10] = {l1, l2, l3, l4, l5, l6, l7,l8,l9,l10};
    int totalSize = 0;
    for(int i = 0 ; i < 10; i++){
        if(factory[i]!= NULL){
            totalSize += factory[i]->returnSize();
        }
       
    }
    return totalSize;
    }
    if(numOfCentreFactory==2 && numOfPlayers==4){
         LinkedList *factory[11] = {l1, l2, l3, l4, l5, l6, l7,l8,l9,l10,l11};
    int totalSize = 0;

    for(int i = 0 ; i < 11; i++){  
        if(factory[i] != NULL){
            factory[i]->printLine();
            totalSize += factory[i]->returnSize();
        }
          else
          {
              return 0;
          }
            
    }
    return totalSize;
    }
    else
    { 
    return 0;
    }
    
    
}



//returns the number of factories present for six different cases
int Factory::numOfFactories(int numOfPlayer, int numOfCentreFactories){
    int totalFactories = 0;
    if(numOfPlayer==2 && numOfCentreFactories==1){
       totalFactories=5;
    }
    else if(numOfPlayer==2 && numOfCentreFactories==2)
    {
        totalFactories=6;
    }
    else if(numOfPlayer==3 && numOfCentreFactories==1){
        totalFactories=7;
    }
     else if(numOfPlayer==3 && numOfCentreFactories==2){
        totalFactories=8;
    }
     else if(numOfPlayer==4 && numOfCentreFactories==1){
        totalFactories=9;
    }
     else if(numOfPlayer==4 && numOfCentreFactories==2){
        totalFactories=10;
    }
    return totalFactories;

}


