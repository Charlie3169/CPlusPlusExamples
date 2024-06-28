#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
    public:
        ItemToPurchase();        
        ItemToPurchase(string name, int price, int quantity);  
        ItemToPurchase(string name, string description, int price, int quantity);  

        string GetName() const;        
        string GetDescription() const;   
        int GetPrice() const;        
        int GetQuantity() const;
        void SetName(string name);
        void SetDescription(string description);
        void SetPrice(int price);
        void SetQuantity(int quantity);

        void PrintItemCost() const; 
        void PrintItemDescription() const;

    private:
        string itemName;
        string itemDescription;
        int itemPrice;
        int itemQuantity;
};

#endif