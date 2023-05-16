#include "qapplication.h"
#include <iostream>
#include <QDebug>
#include <QApplication>
//#include <QMediaPlayer>

using namespace std;
#include "ZorkUL.h"
#include "Character.h"
#include "Room.h"
#include "Escape.h"
#include "toEscape.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ZorkUL temp;
//    QMediaPlayer *player = new QMediaPlayer;
//    player->setMedia(QUrl::fromLocalFile("/path/to/audio/file.mp3"));
//    player->setVolume(50);
//    player->play();

    return a.exec();
}


ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    toEscape *attic, *livingRoom, *bedroom, *utility, *kitchen, *office, *entryway, *bathroom, *landing;
    Escape *escape;
    Character *player;

    attic = new toEscape("attic");
    attic->addItem(new Item("key", "Office", 1, 2));
    attic->addItem(new Item("flashlight", "attic", 1, 2));
    livingRoom = new toEscape("Living Room");
    livingRoom->addItem(new Item("door", "Living Room" , 2, 0));
    bedroom = new toEscape("Bedroom");
    bedroom->addItem(new Item("hammer", "Landing", 3, 2));
    bedroom->addItem(new Item("combinationLock", "Bedroom", 2, 4));
    utility = new toEscape("Utility");
    utility->addItem(new Item("dog", "Utility", 2, 0));
    utility->addItem(new Item("dog food", "Utility", 1, 2));
    utility->addItem(new Item("press", "Utility", 2, 4));
    kitchen = new toEscape("Kitchen");
    kitchen->addItem(new Item("fire", "Kitchen", 2, 0));
    kitchen->addItem(new Item("fireExtinguisher", "Kitchen", 1, 2));
    kitchen->addItem(new Item("key", "Living Room", 3, 2));
    office = new toEscape("Office");
    office->addItem(new Item("safe", "Office", 2, 4));
    office->addItem(new Item("codes", "Bedroom", 3, 2));
    office->addItem(new Item("bookcase", "Office", 2, 0));
    office->addItem(new Item("looseBook", "Office", 1, 4));
    entryway = new toEscape("Entryway");
    entryway->addItem(new Item("lock", "Entryway", 2, 4));
    bathroom = new toEscape("Bathroom");
    bathroom->addItem(new Item("uvLight", "Bathroom", 1, 2));
    bathroom->addItem(new Item("combinationLock", "Bathroom", 2, 4));
    landing = new toEscape("Landing");
    landing->addItem(new Item("lockedDoor", "Landing", 2, 3));
    landing->addItem(new Item("vase", "Landing", 2, 3));
    landing->addItem(new Item("key", "Landing", 1, 2));
    escape = new Escape("Escape");

    player = new Character("player");


    //             (N, E, S, W)
    attic->setExits(office, NULL, NULL, NULL);
    livingRoom->setExits(entryway, NULL, NULL, NULL);
    bedroom->setExits(NULL, NULL, landing, NULL);
    utility->setExits(NULL, kitchen, NULL, NULL);
    kitchen->setExits(livingRoom, NULL, NULL, NULL);
    office->setExits(NULL, NULL, NULL, bathroom);
    entryway->setExits(escape, NULL, NULL, NULL);
    bathroom->setExits(NULL, NULL, bedroom, NULL);
    landing->setExits(NULL, utility, NULL, NULL);

    currentRoom = attic;
    currentCharacter = player;
}

/**
 *  Main play routine.  Loops until end of play.
 */
