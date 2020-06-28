#include <iostream>
#include <stdio.h>
#include <vector>
#include "Board.h"

#include <bits/stdc++.h>
using namespace std;

//This is a constructor responsible for dynamically allocating the memory for board
Board::Board(int numOfTiles)
{
    if (numOfTiles == 6)
    {
        this->row = 6;
        this->column = 14;
        board = new char *[row];
        for (int i = 0; i < row; i++)
        {
            board[i] = new char[column];
        }
    }
    else
    {
        this->row = 5;
        this->column = 12;
        board = new char *[row];
        for (int i = 0; i < row; i++)
        {
            board[i] = new char[column];
        }
    }
}
Board::~Board()
{
}

//making a board dynamically using 2d char array
void Board::makeBoard()
{

    int val = row - 2;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (j < (column - 1) / 2)
            {
                if (j <= val - i)
                {
                    board[i][j] = EMPTY;
                }
                else
                {
                    board[i][j] = BLOCK;
                }
            }
            else
            {
                if (j >= 6 && j <= 7 && row == 6 && column == 14)
                {
                    board[i][j] = AREA;
                }
                else if (j >= 5 && j <= 6 && row == 5 && column == 12)
                {
                    board[i][j] = AREA;
                }
                else
                {
                    board[i][j] = BLOCK;
                }
            }
        }
    }
}

//It print the board with colored tiles
void Board::printBoard()
{

    //changed
    for (int i = 0; i < row; i++)
    {
        std::cout << i + 1 << ": ";
        for (int j = 0; j < column; j++)
        {
            if (board[i][j] == 'R')
            {
                std::cout << "\033[1m\033[31m" << board[i][j] << "\033[0m";
            }
            else if (board[i][j] == 'Y')
            {
                std::cout << "\033[1m\033[33m" << board[i][j] << "\033[0m";
            }
            else if (board[i][j] == 'U')
            {
                std::cout << "\033[1m\033[35m" << board[i][j] << "\033[0m";
            }
            else if (board[i][j] == 'L')
            {
                std::cout << "\033[1m\033[36m" << board[i][j] << "\033[0m";
            }
            else if (board[i][j] == 'B')
            {
                std::cout << "\033[1m\033[34m" << board[i][j] << "\033[0m";
            }
            else if (board[i][j] == 'O')
            {
                std::cout << "\033[1m\033[32m" << board[i][j] << "\033[0m";
            }
            else if (board[i][j] == 'F')
            {
                std::cout << "\033[1m\033[37m" << board[i][j] << "\033[0m";
            }
            else
            {
                std::cout << board[i][j];
            }
        }
        std::cout << std::endl;
    }
}

//This returns the count of empty spaces in a particular row(i.e, returns number of '.')
int Board::getEmptyRowSize(int val)
{

    //changed
    int value = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {

            if (i == val && board[i][j] == '.' && j < (column - 1) / 2)
            {
                value += 1;
            }
        }
    }
    return value;
}

//This function checks if already a tile is placed or if a row is completed and validates the user input
int Board::checkBoardForSameTile(char tile, int row)
{

    // int flag =0;
    if (this->column == 12)
    {
        int count = 0;
        for (int j = 0; j < (column - 1) / 2; j++)
        {
            if (board[row][j] == tile || (board[row][j] == '.' && board[row][j - 1] == ' ' && j - 1 >= 0) || (board[row][j] == '.' && board[row][j - 1] == '.' && board[row][j - 2] == ' ' && j - 2 >= 0) || (board[row][j] == '.' && board[row][j - 1] == '.' && board[row][j - 2] == '.' && board[row][j - 3] == ' ' && j - 3 >= 0) || (board[row][j] == '.' && board[row][j - 1] == '.' && board[row][j - 2] == '.' && board[row][j - 3] == '.' && board[row][j - 4] == ' ' && j - 4 >= 0) || (board[4][0] == '.'))
            {
                count += 1;
            }
        }
        if (checkTileOnTriangle(tile) == 0 && countNumberOfEmpty() == 10)
        {
            int flag = 1;
            addBrokenTile(2, 1, tile);
            return flag;
        }
        return count;
    }
    else
    {
        int count = 0;
        for (int j = 0; j < (column - 1) / 2; j++)
        {
            if (board[row][j] == tile || (board[row][j] == '.' && board[row][j - 1] == ' ' && j - 1 >= 0) || (board[row][j] == '.' && board[row][j - 1] == '.' && board[row][j - 2] == ' ' && j - 2 >= 0) || (board[row][j] == '.' && board[row][j - 1] == '.' && board[row][j - 2] == '.' && board[row][j - 3] == ' ' && j - 3 >= 0) || (board[row][j] == '.' && board[row][j - 1] == '.' && board[row][j - 2] == '.' && board[row][j - 3] == '.' && board[row][j - 4] == ' ' && j - 4 >= 0) || (board[row][j] == '.' && board[row][j - 1] == '.' && board[row][j - 2] == '.' && board[row][j - 3] == '.' && board[row][j - 4] == '.' && board[row][j - 5] == ' ' && j - 5 >= 0) || (board[5][0] == '.'))
            {
                count += 1;
            }
        }
        //changes
        if (checkTileOnTriangle(tile) == 0 && countNumberOfEmpty() == 15)
        {
            int flag = 1;
            addBrokenTile(2, 1, tile);
            return flag;
        }
        return count;
    }
}

