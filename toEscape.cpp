#include "toEscape.h"
#include <sstream>
#include <qDebug>

toEscape::toEscape(string description) : Room(description) {}

string toEscape :: longDescription() {
    qDebug() << description;
    if (description == "attic"){
        return "You are in the attic, it is pitch black. \n You feel around and find a flashlight.";
    } else if (description == "Office"){
        return "You are now in the office. You see a large bookcase and a safe.\n You first go over to the safe and find you need a key to open it. ";
    } else if (description == "Bathroom") {
        return "You have entered the bathroom.\n On the counter you see a UV torch\n (to take it you must say 'take uvLight')";
    }else if (description == "Bedroom") {
        return "You are in the bedroom.\n You see a hammer on the bed";
    }else if (description == "Landing") {
        return "Now you are in the landing. There is a locked door. \n There is a vase beside the door (remember your hammer)";
    }else if (description == "Utility") {
        return "In the utility there is a large dog blocking the door.\n You look to the right and see a press.";
    }else if (description == "Living Room") {
        return "In the Living Room you see a borded up door.\n You need to smash the boards.";
    }else if (description == "Kitchen") {
        return "You are in the kitchen. There is a large fire. You see an extinguisher";
    }else {
        throw MyException("Invalid request"); // Throw custom exception
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
        throw MyException("Invalid request"); // Throw custom exception
    }
}

string toEscape:: office(string inv, string command, string objectIn){
    if(command.compare("open") ==0) {
        if (objectIn == "safe"){
            size_t foundK = inv.find("key");

            if (foundK != string::npos){
                return "you must unlock the safe first";
            }else {
                return "You have opened the safe and you have found a sheet with codes.";
            }
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
    } else if (command.compare("go") == 0){
        bool hasCodes = false;
        size_t foundC = inv.find("codes");

        if (foundC != string::npos){
            hasCodes = true;
        }
        if (hasCodes) {
            return "true";
        }else {
            return "You have not found all items in this room";
        }
    }else {
        throw MyException("Invalid request"); // Throw custom exception
    }
}

string toEscape:: bathroom(string inv, string command, string objectIn){
    if (command.compare("take") == 0){
        if (objectIn == "uvLight"){
            return "You take the torch. You see nothing else of note.\n You notice you need a code to open the door.\n The code for the door doesn't match the format of the codes found.";
        }
    }else if(command.compare("use") == 0){
        if (objectIn == "uvLight"){
            return "You can see a code on on the wall. You use that to open the lock";
        }
    }else if(command.compare("open") == 0){
        if (objectIn == "lock"){
            return "You open the lock and you can exit south";
        }
    }else if(command.compare("go") == 0){
        return "true";
    }else {
        throw MyException("Invalid request"); // Throw custom exception
    }
}

string toEscape:: bedroom(string inv, string command, string objectIn){
    if (command.compare("take") == 0){
        if (objectIn == "hammer"){
            return "You dont see anything to use the hammer on.\n You go over to the door and notice a lock.\n Remember you have codes in your inventory";
        }
    }else if (command.compare("use") == 0){
        if (objectIn == "codes"){
            return "You use the codes on the door and it unlocks. You can go south";
        }
    }else if(command.compare("go") == 0){

        size_t foundH = inv.find("hammer");
        if (foundH != string::npos){
            return "true";
        }else {
            return "You need to find one more item in this room";
        }
    }else {
        throw MyException("Invalid request"); // Throw custom exception
    }
}

string toEscape:: landing(string inv, string command, string objectIn){
    if (command.compare("smash") == 0){
        if (objectIn == "vase"){
            return "You have smashed the vase and a key fell out.";
        }
    } else if (command.compare("take") == 0){
        if (objectIn == "key"){
            return "You pick up the key and go over to the locked door.";
        }
    }else if (command.compare("use") == 0){
        if (objectIn == "key"){
            return "The door unlocks. You can go east";
        }
    }else if(command.compare("go") == 0){
        return "true";
    }else {
        throw MyException("Invalid request"); // Throw custom exception
    }
}

string toEscape:: utility(string inv, string command, string objectIn){
    if(command.compare("go") == 0){
        return "true";
    } else if(command.compare("open") ==0) {
        if (objectIn == "press"){
            return "Inside the press you see a pack of treats.";
        }
    }else if(command.compare("take") ==0) {
        if (objectIn == "treats"){
            return "Try to use the treats on the dog.";
        }
    }else if(command.compare("use") ==0) {
        if (objectIn == "treats"){
            return "The dog becomes docile and you can go east.";
        }
    } else {
        throw MyException("Invalid request"); // Throw custom exception
    }
}

string toEscape:: kitchen(string inv, string command, string objectIn){
    if(command.compare("take") == 0){
        if (objectIn == "extinguisher"){
            return "You should use this on the fire";
        } else if (objectIn == "key"){
            return ("You take the key. However, when you touch the door it swings open\n You can go north");
        }
    }else if(command.compare("use") == 0){
        if (objectIn == "extinguisher"){
            return "The fire goes out. You see a key canging on the hook beside the door";
        }
    }else if(command.compare("go") == 0){
        size_t foundK = inv.find("key");
        if (foundK != string::npos){
            return "true";
        }else {
            return "You need to find one more item in this room";
        }
    }else {
        throw MyException("Invalid request"); // Throw custom exception
    }
}

string toEscape:: lRoom(string inv, string command, string objectIn){
    if(command.compare("use") == 0){
        if (objectIn == "key"){
            return "You have unlocked the door and you can now go north";
        }
    }else if(command.compare("smash") == 0){
        if (objectIn == "boards"){
            return "You have smashed the boards and see a lock.";
        }
    }else if(command.compare("go") == 0){
        size_t foundK = inv.find("key");
        if (foundK != string::npos){
            return "you must unlock the door";
        }else {
            return "true";
        }
    }else {
        throw MyException("Invalid request"); // Throw custom exception
    }
}

string toEscape:: getOrder(string currentR, string inv, string command, string objectIn){
    qDebug() << "currentR: " << currentR;
    if (currentR == "attic"){
        return attic(inv, command, objectIn);
    }else if (currentR == "Office"){
        return office(inv, command, objectIn);
    }else if (currentR == "Bathroom"){
        return bathroom(inv, command, objectIn);
    }else if (currentR == "Bedroom"){
        return bedroom(inv, command, objectIn);
    }else if (currentR == "Landing"){
        return landing(inv, command, objectIn);
    }else if (currentR == "Utility"){
        return utility(inv, command, objectIn);
    }else if (currentR == "Kitchen"){
        return kitchen(inv, command, objectIn);
    }else if (currentR == "Living Room"){
        return lRoom(inv, command, objectIn);
    }else {
        throw MyException("Invalid request"); // Throw custom exception
    }
}
