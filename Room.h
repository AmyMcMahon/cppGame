#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
    map<string, Room*> exits;
    string exitString();
    vector <Item> itemsInRoom;

protected:
    string description;
    string descriptionR;

public:
    int numberOfItems();
    Room(string description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription();
    virtual string longDescription() = 0;
    virtual string getOrder(string currentR, string inv, string command, string objectIn);
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    Item* getItemFromRoom(int location);
    int addToRoom(string inString);
    void removeItemFromRoom(int location);
    Item checkRoom(string description);
};

#endif
