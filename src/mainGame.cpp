
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <limits>
#include "mainGame.h"
using namespace std;

//constrcutor that initializes the tile bag, factories, boards and player details
mainGame::mainGame(){
   
 
    tileBag = new Bag(5);
    factory = new Factory();

    //For two Players
    player1Name = "";
    player1Scores = 0;
    player2Name = "";
    player2Scores = 0;
    board1 = new Board(5);
    board2 = new Board(5);
   
    //For three Players
    player3Name = "";
    player3Scores = 0;
    board3 = new Board(5);
  
    //For Four Players
    player4Name = "";
    player4Scores = 0;
    board4 = new Board(5);

    //Tells us that the game is not loaded 
    boardsLoaded = false;
 
}

// function used to save the game to a .txt file in a particular format
// format is changed for the individual enhancements
// details in report
void mainGame::saveGame(string filename, int numOfPlayers, int numOfCentreFactory,Player* currentPlayer) {
    ofstream of;
    of.open(filename, std::ofstream::out | std::ofstream::trunc);
    of<<"# Grey Board Mode: \n";
    of<<this->greyBoardMode<<"\n";
    of<<"# 6 Tile Mode: \n";
    of<<this->sixTileMode<<"\n";
    of<<"# Number Of Players: \n";
    of<<numOfPlayers<<"\n";
    of<<"# Number of Centre Factories: \n";
    of<<numOfCentreFactory<<"\n";
    of << "# Bag\n";
    of << tileBag->returnAsString() + "\n";
    of << "# Lid: \n";
    of << "_ \n";
    of << "# Factories: \n";
    //changes
    of << factory->returnAsString(numOfPlayers,numOfCentreFactory);
    of << "# Player1 name: \n";
    of << player1Name + "\n";
    of << "# Player2 name: \n";
    of << player2Name + "\n";

    if(numOfPlayers==3){
        of << "# Player3 name: \n";
        of<<player3Name + "\n";
    }
    if(numOfPlayers==4){
        of << "# Player3 name: \n";
        of<<player3Name + "\n";
        of << "# Player4 name: \n";
        of<<player4Name + "\n";
    }

    of << "# Player1 points: \n";
    of << to_string(player1Scores) + "\n";
    of << "# Player2 points: \n";
    of << to_string(player2Scores) + "\n";

    if(numOfPlayers==3){
        of<<"# Player3 points: \n";
        of<<to_string(player3Scores) + "\n";
    }
    if(numOfPlayers==4){
        of<<"# Player3 points: \n";
        of<<to_string(player3Scores) + "\n";
        of<<"# Player4 points: \n";
        of<<to_string(player4Scores) + "\n";
    }

    of << "# Player1 board: \n";
    of << board1->returnTriangleAsString();
    of << board1->returnWallAsString();
    of << "# Player2 board: \n";
    of << board2->returnTriangleAsString();
    of << board2->returnWallAsString();

    if(numOfPlayers==3){
        of << "# Player3 board: \n";
        of<<board3->returnTriangleAsString();
        of<<board3->returnWallAsString();
    }
    if(numOfPlayers==4){
        of << "# Player3 board: \n";
        of<<board3->returnTriangleAsString();
        of<<board3->returnWallAsString();
        of << "# Player4 board: \n";
        of<<board4->returnTriangleAsString();
        of<<board4->returnWallAsString();
    }
    of<<"# Current Player: \n";
    of<<currentPlayer->getName();
    of.close();
    std::cout << "Game successfully saved to " << filename << std::endl;
    boardsLoaded = true;
    playGameUpdated(numOfPlayers);
}

//used to laod the factories, never used in later stages
void mainGame::load(string filename, int numOfPlayers, int centreFactory){
    fstream of;
    of.open(filename);
    char c;
    int i=0;
    of.get(c);
    string factoryString[6];
    while(c!=EOF){
        of.ignore('#');
        of.get(c);
        factoryString[i] = c;
        i++;
    }
    factory->loadFactoryFromFile(factoryString,numOfPlayers,centreFactory);
}

//function used to load a particular game and starts the same game from that point of time
//read line by line
//wanted to reduce the code duplication but time was a constraint
void mainGame::LoadGame(string filename,bool greyBoard, bool sixTileGame){
    fstream of;
    of.open(filename);
    string line;

    string basefactoryStrings[6];
    string twoCentrefactoryTwoStrings[7];
    string oneCentrefactoryThreeStrings[8];
    string twoCentrefactoryThreeStrings[9];
    string oneCentreFourFactoryStrings[10];
    string twoCentrefactoryFourStrings[11];
    int factoryCounter = 0;

    string board1Triangle[5];
    int board1TriangleCounter = 0;

    string board1Wall[5];
    int board1WallCounter = 0;

    string board2Triangle[5];
    int board2TriangleCounter = 0;

    string board3Triangle[5];
    int board3TriangleCounter = 0;

    string board4Triangle[5];
    int board4TriangleCounter = 0;

    string board2Wall[5];
    int board2WallCounter = 0;

    string board3Wall[5];
    int board3WallCounter = 0;

   string board4Wall[5];
    int board4WallCounter = 0;

    string board1TriangleSix[6];
    string board1WallSix[6];
    string board2TriangleSix[6];
    string board2WallSix[6];
    string board3TriangleSix[6];
    string board3WallSix[6];
    string board4TriangleSix[6];
    string board4WallSix[6];
    int lineCounter = 0;
    int greyBoardValue=0;
    int sixTileValue=0;
    int board1TriangleSixCounter =0;
    int board1WallSixCounter =0;
    int board2TriangleSixCounter =0;
    int board2WallSixCounter=0;
    int numOfPlayersGame = 0;
    int numOfCentreFactories = 0;

    while(getline(of,line)){
        
          if(lineCounter==1){
                greyBoardValue= stoi(line);
            }
            if(lineCounter==3){
                sixTileValue = stoi(line);
            }

            if(lineCounter==5){
                numOfPlayersGame = stoi(line);
            }
            if(lineCounter==7){
                numOfCentreFactories= stoi(line);
            }
          if(greyBoardValue==1){  
        if(numOfPlayersGame==2 && numOfCentreFactories==1){
        
        if(lineCounter >= 13 && lineCounter <= 18){
            basefactoryStrings[factoryCounter] = line;
            factoryCounter++;
        }
        if(lineCounter == 20) {
            player1Name = line;
        }
        if(lineCounter == 24) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 22) {
            player2Name = line;
        }
        if(lineCounter == 26) {
            player2Scores = stoi(line);
        }

        if(lineCounter >= 28 && lineCounter <= 32){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 33 && lineCounter <= 37){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 39 && lineCounter <= 43){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 44 && lineCounter <= 47){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }
   }
   else  if(numOfPlayersGame==2 && numOfCentreFactories==2){
        
        if(lineCounter >= 13 && lineCounter <= 19){
            twoCentrefactoryTwoStrings[factoryCounter] = line;
            factoryCounter++;
        }
        if(lineCounter == 21) {
            player1Name = line;
        }
        if(lineCounter == 25) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 23) {
            player2Name = line;
        }
        if(lineCounter == 27) {
            player2Scores = stoi(line);
        }

        if(lineCounter >= 29 && lineCounter <= 33){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 34 && lineCounter <= 38){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 40 && lineCounter <= 44){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 45 && lineCounter <= 49){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }
    }

    else  if(numOfPlayersGame==3 && numOfCentreFactories==1){
        
        if(lineCounter >= 13 && lineCounter <= 20){
            oneCentrefactoryThreeStrings[factoryCounter] = line;
            factoryCounter++;
        }
        if(lineCounter == 22) {
            player1Name = line;
        }

        if(lineCounter == 28) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 24) {
            player2Name = line;
        }
        if(lineCounter == 30) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 26){
            player3Name = line;
        }

        if(lineCounter==32){
            player3Scores = stoi(line);
        }

        if(lineCounter >= 34 && lineCounter <= 38){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 39 && lineCounter <= 43){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 45 && lineCounter <= 49){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 50 && lineCounter <= 54){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }

        if(lineCounter >= 56 && lineCounter <=60 ){
            board3Triangle[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }
        
        if(lineCounter >= 61 && lineCounter <=65 ){
            board3Wall[board3WallCounter] = line;
            board3WallCounter++;
        }
    }
    else if(numOfPlayersGame==3 && numOfCentreFactories==2){
          if(lineCounter >= 13 && lineCounter <= 21){
            twoCentrefactoryThreeStrings[factoryCounter] = line;
            factoryCounter++;
        }
        if(lineCounter == 23) {
            player1Name = line;
        }

        if(lineCounter == 29) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 25) {
            player2Name = line;
        }
        if(lineCounter == 31) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 27){
            player3Name = line;
        }

        if(lineCounter==33){
            player3Scores = stoi(line);
        }
        if(lineCounter >= 35 && lineCounter <= 39){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 40 && lineCounter <= 44){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 46 && lineCounter <= 50){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 51 && lineCounter <= 55){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }

        if(lineCounter >= 57 && lineCounter <=61 ){
            board3Triangle[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }
        
        if(lineCounter >= 62 && lineCounter <=66 ){
            board3Wall[board3WallCounter] = line;
            board3WallCounter++;
        }
    }

    else if(numOfPlayersGame==4 && numOfCentreFactories==1){
          if(lineCounter >= 13 && lineCounter <= 22){
            oneCentreFourFactoryStrings[factoryCounter] = line;
            factoryCounter++;
        }

        if(lineCounter == 24) {
            player1Name = line;
        }
        if(lineCounter == 32) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 26) {
            player2Name = line;
        }
        if(lineCounter == 34) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 28) {
            player3Name = line;
        }
        if(lineCounter == 36) {
            player3Scores = stoi(line);
        }

        if(lineCounter == 30) {
            player4Name = line;
        }
        if(lineCounter == 38) {
            player4Scores = stoi(line);
        }

        if(lineCounter >= 40 && lineCounter <= 44){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 45 && lineCounter <= 49){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 51 && lineCounter <= 55){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 56 && lineCounter <= 60){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }

        if(lineCounter >= 62 && lineCounter <= 66){
            board3Triangle[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }

        if(lineCounter >= 67 && lineCounter <= 71){
            board3Wall[board3WallCounter] = line;
            board3WallCounter++;
        }

        if(lineCounter >= 73 && lineCounter <= 77){
            board4Triangle[board4TriangleCounter] = line;
            board4TriangleCounter++;
        }

        if(lineCounter >= 78 && lineCounter <= 82){
            board4Wall[board4WallCounter] = line;
            board4WallCounter++;
        }
    }

     else if(numOfPlayersGame==4 && numOfCentreFactories==2){
          if(lineCounter >= 13 && lineCounter <= 23){
            twoCentrefactoryFourStrings[factoryCounter] = line;
            factoryCounter++;
        }

        if(lineCounter == 25) {
            player1Name = line;
        }
        if(lineCounter == 33) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 27) {
            player2Name = line;
        }
        if(lineCounter == 35) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 29) {
            player3Name = line;
        }
        if(lineCounter == 37) {
            player3Scores = stoi(line);
        }

        if(lineCounter == 31) {
            player4Name = line;
        }
        if(lineCounter == 39) {
            player4Scores = stoi(line);
        }

        if(lineCounter >= 41 && lineCounter <= 45){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 46 && lineCounter <= 50){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 52 && lineCounter <= 56){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 57 && lineCounter <= 61){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }

        if(lineCounter >= 63 && lineCounter <= 67){
            board3Triangle[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }

        if(lineCounter >= 68 && lineCounter <= 72){
            board3Wall[board3WallCounter] = line;
            board3WallCounter++;
        }

        if(lineCounter >= 74 && lineCounter <= 78){
            board4Triangle[board4TriangleCounter] = line;
            board4TriangleCounter++;
        }

        if(lineCounter >= 79 && lineCounter <= 83){
            board4Wall[board4WallCounter] = line;
            board4WallCounter++;
        }

    }
    else{
        //TODO
        //Will never gets here as check for players and centre factory already done
    }
        }

