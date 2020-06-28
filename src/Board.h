#include<iostream>
#include<vector>
#include "Factory.h"
#include "Player.h"

using namespace std;

#define EMPTY ' '
#define BLOCK '.'
#define AREA '|'
class Board{


public:
Board(int numOfTiles);
~Board();
void makeBoard();

void printBoard();
const char** getBoard();
void addTileOnBoard(string val,string tile, string count);
int getEmptyRowSize(int val);
void addBrokenTile(int count, int value, char tile);

bool isEmpty();

void addTileOnSquareBoard(int val, char c);
//changes

bool addTileOnGreyBoard(int val, char c, int valColumn);
bool repeatingElements(int val,char c);
bool repeatingElementsVertically(int colVal, char c);

bool does_exist(const vector< vector<const char *> >&  v);
void addTile(int row,char value,int count);

std::string returnTriangleAsString();
std::string returnWallAsString();
void saveBroken(string filename);
bool checkTile(int val, char tile);
void loadBoard(std::string* triangle, std::string* wall, bool sixTile);

//changes
void removeTileFromBoard(Bag* tileBag);
std::fstream& GotoLine(std::fstream& file, unsigned int num);


void setSize(int size);
int getSize();
int checkTilesHorizontally(int x);
int checkTilesVertically(int y);
int checkTotaltiles();

bool checkTileInMosiac(int row,char tile);
bool checkForSimilarTiles(int val,int count);
void addPoints(Player* player,Board* board);
void saveLid(string fileName);


//changes
void placeTileAtLast(bool greyboard);

//changes
void printBoardForAllPlayers(int numofPlayers, int numOfTiles);

void printBoardRow(int i);
int getRowSize();
int getColumnSize();

void printColorBoard(bool greyBoard, bool sixTile);
void printColorBoardRow(int i,bool greyBoard, bool sixTile);
void printBoardForGrey(int k);

void printBoardMultiplayer(int k);
void printBoardSixTile(int k);
void printBrokenTiles();
int checkBoardForSameTile(char tile, int row);
int checkTileOnTriangle(char tile);
int countNumberOfEmpty();
void clearBroken();
private:

int size;
int row;
int column;

//char board[5][12];
//changes
char ** board;
std::vector<char> lid;
std::vector<char> broken;
// std::vector<std::vector<const char*>> newBoard = std::vector<std::vector<const char*>> (5,std::vector<const char*> (11,0));


};