//this board checks for a particular tile on the triangular area of the board
int Board::checkTileOnTriangle(char tile)
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < (column - 1) / 2; j++)
        {
            if (board[i][j] == tile && getEmptyRowSize(i) != 0)
            {
                count += 1;
                //return true;
            }
        }
    }
    //return false;
    return count;
}

//this function checks for the number of tiles already present on the traingular board
int Board::countNumberOfEmpty()
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < (column - 1) / 2; j++)
        {
            if (board[i][j] != '.' && board[i][j - 1] == ' ' && j - 1 >= 0)
            {
                count += 1;
            }
        }
    }
    //cout<<"Count is"<<count;
    return count;
}

//this functions add the broken tiles to the floor
void Board::addBrokenTile(int count, int value, char tile)
{

    if (count > value)
    {
        if (this->column == 12)
        {
            if (broken.size() < 8)
            {
                //for(int i=0; i<count-value; i++){
                for (int i = 0; i < count - value; i++)
                {
                    if (broken.size() < 8)
                    {
                        broken.push_back(tile);
                    }
                    else
                    {
                        for (unsigned i = 0; i < lid.size(); i++)
                        {
                            lid.push_back(tile);
                        }
                    }
                }

                cout << "broken:";
                for (unsigned i = 0; i < broken.size(); i++)
                {
                    cout << broken[i] << " ";
                }
                cout << "Size of broken" << broken.size();
                cout << endl;
            }
            else
            {
                for (unsigned i = 0; i < lid.size(); i++)
                {
                    lid.push_back(tile);
                }
            }
        }
        else
        {
            if (broken.size() < 9)
            {
                for (int i = 0; i < count - value; i++)
                {
                    if (broken.size() < 9)
                    {
                        broken.push_back(tile);
                    }
                    else
                    {
                        for (unsigned i = 0; i < lid.size(); i++)
                        {
                            lid.push_back(tile);
                        }
                    }
                }

                cout << "broken:";
                for (unsigned i = 0; i < broken.size(); i++)
                {
                    cout << broken[i] << " ";
                }

                cout << endl;
            }
            else
            {
                for (unsigned i = 0; i < lid.size(); i++)
                {
                    lid.push_back(tile);
                }
            }
        }
    }

    else
    {
        cout << "broken:";
        for (unsigned i = 0; i < broken.size(); i++)
        {
            cout << broken[i] << " ";
        }
        cout << endl;
    }
}

//it is resposnible for clearing the broken tiles after each round
void Board::clearBroken()
{
    this->broken.clear();
}

//used to save the floor tiles on the .txt file
void Board::saveBroken(string fileName)
{

    ofstream of;
    of.open(fileName, ios::app);
    for (unsigned int i = 0; i < broken.size(); i++)
    {
        of << broken[i];
    }
    of << "\n";
    of.close();
}

bool Board::isEmpty()
{

    //changed
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (board[i][j] == '.')
            {
                return true;
            }
        }
    }
    return false;
}

bool Board::does_exist(const vector<vector<const char *>> &v)
{

    vector<vector<const char *>>::const_iterator row;
    for (row = v.begin(); row != v.end(); row++)
    {
        if (find(row->begin(), row->end(), ".") != row->end())
        {
            return true;
        }
    }
    return false;
}

bool Board::checkTileInMosiac(int rowValue, char tile)
{
    //changed
    int size = 13;
    int newJ = (size + 1) / 2;

    for (int i = 0; i < row; i++)
    {
        for (int j = newJ; j < column; j++)
        {
            if (i == rowValue)
            {
                if (board[rowValue][j] == tile)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

//This function is responsible for adding tiles on the triangular area of board
//checks for similar tiles and only add them
void Board::addTile(int rowValue, char value, int count)
{

    int flag = 0;
    char sandwich = '.';
    int val = getEmptyRowSize(rowValue);

    if (checkTileInMosiac(rowValue, value) == true)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < (column - 1) / 2; j++)
            {
                if (i == rowValue)
                {
                    if (board[i][j] == sandwich && flag < count)
                    {
                        board[i][j] = value;
                        flag = flag + 1;
                    }
                }
            }
        }
    }
    checkForSimilarTiles(rowValue, count);
    // printBoard();

    addBrokenTile(count, val, value);
    cout << endl;
}

void Board::setSize(int size)
{
    this->size = size;
}
int Board::getSize()
{
    return broken.size();
}

//changes
// This function is used to place the tile on the mosaic
// If grey Board, asks the input from user
// Else place it automatically
void Board::placeTileAtLast(bool greyBoard)
{

    //changes 2
    if (greyBoard == false)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (checkForSimilarTiles(i, 1) == false || getEmptyRowSize(i) == 0)
                {
                    addTileOnSquareBoard(i, board[i][j]);
                }
            }
        }
    }
    else
    {
        int valColumn;

        for (int i = 0; i < row; i++)
        {

            if (checkForSimilarTiles(i, 1) == false || getEmptyRowSize(i) == 0)
            {
                if (getEmptyRowSize(i) == 0)
                {
                    cout << "On which column would you like to place your tile at row " << i + 1 << "where tile is " << board[i][4] << " of board \n";
                    cout << "column>=7 & column<=11 \n";
                    cout << ">";
                    cin >> valColumn;
                    while (valColumn > 11 || valColumn < 7)
                    {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout << "On which column would you like to place your tile at row " << i + 1 << " of board \n";
                        cout << "column>=7 & column<=11 \n";
                        cout << ">";
                        cin >> valColumn;
                    }
                }
                for (int j = 0; j < column; j++)
                {
                    addTileOnGreyBoard(i, board[i][j], valColumn);
                }
            }
        }
    }
}