else if(sixTileValue==1){
 if(numOfPlayersGame==2 && numOfCentreFactories==1){
        
        if(lineCounter >= 13 && lineCounter <= 18){
            basefactoryStrings[factoryCounter] = line;
            factoryCounter++;
        }
        if(lineCounter == 20) {
            player1Name = line;
        }
        if(lineCounter == 24) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 22) {
            player2Name = line;
        }
        if(lineCounter == 26) {
            player2Scores = stoi(line);
        }

        if(lineCounter >= 28 && lineCounter <= 33){
            board1TriangleSix[board1TriangleSixCounter] = line;
            board1TriangleSixCounter++;
        }

        if(lineCounter >= 34 && lineCounter <= 39){
            board1WallSix[board1WallSixCounter] = line;
            board1WallSixCounter++;
        }

        if(lineCounter >= 41 && lineCounter <= 46){
            board2TriangleSix[board2TriangleSixCounter] = line;
            board2TriangleSixCounter++;
        }

        if(lineCounter >= 47 && lineCounter <= 52){
            board2WallSix[board2WallSixCounter] = line;
            board2WallSixCounter++;
        }

   }
   else  if(numOfPlayersGame==2 && numOfCentreFactories==2){
        
        if(lineCounter >= 13 && lineCounter <= 19){
            twoCentrefactoryTwoStrings[factoryCounter] = line;
            factoryCounter++;
        }
        if(lineCounter == 21) {
            player1Name = line;
        }
        if(lineCounter == 25) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 23) {
            player2Name = line;
        }
        if(lineCounter == 27) {
            player2Scores = stoi(line);
        }

        if(lineCounter >= 29 && lineCounter <= 34){
            board1TriangleSix[board1TriangleSixCounter] = line;
            board1TriangleSixCounter++;
        }

        if(lineCounter >= 35 && lineCounter <= 40){
            board1WallSix[board1WallSixCounter] = line;
            board1WallSixCounter++;
        }

        if(lineCounter >= 42 && lineCounter <= 47){
            board2TriangleSix[board2TriangleSixCounter] = line;
            board2TriangleSixCounter++;
        }

        if(lineCounter >= 48 && lineCounter <= 53){
            board2WallSix[board2WallSixCounter] = line;
            board2WallSixCounter++;
        }
    
    }

    else  if(numOfPlayersGame==3 && numOfCentreFactories==1){
        
        if(lineCounter >= 13 && lineCounter <= 20){
            oneCentrefactoryThreeStrings[factoryCounter] = line;

            factoryCounter++;
        }
     
       
        if(lineCounter == 22) {
            player1Name = line;
        }

        if(lineCounter == 28) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 24) {
            player2Name = line;
        }
        if(lineCounter == 30) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 26){
            player3Name = line;
        }

        if(lineCounter==32){
            player3Scores = stoi(line);
        }

        if(lineCounter >= 34 && lineCounter <= 39){
            board1TriangleSix[board1TriangleSixCounter] = line;
            board1TriangleSixCounter++;
        }

        if(lineCounter >= 40 && lineCounter <= 45){
            board1WallSix[board1WallSixCounter] = line;
            board1WallSixCounter++;
        }

        if(lineCounter >= 47 && lineCounter <= 52){
            board2TriangleSix[board2TriangleSixCounter] = line;
            board2TriangleSixCounter++;
        }

        if(lineCounter >= 53 && lineCounter <= 58){
            board2WallSix[board2WallSixCounter] = line;
            board2WallSixCounter++;
        }

        if(lineCounter >= 60 && lineCounter <=65 ){
            board3TriangleSix[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }
        
        if(lineCounter >= 66 && lineCounter <=71 ){
            board3WallSix[board3WallCounter] = line;
            board3WallCounter++;
        }
    }
    else if(numOfPlayersGame==3 && numOfCentreFactories==2){
          if(lineCounter >= 13 && lineCounter <= 21){
            twoCentrefactoryThreeStrings[factoryCounter] = line;
            factoryCounter++;
        }
        if(lineCounter == 23) {
            player1Name = line;
        }

        if(lineCounter == 29) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 25) {
            player2Name = line;
        }
        if(lineCounter == 31) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 27){
            player3Name = line;
        }

        if(lineCounter==33){
            player3Scores = stoi(line);
        }

        if(lineCounter >= 35 && lineCounter <= 40){
            board1TriangleSix[board1TriangleSixCounter] = line;
            board1TriangleSixCounter++;
        }

        if(lineCounter >= 41 && lineCounter <= 46){
            board1WallSix[board1WallSixCounter] = line;
            board1WallSixCounter++;
        }

        if(lineCounter >= 48 && lineCounter <= 53){
            board2TriangleSix[board2TriangleSixCounter] = line;
            board2TriangleSixCounter++;
        }

        if(lineCounter >= 54 && lineCounter <= 59){
            board2WallSix[board2WallSixCounter] = line;
            board2WallSixCounter++;
        }

        if(lineCounter >= 61 && lineCounter <=66 ){
            board3TriangleSix[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }
        
        if(lineCounter >= 67 && lineCounter <=72 ){
            board3WallSix[board3WallCounter] = line;
            board3WallCounter++;
        }
    }

    else if(numOfPlayersGame==4 && numOfCentreFactories==1){
          if(lineCounter >= 13 && lineCounter <= 22){
            oneCentreFourFactoryStrings[factoryCounter] = line;
            factoryCounter++;
        }

        if(lineCounter == 24) {
            player1Name = line;
        }
        if(lineCounter == 32) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 26) {
            player2Name = line;
        }
        if(lineCounter == 34) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 28) {
            player3Name = line;
        }
        if(lineCounter == 36) {
            player3Scores = stoi(line);
        }

        if(lineCounter == 30) {
            player4Name = line;
        }
        if(lineCounter == 38) {
            player4Scores = stoi(line);
        }

        if(lineCounter >= 40 && lineCounter <= 45){
            board1TriangleSix[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 46 && lineCounter <= 51){
            board1WallSix[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 53 && lineCounter <= 58){
            board2TriangleSix[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 59 && lineCounter <= 64){
            board2WallSix[board2WallCounter] = line;
            board2WallCounter++;
        }

        if(lineCounter >= 66 && lineCounter <= 71){
            board3TriangleSix[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }

        if(lineCounter >= 72 && lineCounter <= 77){
            board3WallSix[board3WallCounter] = line;
            board3WallCounter++;
        }

        if(lineCounter >= 79 && lineCounter <= 84){
            board4TriangleSix[board4TriangleCounter] = line;
            board4TriangleCounter++;
        }

        if(lineCounter >= 85 && lineCounter <= 90){
            board4WallSix[board4WallCounter] = line;
            board4WallCounter++;
        }
    }

     else{
          if(lineCounter >= 13 && lineCounter <= 23){
            twoCentrefactoryFourStrings[factoryCounter] = line;
            factoryCounter++;
        }

        if(lineCounter == 25) {
            player1Name = line;
        }
        if(lineCounter == 33) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 27) {
            player2Name = line;
        }
        if(lineCounter == 35) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 29) {
            player3Name = line;
        }
        if(lineCounter == 37) {
            player3Scores = stoi(line);
        }

        if(lineCounter == 31) {
            player4Name = line;
        }
        if(lineCounter == 39) {
            player4Scores = stoi(line);
        }

        if(lineCounter >= 41 && lineCounter <= 46){
            board1TriangleSix[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 47 && lineCounter <= 52){
            board1WallSix[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 54 && lineCounter <= 59){
            board2TriangleSix[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 60 && lineCounter <= 65){
            board2WallSix[board2WallCounter] = line;
            board2WallCounter++;
        }

        if(lineCounter >= 67 && lineCounter <= 72){
            board3TriangleSix[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }

        if(lineCounter >= 73 && lineCounter <= 78){
            board3WallSix[board3WallCounter] = line;
            board3WallCounter++;
        }

        if(lineCounter >= 80 && lineCounter <= 85){
            board4TriangleSix[board4TriangleCounter] = line;
            board4TriangleCounter++;
        }

        if(lineCounter >= 86 && lineCounter <= 91){
            board4WallSix[board4WallCounter] = line;
            board4WallCounter++;
        }
    }
}

 else if(greyBoardValue==0 && sixTileValue==0){  
        if(numOfPlayersGame==2 && numOfCentreFactories==1){
        
        if(lineCounter >= 13 && lineCounter <= 18){
            basefactoryStrings[factoryCounter] = line;
            factoryCounter++;
        }
        if(lineCounter == 20) {
            player1Name = line;
        }
        if(lineCounter == 24) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 22) {
            player2Name = line;
        }
        if(lineCounter == 26) {
            player2Scores = stoi(line);
        }

        if(lineCounter >= 28 && lineCounter <= 32){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 33 && lineCounter <= 37){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 39 && lineCounter <= 43){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 44 && lineCounter <= 47){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }
   }
   else  if(numOfPlayersGame==2 && numOfCentreFactories==2){
        
        if(lineCounter >= 13 && lineCounter <= 19){
            twoCentrefactoryTwoStrings[factoryCounter] = line;
            factoryCounter++;
        }
        if(lineCounter == 21) {
            player1Name = line;
        }
        if(lineCounter == 25) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 23) {
            player2Name = line;
        }
        if(lineCounter == 27) {
            player2Scores = stoi(line);
        }

        if(lineCounter >= 29 && lineCounter <= 33){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 34 && lineCounter <= 38){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 40 && lineCounter <= 44){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 45 && lineCounter <= 49){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }
       
    }

    else  if(numOfPlayersGame==3 && numOfCentreFactories==1){
        
        if(lineCounter >= 13 && lineCounter <= 20){
            oneCentrefactoryThreeStrings[factoryCounter] = line;
         
            factoryCounter++;
        }
        
       
        if(lineCounter == 22) {
            player1Name = line;
        }

        if(lineCounter == 28) {
         
            player1Scores = stoi(line);
        }

        if(lineCounter == 24) {
            player2Name = line;
        }
        if(lineCounter == 30) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 26){
            player3Name = line;
        }

        if(lineCounter==32){
            player3Scores = stoi(line);
        }

        if(lineCounter >= 34 && lineCounter <= 38){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 39 && lineCounter <= 43){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 45 && lineCounter <= 49){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 50 && lineCounter <= 54){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }

        if(lineCounter >= 56 && lineCounter <=60 ){
            board3Triangle[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }
        
        if(lineCounter >= 61 && lineCounter <=65 ){
            board3Wall[board3WallCounter] = line;
            board3WallCounter++;
        }
    }
    else if(numOfPlayersGame==3 && numOfCentreFactories==2){
          if(lineCounter >= 13 && lineCounter <= 21){
            twoCentrefactoryThreeStrings[factoryCounter] = line;
          
            factoryCounter++;
        }
     
        if(lineCounter == 23) {
            player1Name = line;
        }

        if(lineCounter == 29) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 25) {
            player2Name = line;
        }
        if(lineCounter == 31) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 27){
            player3Name = line;
        }

        if(lineCounter==33){
            player3Scores = stoi(line);
        }
        //add here
        if(lineCounter >= 35 && lineCounter <= 39){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 40 && lineCounter <= 44){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 46 && lineCounter <= 50){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 51 && lineCounter <= 55){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }

        if(lineCounter >= 57 && lineCounter <=61 ){
            board3Triangle[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }
        
        if(lineCounter >= 62 && lineCounter <=66 ){
            board3Wall[board3WallCounter] = line;
            board3WallCounter++;
        }
    }

    else if(numOfPlayersGame==4 && numOfCentreFactories==1){
          if(lineCounter >= 13 && lineCounter <= 22){
            oneCentreFourFactoryStrings[factoryCounter] = line;
            factoryCounter++;
        }

        if(lineCounter == 24) {
            player1Name = line;
        }
        if(lineCounter == 32) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 26) {
            player2Name = line;
        }
        if(lineCounter == 34) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 28) {
            player3Name = line;
        }
        if(lineCounter == 36) {
            player3Scores = stoi(line);
        }

        if(lineCounter == 30) {
            player4Name = line;
        }
        if(lineCounter == 38) {
            player4Scores = stoi(line);
        }

        if(lineCounter >= 40 && lineCounter <= 44){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 45 && lineCounter <= 49){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 51 && lineCounter <= 55){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 56 && lineCounter <= 60){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }

        if(lineCounter >= 62 && lineCounter <= 66){
            board3Triangle[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }

        if(lineCounter >= 67 && lineCounter <= 71){
            board3Wall[board3WallCounter] = line;
            board3WallCounter++;
        }

        if(lineCounter >= 73 && lineCounter <= 77){
            board4Triangle[board4TriangleCounter] = line;
            board4TriangleCounter++;
        }

        if(lineCounter >= 78 && lineCounter <= 82){
            board4Wall[board4WallCounter] = line;
            board4WallCounter++;
        }
    }

     else if(numOfPlayersGame==4 && numOfCentreFactories==2){
          if(lineCounter >= 13 && lineCounter <= 23){
            twoCentrefactoryFourStrings[factoryCounter] = line;
            factoryCounter++;
        }

        if(lineCounter == 25) {
            player1Name = line;
        }
        if(lineCounter == 33) {
            player1Scores = stoi(line);
        }

        if(lineCounter == 27) {
            player2Name = line;
        }
        if(lineCounter == 35) {
            player2Scores = stoi(line);
        }

        if(lineCounter == 29) {
            player3Name = line;
        }
        if(lineCounter == 37) {
            player3Scores = stoi(line);
        }

        if(lineCounter == 31) {
            player4Name = line;
        }
        if(lineCounter == 39) {
            player4Scores = stoi(line);
        }

        if(lineCounter >= 41 && lineCounter <= 45){
            board1Triangle[board1TriangleCounter] = line;
            board1TriangleCounter++;
        }

        if(lineCounter >= 46 && lineCounter <= 50){
            board1Wall[board1WallCounter] = line;
            board1WallCounter++;
        }

        if(lineCounter >= 52 && lineCounter <= 56){
            board2Triangle[board2TriangleCounter] = line;
            board2TriangleCounter++;
        }

        if(lineCounter >= 57 && lineCounter <= 61){
            board2Wall[board2WallCounter] = line;
            board2WallCounter++;
        }

        if(lineCounter >= 63 && lineCounter <= 67){
            board3Triangle[board3TriangleCounter] = line;
            board3TriangleCounter++;
        }

        if(lineCounter >= 68 && lineCounter <= 72){
            board3Wall[board3WallCounter] = line;
            board3WallCounter++;
        }

        if(lineCounter >= 74 && lineCounter <= 78){
            board4Triangle[board4TriangleCounter] = line;
            board4TriangleCounter++;
        }

        if(lineCounter >= 79 && lineCounter <= 83){
            board4Wall[board4WallCounter] = line;
            board4WallCounter++;
        }
    }
    else{
        //TODO
        //Never gets here as check was already made for numOfPlayers and numOfCentreFactory
    }
        }

