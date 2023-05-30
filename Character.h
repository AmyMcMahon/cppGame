#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "item.h"
#include "mainwindow.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
    string description;



public:
    void addItem(Item *item);
    string putItem(Item *item);
    int getItemIndex(Item *item);
    Item hasItem(string name);
    string printInventory();
    vector<string> stringInv;
    vector < Item > itemsInCharacter;

public:
    Character(string description);
    string shortDescription();
    string longDescription();
    string bitStructure(vector<string>&itemsC, vector<string>&itemsR);
    friend class MainWindow;
};

#endif /*CHARACTER_H_*/
