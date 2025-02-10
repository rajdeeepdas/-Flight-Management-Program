#include <iostream>
#include <vector>
#include <string>
#include "passenger.h"



Passenger::Passenger(string _id,string _first_name,string _last_name,string _phone, string _seat_str){
    id = _id;
    first_name = _first_name;
    last_name = _last_name;
    phone = _phone;
    seat = new Seat(_seat_str);
    
}

Passenger::Passenger(string _id,string _first_name,string _last_name,string _phone, int _row, char _seatLetter){
    id = _id;
    first_name = _first_name;
    last_name = _last_name;
    phone = _phone;
    seat = new Seat(_row, _seatLetter);
}


void Passenger::displayInformation(){
    cout << first_name << "\t\t";
    cout << last_name << "\t\t";
    cout << phone << "\t\t";
    cout << seat->getRow() << "\t\t";
    cout << seat->getSeatLetter() << "\t\t";
    cout << id << "\t\t";
    cout << endl;
}


string Passenger::getFirstName(){
    return first_name;
}

string Passenger::getLastName(){
    return last_name;
}

string Passenger::getId(){
    return id;
}

string Passenger::getPhone(){
    return phone;
}

Seat * Passenger::getSeat(){
    return seat;
}


// class Passenger {
// public:
//     // Default constructor
//     Passenger() {}

//     // Parameterized constructor
//     Passenger(std::string firstName, std::string lastName, int age,
//                std::string phoneNumber, int row, char seat, std::string ID)
//         : firstName(firstName), lastName(lastName), age(age),
//           phoneNumber(phoneNumber), row(row), seat(seat), ID(ID) {}

//     // Function to display passenger information
//     void displayInformation() const {
//         std::cout << "First Name: " << firstName << "\n";
//         std::cout << "Last Name: " << lastName << "\n";
//         std::cout << "Age: " << age << "\n";
//         std::cout << "Phone Number: " << phoneNumber << "\n";
//         std::cout << "Row: " << row << "\n";
//         std::cout << "Seat: " << seat << "\n";
//         std::cout << "ID: " << ID << "\n";
//     }

// private:
//     string firstName;
//     string lastName;
//     int age;
//     std::string phoneNumber;
//     int row;
//     char seat;
//     std::string ID;
// };

// int main() {
//     std::vector<Passenger> passengers; // Vector to store multiple passengers

//     // Input information for passengers
//     int numPassengers;
//     std::cout << "Enter the number of passengers: ";
//     std::cin >> numPassengers;

//     for (int i = 0; i < numPassengers; ++i) {
//         std::string firstName, lastName, destination, phoneNumber, ID;
//         int age, row;
//         char seat;

//         std::cout << "\nEnter information for Passenger " << i + 1 << ":\n";
//         std::cout << "First Name: ";
//         std::cin >> firstName;
//         std::cout << "Last Name: ";
//         std::cin >> lastName;
//         std::cout << "Age: ";
//         std::cin >> age;
//         std::cout << "Phone Number: ";
//         std::cin >> phoneNumber;
//         std::cout << "Row: ";
//         std::cin >> row;
//         std::cout << "Seat: ";
//         std::cin >> seat;
//         std::cout << "ID: ";
//         std::cin >> ID;

//         passengers.emplace_back(firstName, lastName, age, destination, phoneNumber, row, seat, ID);
//     }

//     // Display information for all passengers in a table format
//     std::cout << "\nPassenger Information:\n";
//     std::cout << "---------------------------------------------------\n";
//     for (const auto& passenger : passengers) {
//         passenger.displayInformation();
//         std::cout << "---------------------------------------------------\n";
//     }

//     return 0;
// }

