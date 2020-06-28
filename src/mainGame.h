#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include <iostream>
#include "Board.h"




class mainGame {
public:
mainGame();
//For more than two players
void playGameUpdated(int numOfPlayers);
void validatePlayers(int numOfPlayers);
//changes
void makeNewTurnForPlayer(Player* player1, Player* player2, Player* player3, Player* player4, int numOfPlayers, int numOfCentreFactory, bool greyBoard, int numOfTiles);
void decideWinner(Player* player1, Player* player2, Player* player3, Player* player4, int numOfPlayers);

void countpoints(Player* player1, Board* board1);

int getCount();
int getPlayerNum();
void setPlayerNum(int playerNumber);
void saveGame(std::string filename, int numOfPlayers, int numOfcentreFactory,Player* currentPlayer);
//changes
void LoadGame(std::string filename,bool greyBoardValue, bool sixTileGame);
void playTheSixTileMode(int numOfPlayers, int numOfCentreFactory, int sixTileValue);
//changes
void playTheGreyBoardMode(int numOfPlayers,int numOfCentreFactory, Bag* tileBag, int greyBoardValue);
void makeFactoryFromBag(int numOfPlayers, int centreFactory, Bag* tileBag);
void makeBoardForPlayers(int numOfPlayers);
void playMultiPlayer(int numOfPlayers, int centreFactory, Bag* tileBag, int loadValue);
//changes
void endGameResult(Player* player1, Player* player2, Player* player3, Player* player4, int numOfPlayers);
//changes
void startGame(int numOfPLayers,int numOfCentreFactory, bool greyBoard, int numOfTiles);
void load(string filename, int numOfPlayers, int centreFactory);
void helpMenu(int numOfPlayers, int numOfCentreFactory, int numOfTiles);
bool getGreyBoardValue();
bool getsixTileValue();

void printBoardForAllPlayer(int numOfTiles, int numOfPlayers, Board* board[], Player* player[]);
private:
int row;
std::string colour;
int count;
int playerNumber;
Factory* factory;
std::string player1Name;
int player1Scores;
std::string player2Name;
int player2Scores;

//For 3 Players
std::string player3Name;
int player3Scores;
Board* board3;

//For 4 Players
std::string player4Name;
int player4Scores;
Board* board4;

Bag* tileBag;
Board* board1;
Board* board2;
bool boardsLoaded;

bool sixTileMode;
bool greyBoardMode;

bool playTurn=false;


};

#endif 
