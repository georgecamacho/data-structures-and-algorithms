#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <list>
#include <ctime>

class Booking {
public:
    Booking(); // default constructor
    // Constructor
    Booking(const std::string& guestName, const std::string& phoneNumber, std::time_t timeOfBooking,
            const std::list<std::string>& allergyList, const std::string& employeeAssignee);

    // Getters
    int getUniqueBookingID() const;
    const std::string& getGuestName() const;
    const std::string& getPhoneNumber() const;
    std::time_t getTimeOfBooking() const;
    const std::list<std::string>& getAllergies() const;
    const std::string& getEmployeeAssignee() const;

    // Setters
    void setGuestName(const std::string& guestName);
    void setPhoneNumber(const std::string& phoneNumber);
    void setTimeOfBooking(std::time_t timeOfBooking);
    void setAllergies(const std::list<std::string>& allergyList);
    void setEmployeeAssignee(const std::string& employeeAssignee);

    // Operator overloads for sorting
    bool operator<=(const Booking& other) const;
    bool operator>(const Booking& other) const;

    // Display the booking details method
    void printBookingDetails() const;
    
    bool deleteBooking(int bookingID);


private:
    static int nextBookingID;
    int uniqueBookingID;
    std::string guestName;
    std::string phoneNumber;
    std::time_t timeOfBooking;
    std::list<std::string> allergies;
    std::string employeeAssignee;

    // Generate unique booking ID method
    static int generateBookingID();

    std::unordered_map<int, Booking> bookings;
};

#endif // BOOKING_H

