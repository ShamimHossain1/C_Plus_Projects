#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;

class Bill
{
private:
    string Item;
    int Rate, Quantity;

public:
    Bill() : Item(""), Rate(0), Quantity(0) {}
    void setItem(string item)
    {
        Item = item;
    }
    void setRate(int rate)
    {
        Rate = rate;
    }
    void setQuantity(int quantity)
    {
        Quantity = quantity;
    }

    string getItem()
    {
        return Item;
    }
    int getRate()
    {
        return Rate;
    }
    int getQuantity()
    {
        return Quantity;
    }
};


int main()
{
    Bill b;

    bool exit = false;
    while (!exit)
    {
        system("cls");
        int val;
        cout << "\tWelcome To Super Market Billing System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t\t1. Add Item" << endl;
        cout << "\t\t2. Print Bill" << endl;
        cout << "\t\t3. Exit" << endl;
        cout << "\t\tEnter Choice: ";
        cin >> val;
        if (val == 1)
        {
            system("cls");
            addItem(b);
            Sleep(3000);
        }
    }

    return 0;
}