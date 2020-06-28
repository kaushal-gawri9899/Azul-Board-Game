#include "Player.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <limits>


using namespace std;

Player::Player(string name, int points)
{
  this->name = name;
  this->points = points;
}

string Player::getName()
{
  return this->name;
}

void Player::setName(string name)
{
  this->name = name;
}

int Player::getPoints()
{
  return this->points;
}

void Player::setPoints(int points)
{
  this->points = points;
}

LinkedList Player::returnlist()
{
  return *list;
}

int Player::tilesinhand()
{
  return list->returnSize();
}



void Player::winner(Player* player1, Player* player2){
  if(player1->getPoints() > player2->getPoints() ){
    cout << "Player 1:  " << player1->getName() << " is the winner.";
  }
  else if(player1->getPoints() < player2->getPoints()){
    cout << "Player 2: " << player2->getName() << " is the winner.";
  }
}

void Player::updatePoints(int val){
  int currpoints =this->points -val;
  setPoints(currpoints);
} 

void Player::savePlayer(string filename){
  ofstream of;
  of.open(filename,ios::app|ios::out);
  of<<"#Player "<<'\n';
  of << name;
  of<<endl;
  of << points;
  of<<'\n';

}

std::fstream& Player::GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(unsigned i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}


void Player::loadName(string filename){
  fstream file(filename);
  GotoLine(file,6);
  string line;
  file>>line;
  setName(line);
}


void Player::loadName2(string filename){
  fstream file(filename);
  GotoLine(file,23);
  string line;
  file>>line;
  setName(line);

}

void Player::loadPoints1(string filename){
  fstream file(filename);
  GotoLine(file,7);
  int line;
  file>>line;
  setPoints(line);
}

void Player::loadPoints2(string filename){
  fstream file(filename);
  GotoLine(file,24);
  int line;
  file>>line;
  setPoints(line);

}

void Player::setFirstPlayer(int firstPlayer){
  this->firstPlayer = firstPlayer;
}

int Player::getFirstPlayer(){
  return this->firstPlayer;
}