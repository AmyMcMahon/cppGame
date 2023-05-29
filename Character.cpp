#include "Character.h"
#include "Room.h"
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

//void Character::addToInventory(Item inString)
//{
//   itemsInCharacter.push_back(inString);
//}

//Item Character:: checkInv(string description){
//   int sizeItems = (itemsInCharacter.size());
//   for (int i = 0; i < sizeItems; i++) {
//        int tempFlag = description.compare( itemsInCharacter[i].getShortDescription());
//        if (tempFlag == 0) {
//            return itemsInCharacter[i];
//        }
//   }
//}

//int Character::removeFromInventory(Item inString)
//{
//   int sizeItems = (itemsInCharacter.size());
//   if (itemsInCharacter.size() < 1) {
//    return false;
//   }
//   else if (itemsInCharacter.size() > 0) {
//    int x = (0);
//    for (int n = sizeItems; n > 0; n--) {
//        // compare inString with short description
//        int tempFlag = inString.getShortDescription().compare( itemsInCharacter[x].getShortDescription());
//        if (tempFlag == 0) {
//            itemsInCharacter.erase(itemsInCharacter.begin()+x);
//        }
//        x++;
//    }
//   }
//   return -1;
//}