else{
    //TODO
    //No need to worry about it as only two values possible for both greyboard and sixtile
}



    lineCounter++;
    }

    //changes
    if(numOfPlayersGame==2 && numOfCentreFactories==1){
    factory->loadFactoryFromFile(basefactoryStrings,numOfPlayersGame,numOfCentreFactories);
    }
    else if(numOfPlayersGame==2 && numOfCentreFactories==2){
       factory->loadFactoryFromFile(twoCentrefactoryTwoStrings,numOfPlayersGame,numOfCentreFactories);
    }
    else if(numOfPlayersGame==3 && numOfCentreFactories==1){
      
        factory->loadFactoryFromFile(oneCentrefactoryThreeStrings,numOfPlayersGame,numOfCentreFactories);
     
    }
    else if(numOfPlayersGame==3 && numOfCentreFactories==2){
        factory->loadFactoryFromFile(twoCentrefactoryThreeStrings,numOfPlayersGame,numOfCentreFactories);
    }
    else if(numOfPlayersGame==4 && numOfCentreFactories==1){
        
     factory->loadFactoryFromFile(oneCentreFourFactoryStrings,numOfPlayersGame,numOfCentreFactories);
    }
    else{
        factory->loadFactoryFromFile(twoCentrefactoryFourStrings,numOfPlayersGame,numOfCentreFactories);
    }
    
    if(sixTileValue==1){
        board1 = new Board(6);
        board2 = new Board(6);
        board3 = new Board(6);
        board4 = new Board(6);

        
    board1->loadBoard(board1TriangleSix, board1WallSix,true);
        
    board2->loadBoard(board2TriangleSix, board2WallSix,true);
       
            if(numOfPlayersGame==2){
        playTheSixTileMode(numOfPlayersGame,numOfCentreFactories,1);
    }
    if(numOfPlayersGame==3){
        
        board3->loadBoard(board3TriangleSix,board3WallSix,true);
        playTheSixTileMode(numOfPlayersGame,numOfCentreFactories,1);
    }
    if(numOfPlayersGame==4){
        board3->loadBoard(board3TriangleSix,board3WallSix,true);
        board4->loadBoard(board4TriangleSix,board4WallSix,true);
        playTheSixTileMode(numOfPlayersGame,numOfCentreFactories,1);
    }

    }
 
    else if(greyBoardValue==1){
          tileBag = new Bag(5);
        if(tileBag->getSize()==0){
            tileBag->fillBag();
            tileBag->Shuffle();
        }
        board1 = new Board(5);
        board2 = new Board(5);
        board3 = new Board(5);
        board4 = new Board(5);
    
        board1->loadBoard(board1Triangle,board1Wall,false);
        board2->loadBoard(board2Triangle,board2Wall,false);

    if(numOfPlayersGame==2){
        playTheGreyBoardMode(numOfPlayersGame,numOfCentreFactories,tileBag,greyBoardValue);
    }

    else if(numOfPlayersGame==3 && sixTileValue==0){
        board3->loadBoard(board3Triangle, board3Wall,false);
        playTheGreyBoardMode(numOfPlayersGame,numOfCentreFactories,tileBag,1);
    }
  else{
        board3->loadBoard(board3Triangle,board3Wall,false);
        board4->loadBoard(board4Triangle,board4Wall,false);
        playTheGreyBoardMode(numOfPlayersGame,numOfCentreFactories,tileBag,1);
    }
    }
    else{
        tileBag = new Bag(5);
         if(tileBag->getSize()==0){
            tileBag->fillBag();
            tileBag->Shuffle();
        }
      board1 = new Board(5);
      board2 = new Board(5);
      board3 = new Board(5);
      board4 = new Board(5);

      board1->loadBoard(board1Triangle,board1Wall,false);
      board2->loadBoard(board2Triangle,board2Wall,false);
      if(numOfPlayersGame==2){
          
      playMultiPlayer(numOfPlayersGame,numOfCentreFactories,tileBag,1);
      }
      else if(numOfPlayersGame==3){
          board3 = new Board(5);
          board3->loadBoard(board3Triangle,board3Wall,false);
          playMultiPlayer(numOfPlayersGame,numOfCentreFactories,tileBag,1);
      }
      else{
          board3 = new Board(5);
          board4 = new Board(5);
          board3->loadBoard(board3Triangle,board3Wall,false);
          board4->loadBoard(board4Triangle,board4Wall,false);
          playMultiPlayer(numOfPlayersGame,numOfCentreFactories,tileBag,1);
      }
    }
    boardsLoaded = true;
}

