#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

// Room structure
struct Room {
    int roomNumber;
    bool isBooked;
    double price;
    string customerName;
};

vector<Room> rooms;

// Function to load rooms from file
void loadRooms() {
    ifstream file("rooms.txt");
    Room r;
    while (file >> r.roomNumber >> r.isBooked >> r.price) {
        getline(file, r.customerName);
        rooms.push_back(r);
    }
    file.close();
}

// Function to save rooms to file
void saveRooms() {
    ofstream file("rooms.txt");
    for (Room r : rooms) {
        file << r.roomNumber << " " << r.isBooked << " " << r.price << " " << r.customerName << "\n";
    }
    file.close();
}

// Display available rooms
void showAvailableRooms() {
    cout << "\nAvailable Rooms:" << endl;
    bool found = false;
    for (Room r : rooms) {
        if (!r.isBooked) {
            cout << "Room " << r.roomNumber << " - $" << fixed << setprecision(2) << r.price << endl;
            found = true;
        }
    }
    if (!found) cout << "No rooms available.\n";
}

// Book a room
void bookRoom() {
    int roomNum;
    string name;
    showAvailableRooms();
    cout << "Enter Room Number to book: ";
    cin >> roomNum;
    cout << "Enter Your Name: ";
    cin.ignore();
    getline(cin, name);
    for (auto &r : rooms) {
        if (r.roomNumber == roomNum && !r.isBooked) {
            r.isBooked = true;
            r.customerName = name;
            saveRooms();
            cout << "Room booked successfully!\n";
            return;
        }
    }
    cout << "Invalid room number or already booked.\n";
}

// Checkout
void checkoutRoom() {
    int roomNum;
    cout << "Enter Room Number to checkout: ";
    cin >> roomNum;
    for (auto &r : rooms) {
        if (r.roomNumber == roomNum && r.isBooked) {
            cout << "Checkout successful! Total Bill: $" << r.price << endl;
            r.isBooked = false;
            r.customerName = "";
            saveRooms();
            return;
        }
    }
    cout << "Invalid room number or not booked.\n";
}

// Search for rooms by price range
void searchRoomsByPrice() {
    double minPrice, maxPrice;
    cout << "Enter min price: ";
    cin >> minPrice;
    cout << "Enter max price: ";
    cin >> maxPrice;
    bool found = false;
    for (Room r : rooms) {
        if (r.price >= minPrice && r.price <= maxPrice && !r.isBooked) {
            cout << "Room " << r.roomNumber << " - $" << r.price << "\n";
            found = true;
        }
    }
    if (!found) cout << "No available rooms in this price range.\n";
}

// View all bookings
void viewBookings() {
    cout << "\nBooked Rooms:" << endl;
    bool found = false;
    for (Room r : rooms) {
        if (r.isBooked) {
            cout << "Room " << r.roomNumber << " - Booked by: " << r.customerName << "\n";
            found = true;
        }
    }
    if (!found) cout << "No current bookings.\n";
}

// Modify booking (Change customer name)
void modifyBooking() {
    int roomNum;
    string newName;
    cout << "Enter Room Number to modify booking: ";
    cin >> roomNum;
    cin.ignore();
    cout << "Enter new customer name: ";
    getline(cin, newName);
    for (auto &r : rooms) {
        if (r.roomNumber == roomNum && r.isBooked) {
            r.customerName = newName;
            saveRooms();
            cout << "Booking modified successfully!\n";
            return;
        }
    }
    cout << "Invalid room number or not booked.\n";
}

// Cancel booking
void cancelBooking() {
    int roomNum;
    cout << "Enter Room Number to cancel booking: ";
    cin >> roomNum;
    for (auto &r : rooms) {
        if (r.roomNumber == roomNum && r.isBooked) {
            r.isBooked = false;
            r.customerName = "";
            saveRooms();
            cout << "Booking cancelled successfully!\n";
            return;
        }
    }
    cout << "Invalid room number or not booked.\n";
}

// Main Menu
void menu() {
    int choice;
    do {
        cout << "\n--- Hotel Booking System ---\n";
        cout << "1. Show Available Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Checkout\n";
        cout << "4. Search Rooms by Price\n";
        cout << "5. View All Bookings\n";
        cout << "6. Modify Booking\n";
        cout << "7. Cancel Booking\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: showAvailableRooms(); break;
            case 2: bookRoom(); break;
            case 3: checkoutRoom(); break;
            case 4: searchRoomsByPrice(); break;
            case 5: viewBookings(); break;
            case 6: modifyBooking(); break;
            case 7: cancelBooking(); break;
            case 8: cout << "Exiting..."; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);
}

int main() {
    loadRooms();
    menu();
    return 0;
}