/*
============================================================
Project Title : Online Food Ordering System
Restaurant    : BITE & DELIGHT RESTAURANT
Subject       : Object Oriented Programming (C++)
============================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <ctime>

using namespace std;

/* ==============================
   CLASS: FoodItem
============================== */
class FoodItem {
private:
    string name;
    double price;

public:
    FoodItem(string n, double p) {
        name = n;
        price = p;
    }

    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }
};

/* ==============================
   CLASS: OrderItem
============================== */
class OrderItem {
public:
    FoodItem item;
    int quantity;

    OrderItem(FoodItem f, int q) : item(f), quantity(q) {}

    double getSubtotal() {
        return item.getPrice() * quantity;
    }
};

/* ==============================
   CLASS: FoodOrderingSystem
============================== */
class FoodOrderingSystem {

private:
    vector<FoodItem> menu;
    vector<OrderItem> order;
    string customerName;

public:

    FoodOrderingSystem() {

        menu.push_back(FoodItem("Pizza",250));
        menu.push_back(FoodItem("Burger",120));
        menu.push_back(FoodItem("Pasta",180));
        menu.push_back(FoodItem("Sandwich",90));
        menu.push_back(FoodItem("Cold Coffee",80));
        menu.push_back(FoodItem("French Fries",70));
        menu.push_back(FoodItem("Garlic Bread",60));

        customerName="Customer";
    }

    void setCustomerName(string name){
        customerName=name;
    }

    /* ==============================
       DISPLAY MENU
    ============================== */

    void displayMenu(){

        cout<<"\n";
        cout<<"+------------------------------------------+\n";
        cout<<"|        BITE & DELIGHT RESTAURANT         |\n";
        cout<<"|               FOOD MENU                  |\n";
        cout<<"+------------------------------------------+\n";

        cout<<left<<setw(5)<<"No"
            <<setw(22)<<"Item"
            <<"Price\n";

        cout<<"+------------------------------------------+\n";

        for(int i=0;i<menu.size();i++){

            cout<<left
                <<setw(5)<<i+1
                <<setw(22)<<menu[i].getName()
                <<"Rs. "<<fixed<<setprecision(2)
                <<menu[i].getPrice()<<endl;
        }

        cout<<"+------------------------------------------+\n";
    }

    /* ==============================
       VIEW CURRENT ORDER
    ============================== */

    void viewCurrentOrder(){

        if(order.empty()){
            cout<<"\nCart is empty.\n";
            return;
        }

        cout<<"\n------ CURRENT ORDER ------\n";

        cout<<setw(5)<<"No"
            <<setw(20)<<"Item"
            <<setw(8)<<"Qty"
            <<"Subtotal\n";

        for(int i=0;i<order.size();i++){

            cout<<setw(5)<<i+1
                <<setw(20)<<order[i].item.getName()
                <<setw(8)<<order[i].quantity
                <<"Rs. "<<order[i].getSubtotal()
                <<endl;
        }
    }

    /* ==============================
       PLACE ORDER
    ============================== */

    void placeOrder(){

        displayMenu();

        cout<<"\nEnter item number to add (0 to stop): ";

        int choice;

        while(true){

            cin>>choice;

            if(choice==0) break;

            if(choice<1 || choice>menu.size()){
                cout<<"Invalid item\n";
                continue;
            }

            int qty;

            cout<<"Enter quantity: ";
            cin>>qty;

            if(qty<=0){
                cout<<"Invalid quantity\n";
                continue;
            }

            bool exists=false;

            for(int i=0;i<order.size();i++){

                if(order[i].item.getName()==menu[choice-1].getName()){

                    order[i].quantity+=qty;
                    exists=true;
                    break;
                }
            }

            if(!exists){
                order.push_back(OrderItem(menu[choice-1],qty));
            }

            cout<<"Item added successfully\n";
            cout<<"Next item (0 to stop): ";
        }
    }

    /* ==============================
       MODIFY ORDER
    ============================== */