//Used to add tile on mosaic in an automated way
void Board::addTileOnSquareBoard(int val, char c)
{

    int res;
    res = getEmptyRowSize(val);

    char jam = '|';
    if (this->row == 5 && this->column == 12)
    {
        if (res == 0)
        {
            // int size =12;
            for (int i = 0; i < row; i++)
            {
                for (int j = (column - 1) / 2; j < 12; j++)
                {
                    if (board[i][j] != jam)
                    {
                        if (val + 7 == j && c == 'B' && val + 7 < 12)
                        {
                            board[val][j] = DarkBlue;
                        }
                        else if (val + 8 == j && c == 'Y' && val + 8 < 12)
                        {
                            board[val][j] = Yellow;
                        }
                        else if ((val + 9 == j && c == 'R' && val + 9 < 12))
                        {
                            board[val][j] = Red;
                        }
                        else if ((val + 10 == j && c == 'U' && val + 10 < 12))
                        {
                            board[val][j] = Black;
                        }
                        else if ((val + 11 == j && c == 'L' && val + 11 < 12))
                        {
                            board[val][j] = LightBlue;
                        }
                        else if ((j - val) == 3 && c == 'Y')
                        {
                            board[val][j] = Yellow;
                        }
                        else if ((j - val) == 4 && c == 'R')
                        {
                            board[val][j] = Red;
                        }
                        else if ((j - val) == 5 && c == 'U')
                        {
                            board[val][j] = Black;
                        }
                        else if ((j - val) == 6 && c == 'L')
                        {
                            board[val][j] = LightBlue;
                        }
                    }
                }
            }
        }
    }

    else
    {
        if (res == 0)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = (column - 1) / 2; j < column; j++)
                {
                    if (board[i][j] != jam)
                    {
                        if (val + 8 == j && c == 'B' && val + 8 < column)
                        {
                            board[val][j] = DarkBlue;
                        }
                        else if (val + 9 == j && c == 'Y' && val + 8 < column)
                        {
                            board[val][j] = Yellow;
                        }
                        else if ((val + 10 == j && c == 'R' && val + 9 < column))
                        {
                            board[val][j] = Red;
                        }
                        else if ((val + 11 == j && c == 'U' && val + 10 < column))
                        {
                            board[val][j] = Black;
                        }
                        else if ((val + 12 == j && c == 'L' && val + 11 < column))
                        {
                            board[val][j] = LightBlue;
                        }
                        else if ((val + 13 == j && c == 'O' && val + 13 < 12))
                        {
                            board[val][j] = Orange;
                        }
                        else if ((j - val) == 3 && c == 'Y')
                        {
                            board[val][j] = Yellow;
                        }
                        else if ((j - val) == 4 && c == 'R')
                        {
                            board[val][j] = Red;
                        }
                        else if ((j - val) == 5 && c == 'U')
                        {
                            board[val][j] = Black;
                        }
                        else if ((j - val) == 6 && c == 'L')
                        {
                            board[val][j] = LightBlue;
                        }
                        else if ((j - val) == 7 && c == 'O')
                        {
                            board[val][j] = Orange;
                        }
                    }
                }
            }
        }
    }
}

//Used to add tiles on grey board depending upon user input
bool Board::addTileOnGreyBoard(int val, char c, int valColumn)
{

    //changes
    int res = getEmptyRowSize(val);
    char sandwich = '.';
    if (res == 0)
    {
        if (board[val][valColumn] == sandwich)
        {
            if ((repeatingElements(val, c) == false) && (repeatingElementsVertically(valColumn, c) == false))
            {
                if (c == 'B')
                {
                    board[val][valColumn] = DarkBlue;
                }
                else if (c == 'U')
                {
                    board[val][valColumn] = Black;
                }
                else if (c == 'Y')
                {
                    board[val][valColumn] = Yellow;
                }
                else if (c == 'L')
                {
                    board[val][valColumn] = LightBlue;
                }
                else if (c == 'R')
                {
                    board[val][valColumn] = Red;
                }
                return true;
            }
            return false;
        }
    }
    return false;
}