void mainGame::setPlayerNum(int playerNum){
    this->playerNumber= playerNum;
}

int mainGame::getPlayerNum(){
    return this->playerNumber;
}

//Points are calculated using the various combinations of tiles being adjacent in a row or a column
//like a column might have 5 tiles adjacent to each other, but there might be few tiles attached in a row to that particular colum
//This will result in increase of points a further more
void mainGame::countpoints(Player* player1, Board* board1){
  int points1 = 0;
  int points2 = 0;
  //int points3 = 0;
  int finalPoints = 0;
  int rows = board1->getRowSize();
 for (int i = 0; i < rows; i++)
    {
        for(int j=board1->getColumnSize()/2+1;j<board1->getColumnSize();j++){
        if ((board1->checkTilesHorizontally(i) != rows || board1->checkTilesVertically(j) != rows) && (board1->checkTilesHorizontally(i)!=0 && board1->checkTilesVertically(j)!=0))
        {
            points1 = board1->checkTilesHorizontally(i) + board1->checkTilesVertically(j);
        }
        if(board1->checkTilesHorizontally(i)==0 && board1->checkTilesVertically(j)==0){
            points2 = board1->checkTotaltiles();
        }
        if (board1->checkTilesVertically(j) == rows)
        {
            points1 = 7;
        }
        if (board1->checkTilesHorizontally(i) == rows)
        {
            points1 = 5;
        }
        }
    }
    finalPoints=points1+points2;
    if(board1->getSize()>=1 && board1->getSize()<=2){
//player1->setPoints(points1 - board1->getSize());
player1->setPoints(finalPoints - board1->getSize());
    }
    else if(board1->getSize()>=3 && board1->getSize()<=5){
        //player1->setPoints(points1 + 2 - (board1->getSize()*2));
        player1->setPoints(finalPoints - (board1->getSize()*2));
    }
    else if(board1->getSize()==6){
        //player1->setPoints(points1 + 1 - (board1->getSize()*2));
        player1->setPoints(finalPoints - (board1->getSize()*2));
    }
    else if(board1->getSize()==7){
        //player1->setPoints(points1 - (board1->getSize()*2));
        player1->setPoints(finalPoints - (board1->getSize()*2));
    }
    else if(board1->getSize()==8){
        //player1->setPoints(points1 -(board1->getSize()*2) - 2);
        player1->setPoints(finalPoints-(board1->getSize()*2) - 2);
    }
    else{
    //  player1->setPoints(points1-board1->getSize());
    player1->setPoints(finalPoints-board1->getSize());
    }
    cout << player1->getName() << " points :" << player1->getPoints() << endl;
    board1->clearBroken();
}


