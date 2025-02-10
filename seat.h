// Seat.cpp

#ifndef SEAT_H
#define SEAT_H
#include<string>

using namespace std;

class Seat{
    public:
    Seat(int _row,char _seatLetter);
    Seat(string s);
    int getRow();
    char getSeatLetter();
    string getSeatStr();



    private:
    int row;
    char seatLetter;


};

#endif