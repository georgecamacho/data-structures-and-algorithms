#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "Booking.h"
#include "BookingHashTable.h"

using namespace std;

void printMenu() {
    std::cout << "\n============================================================================\n";
    std::cout << "\n                        Restaurant Booking System                           \n";
    std::cout << "1. Create a new booking\n";
    std::cout << "2. Edit an existing booking\n";
    std::cout << "3. View all bookings\n";
    std::cout << "4. Delete a booking\n";
    std::cout << "5. Exit\n";
    std::cout << "\n============================================================================\n";
    std::cout << "Enter your choice: ";
}

void createBooking(BookingHashTable& bookingTable) {
    std::string name;
    std::string phoneNumber;
    std::time_t timeOfBooking;
    std::list<std::string> allergies;
    std::string employeeAssignee;

    std::cout << "Enter Guest Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);

    std::cout << "Enter Time of Booking (in format YYYY-MM-DD HH:MM:SS): ";
    std::string timeString;
    std::getline(std::cin, timeString);
    struct tm tm;
    strptime(timeString.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
    timeOfBooking = mktime(&tm);

    std::cout << "Enter Allergies (separated by commas): ";
    std::string allergiesString;
    std::getline(std::cin, allergiesString);
    size_t start = 0;
    size_t end = allergiesString.find(',');
    while (end != std::string::npos) {
        allergies.push_back(allergiesString.substr(start, end - start));
        start = end + 1;
        end = allergiesString.find(',', start);
    }
    allergies.push_back(allergiesString.substr(start));

    std::cout << "Enter Employee Assignee: ";
    std::getline(std::cin, employeeAssignee);

    bookingTable.addBooking(name, phoneNumber, timeOfBooking, allergies, employeeAssignee);
}

void viewAllBookings(const BookingHashTable& bookingTable) {
    bookingTable.printAllBookings();
}

void deleteBooking(BookingHashTable& bookingTable) {
    int bookingID;
    std::cout << "Enter Booking ID to delete: ";
    std::cin >> bookingID;

    if (bookingTable.deleteBooking(bookingID)) {
        std::cout << "Booking deleted successfully.\n";
    } else {
        std::cout << "Booking ID not found.\n";
    }
}

int main() {
    BookingHashTable bookingTable;
    bool exitApp = false;

    while (!exitApp) {
        printMenu();

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Consume newline character

        switch (choice) {
            case 1:
                createBooking(bookingTable);
                break;
            case 2:
                std::cout << "Feature not implemented yet.\n";
                break;
            case 3:
                viewAllBookings(bookingTable);
                break;
            case 4:
                deleteBooking(bookingTable);
                break;
            case 5:
                exitApp = true;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number from 1 to 5.\n";
                break;
        }
    }

    std::cout << "Exiting the application.\n";
    return 0;
}