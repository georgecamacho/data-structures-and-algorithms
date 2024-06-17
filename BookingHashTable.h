#ifndef BOOKING_HASHTABLE_H
#define BOOKING_HASHTABLE_H

#include <iostream>
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

    // Edit an existing booking in the hash table
    void editBooking(int bookingID, const std::string& guestName, const std::string& phoneNumber, std::time_t timeOfBooking,
                     const std::list<std::string>& allergies, const std::string& employeeAssignee);


    // Display the booking details method
    void printAllBookings() const;

    // Check if booking exists method
    bool bookingExists(int bookingID) const;

    // Search for bookings method
    std::list<Booking> searchBooking(const std::string& guestName) const;

    // Delete a booking using the ID method
    bool deleteBooking(int bookingID);

private:
    std::unordered_map<int, Booking> bookingTable; // Hash table that will store the bookings
    int nextBookingID; // Variable to generate unique booking IDs

    // Generate unique booking ID method
    int generateBookingID();

    // Merge function for merge sort
    std::list<Booking> merge(std::list<Booking>& left, std::list<Booking>& right);

    // Merge sort function
    std::list<Booking> mergeSort(std::list<Booking>& bookings);
};

#endif // BOOKING_HASHTABLE_H