//This the function that displays the menu for the game
//responsible for handling the backend after the user choose a mode
void mainGame::playGameUpdated(int numOfPlayers){

    validatePlayers(numOfPlayers);
    std::cout<<std::endl;
    cout<<"Choose the mode you will like to play?"<<endl;
    cout<<"1: A general Multiplayer Mode"<<endl;
    cout<<"2: A six Tile Multiplayer Mode"<<endl;
    cout<<"3: The Grey-board Multiplayer Mode"<<endl;
    int mode;
    cout<<"> ";
    cin>>mode;
    while(mode>3){
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"> ";
        cin>>mode;
    }
    cout<<std::endl;
    cout<<"How Many centre factories would you like to have? (Could either be 1 or 2) \n";
    cout<<"> ";
    int numOfCentreFactory;
    cin>>numOfCentreFactory;
    while(numOfCentreFactory>2){
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"> ";
        cin>>numOfCentreFactory;
    }
    std::cout<<std::endl;


    std::cout << "\nLet's Play!" << std::endl;
    std::cout << "\n=== Start Round ===" << std::endl;

    if(mode==1){
       
        if(tileBag->getSize() == 0){
        tileBag->fillBag();
        tileBag->Shuffle();
    }
        playMultiPlayer(numOfPlayers,numOfCentreFactory,tileBag,0);
    }

    if(mode==2){
        cout<<"=== Playing the game with six tiles ===  \n";
        cout<<std::endl;
        playTheSixTileMode(numOfPlayers,numOfCentreFactory,0);
    }
    if(mode==3){
        cout<<"=== Playing the game in grey-board mode ===  \n";
         if(tileBag->getSize() == 0){
        tileBag->fillBag();
        tileBag->Shuffle();
    }
        playTheGreyBoardMode(numOfPlayers,numOfCentreFactory,tileBag,0);
    }
    
}

// functions responsible to start the multiplayer mode
// group assignement constraints sustained and still met
//fixed a lot of issues from the last assignment
void mainGame::playMultiPlayer(int numOfPlayers, int numOfCentreFactory, Bag* tileBag,int loadValue){
    if(loadValue==0){
     makeFactoryFromBag(numOfPlayers,numOfCentreFactory,tileBag);
         makeBoardForPlayers(numOfPlayers);
         startGame(numOfPlayers,numOfCentreFactory,false,5);
    }
    else{
        startGame(numOfPlayers,numOfCentreFactory,false,5);
    }
}

//starts the game for a player 
void mainGame::startGame(int numOfPlayers,int numOfCentreFactory, bool greyBoard, int numOfTiles){
Player* p1 = new Player(player1Name,player1Scores);
p1->setFirstPlayer(1);

Player* p2 = new Player(player2Name,player2Scores);
if(numOfPlayers==2){
makeNewTurnForPlayer(p1,p2,nullptr,nullptr,numOfPlayers,numOfCentreFactory,greyBoard,numOfTiles);
}
if(numOfPlayers==3){
Player* p3 = new Player(player3Name,player3Scores);
makeNewTurnForPlayer(p1,p2,p3,nullptr,numOfPlayers,numOfCentreFactory,greyBoard,numOfTiles);
}
if(numOfPlayers==4){
Player* p3 = new Player(player3Name,player3Scores);
Player* p4 = new Player(player4Name,player4Scores);
makeNewTurnForPlayer(p1,p2,p3,p4,numOfPlayers,numOfCentreFactory,greyBoard,numOfTiles);
}
}

//make the initial factories for a round using the tile bag
void mainGame::makeFactoryFromBag(int numOfPlayers, int numOfCentreFactory, Bag* tileBag){
    if(factory->getTotalSize(numOfCentreFactory,numOfPlayers)==0 && numOfPlayers==2){
        if(numOfCentreFactory==1){
            factory->fillFactory(tileBag);
        }
        if(numOfCentreFactory==2){
            factory->fillFactoryTwoCentre(tileBag);
        }
    }

    if(factory->getTotalSize(numOfCentreFactory,numOfPlayers)==0 && numOfPlayers==3){
        if(numOfCentreFactory==1){
        factory->fillFactoryForThree(tileBag);
        }
        if(numOfCentreFactory==2){
            factory->fillFactoryForThreeCentreTwo(tileBag);
        }
    }
     if(factory->getTotalSize(numOfCentreFactory,numOfPlayers)==0 && numOfPlayers==4){
        if(numOfCentreFactory==1){

        factory->fillFactoryForFour(tileBag);
           
        }
        if(numOfCentreFactory==2){
            
            factory->fillFactoryForFourCentreTwo(tileBag);
           
        }
    }
    else{
        return;
    }
}

//instantiates the boards for each players depending on different cases
void mainGame::makeBoardForPlayers(int numOfPlayers){
      if(numOfPlayers==2){
    if(!boardsLoaded) {
        board1->makeBoard();  
        board2->makeBoard();
        
    }
    }
     else if(numOfPlayers==3){
    if(!boardsLoaded) {
        board1->makeBoard();  
        board2->makeBoard();
        board3->makeBoard();
    }
    }

    else if(numOfPlayers==4){
    if(!boardsLoaded) {
        board1->makeBoard();  
        board2->makeBoard();
        board3->makeBoard();
        board4->makeBoard();
    }
    }
    else {
        return;
    }
}

//validate the information for each player
void mainGame::validatePlayers(int numOfPlayers){
    if(numOfPlayers == 2){
        if(player1Name.length() == 0 && player2Name.length() == 0) {
        std::cout << "Enter a name for player 1" << endl;
        std::cout << "> ";
        std::getline(std::cin >> std::ws, player1Name);
        std::cout << "Enter a name for player 2"<< std::endl;
        std::cout << "> ";
        std::getline(std::cin >> std::ws, player2Name);
    }
    }
    else if(numOfPlayers ==3){
        if(player1Name.length() == 0 && player2Name.length() == 0 && player3Name.length()==0) {
        std::cout << "Enter a name for player 1" << endl;
        std::cout << "> ";
        std::getline(std::cin >> std::ws, player1Name);
        std::cout << "Enter a name for player 2"<< std::endl;
        std::cout << "> ";
        std::getline(std::cin >> std::ws, player2Name);
        std::cout << "Enter a name for player 3"<< std::endl;
        std::cout << "> ";
        std::getline(std::cin >> std::ws, player3Name);
    }
    }
    else if(numOfPlayers==4){
        if(player1Name.length() == 0 && player2Name.length() == 0 && player3Name.length()==0 && player4Name.length()==0) {
        std::cout << "Enter a name for player 1" << endl;
        std::cout << "> ";
        std::getline(std::cin >> std::ws, player1Name);
        std::cout << "Enter a name for player 2"<< std::endl;
        std::cout << "> ";
        std::getline(std::cin >> std::ws, player2Name);
        std::cout << "Enter a name for player 3"<< std::endl;
        std::cout << "> ";
        std::getline(std::cin >> std::ws, player3Name);
        std::cout << "Enter a name for player 4"<< std::endl;
        std::cout << "> ";
        std::getline(std::cin >> std::ws, player4Name);
    }

    }
}

