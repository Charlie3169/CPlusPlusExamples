
#include <iostream>
#include <string>

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
    customerName = "none";
    currentDate = "January 1, 2016";   
}


ShoppingCart::ShoppingCart(string name, string date)
{
    customerName = name;
    currentDate = date;   
}

string ShoppingCart::GetCustomerName() const
{
    return customerName;
}


string ShoppingCart::GetDate() const
{
    return currentDate;
}


void ShoppingCart::AddItem(ItemToPurchase item)
{
    cartItems.push_back(item);    
}

void ShoppingCart::RemoveItem(string itemName)
{
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        if(cartItems.at(i).GetName() == itemName)
        {
            cartItems.erase(cartItems.begin() + i);
            break;            
        }
    }

    cout << "Item not found in cart. Nothing removed." << endl;
    
}

void ShoppingCart::ModifyItem(ItemToPurchase item, string itemName)
{
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        if(cartItems.at(i).GetName() == itemName)
        {
            if(item.GetDescription() != "none" && (item.GetPrice() && item.GetQuantity()) != 0)
            {
                cartItems.at(i) = item;             
            }
            break;           
        }
    }

    cout << "Item not found in cart. Nothing modified." << endl;

}

int ShoppingCart::GetNumItemsInCart() const
{
    return cartItems.size();
}


int ShoppingCart::GetCostOfCart() const
{
    int sum = 0;
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        sum += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();        
    }
    return sum;

}


void ShoppingCart::PrintTotal() const
{
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    if(cartItems.size() == 0)
    {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else
    {
        cout << "Number of Items: " << GetNumItemsInCart() << endl;
        for (size_t i = 0; i < cartItems.size(); i++)
        {
            cartItems.at(i).PrintItemCost();          
        }
        cout << "Total: $" << GetCostOfCart() << endl;
    }
}

void ShoppingCart::PrintDescriptions() const
{
    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        cartItems.at(i).PrintItemDescription();         
    }

    
}

ItemToPurchase ShoppingCart::ReturnItemByName(string itemName) const
{
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        if(cartItems.at(i).GetName() == itemName)
        {
            return cartItems.at(i);                    
        }
    }
}