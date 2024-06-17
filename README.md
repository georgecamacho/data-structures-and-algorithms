# Restaurant Booking System

Objective: To create a booking system that allows a guest to select the number of guests, allergies/food preferences and time of booking. An ID would be generated for the booking. The bookings would then be sorted based on the time selected; the priority of each booking will be sorted based on the time selected (the restaurant employee will need to make sure the table is ready and prepared for the guest’s time slot).

Components:
- Booking System: The guest will be the end user, who will input their name, date/time of their booking, the number of guests and their contact details: email and phone number. Once a booking is created a unique ID will be generated.
- Admin Service (MVP): The restaurant employee will be the end user, who will be able to see upcoming bookings. The booking will be assigned to an employee, who will look after the guests during their visit. After the guest’s meal has finished, the employee will be able to mark the booking as complete.
- Review/Edit Booking Service: The guest will be the end user, who will be able to view the booking that they have made and make any changes to their booking.

## To run the application, enter the following command:
- g++ -o booking_system main.cpp BookingHashTable.cpp Booking.cpp 
./booking_system