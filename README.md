🚍 Bus Management System (C Language)

A console-based Bus Management System written in C, using a linked list to store booking data.
This version includes colored console UI (Windows only) using windows.h.

✨ Features

View available seats by date

Book one or multiple seats

Cancel bookings

Search passenger details

Linked-list based seat database

Auto-generate 5 days of seat schedules

Console color highlighting for better UI

Fully interactive menu-driven system

📌 Program Capabilities
🟢 Seat Booking

Enter passenger information

Choose 1–n seats

Validates seat availability

Prevents duplicate bookings

Saves journey date, name, mobile, route

🔴 Seat Cancellation

Enter date & seat number

Resets passenger data

Frees the seat

🔍 Passenger Search

Enter seat number + date

Shows full passenger info

Highlights status in color

📅 View Available Seats

Shows all seats for a specific day

Marks seats as Avail / Booked

📂 Folder Structure
Bus-Management-System/
 ├── src/
 │    └── main.c
 ├── README.md
 └── .gitignore

🛠️ How to Compile & Run
Windows (MinGW / CodeBlocks / VS Code)
gcc src/main.c -o bus.exe
bus.exe


⚠️ Because windows.h is used, this version works on Windows only.

To make a cross-platform version, remove all Windows color code and replace with ANSI colors.

📸 Screenshot (Optional)

Add console screenshots here.

🔮 Future Improvements

You can improve this project by:

Saving & loading data from a file

Adding admin login

Multiple buses

Digital ticket generation

Cross-platform ANSI colors

Better seat validation (A10, B12, etc.)

Free memory when exiting

📜 Author

ABDULLAH AL RIFAT

GitHub: https://github.com/rifatibnatozammal
