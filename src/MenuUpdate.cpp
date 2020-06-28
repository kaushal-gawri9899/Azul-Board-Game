#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "mainGame.h"


using namespace std;
void showMenu();
void newGame();
void loadGame();
void credits();
void quit();

void playTurn(Factory *f, Board *board);

//a game is played only after the user puts 's' ad an args after the compilation is completed
int main(int argc, char *argv[])
{
    
    
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-s") == 0)
        {
            showMenu();
        }
    }

    return 0;

}

//displays the game menu to the user
void showMenu()
{
    cout << "\nWelcome to Azul!" << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "\n Menu" << endl;
    cout << "_ _ _ _ _" << endl;

    cout << "\n1. New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Credits" << endl;
    cout << "4. Quit" << endl;
    string choice;
    cout << "> ";
    cin >> choice;
    if (choice == "1")
    {
        cout << "\n"
             << endl;
        newGame();
    }

    if (choice == "2")
    {
        cout << "\n"
             << endl;
        loadGame();
    }
    if (choice == "3")
    {
        cout << "\n"
             << endl;
        credits();
    }
    if (choice == "4")
    {
        cout << "\n"
             << endl;
        quit();
    }

    if (choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "Incorrect Option, please choose from the menu given" << endl;
        showMenu();
    }
}

//function that makes an object of maingame and invokes the required function to start a new game
void newGame()
{
    mainGame* game = new mainGame();
    cout<<"Enter number of Players \n";
    cout<<"> ";
    int numOfPlayers;
    cin>>numOfPlayers;
    while(numOfPlayers>4 || numOfPlayers<2){
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Invalid Number Of Players \n";
        cout<<"Enter number Of Players Again \n";
        cout<<"> ";
        cin>>numOfPlayers;
    }
   game->playGameUpdated(numOfPlayers);
   
    showMenu();
}

//function that invokes the function required to load a game in mainGame
//could have just made an object of maingame in constructor rather than creating in every other functions, realized quite lately
void loadGame()
{
    mainGame* game = new mainGame();
    cout << "Enter File Name from which load a game: \n";
    cout << "> ";
    string fileName;
    string line;
    cin >> fileName;
    ifstream myFile(fileName);
    if (myFile.is_open())
    {
        cout << "Azul game successfully loaded" << endl;
        game->LoadGame(fileName,game->getGreyBoardValue(), game->getsixTileValue());
        myFile.clear();
        myFile.close();
    }
    else
        cout << "\nUnable to Open File" << endl;

    showMenu();
}

//prints the credits for the assignment on the terminal
void credits()
{
    cout << "Name: Prabhav Mehra" << endl;
    cout << "Student ID: s3743761" << endl;
    cout << "Email: s3743761@student.rmit.edu.au" << endl;

    cout << "\nName: Kaushal Gawri" << endl;
    cout << "Student ID: s3777121" << endl;
    cout << "Email: - s3777121@student.rmit.edu.au" << endl;

    cout << "\nName: Ali Tariq" << endl;
    cout << "Student ID: -" << endl;
    cout << "Email: @student.rmit.edu.au" << endl;
    showMenu();
}

//exit the game
void quit()
{
    cout << "Thanks for Playing." << endl;
    cout<< "Would you like to save the game ? "<<endl;
    char choice;
    cout<< "Y/N: ";
    cin>>choice;

    if(choice == 'Y'){
        return;
    }

    else if(choice == 'N'){
        cout<<"Thanks for Playing."<<endl;
        return;
    }
    else
    {
        throw std::invalid_argument("You can only Enter Y or N");
        showMenu();

    }

}
