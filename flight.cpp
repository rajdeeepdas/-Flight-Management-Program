#include "flight.h"
#include <iomanip> // Include <iomanip> for setw()

// Constructor to initialize from a file
Flight::Flight(string filename) {
    file_name = filename;
    ifstream fin(filename);

    if (!fin.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    string line;
    getline(fin, line);
    stringstream in(line);

    in >> flightNumber >> num_rows >> num_cols;
    seatMap = vector<vector<char>>(num_rows + 1, vector<char>(num_cols + 1, ' '));

    while (getline(fin, line)) {
        stringstream row_in(line);

        string fname;
        string lname;
        string phone;
        string seatstr;
        string id;

        row_in >> fname >> lname >> phone >> seatstr >> id;

        Passenger p = Passenger(id, fname, lname, phone, seatstr);
        passengers.push_back(p);
        seatMap[p.getSeat()->getRow()][p.getSeat()->getSeatLetter() - 'A'] = 'x';
    }

    fin.close();
}

// New constructor to initialize with flight number, rows, and columns
Flight::Flight(string flightNumber, int rows, int cols) {
    this->flightNumber = flightNumber;
    this->num_rows = rows;
    this->num_cols = cols;
    this->seatMap = vector<vector<char>>(num_rows + 1, vector<char>(num_cols + 1, ' '));
    // No passengers initially
}

// Accessors
string Flight::getFlightNumber() {
    return flightNumber;
}

int Flight::getNumRows() {
    return num_rows;
}

int Flight::getNumCols() {
    return num_cols;
}

// Member function to add a passenger to the flight
void Flight::addPassenger(Passenger passenger) {
    passengers.push_back(passenger);
    seatMap[passenger.getSeat()->getRow()][passenger.getSeat()->getSeatLetter() - 'A'] = 'x';
}

// Member function to remove a passenger by ID
void Flight::removePassenger(string id) {
    for (auto it = passengers.begin(); it != passengers.end(); it++) {
        if (it->getId() == id) {
            seatMap[it->getSeat()->getRow()][it->getSeat()->getSeatLetter() - 'A'] = ' ';
            passengers.erase(it);
            break;
        }
    }
}

// Member function to save flight data to disk
void Flight::saveToDisk() {
    ofstream fout(file_name);

    if (!fout.is_open()) {
        cerr << "Error: Could not open file " << file_name << " for saving." << endl;
        return;
    }

    fout << flightNumber << " " << num_rows << " " << num_cols << "\n";
    for (auto &p : passengers) {
        fout << p.getFirstName() << " ";
        fout << p.getLastName() << " ";
        fout << p.getPhone() << " ";
        fout << to_string(p.getSeat()->getRow()) + p.getSeat()->getSeatLetter() << " ";
        fout << p.getId() << "\n";
    }

    fout.close();
}

// Member function to display information about all passengers on the flight
void Flight::displayPassengersInformation() {
    cout << left << setw(12) << "First Name" 
         << setw(12) << "Last Name" 
         << setw(15) << "Phone" 
         << setw(6) << "Row" 
         << setw(6) << "Seat" 
         << setw(10) << "ID" 
         << endl;

    cout << string(65, '-') << endl;

    for (auto &p : passengers) {
        cout << left << setw(12) << p.getFirstName() 
             << setw(12) << p.getLastName() 
             << setw(15) << p.getPhone() 
             << setw(6) << p.getSeat()->getRow() 
             << setw(6) << p.getSeat()->getSeatLetter() 
             << setw(10) << p.getId() 
             << endl;
    }

    cout << string(65, '-') << endl; // Closing separator line
}

// Member function to display the seat map of the flight
void Flight::displaySeatMap() {
    cout << "\t\t\tAircraft Seat Map\n\n";

    cout << "\t\t";
    for (int i = 0; i < num_cols; i++) {
        cout << "    " << (char)('A' + i) << "\t";
    }
    cout << endl;

    cout << "\t        ";
    for (int i = 0; i < num_cols; i++) {
        cout << "+-------";
    }
    cout << "+\n";

    for (int i = 0; i < num_rows + 1; i++) {
        cout << "\t";
        cout << i;
        cout << '\t';
        for (int j = 0; j < num_cols; j++) {
            cout << "|   " << seatMap[i][j] << "   ";
        }
        cout << "|\n";

        cout << "\t        ";
        for (int k = 0; k < num_cols; k++) {
            cout << "+-------";
        }
        cout << "+\n";
    }
}
