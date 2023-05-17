#ifndef TOESCAPE_H
#define TOESCAPE_H

#include "Room.h"

class toEscape : public Room{
public:
    toEscape(string description);
    string attic(string inv, string command, string objectIn);
    string office(string inv, string command, string objectIn);
    string getOrder(string currentR, string inv, string command, string objectIn);
    string longDescription() override;
};

#endif // TOESCAPE_H
