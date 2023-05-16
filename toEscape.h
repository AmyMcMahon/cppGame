#ifndef TOESCAPE_H
#define TOESCAPE_H

#include "Room.h"

class toEscape : public Room{
public:
    toEscape(string description);
    string attic(string inv);
    string getOrder(string currentR, string inv);
    string longDescription() override;
};

#endif // TOESCAPE_H
