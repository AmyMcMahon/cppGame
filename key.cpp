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

int bitStructure(string key){
    struct BitStructure {
        unsigned int key1 : 3;
        unsigned int key2 : 3;
        unsigned int key3 : 3;
    };

    BitStructure bs;
    bs.key1 = 1;
    bs.key2 = 2;
    bs.key3 = 3;

    if (key =="key1"){
        return bs.key1;
    } else if(key == "key2"){
        return bs.key2;
    } else if(key == "key3"){
        return bs.key3;
    }else{
        return 0;
    }
}
