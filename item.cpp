#include "item.h"
#include <qDebug>

Item::Item (string inDescription, string inRoom, int useVal, int inFunction/**, int weaponCheck*/) {
    description = inDescription;
    roomToUse = inRoom;
    value = useVal;
    function = inFunction;
    /**weaponCheck(isWeapon);*/
}

Item::Item(string inDescription) {
    description = inDescription;
}


int Item::setValue(int useVal)
{
    if (useVal == 3)
        value = 1 ;
    return value;
}

/**void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
}*/

string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + ".\n";
}

int Item::getRoomToUse(string currentR)
{
    if (currentR == roomToUse && value == 3){
        setValue(3);
    } else if(currentR != roomToUse){
        value = 3;
    }
    return value;
}

int Item::getFunction()
{
    return function;
}

string Item::getRoomToUseName()
{
    return roomToUse;
}

string Item :: whereToUse(Item objectUse){
    string currentR = objectUse.getRoomToUseName();
    int objectUseInt = objectUse.getRoomToUse(currentR);
    if (objectUseInt == 3){
        return "You cannot use this item in this room";
    }
}


