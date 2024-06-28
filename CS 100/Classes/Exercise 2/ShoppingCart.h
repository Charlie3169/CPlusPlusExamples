#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
using namespace std;


#include "ItemToPurchase.h"


class ShoppingCart {
    public:
        ShoppingCart();        
        ShoppingCart(string name, string date);          

        string GetCustomerName() const;        
        string GetDate() const;          
        void AddItem(ItemToPurchase item);
        void RemoveItem(string itemName);
        void ModifyItem(ItemToPurchase item, string itemName);

        int GetNumItemsInCart() const;
        int GetCostOfCart() const;

        void PrintTotal() const; 
        void PrintDescriptions() const;

        ItemToPurchase ReturnItemByName(string itemName) const;


    private:
        string customerName;
        string currentDate;
        vector<ItemToPurchase> cartItems;
};

#endif