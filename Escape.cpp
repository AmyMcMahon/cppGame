#include "Escape.h"
#include <cstring>
#include <string>



Escape::Escape(string description) : Room(description) {}

inline string Escape :: longDescription() {
    return "Congrats you have escaped from the game";
}

inline string Escape:: getOrder(string currentR, string inv, string command, string objectIn){
    return "true";
}

string Escape:: finalRoom(){
    union EscapedR{
        int roomNo;
        char roomN[16];
    };

    EscapedR data;
    string returnS = "";
    strcpy(data.roomN, "Exit");
    returnS += "Room number: " + string(data.roomN);
    data.roomNo = 9;
    returnS += "\nRoom number: " + std::to_string(data.roomNo);
    return returnS;
}