//function responsible to start the game play
//most essential part of the mainGame class
// binds the code with the rest of the classes
// some code duplication could have been decreased but time is a contraint at such stage of semester
void mainGame::makeNewTurnForPlayer(Player* player1, Player* player2, Player* player3, Player* player4, int numOfPlayers, int numOfCentreFactory, bool greyBoard,int numOfTiles){


    Player* players[numOfPlayers];
    Board* boards[numOfPlayers];
    
    bool gameEnd = false;



      for(int i=0; i<numOfTiles; i++){
         //   while(gameEnd!=true && tileBag->getSize()>factory->getTotalSize(numOfPlayers,numOfCentreFactory)){
              // while(gameEnd!=true ){
                   while(gameEnd!=true && tileBag->getSize()>0){    
            while(factory->getTotalSize(numOfCentreFactory,numOfPlayers) > 0) {
                if(numOfPlayers==2){
                if(player1->getFirstPlayer() == 1){
                    players[0] = player1;
                    players[1] = player2;
                    boards[0] = board1;
                    boards[1] = board2;
                }
                else {
                    players[0] = player2;
                    players[1] = player1;
                    boards[0] = board2;
                    boards[1] = board1;
                }
                }
                //For 3 players, assigning players and board array
                else if(numOfPlayers==3){
                     if(player1->getFirstPlayer() == 1){
                    players[0] = player1;
                    players[1] = player2;
                    players[2] = player3;
                    boards[0] = board1;
                    boards[1] = board2;
                    boards[2] = board3;
                }
                else if(player2->getFirstPlayer()==1) {
                    players[0] = player2;
                    players[1] = player3;
                    players[2] = player1;
                    boards[0] = board2;
                    boards[1] = board3;
                    boards[2] = board1;
                }
                else{
                    players[0] = player3;
                    players[1] = player1;
                    players[2] = player2;
                    boards[0] = board3;
                    boards[1] = board1;
                    boards[2] = board2;
                }
                }
                //For four PLayers, assigning player and board array
                 else if(numOfPlayers==4){
                     if(player1->getFirstPlayer() == 1){
                    players[0] = player1;
                    players[1] = player2;
                    players[2] = player3;
                    players[3] = player4;
                    boards[0] = board1;
                    boards[1] = board2;
                    boards[2] = board3;
                    boards[3] = board4;
                }
                else if(player2->getFirstPlayer()==1) {
                    players[0] = player2;
                    players[1] = player3;
                    players[2] = player4;
                    players[3] = player1;
                    boards[0] = board2;
                    boards[1] = board3;
                    boards[2] = board4;
                    boards[3] = board1;
                }
                else if(player3->getFirstPlayer()==1) {
                    players[0] = player3;
                    players[1] = player4;
                    players[2] = player1;
                    players[3] = player2;
                    boards[0] = board3;
                    boards[1] = board4;
                    boards[2] = board1;
                    boards[3] = board2;
                }
                else{
                    players[0] = player4;
                    players[1] = player1;
                    players[2] = player2;
                    players[3] = player3;
                    boards[0] = board4;
                    boards[1] = board1;
                    boards[2] = board2;
                    boards[3] = board3;
                }
                }

                for(int i = 0; i < numOfPlayers; i++) {
                    //changes
                    if(factory->getSize(numOfCentreFactory,numOfPlayers) != 0){
                    Player* currentPlayer = players[i];
                    Board* currentBoard = boards[i];

                    std::cout << "TURN FOR PLAYER : " << currentPlayer->getName() << std::endl;
                    std::cout << std::endl;
                    std::cout << "Factories:" << std::endl;
                    if(numOfPlayers==2){
                    
                    factory->print(numOfCentreFactory);
                    }
                    if(numOfPlayers==3){
               
                        factory->printFactoryForThree(numOfCentreFactory);
                    }
                    if(numOfPlayers==4){
                     
                        factory->printFactoryForFour(numOfCentreFactory);
                    }
                    std::cout << "Mosaic for " << currentPlayer->getName() << ":" << std::endl;
                    //currentBoard->printBoard();
                    currentBoard->printColorBoard(greyBoard,sixTileMode);
                    printBoardForAllPlayer(numOfTiles,numOfPlayers,boards,players);
                    
                    std::cout << "> ";
                    string command;
                    
                    string secondArgument;
                    
                    char colour;
                    int row;

                    cin >> command;
                    
                    if(command == "help"){
                        helpMenu(numOfPlayers,numOfCentreFactory,numOfTiles);
                        std::cout<<"> ";
                        std::cin>>command;
                    }
                     cin >> secondArgument;
                   
                    if(command == "turn"){
                        int factoryIndex = stoi(secondArgument);
                        cin >> colour;
                        cin >> row;
                        while(factoryIndex>factory->numOfFactories(numOfPlayers,numOfCentreFactory)){
                                     cin.clear();
                                cin.ignore(256,'\n');
                               
                                cout<<"> ";
                                cin>>command;
                                cin>>secondArgument;
                                
                                 factoryIndex = stoi(secondArgument);
                                 cin>>colour;
                                 cin>>row;
                        }
                        //check this thoroughly
                        while(currentBoard->getEmptyRowSize(row-1)==0 || currentBoard->checkBoardForSameTile(colour,row-1)==0){
                            cin.clear();
                            cin.ignore(256,'\n');
                            cout<<"Row already filled, Make another turn : \n";
                            cout<<"> ";
                            cin>>command;
                            cin>>secondArgument;
                            factoryIndex = stoi(secondArgument);
                            cin>>colour;
                            cin>>row;
                        }
                        int numberTiles =0;
                        if(numOfPlayers==2){
                        numberTiles = factory->getNumberTiles(factoryIndex, colour, numOfCentreFactory);
                        }
                        if(numOfPlayers==3){
                        
                        //changes
                         numberTiles = factory->getNumberTilesForThree(factoryIndex,colour,numOfCentreFactory);
                        }
                        if(numOfPlayers==4){
                    
                        numberTiles = factory->getNumberTilesForFour(factoryIndex,colour,numOfCentreFactory);
                        }
                        //add a check for 1 also when numOfCentreFactory=2
                        if(numOfCentreFactory==1){
                        if(factoryIndex != 0){
                            std::cout << factoryIndex << colour << std::endl;
                            if(numOfPlayers==2){
                            factory->addRemainingTiles(factoryIndex, colour,numOfCentreFactory); 
                            }
                            if(numOfPlayers==3){
                            //changes
                            factory->addRemainingTilesForThree(factoryIndex,colour,numOfCentreFactory);
                            }
                            if(numOfPlayers==4){
                            factory->addRemainingTilesForFour(factoryIndex,colour, numOfCentreFactory);
                            }
                            std::cout << "Factory Size: " << factory->getTotalSize(numOfCentreFactory,numOfPlayers) << std::endl;  
                        } 
                        else{ 
                            
                            factory->removeElement(factoryIndex, colour, numOfCentreFactory,numOfPlayers);
                            if(factory->getTotalSize(numOfCentreFactory,numOfPlayers) > 0 && factory->firstPlayerTileExsists(numOfCentreFactory,0,numOfCentreFactory) == true){


                                //changes
                                factory->removeElement(0, 'F', numOfCentreFactory,numOfPlayers);
                                
                                currentPlayer->setFirstPlayer(1);
                                currentPlayer->updatePoints(-1);
                                currentBoard->addBrokenTile(1,0,'F');
                              
                            }
                            std::cout << "Factory Size: " << factory->getTotalSize(numOfCentreFactory,numOfPlayers) << std::endl; 
                        }
                    }


                    //changes 
                    if(numOfCentreFactory==2){
                          if(factoryIndex != 0 && factoryIndex!=1){
                          
                            if(numOfPlayers==2){
                            factory->addRemainingTiles(factoryIndex, colour,numOfCentreFactory); 
                            }
                            if(numOfPlayers==3){
                            //changes
                             factory->addRemainingTilesForThree(factoryIndex,colour,numOfCentreFactory);
                            }
                            if(numOfPlayers==4){
                            
                            factory->addRemainingTilesForFour(factoryIndex,colour,numOfCentreFactory);
                            }
                            std::cout << "Factory Size: " << factory->getTotalSize(numOfCentreFactory,numOfPlayers) << std::endl;  
                        } 
                        else{ 
                            if(factoryIndex==0){

                            
                            if(factory->getList()->findNode(0)->getTile()->getColour()!='F'){
                            factory->removeElement(factoryIndex, colour, numOfCentreFactory,numOfPlayers);
                           
                            factory->printFactoryForFour(numOfCentreFactory);
                            }
                            else{
                            if(factory->getTotalSize(numOfCentreFactory,numOfPlayers) > 0 && factory->firstPlayerTileExsists(numOfCentreFactory,0, numOfPlayers) == true ){
                                //Achieved
                                //changes
                                factory->removeElement(0, 'F', numOfCentreFactory,numOfPlayers);
                                currentPlayer->setFirstPlayer(1);
                                currentPlayer->updatePoints(-1);
                                currentBoard->addBrokenTile(1,0,'F');

                                
                                factory->removeElement(factoryIndex,colour,numOfCentreFactory,numOfPlayers);
                            }
                            else{
                                factory->removeElement(factoryIndex,colour,numOfCentreFactory,numOfPlayers);
                                return;
                            }
                            }
                            
                            }
                            if(factoryIndex==1){
                                 if(!factory->firstPlayerTileExsists(numOfCentreFactory,1,numOfPlayers)){
                                factory->removeElement(factoryIndex, colour, numOfCentreFactory,numOfPlayers);
                                if(factory->firstPlayerTileExsists(numOfCentreFactory,0,numOfPlayers)){
                                      
                                    currentPlayer->setFirstPlayer(1);
                                    currentPlayer->updatePoints(-1);
                                    currentBoard->addBrokenTile(1,0,'F');
                                    factory->removeElement(0,'F',numOfCentreFactory,numOfPlayers);
                                }
                                    
                                 }
                               
                                else{
                                    //changes
                                if(factory->getTotalSize(numOfCentreFactory,numOfPlayers) >0 && factory->firstPlayerTileExsists(numOfCentreFactory,0,numOfPlayers)==true){

                                   //changes
                                   factory->removeElement(0,'F',numOfCentreFactory,numOfPlayers);
                                    currentPlayer->setFirstPlayer(1);
                                    currentPlayer->updatePoints(-1);
                                    factory->removeElement(factoryIndex,colour,numOfCentreFactory,numOfPlayers);
                                }
                                else{
                                    
                                    factory->removeElement(factoryIndex,colour,numOfCentreFactory,numOfPlayers);
                                    return;
                                }

                                 }                       
                            
                            }
                            std::cout << "Factory Size: " << factory->getTotalSize(numOfCentreFactory,numOfPlayers) << std::endl; 
                        }
                    }
                        cout<<"Number of Tiles are"<<numberTiles<<std::endl;
                        currentBoard->addTile(row - 1, colour, numberTiles);
                        
                        std::cout<< "Turn succesful." << std::endl;
                        
                        playTurn = true;
                        
                    }
                    else if(command == "save") {
                        saveGame(secondArgument + ".txt",numOfPlayers,numOfCentreFactory,currentPlayer);
                        return;
                    }
                    else {

                        return;
                    }
                    }
                    
                }

            }

    
            std::cout << "=== END OF ROUND ===" << std::endl;
            
            

            
            if(greyBoard==true){
            cout<<"Place tile on board 1 of "<<player1Name<<endl;
            }
            board1->placeTileAtLast(greyBoard);
            if(greyBoard==true){
            cout<<"Place tile on board 2 of "<<player2Name<<endl;
            }
            board2->placeTileAtLast(greyBoard);
            if(numOfPlayers==3){
                if(greyBoard==true){
                cout<<"Place tile on board 3 of "<<player3Name<<endl;
                }
                board3->placeTileAtLast(greyBoard);
            }
            if(numOfPlayers==4){
                if(greyBoard==true){
                cout<<"Place tile on board 3 of "<<player3Name<<endl;
                }
                board3->placeTileAtLast(greyBoard);
                if(greyBoard==true){
                cout<<"Place tile on board 4 of "<<player4Name<<endl;
                }
                board4->placeTileAtLast(greyBoard);
            }
            
            //changes
            board1->removeTileFromBoard(tileBag);
            board2->removeTileFromBoard(tileBag);
            if(numOfPlayers==3){
                //changes
                board3->removeTileFromBoard(tileBag);
            }
            if(numOfPlayers==4){
                //changes
                board3->removeTileFromBoard(tileBag);
                board4->removeTileFromBoard(tileBag);
            }
            countpoints(player1, board1);
            countpoints(player2, board2);
            if(numOfPlayers==3){
                countpoints(player3, board3);
            }
            if(numOfPlayers==4){
                countpoints(player3,board3);
                countpoints(player4, board4);
            }
            std::cout << player1->getName() << " Total Points :" << player1->getPoints() << std::endl;
            std::cout << player2->getName() << " Total Points :" << player2->getPoints() << std::endl;

            if(numOfPlayers==3){
                std::cout << player3->getName() << " Total Points :" << player3->getPoints() << std::endl;
            }
            if(numOfPlayers==4){
                std::cout << player3->getName() << " Total Points :" << player3->getPoints() << std::endl;
                std::cout << player4->getName() << " Total Points :" << player4->getPoints() << std::endl;
            }

            if(numOfPlayers==3){ 
                if(tileBag->getSize()>=28 && numOfCentreFactory==1){
                factory->fillFactoryForThree(tileBag);
                }
                else if(tileBag->getSize()>=28 && numOfCentreFactory==2){
                    factory->fillFactoryForThreeCentreTwo(tileBag);
                }
                else{
                    if(numOfCentreFactory==1)
                      factory->fillFactoryForThree(tileBag);
                      else
                      {
                          factory->fillFactoryForThreeCentreTwo(tileBag);
                      }
                      
                }
            }
            else if(numOfPlayers==4){
                if(tileBag->getSize()>=36 && numOfCentreFactory==1){
                factory->fillFactoryForFour(tileBag);
                }
                else if(tileBag->getSize()>=36 && numOfCentreFactory==2){
                    factory->fillFactoryForFourCentreTwo(tileBag);
                }
                else{
                    if(numOfCentreFactory==1){
                    factory->fillFactoryForFour(tileBag);
                    }
                    else{
                        factory->fillFactoryForFourCentreTwo(tileBag);
                    }
                }
            }
            else
            {
                if(tileBag->getSize()>=20){
                    if(numOfCentreFactory==1){
                factory->fillFactory(tileBag);
                    }
                    if(numOfCentreFactory==2) {
                factory->fillFactoryTwoCentre(tileBag);
                    }
                
                }
                else{
                    if(numOfCentreFactory==1)
                    factory->fillFactory(tileBag);
                    else
                    {
                        factory->fillFactoryTwoCentre(tileBag);
                    }
                }
            }
           
            for(int k=0; k<5;k++){
              
            if(numOfPlayers==2){
                if(board1->checkTilesHorizontally(k)==5 || board2->checkTilesHorizontally(k)==5){
                    gameEnd = true;
                }
            }
            else if(numOfPlayers==3){
                if(board1->checkTilesHorizontally(k)==5  || board2->checkTilesHorizontally(k)==5 || board3->checkTilesHorizontally(k)==5){
                    gameEnd = true;
                }
            }
            else{
                if(board1->checkTilesHorizontally(k)==5  || board2->checkTilesHorizontally(k)==5 || board3->checkTilesHorizontally(k)==5  || board4->checkTilesHorizontally(k)==5){
                    gameEnd = true;
                }
            }
                }
    
    }
  }
  
    endGameResult(player1,player2,player3,player4,numOfPlayers);
   
}

