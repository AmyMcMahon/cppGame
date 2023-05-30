#ifndef KEY_H
#define KEY_H

#include "Room.h"
#include "Item.h"

class Key : public Room, public Item {

private:
    string roomDescription;
    string itemDescription;
    string roomToUse;
public:
    Key(string roomDescription, string itemDescription, string roomToUse);
    string getRoomToUseName();
    string longDescription() override;
    Key(const Key& other); // Copy constructor
    Key& operator=(const Key& other); // Assignment operator overload
    ~Key(); // Destructor
    string checkCorrect(string roomToUse, string roomDescription);
    bool operator==(const Key& other) const;
    bool operator!=(const Key& other) const;
    bool compareKey(Key key);

};

#endif // KEY_H
