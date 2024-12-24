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

void addItem(Bill b)
{

    bool close = false;
    while (!close)
    {
        int choice;
        cout << "\t1.Add." << endl;
        cout << "\t2.Close." << endl;
        cout<<"\tEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            string item;
            int rate, quant;
            cout << "\tEnter item name: ";
            cin >> item;
            cout << "\tEnter rate: ";
            cin >> rate;
            cout << "\tEnter quantity: ";
            cin >> quant;
            b.setItem(item);
            b.setRate(rate);
            b.setQuantity(quant);

            ofstream out("bill.txt", ios::app);
            if (!out)
            {
                cout << "\tError: File can't open" << endl;
            }
            else
            {
                out << "\t" << b.getItem() << " " << b.getRate() << " " << b.getQuantity() << endl
                    << endl;
            }
            out.close();
            cout << "\tItem added Successfully!" << endl;
            Sleep(3000);
        }
        else if (choice == 2)
        {
            system("cls");
            close = true;
            cout << "\tBack to main menu..........." << endl;
            Sleep(3000);
        }
    }
}

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