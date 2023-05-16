#include "Escape.h"

Escape::Escape(string description) : Room(description) {}

string Escape :: longDescription() {
    return "Congrats you have escaped from the game";
}

string Escape:: getOrder(string currentR, string inv){
    return "true";
}
