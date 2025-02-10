// Seat.cpp

#include "seat.h"


// Parameterized constructor
Seat::Seat(int _row, char _seatLetter){
    row = _row;
    seatLetter = _seatLetter;
}

Seat::Seat(string s){
    seatLetter = s.back();
    s.pop_back();
    row = stoi(s);
}

string Seat::getSeatStr(){
    return ""+row+seatLetter;
}

// Accessors
int Seat::getRow() {
    return row;
}

char Seat::getSeatLetter() {
    return seatLetter;
}