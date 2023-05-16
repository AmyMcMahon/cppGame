#include "toEscape.h"
#include <sstream>

toEscape::toEscape(string description) : Room(description) {}

string toEscape :: longDescription() {
    if (description == "attic"){
        return "You are in the attic, it is pitch black. \n You feel around and find a flashlight.";
    } else{
        return "oops";
    }
}

string toEscape:: attic(string inv){
    vector<string> inventory;
    stringstream ss(inv);
    string item;
    while (getline(ss, item, ',')) {
        inventory.push_back(item);
    }

    bool hasKey = false;
    bool hasFlashlight = false;

    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == "key") {
            hasKey = true;
        }
        if (inventory[i] == "flashlight") {
            hasFlashlight = true;
        }
    }

    if (hasKey && hasFlashlight) {
        return "You have found the key and flashlight! You can now move to the next room.";
    } else if (hasKey) {
        return "You have found the key. Keep looking for the flashlight!";
    } else {
        return "You have not found the key or flashlight yet.";
    }

}

string toEscape:: getOrder(string currentR, string inv){
    if (currentR == "attic"){
        return attic(inv);
    }
    return "oop";
}
