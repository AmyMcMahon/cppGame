#ifndef ESCAPE_H
#define ESCAPE_H
#include "Room.h"

class Escape : public Room{
public:
    Escape(string description);
    inline string longDescription() override;
    inline string getOrder(string currentR, string inv, string command, string objectIn) ;
};

#endif // ESCAPE_H
