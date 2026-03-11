# 🍽️ Online Food Ordering System (C++)

![C++](https://img.shields.io/badge/Language-C++-blue.svg)
![OOP](https://img.shields.io/badge/Concepts-OOP-green.svg)
![Platform](https://img.shields.io/badge/Platform-Console-orange.svg)

A **menu-driven Online Food Ordering System** developed using **C++ and Object-Oriented Programming (OOP)** concepts.

This program simulates a **restaurant ordering system** where customers can:

- View menu items
- Place orders
- Modify orders
- Generate a bill
- Save order history to a file

---

#  Features

✔ View restaurant food menu  
✔ Place order with quantity  
✔ Modify existing order  
✔ View current order  
✔ Generate formatted restaurant bill  
✔ Automatic **5% tax calculation**  
✔ Save order history to **orders.txt**  
✔ Menu-driven console interface  

---

#  Technologies Used

| Technology | Purpose |
|-----------|--------|
| C++ | Main programming language |
| OOP | Class-based system design |
| Vectors | Store menu items & orders |
| iostream | Input/output |
| iomanip | Format bill output |
| ctime | Display date & time |
| fstream | File handling (saving orders) |

---

# 🏗️Project Structure

```
online-food-ordering-system
│
├── main.cpp
├── README.md
├── orders.txt
└── report
    └── case-study-report.docx
```

---

#  System Design

The program is implemented using **three main classes**.

### 1️ FoodItem
Stores menu information.

```cpp
class FoodItem {
    string name;
    double price;
};
```

---

### 2️ OrderItem
Stores ordered item and quantity.

```cpp
class OrderItem {
    FoodItem item;
    int quantity;
};
```

---

### 3️ FoodOrderingSystem
Controls the entire system.

Functions include:

- `displayMenu()`
- `placeOrder()`
- `viewCurrentOrder()`
- `modifyOrder()`
- `generateBill()`

---

#  Example Program Output

```
============================================
        BITE & DELIGHT RESTAURANT
============================================

Customer : Aditya

Item                Qty   Rate       Amount
--------------------------------------------
Cold Coffee         1     Rs. 80     Rs. 80

Subtotal : Rs. 80
Tax (5%) : Rs. 4
TOTAL    : Rs. 84

============================================
Thank you for visiting!
============================================
```

---

#  Example Saved Order (orders.txt)

```
Customer: Aditya Khare
Order Details:
Cold Coffee x 1 = Rs 80
Pasta x 1 = Rs 180
Total Bill: Rs 260
--------------------------------
```

This demonstrates **file handling and data storage**, fulfilling the assignment requirement.

---

#  How to Run the Project

### 1️ Compile

```bash
g++ main.cpp -o food_order
```

### 2️ Run

```bash
./food_order
```

---

#  Academic Purpose

This project was created for a **C++ Case Study Assignment** demonstrating:

- Object-Oriented Programming
- Menu-driven applications
- File handling
- Data management
- Billing logic

---


#  Future Improvements

Possible upgrades:

- GUI version using **Qt**
- Database storage instead of text files
- Order search functionality
- Multiple customer sessions
- Online payment simulation

---

 If you found this project helpful, consider giving the repository a star!
