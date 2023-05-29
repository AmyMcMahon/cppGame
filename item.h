#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
    string longDescription;
    int value;
    string description;
    int function;
    bool weaponCheck;

protected:
    string roomToUse;
    string descriptionI;

public:
    int invCount;
    template <typename T> T invAdd(T x);
    template <typename T> T invRemove(T x);
    Item (string description, string inRoom, int useVal, int function);
    Item (string description);
    string getShortDescription();
    int getRoomToUse(string currentR);
    string getLongDescription();
    string getRoomTaken();
    string getRoomToUseName();
    void setRoomToUse(const string& roomToUse);
    int getValue();
    int setValue(int value);
    int getFunction();
    string whereToUse(Item objectUse);
};


#endif /*ITEM_H_*/