    void modifyOrder(){

        if(order.empty()){
            cout<<"\nNothing to modify.\n";
            return;
        }

        viewCurrentOrder();

        int choice;

        cout<<"Select item number (0 cancel): ";
        cin>>choice;

        if(choice==0) return;

        if(choice<1 || choice>order.size()){
            cout<<"Invalid selection\n";
            return;
        }

        cout<<"1 Change quantity\n";
        cout<<"2 Remove item\n";

        int action;
        cin>>action;

        if(action==1){

            int q;

            cout<<"Enter new quantity: ";
            cin>>q;

            if(q>0)
                order[choice-1].quantity=q;
        }

        else if(action==2){

            order.erase(order.begin()+choice-1);
        }

        cout<<"Order updated\n";
    }

    /* ==============================
       GENERATE BILL
    ============================== */

    void generateBill(){

        if(order.empty()){
            cout<<"\nYour cart is empty!\n";
            return;
        }

        double subtotal=0;
        int totalItems=0;

        cout<<"\n\n";
        cout<<"============================================\n";
        cout<<"        BITE & DELIGHT RESTAURANT           \n";
        cout<<"============================================\n";

        cout<<"Customer : "<<customerName<<endl;

        time_t now=time(0);
        char* dt=ctime(&now);

        cout<<"Date & Time : "<<dt;

        cout<<"--------------------------------------------\n";

        cout<<left
            <<setw(20)<<"Item"
            <<setw(6)<<"Qty"
            <<setw(10)<<"Rate"
            <<"Amount\n";

        cout<<"--------------------------------------------\n";

        for(int i=0;i<order.size();i++){

            double sub=order[i].getSubtotal();

            subtotal+=sub;
            totalItems+=order[i].quantity;

            cout<<left
                <<setw(20)<<order[i].item.getName()
                <<setw(6)<<order[i].quantity
                <<setw(10)<<("Rs."+to_string((int)order[i].item.getPrice()))
                <<"Rs. "<<fixed<<setprecision(2)<<sub
                <<endl;
        }

        double tax=subtotal*0.05;
        double total=subtotal+tax;

        cout<<"--------------------------------------------\n";

        cout<<right<<setw(30)<<"Subtotal : "
            <<"Rs. "<<subtotal<<endl;

        cout<<right<<setw(30)<<"Tax (5%) : "
            <<"Rs. "<<tax<<endl;

        cout<<"============================================\n";

        cout<<right<<setw(30)<<"TOTAL : "
            <<"Rs. "<<total<<endl;

        cout<<"============================================\n";

        cout<<"Total Items Ordered : "<<totalItems<<endl;

        cout<<"\nSelect Payment Method\n";
        cout<<"1. Cash\n";
        cout<<"2. Card\n";
        cout<<"3. UPI\n";
        cout<<"Choice: ";

        int pay;
        cin>>pay;

        string method;

        if(pay==1) method="Cash";
        else if(pay==2) method="Card";
        else if(pay==3) method="UPI";
        else method="Unknown";

        cout<<"Payment Method : "<<method<<endl;

        cout<<"\nThank you, "<<customerName<<"! Enjoy your meal :)\n";
        cout<<"============================================\n\n";

        order.clear();
    }
};

/* ==============================
   MAIN MENU
============================== */

void showMenu(){

    cout<<"\n====================================\n";
    cout<<"        BITE & DELIGHT SYSTEM       \n";
    cout<<"====================================\n";

    cout<<"1 View Menu\n";
    cout<<"2 Place Order\n";
    cout<<"3 View Current Order\n";
    cout<<"4 Modify Order\n";
    cout<<"5 Checkout / Generate Bill\n";
    cout<<"6 Exit\n";

    cout<<"Enter choice: ";
}

/* ==============================
   MAIN FUNCTION
============================== */

int main(){

    FoodOrderingSystem system;

    cout<<"\n============================================\n";
    cout<<"        BITE & DELIGHT RESTAURANT           \n";
    cout<<"      Online Food Ordering System           \n";
    cout<<"============================================\n";

    string name;

    cout<<"Enter your name: ";
    getline(cin,name);

    if(name.empty()) name="Guest";

    system.setCustomerName(name);

    int choice;

    while(true){

        showMenu();

        cin>>choice;

        switch(choice){

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
                cout<<"\nThank you for visiting BITE & DELIGHT!\n";
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }
}