string ZorkUL::play() {
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    string finished = "false";
    while (finished != "false") {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    return "false";
}

string ZorkUL::printWelcome() {
    string toPush = "Start: enter 'info' to get help on commands. \n " + currentRoom -> longDescription();
    return toPush;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
string ZorkUL::processCommand(Command command) {
    //string output = "";
    if (command.isUnknown()) {
        return "invalid input";
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0){
        string output = printHelp();
        return output;
    }

    else if (commandWord.compare("map") == 0)
    {
        string map = "[Bathroom] --- [Office]       [Entryway]\n"
                     "        |                   |                     | \n"
                     "        |                   |                     | \n"
                     "[Bedroom]      [Attic]        [Living Room]\n"
                     "        |                                          | \n"
                     "        |                                          | \n"
                     "[Landing] --- [Utility]   ---   [Kitchen]\n";
        return map;
    }

    else if (commandWord.compare("go") == 0){
        string inv = currentCharacter->printInventory();
        string getRoom = currentRoom->shortDescription();
        string moveOn = currentRoom->getOrder(getRoom, inv);
        if (moveOn == "true"){
            string room = goRoom(command);
            return room;
        } else {
            return moveOn;
        }

    }

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
            return "incomplete input";
        }
        else
            if (command.hasSecondWord()) {
            string strO = "you're trying to take: " + command.getSecondWord() + "\n";
                int location = currentRoom->isItemInRoom(command.getSecondWord());
                if (location  == -1 ){
                    strO += " item is not in room \n" + currentRoom->longDescription() ;
                }
                else{
                    Item* currentItem = currentRoom->getItemFromRoom(location);
                    int value = currentItem->getRoomToUse(currentRoom->shortDescription());
                    if (value == 2){
                        strO += "You cannot take this item but you can use another item on it";
                    } else {
                        currentCharacter->addItem(currentItem);
                        currentRoom->removeItemFromRoom(location);
                        strO += "item is in room \n" + currentRoom->longDescription();
                    }
                }
                return strO;
            }
    }

    else if (commandWord.compare("put") == 0)
    {
        if (!command.hasSecondWord()) {
            return "incomplete input";
        }
        else if (command.hasSecondWord()) {
            string str1 = "";
                str1 += "you're adding " + command.getSecondWord() + "\n";
                Item itemToPut = currentCharacter->hasItem(command.getSecondWord());
                if(itemToPut.getShortDescription().compare("Nothing") == 0){
                    str1 += "You dont have this item in your inventory. \n" + currentRoom->longDescription() + "\n";
                }
                else {
                    int canUse = itemToPut.getRoomToUse(currentRoom->shortDescription());
                    str1 += "value: " + to_string(canUse) + "\n";
                    if (canUse == 3){
                        str1 += "You cannot use this item in this room \n";
                    } else {
                        currentRoom->addItem(&itemToPut);
                        currentCharacter->putItem(&itemToPut);
                        str1 += "And you manage to sucessfully \n" + currentRoom->longDescription();
                    }
                }
                return str1;
            }

    }
    else if (commandWord.compare("use") == 0)
    {
            if (!command.hasSecondWord()) {
                return "incomplete input";
            }
            else if (command.hasSecondWord()) {
                string str1 = "";
                str1 += "you're using " + command.getSecondWord() + "\n";
                Item itemToPut = currentCharacter->hasItem(command.getSecondWord());
                if(itemToPut.getShortDescription().compare("Nothing") == 0){
                    str1 += "You dont have this item in your inventory. \n" + currentRoom->longDescription() + "\n";
                }
                else {
                    int canUse = itemToPut.getRoomToUse(currentRoom->shortDescription());
                    int function = itemToPut.getFunction();
                    //str1 += "value: " + to_string(canUse) + "\n";
                    if (canUse == 3){
                        str1 += "You cannot use this item in this room \n";
                    }
                    else if (function != 2) {
                        str1 += "You cannot perform this action with this item, try another";
                    }
                    else{
                        currentCharacter->putItem(&itemToPut);
                        str1 += "And you manage to sucessfully \n" + currentRoom->longDescription();
                    }
                }
                return str1;
            }

    }

    else if (commandWord.compare("smash") == 0)
    {
            if (!command.hasSecondWord()) {
                return "incomplete input";
            }
            else if (command.hasSecondWord()) {
                string str1 = "";
                str1 += "you're trying to smash " + command.getSecondWord() + "\n";
                int location = currentRoom->isItemInRoom(command.getSecondWord());
                if (location  == -1 ){
                    str1 += " item is not in room \n" + currentRoom->longDescription() ;
                }
                else {
                    Item hammer = currentCharacter->hasItem("hammer");
                    if(hammer.getShortDescription().compare("Nothing") == 0){
                        str1 += "You must have the hammer in your inventory. \n" + currentRoom->longDescription() + "\n";
                        return str1;
                    }
                    Item* currentItem = currentRoom->getItemFromRoom(location);
                    currentCharacter->addItem(currentItem);
                    Item itemToPut = currentCharacter->hasItem(command.getSecondWord());
                    int function = itemToPut.getFunction();
                    if (function != 3){
                        str1 += "You cannot perform this action with this item, try another \n";
                    } else {
                        currentRoom->removeItemFromRoom(location);
                        str1 += "you have sucessfully smashed the " + command.getSecondWord();
                    }
                    currentCharacter->putItem(&itemToPut);
                }
                return str1;
            }

    }
    else if (commandWord.compare("open") == 0)
    {
            if (!command.hasSecondWord()) {
                return "incomplete input";
            }
            else if (command.hasSecondWord()) {
                string str1 = "";
                str1 += "you're trying to open " + command.getSecondWord() + "\n";
                int location = currentRoom->isItemInRoom(command.getSecondWord());
                if (location  == -1 ){
                    str1 += " item is not in room \n" + currentRoom->longDescription() ;
                }
                else {
                    if(command.getSecondWord() == "safe"){
                        Item key = currentCharacter->hasItem("key");
                        if(key.getShortDescription().compare("Nothing") == 0){
                            str1 += "You must have the key in your inventory. \n" + currentRoom->longDescription() + "\n";
                            return str1;
                        }
                    }else if(command.getSecondWord() == "combinationLock"){
                        Item key = currentCharacter->hasItem("codes");
                        if(key.getShortDescription().compare("Nothing") == 0){
                            str1 += "You must have the codes in your inventory. \n" + currentRoom->longDescription() + "\n";
                            return str1;
                        }
                    }
                    Item* currentItem = currentRoom->getItemFromRoom(location);
                    currentCharacter->addItem(currentItem);
                    Item itemToPut = currentCharacter->hasItem(command.getSecondWord());
                    int function = itemToPut.getFunction();
                    if (function != 4){
                        str1 += "You cannot perform this action with this item, try another \n";
                    } else {
                        currentRoom->removeItemFromRoom(location);
                        str1 += "you have sucessfully opened the " + command.getSecondWord();
                    }
                    currentCharacter->putItem(&itemToPut);
                }
                return str1;
            }

    }

    else if (commandWord.compare("inventory") == 0){
        return currentCharacter->printInventory();
    }

    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
                return "overdefined input";
        else
            return "true"; /**signal to quit*/
    }
    return "test";
}
/** COMMANDS **/
string ZorkUL::printHelp() {
    string output = "valid inputs are; \n" + parser.showCommands() + "\nType the command followed by the object name.";
    return output;
}

string ZorkUL::goRoom(Command command) {
    string returnStr = "";
    if (!command.hasSecondWord()) {
        returnStr += "incomplete input";
        //printOut(returnStr);
        return returnStr;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        returnStr += "no room in this direction";
    else {
        currentRoom = nextRoom;
        returnStr += currentRoom->longDescription();
    }
    return returnStr;
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
