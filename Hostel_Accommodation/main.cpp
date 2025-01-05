#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>

using namespace std;

class Hostel
{
private:
    string Name;
    int Rent, Bed;

public:
    Hostel(string name, int rent, int bed)
    {
        Name = name;
        Rent = rent;
        Bed = bed;
    }

    string getName()
    {
        return Name;
    }
    int getRent()
    {
        return Rent;
    }
    int getBed()
    {
        return Bed;
    }

    void reserve()
    {
        ifstream in("HostelFile.txt");
        ofstream out("HostelTempFile.txt");
        string line;
        while (getline(in, line))
        {
            int pos = line.find("Shera");
            if (pos != string::npos)
            {
                int bed = Bed - 1;
                Bed = bed;
                stringstream ss;
                ss << bed;
                string strBed = ss.str();

                int bedPos = line.find_last_of(':');
                line.replace(bedPos + 1, string::npos, strBed);
            }
            out << line << endl;
        }
        in.close();
        out.close();
        remove("HostelFile.txt");
        rename("HostelTempFile.txt", "HostelFile.txt");
        cout << "\tBed Reserved Successfully" << endl;
    }
};

class Student
{

private:
    string Name, RollNo, Address;

public:
    Student() : Name(""), RollNo(""), Address("") {}
    void setName(string name)
    {
        Name = name;
    }
    void setRollNo(string rollNo)
    {
        RollNo = rollNo;
    }
    void setAddress(string address)
    {
        Address = address;
    }
    string getName()
    {
        return Name;
    }
    string getRollNo()
    {
        return RollNo;
    }
    string getAddress()
    {
        return Address;
    }
};

int main()
{
    Hostel Shera("Shera", 30000, 2);
    ofstream out("HostelFile.txt");
    out << "\t" << Shera.getName() << " : " << Shera.getRent() << " : " << Shera.getBed() << endl
        << endl;
    cout << "Hostel Data Saved" << endl;
    out.close();

    Student Sauda;

    bool exit = false;
    while (!exit)
    {
        system("cls");
        int val;
        cout << "\tWelcome To Hostel Accommodation System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1.Reserve A Bed." << endl;
        cout << "\t2.Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1)
        {
            system("cls");
            string name, rollNo, address;
            cout << "\tEnter Your Name: ";
            cin >> name;
            cout << "\tEnter Your Roll No: ";
            cin >> rollNo;
            cout << "\tEnter Your Address: ";
            cin >> address;

            Sauda.setName(name);
            Sauda.setRollNo(rollNo);
            Sauda.setAddress(address);

            if (Shera.getBed() > 0)
            {
                Shera.reserve();
            }
            else
            {
                cout << "\tSorry, No Bed Available." << endl;
                  exit = true;
                  Sleep(3000);
            }

            ofstream out("StudentFile.txt", ios::app);
            out << "\t" << Sauda.getName() << " : " << Sauda.getRollNo() << " : " << Sauda.getAddress() << endl
                << endl;
        }
        else if(val == 2){
            cout<<"\tExiting"<<endl;
            exit = true;
            Sleep(3000);
        }
        else{
            cout << "\tInvalid Choice. Please Try Again." << endl;
            Sleep(2000);
        }
    }

    return 0;
}