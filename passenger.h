// AirlinePassenger.h

#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include "seat.h"

using namespace std;

class Passenger {
public:
    Passenger(string _id,string _first_name,string _last_name,string _phone, string _seat_str);
    Passenger(string _id,string _first_name,string _last_name,string _phone, int row, char _seatLetter);

    string getId();
    string getFirstName();
    string getLastName();
    string getPhone();
    Seat * getSeat();

    void displayInformation();

private:
   string id;
   string first_name;
   string last_name;
   string phone;
   Seat * seat;
};

#endif // AIRLINE_PASSENGER_H
