#ifndef TOESCAPE_H
#define TOESCAPE_H

#include "Room.h"

class MyException : public std::exception {
private:
    std::string message;

public:
    MyException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class toEscape : public Room{
public:
    toEscape(string description);
    string attic(string inv, string command, string objectIn);
    string office(string inv, string command, string objectIn);
    string bathroom(string inv, string command, string objectIn);
    string bedroom(string inv, string command, string objectIn);
    string landing(string inv, string command, string objectIn);
    string utility(string inv, string command, string objectIn);
    string kitchen(string inv, string command, string objectIn);
    string lRoom(string inv, string command, string objectIn);
    string getOrder(string currentR, string inv, string command, string objectIn);
    string longDescription() override;
};

#endif // TOESCAPE_H
