#ifndef ESCAPE_H
#define ESCAPE_H
#include "Room.h"

class Escape : public Room{
public:
    Escape(string description);
    string longDescription() override;
    string getOrder(string currentR, string inv) ;
};

#endif // ESCAPE_H
