#include "Character.h"
#include "Room.h"
#include "toEscape.h"
#include <qDebug>

Character::Character(string description) {
    this->description = description;
}
void Character::addItem(Item *item) {
    itemsInCharacter.push_back(*item);
    stringInv.push_back(item->getShortDescription());
}
string Character::putItem(Item *item) {
    int location = getItemIndex(item);
    if (location == -1){
        return "you don't have the item";
    }
    else{
        itemsInCharacter.erase(itemsInCharacter.begin()+location);
    }
    return "";
}
int Character::getItemIndex(Item *item){
    string name = item->getShortDescription();
    int size = itemsInCharacter.size();
    for (int i = 0; i < size; i++){
        if(itemsInCharacter[i].getShortDescription().compare(name) == 0)
            return i;
    }
    return -1;
}

Item Character::hasItem(string name){
    for (Item i : itemsInCharacter)
        if(i.getShortDescription().compare(name) == 0)
            return i;
    Item* temp = new Item("Nothing");
    return *temp;
}

string Character::printInventory()
{
    string output = "";
    for (Item i : stringInv)
        output += (i).getShortDescription() + ", ";
    return output;
//    for (Item i : itemsInCharacter)
//        output += (i).getShortDescription() + ", ";
//    return output;
}

string Character::longDescription()
{
    string ret = this->description;
    ret += "\n Item list:\n";
    for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
        ret += "\t"+ (*i).getLongDescription() + "\n";
    return ret;
}

string bitStructure(vector<string>&itemsC, vector<string>&itemsR){
    struct BitStructure {
        unsigned int invN : 2;
        unsigned int roomN : 3;
    };

    int cItems = itemsC.size();
    int rItems = itemsR.size();

    int cBits = log2(cItems) + 1;
    int rBits = log2(rItems);

    string str1;

    BitStructure bs;
    bs.invN = 2;
    bs.roomN = 3;

    if (bs.invN < cBits){
        str1 += "too many items in inv\n";
    }
    if (bs.roomN < rBits){
        str1 += "too many items in room\n";
    }

    return str1;
}


