#include <string>
#include <iostream>

using namespace std;

#include "ItemToPurchase.hpp"


int main()
{
    string name;
    string description;
    int price;
    int quantity1;

    cout << "Item 1" << endl << "Enter the item name:" << endl;
    getline(cin, name);
    cout << "Enter the item price:" << endl;
    cin.ignore();
    cin >> price;
    cout << "Enter the item quantity:" << endl << endl;
    cin.ignore();
    cin >> quantity1;

    ItemToPurchase item1(name, description, price, quantity1);

    string name2;
    int price2;
    int quantity2;

    cin.ignore();

    cout << "Item 2" << endl << "Enter the item name:" << endl;
    getline(cin, name2);
    cout << "Enter the item price:" << endl;
    cin.ignore();
    cin >> price2;
    cout << "Enter the item quantity:" << endl << endl;
    cin.ignore();
    cin >> quantity2;

    ItemToPurchase item2(name2, price2, quantity2);


    cout << "TOTAL COST" << endl;
    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1.GetPrice() * item1.GetQuantity() << endl;
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2.GetPrice() * item2.GetQuantity() << endl << endl;
    int total = item1.GetPrice() * item1.GetQuantity() + item2.GetPrice() * item2.GetQuantity();
    cout << "Total: " << total << endl;



}