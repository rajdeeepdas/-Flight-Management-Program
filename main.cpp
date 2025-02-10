#include <iostream>
#include <vector>
#include <fstream>
#include "flight.h"
#include<stdlib.h>

using namespace std;


int main(){

    Flight f = Flight("flight_info.txt");

    cout << "Version 1.0\n";
    cout << "Term Project - Flight Management Program in C++\n";
    cout << "Produced by: Rajdeep Das\n";
    cout << "Year 2024\n";

    cout <<"\n<<< Press Return to Continue>>>>" << endl;
    cin.get();
    cout <<"<<< Press Return to Continue>>>>" << endl;
    cin.get();


    while(true){
        cout << "\n\n\n";
        cout << "Please select one of the following options: \n";
        cout << "1. Display Flight Seat Map\n";
        cout << "2. Display Passengers Information\n";
        cout << "3. Add a new Passenger\n";
        cout << "4. Remove an existing passenger\n";
        cout << "5. Save data\n";
        cout << "6. Quit\n";

        cout << "Enter your Choice (1,2,3,4,5,6) : ";

        int choice;
        cin >> choice;

        if(choice == 1){
            f.displaySeatMap();



        }else if(choice == 2){
            f.displayPassengersInformation();
        }else if(choice == 3){
            string id,fname,lname,phone,phone1,phone2,phone3;
            int row;
            char cseat;
            
            cout << "Enter the passenger id: ";
            cin >> id;
            cout << "Enter the passenger first name: ";
            cin >> fname;
            cout << "Enter the passenger last name: ";
            cin >> lname;
            cout << "Enter the passenger phone: ";
            cin >> phone1;
            cin >> phone2;
            cin >> phone3;
            phone = phone1 + "-"+phone2 +"-"+phone3;

            cout << "Enter the passenger 's desired row: ";
            cin >> row;
            cout << "Enter the passenger 's desired seat: ";
            cin >> cseat;

            Passenger p = Passenger(id,fname,lname,phone,row,cseat);

            f.addPassenger(p);

        }else if(choice == 4){
            string id;
            cout << "Please Enter the id of the passenger that needs to be removed: ";
            cin >> id;
            f.removePassenger(id);

        }else if(choice == 5){
            f.saveToDisk();

        }else if(choice == 6){
            return 0;
        }

        cout <<"\n<<< Press Return to Continue>>>>" << endl;
        cin.get();
        cin.get();
    }
}




