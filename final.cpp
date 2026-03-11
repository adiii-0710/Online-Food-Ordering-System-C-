/*
============================================================
Project Title : Online Food Ordering System
Restaurant    : BITE & DELIGHT RESTAURANT
============================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

/* =========================
   CLASS: FoodItem
========================= */

class FoodItem
{

private:
    string name;
    double price;

public:
    FoodItem(string n, double p)
    {
        name = n;
        price = p;
    }

    string getName()
    {
        return name;
    }

    double getPrice()
    {
        return price;
    }
};

/* =========================
   CLASS: OrderItem
========================= */

class OrderItem
{

public:
    FoodItem item;
    int quantity;

    OrderItem(FoodItem f, int q) : item(f), quantity(q) {}

    double getSubtotal()
    {
        return item.getPrice() * quantity;
    }
};

/* =========================
   CLASS: FoodOrderingSystem
========================= */

class FoodOrderingSystem
{

private:
    vector<FoodItem> menu;
    vector<OrderItem> order;
    string customerName;

public:
    FoodOrderingSystem()
    {

        menu.push_back(FoodItem("Pizza", 250));
        menu.push_back(FoodItem("Burger", 120));
        menu.push_back(FoodItem("Pasta", 180));
        menu.push_back(FoodItem("Sandwich", 90));
        menu.push_back(FoodItem("Cold Coffee", 80));
        menu.push_back(FoodItem("French Fries", 70));
        menu.push_back(FoodItem("Garlic Bread", 60));
    }

    void setCustomerName(string name)
    {
        customerName = name;
    }

    /* =========================
       DISPLAY MENU
    ========================= */

    void displayMenu()
    {

        cout << "\n--------------------------------------------\n";
        cout << "           ONLINE FOOD MENU\n";
        cout << "--------------------------------------------\n";

        cout << left << setw(5) << "No"
             << setw(20) << "Item"
             << "Price\n";

        cout << "--------------------------------------------\n";

        for (int i = 0; i < menu.size(); i++)
        {

            cout << setw(5) << i + 1
                 << setw(20) << menu[i].getName()
                 << "Rs " << menu[i].getPrice() << endl;
        }

        cout << "--------------------------------------------\n";
    }

    /* =========================
       VIEW CURRENT ORDER
    ========================= */

    void viewCurrentOrder()
    {

        if (order.empty())
        {
            cout << "\nCart is empty\n";
            return;
        }

        cout << "\nCurrent Order\n";

        for (int i = 0; i < order.size(); i++)
        {

            cout << i + 1 << ". "
                 << order[i].item.getName()
                 << " x " << order[i].quantity
                 << " = Rs " << order[i].getSubtotal()
                 << endl;
        }
    }

    /* =========================
       PLACE ORDER
    ========================= */

    void placeOrder()
    {

        displayMenu();

        int choice;

        cout << "\nEnter item number (0 to stop): ";

        while (true)
        {

            cin >> choice;

            if (choice == 0)
                break;

            if (choice < 1 || choice > menu.size())
            {

                cout << "Invalid item\n";
                continue;
            }

            int qty;

            cout << "Enter quantity: ";
            cin >> qty;

            if (qty <= 0)
            {

                cout << "Invalid quantity\n";
                continue;
            }

            bool exists = false;

            for (int i = 0; i < order.size(); i++)
            {

                if (order[i].item.getName() == menu[choice - 1].getName())
                {

                    order[i].quantity += qty;
                    exists = true;
                    break;
                }
            }

            if (!exists)
            {

                order.push_back(OrderItem(menu[choice - 1], qty));
            }

            cout << "Item added successfully\n";
            cout << "Next item (0 to stop): ";
        }
    }

    /* =========================
       MODIFY ORDER
    ========================= */

    void modifyOrder()
    {

        if (order.empty())
        {
            cout << "No order to modify\n";
            return;
        }

        viewCurrentOrder();

        int choice;

        cout << "Select item number: ";
        cin >> choice;

        if (choice < 1 || choice > order.size())
        {

            cout << "Invalid selection\n";
            return;
        }

        cout << "1 Change quantity\n";
        cout << "2 Remove item\n";

        int action;
        cin >> action;

        if (action == 1)
        {

            int q;

            cout << "Enter new quantity: ";
            cin >> q;

            if (q > 0)
                order[choice - 1].quantity = q;
        }

        else if (action == 2)
        {

            order.erase(order.begin() + choice - 1);
        }

        cout << "Order updated\n";
    }

    /* =========================
       GENERATE BILL
    ========================= */

    void generateBill()
    {

        if (order.empty())
        {
            cout << "No items ordered\n";
            return;
        }

        double subtotal = 0;
        int totalItems = 0;

        cout << "\n============================================\n";
        cout << "        BITE & DELIGHT RESTAURANT\n";
        cout << "============================================\n";

        cout << "Customer: " << customerName << endl;

        time_t now = time(0);
        char *dt = ctime(&now);

        cout << "Date: " << dt << endl;

        cout << "Item                Qty    Amount\n";
        cout << "--------------------------------------------\n";

        for (int i = 0; i < order.size(); i++)
        {

            double sub = order[i].getSubtotal();

            subtotal += sub;
            totalItems += order[i].quantity;

            cout << setw(20) << order[i].item.getName()
                 << setw(6) << order[i].quantity
                 << "Rs " << sub << endl;
        }

        double tax = subtotal * 0.05;
        double total = subtotal + tax;

        cout << "--------------------------------------------\n";

        cout << "Subtotal : Rs " << subtotal << endl;
        cout << "Tax (5%) : Rs " << tax << endl;

        cout << "TOTAL    : Rs " << total << endl;

        cout << "Total Items Ordered: " << totalItems << endl;

        /* =========================
           FILE HANDLING
        ========================== */

        ofstream file("orders.txt", ios::app);

        file << "Customer: " << customerName << endl;
        file << "Order Details:" << endl;

        for (int i = 0; i < order.size(); i++)
        {
            file << order[i].item.getName()
                 << " x " << order[i].quantity
                 << " = Rs " << order[i].getSubtotal()
                 << endl;
        }

        file << "Total Bill: Rs " << total << endl;
        file << "--------------------------------" << endl;

        file.close();

        cout << "\nOrder saved to orders.txt\n";

        cout << "============================================\n";
        cout << "Thank you for visiting!\n";

        order.clear();
    }
};

/* =========================
   MENU
========================= */

void showMenu()
{

    cout << "\n====================================\n";
    cout << " Online Food Ordering System\n";
    cout << "====================================\n";

    cout << "1 View Menu\n";
    cout << "2 Place Order\n";
    cout << "3 View Current Order\n";
    cout << "4 Modify Order\n";
    cout << "5 Checkout / Generate Bill\n";
    cout << "6 Exit\n";

    cout << "Enter choice: ";
}

/* =========================
   MAIN
========================= */

int main()
{

    FoodOrderingSystem system;

    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    system.setCustomerName(name);

    int choice;

    while (true)
    {

        showMenu();

        cin >> choice;

        switch (choice)
        {

        case 1:
            system.displayMenu();
            break;

        case 2:
            system.placeOrder();
            break;

        case 3:
            system.viewCurrentOrder();
            break;

        case 4:
            system.modifyOrder();
            break;

        case 5:
            system.generateBill();
            break;

        case 6:
            cout << "Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}