//Checks for repeating elements in a particular row
//used for grey board
bool Board::repeatingElements(int val, char c)
{

    for (int j = (column - 1) / 2; j < column; j++)
    {
        if (board[val][j] == c)
        {
            return true;
        }
    }
    return false;
}

//checks for repeating elements in a particular column
//used for grey board
bool Board::repeatingElementsVertically(int colVal, char c)
{

    for (int i = 0; i < row; i++)
    {
        if (board[i][colVal] == c)
        {
            return true;
        }
    }
    return false;
}

//used to remove tiles from the board after the end of the round
//the tiles are placed at the box lid after they are removed
//The box lid is used to refil the bag
void Board::removeTileFromBoard(Bag *tileBag)
{

    //changes
    char sandwich = '.';
    char jam = ' ';

    for (int i = 0; i < row; i++)
    {
        if (getEmptyRowSize(i) == 0)
        {
            for (int j = 0; j < row; j++)
            {

                if (board[i][j] != jam)
                {
                    lid.push_back(board[i][j]);
                    board[i][j] = sandwich;
                }
            }
        }
    }
    for (unsigned i = 0; i < lid.size(); i++)
    {
        Tiles *t = nullptr;
        if (lid.at(i) == 'R')
        {
            t = new Tiles(Red);
            tileBag->getList()->addNode(t);
        }
        if (lid.at(i) == 'B')
        {
            t = new Tiles(DarkBlue);
            tileBag->getList()->addNode(t);
        }
        if (lid.at(i) == 'Y')
        {
            t = new Tiles(Yellow);
            tileBag->getList()->addNode(t);
        }
        if (lid.at(i) == 'L')
        {
            t = new Tiles(LightBlue);
            tileBag->getList()->addNode(t);
        }
        if (lid.at(i) == 'U')
        {
            t = new Tiles(Black);
            tileBag->getList()->addNode(t);
        }
        if (lid.at(i) == 'O')
        {
            t = new Tiles(Orange);
            tileBag->getList()->addNode(t);
        }
    }
    //No need to display the lid to the user
    // cout<<"Box Lid contains: ";
    // for(unsigned i = 0; i<lid.size(); i++){
    //     cout<<lid.at(i);
    // }

    lid.clear();
    //clearBroken();
    cout << endl;
}

//Checks for the similar tiles present on the board while placing tiles
bool Board::checkForSimilarTiles(int val, int count)
{
    char jam = '.';
    int flag = 0;
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (i == val)
            {
                if ((board[val][j] != board[val][j - 1] && board[val][j] != '|' && board[val][j - 1] != ' ' && j - 1 >= 0) || (board[val][j] != board[val][j - 2] && board[val][j] != '|' && board[val][j - 2] != ' ' && j - 2 >= 0) || (board[val][j] != board[val][j - 3] && board[val][j] != '|' && board[val][j - 3] != ' ' && j - 3 >= 0) || ((board[val][j] != board[val][j - 4] && board[val][j] != '|' && board[val][j - 4] != ' ' && j - 4 >= 0)))
                {
                    board[val][j] = jam;
                    flag += 1;
                    return false;
                }
            }
        }
    }
    return true;
}

void Board::addPoints(Player *player, Board *board)
{
    int points1 = 0;

    for (int i = 0; i < 5; i++)
    {
        if (board->checkTilesHorizontally(i) != 5 || board->checkTilesVertically(i) != 5)
        {

            points1 = board->checkTotaltiles();
        }
        if (board->checkTilesVertically(i) == 5)
        {
            points1 = 7;
        }
        if (board->checkTilesHorizontally(i) == 5)
        {
            points1 = 5;
        }
    }

    cout << endl;
    cout << "Points: " << points1 << endl;
    player->setPoints(player->getPoints() + points1);
}

bool Board::checkTile(int val, char tile)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < (column - 1) / 2; j++)
        {
            if (i == val)
            {
                if (board[val][j] == tile)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

//Saves the lid to the txt file
void Board::saveLid(string fileName)
{

    ofstream of;
    of.open(fileName, ios::app);
    of << "Lid" << '\n';
    for (unsigned int i = 0; i < lid.size(); i++)
    {
        of << lid[i];
    }
    of << "\n";
    of.close();
}

//Stores the traingle as a string to be saved on .txtfile
std::string Board::returnTriangleAsString()
{

    if (this->row == 6 && this->column == 14)
    {
        std::string boardString = "";

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                boardString += board[i][j];
                boardString += " ";
            }

            boardString += "\n";
        }

        return boardString;
    }
    else
    {
        std::string boardString = "";

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                boardString += board[i][j];
                boardString += " ";
            }

            boardString += "\n";
        }

        return boardString;
    }
}

