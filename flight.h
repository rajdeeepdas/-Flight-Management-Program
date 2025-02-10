
// Flight.h

#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "passenger.h" 
#include "seat.h"      

using namespace std;

class Flight {
public:
    // Constructors
    Flight(string filename);
    Flight(string flightNumber, int rows, int cols);

    // Accessors
    string file_name;
    string getFlightNumber();
    int getNumRows();
    int getNumCols();

    // Member functions
    void addPassenger(Passenger passenger);
    void removePassenger(string id);
    void displayPassengersInformation();
    void displaySeatMap();
    void saveToDisk();

private:
    string flightNumber;
    int num_rows;
    int num_cols;
    vector<Passenger> passengers;
    vector<vector<char>> seatMap;
};

#endif // FLIGHT_H
