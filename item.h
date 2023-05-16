#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
    string description;
    string longDescription;
    string roomToUse;
    int value;
    int function;
    bool weaponCheck;

public:
    Item (string description, string inRoom, int useVal, int function);
    Item (string description);
    string getShortDescription();
    int getRoomToUse(string currentR);
    string getLongDescription();
    string getRoomTaken();
    string getRoomToUseName();
    int getValue();
    int setValue(int value);
    int getFunction();
    string whereToUse(Item objectUse);
};

#endif /*ITEM_H_*/
