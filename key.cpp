#include "key.h"
#include <string>
using namespace std;

Key::Key(const string roomDescription, const string itemDescription, const string roomToUse) : Room(roomDescription), Item(itemDescription, roomToUse, 0, 0) {
    this->roomDescription = descriptionR;
    this->itemDescription = descriptionI;
    this->roomToUse = roomToUse;
}


Key::Key(const Key& other) : Room(other), Item(other) {

    setRoomToUse("kitchen");
}


Key::~Key() {
}

bool Key::operator==(const Key& other) const {
    return (roomToUse == other.roomToUse);
}

bool Key::operator!=(const Key& other) const {
    return !(*this == other);
}

string Key::longDescription() {

    string room = roomToUse;
    return "Key to be used in " + room;
}

string checkCorrect(string room, string roomToUse){
    if (room == roomToUse){
        return "true";
    }else {
        return "false";
    }
}

bool compareKey(Key key){
    Key origkey = *new Key("kitchen", "key", "bedroom");
    bool isEqual1 = (key == origkey);
    return isEqual1;
}


