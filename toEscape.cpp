#include "toEscape.h"
#include <sstream>
#include <qDebug>

toEscape::toEscape(string description) : Room(description) {}

string toEscape :: longDescription() {
    if (description == "attic"){
        return "You are in the attic, it is pitch black. \n You feel around and find a flashlight.";
    } else if (description == "Office"){
        return "You are now in the office. You see a large bookcase and a safe.\n You first go over to the safe and find you need a key to open it. ";
    } else id (description == "Bathroom") {
        return "You have entered the bathroom.";
    }
}

string toEscape:: attic(string inv, string command, string objectIn){
    if (command.compare("go") == 0){
        bool hasKey = false;
        bool hasFlashlight = false;
        size_t foundF = inv.find("flashlight");
        size_t foundK = inv.find("key");

        if (foundF != string::npos){
            hasFlashlight = true;
        }
        if (foundK != string::npos){
            hasKey = true;
        }

        if (hasKey && hasFlashlight) {
            return "true";
        } else if (hasKey) {
            return "You have found the key. Keep looking for the flashlight!";
        } else if (!hasFlashlight && !hasKey) {
            return "You have not found the key or flashlight yet.";
        } else {
            return "You have found the flashlight - to use type 'use flashlight'";
        }
    } else if (command.compare("take") == 0){
        if (objectIn == "flashlight"){
            return "You have found the flashlight you can now use it to explore the room";
        } else if (objectIn == "key"){
            return "You take the key and walk over to the door.\n You find the door unlocked. \n You must need the key in a different room.\n You can go north";
        }
    } else if(command.compare("use") == 0){
        if (objectIn == "flashlight"){
            return "You look around the room, you see a door and a table. \nYou walk over to the table and find a key";
        }
    } else {
        return "invalid request";
    }
}

string toEscape:: office(string inv, string command, string objectIn){
    if(command.compare("open") ==0) {
        if (objectIn == "safe"){
            return "You have opened the safe and you have found a sheet with codes.";
        }
    } else if (command.compare("use") == 0) {
        if (objectIn == "key"){
            return "You have unlocked the safe and can now open it.";
        }
    } else if (command.compare("take") == 0){
        if (objectIn == "codes"){
            return "The safe is now empty. You go investigate the bookcase. \n There is an empty space in one shelf. You see a book on the table.";
        } if (objectIn == "book"){
            return "You take the book and you can now 'put book'";
        }
    } else if (command.compare("put") == 0){
        if (objectIn == "book"){
            return "The bookcase suddenly swings open and you can go west";
        }
    } return "wronG";
}


string toEscape:: getOrder(string currentR, string inv, string command, string objectIn){
    if (currentR == "attic"){
        return attic(inv, command, objectIn);
    }else if (currentR == "Office"){
        return office(inv, command, objectIn);
    }
}
