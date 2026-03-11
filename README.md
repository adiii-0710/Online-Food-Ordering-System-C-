# 🍽️ Online Food Ordering System (C++)

![C++](https://img.shields.io/badge/Language-C++-blue.svg)
![OOP](https://img.shields.io/badge/Concepts-OOP-green.svg)
![Platform](https://img.shields.io/badge/Platform-Console-orange.svg)
![Status](https://img.shields.io/badge/Project-Academic-blueviolet.svg)

A **console-based Online Food Ordering System** developed using **C++ and Object-Oriented Programming (OOP)** concepts.

This project simulates a **restaurant ordering workflow** where customers can browse the menu, place orders, modify them, and generate a final bill.

---

#  Features

✔ View food menu  
✔ Place order with quantity  
✔ Modify existing order  
✔ View current order  
✔ Generate bill with tax calculation  
✔ Payment method selection (Cash / Card / UPI)  
✔ Menu-driven console interface  

---

#  Technologies Used

| Technology | Purpose |
|-----------|--------|
| C++ | Main programming language |
| OOP | Class-based system design |
| Vectors | Dynamic storage for menu & orders |
| iostream | Input/output operations |
| iomanip | Formatting bill display |
| ctime | Date and time in bill |

---

#  Project Structure

```
online-food-ordering-system
│
├── main.cpp
├── README.md
└── report
    └── case-study-report.docx
```

---

#  System Design

The program is designed using **three main classes**.

### 1️ FoodItem
Stores menu item information.

```
class FoodItem {
    string name;
    double price;
};
```

### 2️OrderItem
Stores ordered item and quantity.

```
class OrderItem {
    FoodItem item;
    int quantity;
};
```

### 3️ FoodOrderingSystem
Handles the main system functionality.

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

#  How to Run the Project

### 1️ Compile the program

```
g++ main.cpp -o food_order
```

### 2️ Run the program

```
./food_order
```

---

#  Academic Purpose

This project was developed for an **Object-Oriented Programming Case Study** to demonstrate:

- OOP class design
- Menu-driven programs
- Order management logic
- Billing computation
- Real-world restaurant ordering simulation


---

#  Future Improvements

Possible future upgrades:

- GUI interface using **Qt**
- Database integration
- Online payment gateway
- Order history system
- Multi-user support

---

 If you found this project helpful, consider giving the repository a star!