//returns the mosaic as string to be stored on .txt file
std::string Board::returnWallAsString()
{

    if (row == 6 && column == 14)
    {
        std::string boardString = "";

        for (int i = 0; i < row; i++)
        {
            for (int j = 8; j < column; j++)
            {
                boardString += board[i][j];
                boardString += " ";
            }

            boardString += "\n";
        }

        return boardString;
    }
    else
    {
        std::string boardString = "";

        for (int i = 0; i < 5; i++)
        {
            for (int j = 7; j < 12; j++)
            {
                boardString += board[i][j];
                boardString += " ";
            }

            boardString += "\n";
        }

        return boardString;
    }
}

//Loads the dynamic board with different number of cases possible
void Board::loadBoard(std::string *triangle, std::string *wall, bool sixTile)
{
    //changed as required
    if (sixTile == false)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 14; j += 2)
            {
                char c = triangle[i].at(j);
                board[i][j / 2] = c;
            }
        }

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 10; j += 2)
            {
                char c = wall[i].at(j);
                board[i][j / 2 + 7] = c;
            }
        }
    }
    else
    {

        for (int i = 0; i < 6; i++)
        {
            //changed it to <16 form <20 and <18(initially)
            for (int j = 0; j < 16; j += 2)
            {
                char c = triangle[i].at(j);
                board[i][j / 2] = c;
            }
        }
        //changed i<5 to i<6
        for (int i = 0; i < 6; i++)
        {
            //changes j<14 to j<12
            //changed j<0 from j<2
            for (int j = 0; j < 12; j += 2)
            {
                char c = wall[i].at(j);
                board[i][(j + 2) / 2 + 7] = c;
            }
        }
    }
}

std::fstream &Board::GotoLine(std::fstream &file, unsigned int num)
{
    file.seekg(std::ios::beg);
    for (unsigned i = 0; i < num - 1; ++i)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

//checks for adjacent tiles in a row
int Board::checkTilesHorizontally(int x)
{
    int size = 13;
    int count = 0;
    for (int j = (size + 1) / 2; j < column; j++)
    {
        if (board[x][j] != '.' && board[x][j + 1] != '.' && j + 1 < column)
        {
            count += 1;
        }
    }

    if (count == 0)
        return 0;
    else
        return count + 1;
}

//checks for adjacent tiles in a column
int Board::checkTilesVertically(int y)
{

    int count = 0;
    //test it thoroughly
    for (int i = 0; i < row - 1; i++)
    {
        if (board[i][y] != '.' && board[i + 1][y] != '.' && i + 1 < row)
        {
            count += 1;
        }
    }
    if (count == 0)
    {
        return 0;
    }
    return count + 1;
}

//check total number of tiles in the mosiac
int Board::checkTotaltiles()
{
    if (this->row == 5 && this->column == 12)
    {
        int size = 13;
        int newJ = (size + 1) / 2;
        int rows = 5;
        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = newJ; j < 12; j++)
            {
                if (board[i][j] != '.')
                {
                    count++;
                }
            }
        }
        if (count == 0)
        {
            return 0;
        }
        else
        {
            return count;
        }
    }
    else
    {
        int size = 15;
        int newJ = (size + 1) / 2;
        int rows = 6;
        int count = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = newJ; j < 14; j++)
            {
                if (board[i][j] != '.')
                {
                    count++;
                }
            }
        }
        if (count == 0)
        {
            return 0;
        }
        else
        {
            return count;
        }
    }
}

//Prints the colored text for a particular row of a board
void Board::printBoardRow(int i)
{

    for (int j = 0; j < column; j++)
    {
        if (board[i][j] == 'R')
        {
            std::cout << "\033[1m\033[31m" << board[i][j] << "\033[0m";
        }
        else if (board[i][j] == 'Y')
        {
            std::cout << "\033[1m\033[33m" << board[i][j] << "\033[0m";
        }
        else if (board[i][j] == 'U')
        {
            std::cout << "\033[1m\033[35m" << board[i][j] << "\033[0m";
        }
        else if (board[i][j] == 'L')
        {
            std::cout << "\033[1m\033[36m" << board[i][j] << "\033[0m";
        }
        else if (board[i][j] == 'B')
        {
            std::cout << "\033[1m\033[34m" << board[i][j] << "\033[0m";
        }
        else if (board[i][j] == 'O')
        {
            std::cout << "\033[1m\033[32m" << board[i][j] << "\033[0m";
        }
        else if (board[i][j] == 'F')
        {
            std::cout << "\033[1m\033[37m" << board[i][j] << "\033[0m";
        }
        else
        {
            std::cout << board[i][j];
        }
    }
    cout << "  \t      \t";
}

//prints the colored text for a row of a board
//different test cases used
void Board::printColorBoardRow(int i, bool greyBoard, bool sixTile)
{

    if (greyBoard == false and sixTile == false)
    {
        printBoardMultiplayer(i);
    }
    else if (greyBoard == false and sixTile == true)
    {
        printBoardSixTile(i);
    }
    else
    {
        printBoardForGrey(i);
    }
    cout << "  \t      \t";
}

//returns the number of rows in the board
int Board::getRowSize()
{
    return this->row;
}

//returns the number of columns in the board
int Board::getColumnSize()
{
    return this->column;
}

