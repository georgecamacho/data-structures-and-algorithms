#include "../Booking.cpp"
#include "../BookingHashTable.cpp"
#include <iostream>

// Simple test case for creating a booking and verifying the inputs are reflected correctly
void testCreateBooking() {
    std::cout << "Testing Creating a Booking...\n";

    // Create an instance of BookingHashTable
    BookingHashTable bookingTable;

    // Assert
    std::string guestName = "Joe Bloggs";
    std::string phoneNumber = "01632960001"; // dummy number used
    std::time_t timeOfBooking = std::time(nullptr);
    std::list<std::string> allergies = {"Crustaceans", "Lactose"};
    std::string employeeAssignee = "Employee1";

    // Act
    bookingTable.addBooking(guestName, phoneNumber, timeOfBooking, allergies, employeeAssignee);

    int bookingID = 0;
    Booking retrievedBooking = bookingTable.getBookingByID(bookingID);

    // Assert
    assert(retrievedBooking.getGuestName() == guestName);
    assert(retrievedBooking.getPhoneNumber() == phoneNumber);
    assert(retrievedBooking.getTimeOfBooking() == timeOfBooking);
    assert(retrievedBooking.getAllergies() == allergies);
    assert(retrievedBooking.getEmployeeAssignee() == employeeAssignee);

    std::cout << "Test Passed!\n";
}