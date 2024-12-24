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

// **********  Option 1: Add Item Function ****************

void addItem(Bill b)
{

    bool close = false;
    while (!close)
    {
        system("cls");
        int choice;
        cout << "\t Add items " << endl;
        cout << "\t***********" << endl;
        cout << "\t1.Add." << endl;
        cout << "\t2.Close." << endl;
        cout << "\tEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            string item;
            int rate, quant;
            cout << "\t Add items " << endl;
            cout << "\t***********" << endl;
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
                out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuantity() << endl
                    << endl;
            }
            out.close();
            cout << "\tItem added Successfully!" << endl;
            Sleep(2000);
        }
        else if (choice == 2)
        {
            system("cls");
            close = true;
            cout << "\tBack to main menu..........." << endl;
            Sleep(1000);
        }
    }
}

//********* */ Option 2: Print Bill Function ****************

void printBill()
{
    system("cls");
    int count = 0;
    bool close = false;
    while (!close)
    {
        system("cls");
        int choice;
        cout << "\t  Print Bill  " << endl;
        cout << "\t**************" << endl;
        cout << "\t1. Add Bill" << endl;
        cout << "\t2. Close Session" << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            string item;
            int quant;

            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter quantity: ";
            cin >> quant;
            // b.setItem(item);
            // b.setQuantity(quant);

            ifstream in("bill.txt");
            ofstream out("bill_temp.txt");
            string line;
            bool found = false;
            while (getline(in, line))
            {
                stringstream ss(line);
                string itemName;
                int itemRate, itemQuant;
                char delimiter;
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;
                if (item == itemName)
                {
                    found = true;
                    if (quant <= itemQuant)
                    {
                        int amount = itemRate * quant;
                        cout << "\t Item | Rate | Quantity | Amount" << endl;
                        cout << "\t " << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += amount;
                        
                        
                            out <<"\t"<< itemName << " : " << itemRate << " : " << newQuant << endl;
                        
                    }
                    else
                    {
                        cout << "\tSorry, insufficient quantity for " << item << "." << endl;
                        out << line << endl;
                    }
                }
                else
                {
                    out << line << endl;
                }
               
            }
             if (!found)
                {
                    cout << "\tItem not available!" << endl;
                }
                in.close();
                out.close();
                remove("bill.txt");
                rename("bill_temp.txt", "bill.txt");
        }
        else if (choice == 2)
        {

            close = true;
            cout << "\tCounting Total Bill" << endl;
        }
        Sleep(3000);
    }
    system("cls");
    cout << endl
         << endl;
    cout << "\t Total Bill ----------- : " << count << endl
         << endl;
    cout << "\t Thank you for shopping with us!" << endl;
    Sleep(5000);
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

            addItem(b);
            Sleep(2000);
        }
        else if (val == 2)
        {
            printBill();
        }
        else if (val == 3)
        {
            system("cls");
            exit = true;
            cout << "\tThank you for shopping with us!" << endl;
            Sleep(3000);
        }
    }

    return 0;
}