#include <iostream>

// Declare test functions
void testCreateBooking();
// void testEditBooking();

int main() {
    std::cout << "Running Unit Tests...\n";

    testCreateBooking();
    // testEditBooking();

    std::cout << "All tests passed!\n";
    return 0;
}