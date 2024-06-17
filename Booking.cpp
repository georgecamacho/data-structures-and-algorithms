#include "Booking.h"
#include <iostream>

// Initialize static member
int Booking::nextBookingID = 0;

Booking::Booking() 
    : uniqueBookingID(-1), guestName(""), phoneNumber(""), timeOfBooking(0), employeeAssignee("") {

}

// Constructor
Booking::Booking(const std::string& guestName, const std::string& phoneNumber, std::time_t timeOfBooking,
                 const std::list<std::string>& allergyList, const std::string& employeeAssignee)
    : uniqueBookingID(generateBookingID()), guestName(guestName), phoneNumber(phoneNumber), timeOfBooking(timeOfBooking),
      allergies(allergyList), employeeAssignee(employeeAssignee) {}

// Generate unique booking ID method
int Booking::generateBookingID() {
    return nextBookingID++;
}

// Getters
int Booking::getUniqueBookingID() const { return uniqueBookingID; }
const std::string& Booking::getGuestName() const { return guestName; }
const std::string& Booking::getPhoneNumber() const { return phoneNumber; }
std::time_t Booking::getTimeOfBooking() const { return timeOfBooking; }
const std::list<std::string>& Booking::getAllergies() const { return allergies; }
const std::string& Booking::getEmployeeAssignee() const { return employeeAssignee; }

// Setters
void Booking::setGuestName(const std::string& guestName) { this->guestName = guestName; }
void Booking::setPhoneNumber(const std::string& phoneNumber) { this->phoneNumber = phoneNumber; }
void Booking::setTimeOfBooking(std::time_t timeOfBooking) { this->timeOfBooking = timeOfBooking; }
void Booking::setAllergies(const std::list<std::string>& allergyList) { this->allergies = allergyList; }
void Booking::setEmployeeAssignee(const std::string& employeeAssignee) { this->employeeAssignee = employeeAssignee; }

// Sorting of bookings based on time of booking methods
bool Booking::operator<=(const Booking& other) const {
    return timeOfBooking <= other.timeOfBooking;
}

bool Booking::operator>(const Booking& other) const {
    return timeOfBooking > other.timeOfBooking;
}

// Display the booking details method
void Booking::printBookingDetails() const {
    std::cout << "Booking ID: " << uniqueBookingID << "\n";
    std::cout << "Name: " << guestName << "\n";
    std::cout << "Phone Number: " << phoneNumber << "\n";
    std::cout << "Time of Booking: " << std::ctime(&timeOfBooking); // Convert time input into a string for reading
    std::cout << "Allergies: ";
    for (const auto& allergy : allergies) {
        std::cout << allergy << " ";
    }
    std::cout << "\n";
    std::cout << "Employee Assignee: " << employeeAssignee << "\n";
}