//displays the result on the terminal once a game is completed
void mainGame::endGameResult(Player* player1, Player* player2, Player* player3, Player* player4, int numOfPlayers){
    std::cout << "=== GAME OVER ===" << std::endl;
    countpoints(player1,board1);
    countpoints(player2,board2);
    if(numOfPlayers==3){
        countpoints(player3,board3);
    }
    if(numOfPlayers==4){
        countpoints(player3,board3);
        countpoints(player4,board4);
    }
    if(numOfPlayers==4){
        decideWinner(player1,player2,player3,player4,numOfPlayers);
    }
    else if(numOfPlayers==3){
        decideWinner(player1,player2,player3,nullptr,numOfPlayers);
    }
    else
    {
        decideWinner(player1,player2,nullptr,nullptr,numOfPlayers);
    }
}


//compares the points of every player
void mainGame::decideWinner(Player* player1, Player* player2, Player* player3, Player* player4, int numOfPlayers){

if(numOfPlayers==4){
    int player4Points = player4->getPoints();
    int player3Points = player3->getPoints();
    int player2Points = player2->getPoints();
    int player1Points = player1->getPoints();
    if(player4Points>player3Points && player4Points>player2Points && player4Points>player1Points){
        std::cout << "Player "<< player4->getName() << " wins!"<< std::endl;   
    }
    else if(player3Points>player4Points && player3Points>player2Points && player3Points>player1Points){
        std::cout << "Player "<<player3->getName() << " wins!"<< std::endl;
    }
    else if(player2Points>player4Points && player2Points>player3Points && player2Points>player1Points){
        std::cout << "Player "<<player2->getName() << " wins!"<< std::endl;
    }
    else if(player1Points>player2Points && player1Points>player3Points && player1Points>player4Points){
        std::cout << "Player "<<player1->getName() << " wins!"<< std::endl;
    }
    else{
        std::cout << "Game Tied between the players"<<std::endl;
    }
    }

else if(numOfPlayers==3){
    int player3Points = player3->getPoints();
    int player2Points = player2->getPoints();
    int player1Points = player1->getPoints();
    if(player3Points>player2Points && player3Points>player1Points){
        std::cout << "Player "<<player3->getName() << " wins!"<< std::endl;
    }
    else if(player2Points>player3Points && player2Points>player1Points){
        std::cout << "Player "<<player2->getName() << " wins!"<< std::endl;
    }
    else if(player1Points>player2Points && player1Points>player3Points){
        std::cout << "Player "<<player1->getName() << " wins!"<< std::endl;
    }
    else{
        std::cout<< "Game Tied Between the players"<<std::endl;
    }
}
else{
    if(player1->getPoints() > player2->getPoints()){
        std::cout << "Player "<< player1->getName() << " wins!"<< std::endl;
    }
    else if(player2->getPoints() > player1->getPoints()){
        std::cout << "Player "<<player2->getName() << " wins!"<< std::endl;
    }
    else{
        std::cout<< "Game Tied Between the players"<<std::endl;
    }
}
}

