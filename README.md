# Hotel-management-booking-system
# Hotel Room Management System  This C++ project implements a simple hotel room management system. It allows users to view available rooms, book rooms, checkout, search rooms by price range, view all bookings, modify bookings, and cancel bookings.  The room data is persisted between sessions using a text file.
## Features

* **Room Management:**  Add, view, book, and checkout rooms.
* **Availability Tracking:**  Real-time tracking of room availability.
* **Data Persistence:** Room data is saved to a file ("rooms.txt") and loaded on startup.
* **Search Functionality:** Search for available rooms within a specified price range.
* **Booking Management:** View all current bookings, modify existing bookings (change customer name), and cancel bookings.
* **User-Friendly Interface:**  A simple menu-driven interface for easy interaction.

## Technologies Used

* C++
* File I/O

## Build Instructions

1.  Clone the repository: `git clone https://github.com/YOUR_USERNAME/Hotel-Room-Management-System.git` (Replace with your repository URL)
2.  Compile the code: `g++ -o hotel_management main.cpp`
3.  Run the executable: `./hotel_management`

## Data File Format

The `rooms.txt` file should be formatted as follows, with each room's information on a new line:
`roomNumber`: An integer representing the room number.
*   `isBooked`: A boolean value (0 for not booked, 1 for booked).
*   `price`: A double representing the room price.
*   `customerName`: A string representing the customer's name (can be empty if the room is not booked).


