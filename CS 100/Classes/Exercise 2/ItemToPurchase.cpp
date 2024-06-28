#include <iostream>

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0;
    itemQuantity = 0;

}

ItemToPurchase::ItemToPurchase(string name, int price, int quantity)
{
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity)
{
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
    itemDescription = description;
}

string ItemToPurchase::GetName() const 
{
    return itemName;
}

string ItemToPurchase::GetDescription() const 
{
    return itemDescription;
}

int ItemToPurchase::GetPrice() const
{
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const
{
    return itemQuantity;
}

void ItemToPurchase::SetName(string name)
{
    itemName = name;
}

void ItemToPurchase::SetDescription(string description)
{
    itemDescription = description;
}

void ItemToPurchase::SetPrice(int price)
{
    itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity)
{
    itemQuantity = quantity;
}


void ItemToPurchase::PrintItemCost() const
{
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
} 

void ItemToPurchase::PrintItemDescription() const
{
    cout << itemName << ": " << itemDescription << endl;
}