//function for playing the six tile mode
//invokes the start game function
//checks if game is loadec or a new game started
void mainGame::playTheSixTileMode(int numOfPlayers, int numOfCentreFactory, int sixTileValue){
    if(sixTileValue==0){
        int numOfTiles=6;
        tileBag = new Bag(numOfTiles);
        this->sixTileMode=true;
        if(tileBag->getSize()==0){
            tileBag->fillBag();
            tileBag->Shuffle();
        }
        
        board1 = new Board(numOfTiles);
        board2 = new Board(numOfTiles);
        board3 = new Board(numOfTiles);
        board4 = new Board(numOfTiles);
        makeFactoryFromBag(numOfPlayers,numOfCentreFactory,tileBag);
        makeBoardForPlayers(numOfPlayers);
        startGame(numOfPlayers,numOfCentreFactory,false,6);
    }
    else{
         tileBag = new Bag(6);
          if(tileBag->getSize()==0){
            tileBag->fillBag();
            tileBag->Shuffle();
        }

        startGame(numOfPlayers,numOfCentreFactory,false,6);
    }

}

//function responsible for playing the grey board mode
//checks if game is loadec or a new game started
void mainGame::playTheGreyBoardMode(int numOfPlayers, int numOfCentreFactory, Bag* tileBag, int greyBoardValue){    
        
        if(greyBoardValue==0){
        bool greyBoard = true;
        int numOfTiles = 5;
        this->greyBoardMode = true;
        board1 = new Board(numOfTiles);
        board2 = new Board(numOfTiles);
        board3 = new Board(numOfTiles);
        board4 = new Board(numOfTiles);
        makeFactoryFromBag(numOfPlayers,numOfCentreFactory,tileBag);
        makeBoardForPlayers(numOfPlayers);
        startGame(numOfPlayers,numOfCentreFactory,greyBoard,5);
        }
        else {
            bool greyBoard = true;
            startGame(numOfPlayers,numOfCentreFactory,greyBoard,5);
        }

}

//returns the value of private variable
//mostly used to load file correctly
bool mainGame::getGreyBoardValue(){
    return this->greyBoardMode;
}

//returns the value of private variable
//mostly used to load file correctly
bool mainGame::getsixTileValue(){
    return this->sixTileMode;
}

//This is a help menu 
//Provides some suitable directions to the user depending on the game state
void mainGame::helpMenu(int numOfPlayers, int numOfCentreFactory, int numOfTiles){

    
    if(playTurn==true && numOfTiles==5 && greyBoardMode==false){
        cout<<"                Mode: YOU ARE IN A MULTIPLAYER MODE                      \n";
        cout<<"                      COMPETING AGAINST "<<numOfPlayers<<" OTHER PLAYERS \n";
        cout<<" ALL THE TILES ON THE MOSAIC ARE PLACED AUTOMATICALLY AT THE END OF EACH ROUND \n";

        cout<<"          You should be using the given format to play a turn            \n";
        cout<<"                  turn <factory> <colour> <storage row>                  \n";
    }
    else if(playTurn==true && numOfTiles==6 && greyBoardMode==false){
        cout<<"               Mode: YOU ARE IN THE SIX TILE MODE                        \n";
        cout<<"                     COMPETING AGAINST "<<numOfPlayers<<" OTHER PLAYERS  \n";
        cout<<" ALL THE TILES ON THE MOSAIC ARE PLACED AUTOMATICALLY AT THE END OF EACH ROUND \n";

        cout<<"          You should be using the given format to play a turn            \n";
        cout<<"                  turn <factory> <colour> <storage row>                  \n";
    }
    else if(playTurn==true && numOfTiles==5 && greyBoardMode==true){
        cout<<"                   Mode: YOU ARE IN THE GREY BOARD MODE                        \n";
        cout<<"                         COMPETING AGAINST "<<numOfPlayers<<" OTHER PLAYERS    \n";
        cout<<" YOU ARE REQUIRED TO CHOOSE THE POSITION OF THE TILES PLACED AT THE MOSIAC AFTER EACH ROUND \n";

        cout<<"                You should be using the given format to play a turn            \n";
        cout<<"                        turn <factory> <colour> <storage row>                  \n";
    }
    else{
    cout<<"In which Area do you need the help with?";
    cout<<"1. Playing a Turn"<<endl;
    cout<<"2. Saving a File"<<endl;
    cout<<"3. Loading from a File"<<endl;
    cout<<"> ";
    int userInput;
    cin>>userInput;

     while(userInput>3){
         cin.clear();
         cin.ignore(256,'\n');
         cout<<"> ";
         cin>>userInput;
     }

    if(userInput==1){
        cout<<"          You should be using the given format to play the turn  \n";
        cout<<"                  turn <factory> <colour> <storage row>          \n";
        cout<<endl;
        cout<<"    Here,\n";
        cout<<"      A. <factory> suggests a number of the factory to draw from \n";
        cout<<"      B. <colour> suggests the colour to take from the factory   \n";
        cout<<"      C. <storage row> suggests the row in the mosaic storage to place the tiles \n";
    }
    else if(userInput==2){
        cout<<"          You should be using the given format to save the game at any stage \n";
        cout<<"                                    save <file>                              \n";
        cout<<"    Here,\n";
        cout<<"            <filename> suggests the name of the file without .txt extension  \n";
        cout<<"                       It will overwrite the already existing file           \n";
    }
    else if(userInput==3){
        cout<<"    You should be using the given format to load from a file before starting a new round \n";
        cout<<"                                 load <filename.txt>                                     \n";
        cout<<"                                      Enter the filename with .txt extension             \n";
    }
    else{
        //DO NOT WORRY ABOUT THIS -> ALREADY IMPOSSIBLE VALUES CHECK COMPLETED
        cout<<"    Wrong choice made, Enter your choice again from the above Menu";
        //recursive call
        helpMenu(numOfPlayers,numOfCentreFactory,numOfTiles);
    }
    }

}


//function responssible to print all the boards parallely on the terminal
//invokes the method in board class that prints particular row for a board
void mainGame::printBoardForAllPlayer(int numOfTiles, int numOfPlayers, Board* board[], Player* player[]){

    //cout<<"Mosaic for All the Players: \n";
    if(numOfTiles==5){
        for(int j=0; j<numOfPlayers; j++){
            cout<<"Mosaic for "<<player[j]->getName()<<":  \t  \t  \t";
        }
        std::cout<<std::endl;
        for(int i =0; i<5; i++){
           for(int k=0; k<numOfPlayers; k++){
               cout<<i+1<<": ";
             //  board[k]->printBoardRow(i);
               board[k]->printColorBoardRow(i,greyBoardMode,sixTileMode);
           }
           cout<<std::endl;
        }
       for(int k=0; k<numOfPlayers; k++){
            board[k]->printBrokenTiles();
            cout<<"  \t   \t   \t  \t";
        }
        cout<<endl;
    }
    else {
        for(int j=0; j<numOfPlayers; j++){
            cout<<"Mosaic for "<<player[j]->getName()<<":  \t  \t  \t";
        }
        std::cout<<std::endl;
        for(int i=0; i<6; i++){
            for(int k=0; k<numOfPlayers; k++){
                cout<<i+1<<":";
               // board[k]->printBoardRow(i);
               board[k]->printColorBoardRow(i,greyBoardMode,sixTileMode);
            }
            cout<<std::endl;
        }
        for(int k=0; k<numOfPlayers; k++){
            board[k]->printBrokenTiles();
            cout<<"   \t  \t  \t  \t";
        }
        cout<<std::endl;

    }

}


