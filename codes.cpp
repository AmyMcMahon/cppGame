#include "codes.h"
using namespace std;

codes::codes(string descriptionR, string descriptionI) : Room(descriptionR), Item(descriptionI) {}

string codes :: longDescription() {
    return "Congrats you have escaped from the game";
}

string codes:: getOrder(string currentR, string inv, string command, string objectIn){
    return "true";
}
