#ifndef BOOKING_HASHTABLE_H
#define BOOKING_HASHTABLE_H

#include <unordered_map>
#include <list>
#include <string>
#include "Booking.h"

class BookingHashTable {
public:
    BookingHashTable();

    // Add booking to the Hash Table method
    void addBooking(const std::string& guestName, const std::string& phoneNumber, std::time_t timeOfBooking,
                    const std::list<std::string>& allergies, const std::string& employeeAssignee);

    // Display the booking details method
    void printAllBookings() const;

    // Search for bookings method
    std::list<Booking> searchBooking(const std::string& guestName) const;

private:
    std::unordered_map<int, Booking> bookingTable; // Hash table that will store the bookings
    int nextBookingID; // Variable to generate unique booking IDs

    // Generate unique booking ID method
    int generateBookingID();
};

#endif // BOOKING_HASHTABLE_H
