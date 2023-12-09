// MichaelMirhom_COSC-1436_Module16-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

// Global Constants
const double RON_BASE = 350.0;
const double RON_LEADERSHIP = 100.0;
const double RON_EQUIPMENT = 40.0;
const double MICHAEL_BASE = 1000.0;
const double COX_BASE = 400.0;
const double COX_LODGING = 65.0;
const double COX_LUXURY_LODGING = 120.0;
const double JOHNSON_BASE = 700.0;
const double JOHNSON_EQUIPMENT = 40.0;

// Function Declarations
double burgundy(int attendees);
double scott(int attendees);
double cox(int attendees, int days, bool luxuryLodging);
double johnson(int attendees, int equipmentDays);
int menu();
void processOrder();

int main() {
    processOrder();
    return 0;
}

int menu() {
    int choice;
    cout << "Which retreat would you like to purchase?\n";
    cout << "1. The Ron Burgundy People Know Me Retreat\n";
    cout << "2. The Michael Scott World's Best Boss Retreat\n";
    cout << "3. Dr. Cox Presents Man Not Caring Retreat\n";
    cout << "4. Tony Johnson's I Really Don't Care Retreat\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

double burgundy(int attendees) {
    double total = attendees * RON_BASE;
    char leadershipOpt;
    int numLeadership;

    cout << "Would you like to add the Leadership Instruction option? (Y/N): ";
    cin >> leadershipOpt;
    if (toupper(leadershipOpt) == 'Y') {
        cout << "How many Leadership Instruction options would you like to add? ";
        cin >> numLeadership;
        total += numLeadership * RON_LEADERSHIP;
    }
    total += attendees * RON_EQUIPMENT; // Equipment is mandatory
    return total;
}

double scott(int attendees) {
    return attendees * (MICHAEL_BASE + RON_LEADERSHIP); // Assuming leadership instruction is mandatory
}

double cox(int attendees, int days, bool luxuryLodging) {
    double lodgingRate = luxuryLodging ? COX_LUXURY_LODGING : COX_LODGING;
    return attendees * (COX_BASE + days * lodgingRate);
}

double johnson(int attendees, int equipmentDays) {
    return attendees * (JOHNSON_BASE + equipmentDays * JOHNSON_EQUIPMENT);
}

void processOrder() {
    double total = 0.0;
    string email;
    bool addMore;
    do {
        int choice = menu();
        int attendees, days;
        char luxuryOpt;
        switch (choice) {
        case 1:
            cout << "How many tickets would you like to purchase? ";
            cin >> attendees;
            total += burgundy(attendees);
            break;
        case 2:
            cout << "How many tickets would you like to purchase? ";
            cin >> attendees;
            total += scott(attendees);
            break;
        case 3:
            cout << "How many tickets would you like to purchase? ";
            cin >> attendees;
            cout << "How many days of lodging? ";
            cin >> days;
            cout << "Would you like luxury lodging? (Y/N): ";
            cin >> luxuryOpt;
            total += cox(attendees, days, toupper(luxuryOpt) == 'Y');
            break;
        case 4:
            cout << "How many tickets would you like to purchase? ";
            cin >> attendees;
            cout << "How many days of equipment rental? ";
            cin >> days;
            total += johnson(attendees, days);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
        cout << "Would you like to add any additional retreats? (Y/N): ";
        char moreRetreats;
        cin >> moreRetreats;
        addMore = toupper(moreRetreats) == 'Y';
    } while (addMore);

    cout << "Your total is $" << total << ". Please enter your email to receive an invoice with payment information: ";
    cin >> email;
    cout << "Thank you. An invoice will be sent to " << email << endl;
}






