#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "Character.h"
#include "mainwindow.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Parser parser;
    Room *currentRoom;
    Character *currentCharacter;
    MainWindow *currentWindow;
    void createRooms();
    string processCommand(Command command);
    string printHelp();
    string goRoom(Command command);
    void createItems();
    void displayItems();


public:
    ZorkUL();
    string printWelcome();
    string currentR();
    string printAttic();
    string play();
    Item changeVal();
    string getData(string info);
    string go(string direction);
};

#endif /*ZORKUL_H_*/
