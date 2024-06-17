#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <list>
#include <ctime>

class Booking {
public:
    // Constructor
    Booking(const std::string& guestName, const std::string& phone, std::time_t bookingTime,
            const std::list<std::string>& allergyList, const std::string& employee);

    // Getters
    int getUniqueBookingID() const;
    const std::string& getGuestName() const;
    const std::string& getPhoneNumber() const;
    std::time_t getTimeOfBooking() const;
    const std::list<std::string>& getAllergies() const;
    const std::string& getEmployeeAssignee() const;

    // Setters
    void setName(const std::string& guestName);
    void setPhoneNumber(const std::string& phone);
    void setTimeOfBooking(std::time_t bookingTime);
    void setAllergies(const std::list<std::string>& allergyList);
    void setEmployeeAssignee(const std::string& employee);

    // Display the booking details method
    void printBookingDetails() const;

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
};

#endif // BOOKING_H

