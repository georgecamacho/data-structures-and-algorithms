#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "Booking.h"

int main() {
    std::string name;
    std::string phoneNumber;
    std::time_t timeOfBooking;
    std::list<std::string> allergies;
    std::string employeeAssignee;

    // Prompt user for input
    std::cin.ignore(); // To ignore the newline character left by std::cin

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

    // Create booking object
    Booking booking(name, phoneNumber, timeOfBooking, allergies, employeeAssignee);

    // Print booking details
    std::cout << "\nBooking Details:\n";
    booking.printBookingDetails();

    return 0;
}

