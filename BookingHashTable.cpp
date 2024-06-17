#include "BookingHashTable.h"
#include <iostream>

// Constructor
BookingHashTable::BookingHashTable() : nextBookingID(1) {}

// Generate unique booking ID method
int BookingHashTable::generateBookingID() {
    return nextBookingID++;
}

// Add booking to the Hash Table method
void BookingHashTable::addBooking(const std::string& guestName, const std::string& phoneNumber, std::time_t timeOfBooking,
                                  const std::list<std::string>& allergies, const std::string& employeeAssignee) {
    // Create booking object
    Booking newBooking(guestName, phoneNumber, timeOfBooking, allergies, employeeAssignee);

    // Generate unique booking ID and store in hash table
    int newBookingID = generateBookingID();
    bookingTable[newBookingID] = newBooking;

    // Display the booking details
    std::cout << "\nBooking Details:\n";
    bookingTable[newBookingID].printBookingDetails();
}

// Display all booking details
void BookingHashTable::printAllBookings() const {
    std::cout << "\nAll Bookings:\n";
    for (const auto& pair : bookingTable) {
        std::cout << "Booking ID: " << pair.first << "\n";
        pair.second.printBookingDetails();
        std::cout << "\n";
    }
}

// Search for bookings method
std::list<Booking> BookingHashTable::searchBooking(const std::string& guestName) const {
    std::list<Booking> results;

    for (const auto& pair : bookingTable) {
        if (pair.second.getGuestName() == guestName) {
            results.push_back(pair.second);
        }
    }

    return results;
}
