#ifndef CODES_H
#define CODES_H

#include "Room.h"
#include "Item.h"

class codes : public Room, public Item {
public:
    codes(string descriptionR, string descriptionI);
    string longDescription() override;
    string getOrder(string currentR, string inv, string command, string objectIn) override;
};

#endif // CODES_H
