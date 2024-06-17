#include "Booking.h"
#include <iostream>

// Initialize static member
int Booking::nextBookingID = 1;

// Constructor
Booking::Booking(const std::string& guestName, const std::string& phone, std::time_t bookingTime,
                 const std::list<std::string>& allergyList, const std::string& employee)
    : uniqueBookingID(generateBookingID()), name(guestName), phoneNumber(phone), timeOfBooking(bookingTime),
      allergies(allergyList), employeeAssignee(employee) {}

// Generate unique booking ID method
int Booking::generateBookingID() {
    return nextBookingID++;
}

// Getters
int Booking::getUniqueBookingID() const { return uniqueBookingID; }
const std::string& Booking::getName() const { return name; }
const std::string& Booking::getPhoneNumber() const { return phoneNumber; }
std::time_t Booking::getTimeOfBooking() const { return timeOfBooking; }
const std::list<std::string>& Booking::getAllergies() const { return allergies; }
const std::string& Booking::getEmployeeAssignee() const { return employeeAssignee; }

// Setters
void Booking::setName(const std::string& guestName) { name = guestName; }
void Booking::setPhoneNumber(const std::string& phone) { phoneNumber = phone; }
void Booking::setTimeOfBooking(std::time_t bookingTime) { timeOfBooking = bookingTime; }
void Booking::setAllergies(const std::list<std::string>& allergyList) { allergies = allergyList; }
void Booking::setEmployeeAssignee(const std::string& employee) { employeeAssignee = employee; }

// Display the booking details method
void Booking::printBookingDetails() const {
    std::cout << "Booking ID: " << uniqueBookingID << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Phone Number: " << phoneNumber << "\n";
    std::cout << "Time of Booking: " << std::ctime(&timeOfBooking); // Convert time input into a string for reading
    std::cout << "Allergies: ";
    for (const auto& allergy : allergies) {
        std::cout << allergy << " ";
    }
    std::cout << "\n";
    std::cout << "Employee Assignee: " << employeeAssignee << "\n";
}
