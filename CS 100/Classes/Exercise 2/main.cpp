#include <string>
#include <iostream>

using namespace std;

#include "ShoppingCart.h"

ItemToPurchase AddItemMenuOption()
{
    string name;
    string description;
    int price;
    int quantity;

    ItemToPurchase item;
    
    
    cout << "ADD ITEM TO CART" << endl;   
    cout << "Enter the item name:" << endl;
    cin.clear();    
    cin.ignore(1000,'\n');
    getline(cin, name);
    cout << "Enter the item description:" << endl;
    cin.clear();    
    cin.ignore(1000,'\n');
    getline(cin, description);
    cout << "Enter the item price:" << endl;
    cin.clear();    
    cin.ignore(1000,'\n');
    cin >> price;
    cout << "Enter the item quantity:" << endl << endl;
    cin.clear();    
    cin.ignore(1000,'\n');
    cin >> quantity;

    item.SetName(name);
    item.SetDescription(description);
    item.SetPrice(price);
    item.SetQuantity(quantity);


    
    return item;


}

string RemoveItemMenuOption()
{
    string name;
    cout << "REMOVE ITEM FROM CART" << endl;
    cout << "Enter name of item to remove:" << endl;
    cin.clear();    
    cin.ignore(1000,'\n');
    getline(cin, name);


    return name;
}

void ChangeItemMenuOption(ShoppingCart & cart)
{
    string name;
    int quantity;

    cout << "CHANGE ITEM QUANTITY" << endl;
    cout << "Enter the item name:" << endl;
    cin.clear();    
    cin.ignore(1000,'\n');
    getline(cin, name);

    ItemToPurchase item = cart.ReturnItemByName(name);

    cout << "Enter the new quantity:" << endl;
    cin.clear();    
    cin.ignore(1000,'\n');
    cin >> quantity;

    item.SetQuantity(quantity);

    cart.ModifyItem(item, item.GetName());   
    
}


void PrintMenu(ShoppingCart & cart)
{
    
    char selection;    
    

    const char ADD = 'a',
               REMOVE = 'd',
               CHANGE = 'c',
               OUTPUT_DESCRIPTION = 'i',
               OUTPUT_CART = 'o',
               QUIT = 'q';

    do
    {                    
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl; 
        cout << "d - Remove item from cart" << endl; 
        cout << "c - Change item quantity" << endl; 
        cout << "i - Output items' descriptions" << endl; 
        cout << "o - Output shopping cart" << endl; 
        cout << "q - Quit" << endl << endl; 

        cout << "Choose an option:" << endl;

        cin.clear();      
        cin.ignore(1000, '\n');  
        cin >> selection;
                       

        switch (selection)
        {
            case ADD:
                cart.AddItem(AddItemMenuOption());                              
                break;

            case REMOVE:
                cart.RemoveItem(RemoveItemMenuOption());
                
                break;

            case CHANGE:
                ChangeItemMenuOption(cart);

                               
                break;

            case OUTPUT_DESCRIPTION:
                cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
                cart.PrintTotal();
                               
                break;

            case OUTPUT_CART:

                cout << "OUTPUT SHOPPING CART" << endl;
                cart.PrintTotal();                               
                break;     

            case QUIT:                
                           
                break;                   

        }

    } while (selection != QUIT);

}

int main()
{
    string custName;
    string date;

    cout << "Enter customer's name:" << endl;
    cin.clear();    
    cin.ignore(1000, '\n');
    getline(cin, custName);
    cout << "Enter today's date:" << endl;
    cin.clear();    
    cin.ignore(1000, '\n');
    getline(cin, date);

    cout << endl << "Customer name: " << custName << endl;
    cout << "Today's date: " << date << endl;

    ShoppingCart cart(custName, date);
    cout << endl << cart.GetCustomerName() << endl << cart.GetDate() << endl;
    PrintMenu(cart);



}