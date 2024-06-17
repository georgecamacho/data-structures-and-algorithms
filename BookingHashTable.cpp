#include "BookingHashTable.h"
#include <iostream>
#include <algorithm> // for std::sort

// Constructor
BookingHashTable::BookingHashTable() : nextBookingID(1) {}

// Generate unique booking ID method
int BookingHashTable::generateBookingID() {
    return nextBookingID++;
}

// Add booking to the Hash Table method
void BookingHashTable::addBooking(const std::string& guestName, const std::string& phoneNumber, std::time_t timeOfBooking,
                                  const std::list<std::string>& allergiesList, const std::string& employeeAssignee) {
    // Create booking object
    Booking newBooking(guestName, phoneNumber, timeOfBooking, allergiesList, employeeAssignee);

    // Generate unique booking ID and store in hash table
    int newBookingID = newBooking.getUniqueBookingID(); 
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

bool BookingHashTable::bookingExists(int bookingID) const {
    return bookingTable.find(bookingID) != bookingTable.end();
}

void BookingHashTable::editBooking(int bookingID, const std::string& guestName, const std::string& phoneNumber,
                                   std::time_t timeOfBooking, const std::list<std::string>& allergies,
                                   const std::string& employeeAssignee) {
    auto it = bookingTable.find(bookingID);
    if (it != bookingTable.end()) {
        // Update the booking with new information
        it->second.setGuestName(guestName);
        it->second.setPhoneNumber(phoneNumber);
        it->second.setTimeOfBooking(timeOfBooking);
        it->second.setAllergies(allergies);
        it->second.setEmployeeAssignee(employeeAssignee);

        // Successful message displayed for edited booking
        std::cout << "\nBooking with ID " << bookingID << " updated successfully.\n";
        // Show updated booking details
        it->second.printBookingDetails();
    } else {
        std::cout << "Booking with ID " << bookingID << " not found.\n";
        // Handle error or inform user accordingly
    }
}

bool BookingHashTable::deleteBooking(int bookingID) {
    auto it = bookingTable.find(bookingID); 
    if (it != bookingTable.end()) {
        bookingTable.erase(it);
        return true;
    }
    return false; 
}

// Method for merging the two lists together
std::list<Booking> BookingHashTable::merge(std::list<Booking>& left, std::list<Booking>& right) {
    std::list<Booking> result;

    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();
        } else {
            result.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty()) {
        result.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty()) {
        result.push_back(right.front());
        right.pop_front();
    }

    return result;
}

// Method for carrying out the merge sort algorithm
std::list<Booking> BookingHashTable::mergeSort(std::list<Booking>& bookings) {
    if (bookings.size() <= 1) {
        return bookings;
    }

    std::list<Booking> left, right;
    int middle = bookings.size() / 2;
    int count = 0;
    for (auto& it : bookings) {
        if (count < middle) {
            left.push_back(it);
        } else {
            right.push_back(it);
        }
        ++count;
    }

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}