//print the colored mosiac depending upon different cases
void Board::printColorBoard(bool greyBoard, bool sixTile)
{
    if (greyBoard == false && sixTile == false)
    {
        printBoardMultiplayer(-1);
    }

    else if (greyBoard == false && sixTile == true)
    {

        printBoardSixTile(-1);
    }

    else
    {
        printBoardForGrey(-1);
    }
    cout << std::endl;
    printBrokenTiles();
    cout << std::endl;
}

//prints the broken tile to the terminal
void Board::printBrokenTiles()
{

    cout << "broken:";
    for (unsigned i = 0; i < broken.size(); i++)
    {
        cout << broken[i] << " ";
    }
}

//prints the colored grey board
void Board::printBoardForGrey(int k)
{
    if (k == -1)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (j >= (column + 2) / 2)
                {
                    if (board[i][j] == '.')
                    {
                        std::cout << "\033[1m\033[47m"
                                  << "\033[1m\033[30m"
                                  << "[" << board[i][j] << "]"
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'R')
                    {
                        std::cout << "\033[1m\033[31m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'Y')
                    {
                        std::cout << "\033[1m\033[33m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'U')
                    {
                        std::cout << "\033[1m\033[35m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'L')
                    {
                        std::cout << "\033[1m\033[36m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'B')
                    {
                        std::cout << "\033[1m\033[34m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'O')
                    {
                        std::cout << "\033[1m\033[32m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'F')
                    {
                        std::cout << "\033[1m\033[37m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else
                    {
                    }
                }
                else
                {

                    if (board[i][j] == 'R')
                    {
                        std::cout << "\033[1m\033[31m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'Y')
                    {
                        std::cout << "\033[1m\033[33m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'U')
                    {
                        std::cout << "\033[1m\033[35m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'L')
                    {
                        std::cout << "\033[1m\033[36m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'B')
                    {
                        std::cout << "\033[1m\033[34m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'O')
                    {
                        std::cout << "\033[1m\033[32m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'F')
                    {
                        std::cout << "\033[1m\033[37m" << board[i][j] << "\033[0m";
                    }
                    else
                    {
                        std::cout << board[i][j];
                    }
                }
            }
            std::cout << std::endl;
        }
    }
    else
    {
        for (int j = 0; j < column; j++)
        {
            if (j >= (column + 2) / 2)
            {
                if (board[k][j] == '.')
                {
                    std::cout << "\033[1m\033[47m"
                              << "\033[1m\033[30m"
                              << "[" << board[k][j] << "]"
                              << "\033[0m";
                }
                else if (board[k][j] == 'R')
                {
                    std::cout << "\033[1m\033[31m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'Y')
                {
                    std::cout << "\033[1m\033[33m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'U')
                {
                    std::cout << "\033[1m\033[35m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'L')
                {
                    std::cout << "\033[1m\033[36m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'B')
                {
                    std::cout << "\033[1m\033[34m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'O')
                {
                    std::cout << "\033[1m\033[32m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'F')
                {
                    std::cout << "\033[1m\033[37m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else
                {
                }
            }
            else
            {

                if (board[k][j] == 'R')
                {
                    std::cout << "\033[1m\033[31m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'Y')
                {
                    std::cout << "\033[1m\033[33m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'U')
                {
                    std::cout << "\033[1m\033[35m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'L')
                {
                    std::cout << "\033[1m\033[36m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'B')
                {
                    std::cout << "\033[1m\033[34m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'O')
                {
                    std::cout << "\033[1m\033[32m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'F')
                {
                    std::cout << "\033[1m\033[37m" << board[k][j] << "\033[0m";
                }
                else
                {
                    std::cout << board[k][j];
                }
            }
        }
    }
}

//prints the colored board for the multiplayer mode
void Board::printBoardMultiplayer(int k)
{
    if (k == -1)
    {
        for (int i = 0; i < row; i++)
        {
            std::cout << i + 1 << ": ";
            for (int j = 0; j < column; j++)
            {
                if (j >= (column + 2) / 2)
                {
                    if (board[i][j] == '.')
                    {
                        if (i + 7 == j && i + 7 < 12)
                        {
                            //board[val][j] = DarkBlue;
                            cout << "\033[1m\033[34m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if (i + 8 == j && i + 8 < 12)
                        {
                            //board[val][j] = Yellow;
                            cout << "\033[1m\033[33m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((i + 9 == j && i + 9 < 12))
                        {
                            //board[val][j] = Red;
                            cout << "\033[1m\033[31m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((i + 10 == j && i + 10 < 12))
                        {
                            //board[val][j] = Black;
                            cout << "\033[1m\033[35m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((i + 11 == j && i + 11 < 12))
                        {
                            // board[val][j] = LightBlue;
                            cout << "\033[1m\033[36m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((j - i) == 3)
                        {
                            // board[val][j] = Yellow;
                            cout << "\033[1m\033[33m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((j - i) == 4)
                        {
                            // board[val][j] = Red;
                            cout << "\033[1m\033[31m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((j - i) == 5)
                        {
                            // board[val][j] = Black;
                            cout << "\033[1m\033[35m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((j - i) == 6)
                        {
                            //board[val][j] = LightBlue;
                            cout << "\033[1m\033[36m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                    }

                    else if (board[i][j] == 'R')
                    {
                        std::cout << "\033[1m\033[31m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'Y')
                    {
                        std::cout << "\033[1m\033[33m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'U')
                    {
                        std::cout << "\033[1m\033[35m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'L')
                    {
                        std::cout << "\033[1m\033[36m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'B')
                    {
                        std::cout << "\033[1m\033[34m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'O')
                    {
                        std::cout << "\033[1m\033[32m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'F')
                    {
                        std::cout << "\033[1m\033[37m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else
                    {
                    }
                }
                else
                {

                    if (board[i][j] == 'R')
                    {
                        std::cout << "\033[1m\033[31m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'Y')
                    {
                        std::cout << "\033[1m\033[33m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'U')
                    {
                        std::cout << "\033[1m\033[35m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'L')
                    {
                        std::cout << "\033[1m\033[36m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'B')
                    {
                        std::cout << "\033[1m\033[34m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'O')
                    {
                        std::cout << "\033[1m\033[32m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'F')
                    {
                        std::cout << "\033[1m\033[37m" << board[i][j] << "\033[0m";
                    }
                    else
                    {
                        std::cout << board[i][j];
                    }
                }
            }
            std::cout << std::endl;
        }
    }
    else
    {
        for (int j = 0; j < column; j++)
        {
            if (j >= (column + 2) / 2)
            {
                if (board[k][j] == '.')
                {
                    if (k + 7 == j && k + 7 < 12)
                    {
                        //board[val][j] = DarkBlue;
                        cout << "\033[1m\033[34m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if (k + 8 == j && k + 8 < 12)
                    {
                        //board[val][j] = Yellow;
                        cout << "\033[1m\033[33m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((k + 9 == j && k + 9 < 12))
                    {
                        //board[val][j] = Red;
                        cout << "\033[1m\033[31m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((k + 10 == j && k + 10 < 12))
                    {
                        //board[val][j] = Black;
                        cout << "\033[1m\033[35m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((k + 11 == j && k + 11 < 12))
                    {
                        // board[val][j] = LightBlue;
                        cout << "\033[1m\033[36m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((j - k) == 3)
                    {
                        // board[val][j] = Yellow;
                        cout << "\033[1m\033[33m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((j - k) == 4)
                    {
                        // board[val][j] = Red;
                        cout << "\033[1m\033[31m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((j - k) == 5)
                    {
                        // board[val][j] = Black;
                        cout << "\033[1m\033[35m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((j - k) == 6)
                    {
                        //board[val][j] = LightBlue;
                        cout << "\033[1m\033[36m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                }

                else if (board[k][j] == 'R')
                {
                    std::cout << "\033[1m\033[31m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'Y')
                {
                    std::cout << "\033[1m\033[33m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'U')
                {
                    std::cout << "\033[1m\033[35m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'L')
                {
                    std::cout << "\033[1m\033[36m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'B')
                {
                    std::cout << "\033[1m\033[34m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'O')
                {
                    std::cout << "\033[1m\033[32m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'F')
                {
                    std::cout << "\033[1m\033[37m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else
                {
                }
            }
            else
            {

                if (board[k][j] == 'R')
                {
                    std::cout << "\033[1m\033[31m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'Y')
                {
                    std::cout << "\033[1m\033[33m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'U')
                {
                    std::cout << "\033[1m\033[35m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'L')
                {
                    std::cout << "\033[1m\033[36m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'B')
                {
                    std::cout << "\033[1m\033[34m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'O')
                {
                    std::cout << "\033[1m\033[32m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'F')
                {
                    std::cout << "\033[1m\033[37m" << board[k][j] << "\033[0m";
                }
                else
                {
                    std::cout << board[k][j];
                }
            }
        }
    }
}

//prints the colored board for the six tile mode
void Board::printBoardSixTile(int k)
{
    if (k == -1)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (j >= (column + 2) / 2)
                {
                    if (board[i][j] == '.')
                    {
                        if (i + 8 == j && i + 8 < 14)
                        {
                            //board[val][j] = DarkBlue;
                            cout << "\033[1m\033[34m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if (i + 9 == j && i + 9 < 14)
                        {
                            //board[val][j] = Yellow;
                            cout << "\033[1m\033[33m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((i + 10 == j && i + 10 < 14))
                        {
                            //board[val][j] = Red;
                            cout << "\033[1m\033[31m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((i + 11 == j && i + 11 < 14))
                        {
                            //board[val][j] = Black;
                            cout << "\033[1m\033[35m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((i + 12 == j && i + 12 < 14))
                        {
                            // board[val][j] = LightBlue;
                            cout << "\033[1m\033[36m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((i + 13 == j && i + 13 < 14))
                        {
                            cout << "\033[1m\033[32m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((j - i) == 3)
                        {
                            // board[val][j] = Yellow;
                            cout << "\033[1m\033[33m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((j - i) == 4)
                        {
                            // board[val][j] = Red;
                            cout << "\033[1m\033[31m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((j - i) == 5)
                        {
                            // board[val][j] = Black;
                            cout << "\033[1m\033[35m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((j - i) == 6)
                        {
                            //board[val][j] = LightBlue;
                            cout << "\033[1m\033[36m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                        else if ((j - i) == 7)
                        {
                            //board[val][j] = LightBlue;
                            cout << "\033[1m\033[32m"
                                 << "[" << board[i][j] << "]"
                                 << "\033[0m";
                        }
                    }

                    else if (board[i][j] == 'R')
                    {
                        std::cout << "\033[1m\033[31m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'Y')
                    {
                        std::cout << "\033[1m\033[33m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'U')
                    {
                        std::cout << "\033[1m\033[35m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'L')
                    {
                        std::cout << "\033[1m\033[36m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'B')
                    {
                        std::cout << "\033[1m\033[34m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'O')
                    {
                        std::cout << "\033[1m\033[32m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else if (board[i][j] == 'F')
                    {
                        std::cout << "\033[1m\033[37m"
                                  << " " << board[i][j] << " "
                                  << "\033[0m";
                    }
                    else
                    {
                        std::cout << board[i][j];
                    }
                }
                else
                {
                    if (board[i][j] == 'R')
                    {
                        std::cout << "\033[1m\033[31m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'Y')
                    {
                        std::cout << "\033[1m\033[33m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'U')
                    {
                        std::cout << "\033[1m\033[35m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'L')
                    {
                        std::cout << "\033[1m\033[36m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'B')
                    {
                        std::cout << "\033[1m\033[34m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'O')
                    {
                        std::cout << "\033[1m\033[32m" << board[i][j] << "\033[0m";
                    }
                    else if (board[i][j] == 'F')
                    {
                        std::cout << "\033[1m\033[37m" << board[i][j] << "\033[0m";
                    }
                    else
                    {
                        std::cout << board[i][j];
                    }
                }
            }
            std::cout << std::endl;
        }
    }
    else
    {
        for (int j = 0; j < column; j++)
        {
            if (j >= (column + 2) / 2)
            {
                if (board[k][j] == '.')
                {
                    if (k + 8 == j && k + 8 < 14)
                    {
                        //board[val][j] = DarkBlue;
                        cout << "\033[1m\033[34m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if (k + 9 == j && k + 9 < 14)
                    {
                        //board[val][j] = Yellow;
                        cout << "\033[1m\033[33m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((k + 10 == j && k + 10 < 14))
                    {
                        //board[val][j] = Red;
                        cout << "\033[1m\033[31m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((k + 11 == j && k + 11 < 14))
                    {
                        //board[val][j] = Black;
                        cout << "\033[1m\033[35m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((k + 12 == j && k + 12 < 14))
                    {
                        // board[val][j] = LightBlue;
                        cout << "\033[1m\033[36m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((k + 13 == j && k + 13 < 14))
                    {
                        cout << "\033[1m\033[32m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((j - k) == 3)
                    {
                        // board[val][j] = Yellow;
                        cout << "\033[1m\033[33m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((j - k) == 4)
                    {
                        // board[val][j] = Red;
                        cout << "\033[1m\033[31m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((j - k) == 5)
                    {
                        // board[val][j] = Black;
                        cout << "\033[1m\033[35m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((j - k) == 6)
                    {
                        //board[val][j] = LightBlue;
                        cout << "\033[1m\033[36m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                    else if ((j - k) == 7)
                    {
                        //board[val][j] = LightBlue;
                        cout << "\033[1m\033[32m"
                             << "[" << board[k][j] << "]"
                             << "\033[0m";
                    }
                }

                else if (board[k][j] == 'R')
                {
                    std::cout << "\033[1m\033[31m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'Y')
                {
                    std::cout << "\033[1m\033[33m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'U')
                {
                    std::cout << "\033[1m\033[35m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'L')
                {
                    std::cout << "\033[1m\033[36m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'B')
                {
                    std::cout << "\033[1m\033[34m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'O')
                {
                    std::cout << "\033[1m\033[32m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else if (board[k][j] == 'F')
                {
                    std::cout << "\033[1m\033[37m"
                              << " " << board[k][j] << " "
                              << "\033[0m";
                }
                else
                {
                }
            }
            else
            {
                if (board[k][j] == 'R')
                {
                    std::cout << "\033[1m\033[31m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'Y')
                {
                    std::cout << "\033[1m\033[33m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'U')
                {
                    std::cout << "\033[1m\033[35m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'L')
                {
                    std::cout << "\033[1m\033[36m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'B')
                {
                    std::cout << "\033[1m\033[34m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'O')
                {
                    std::cout << "\033[1m\033[32m" << board[k][j] << "\033[0m";
                }
                else if (board[k][j] == 'F')
                {
                    std::cout << "\033[1m\033[37m" << board[k][j] << "\033[0m";
                }
                else
                {
                    std::cout << board[k][j];
                }
            }
        }
    }
}