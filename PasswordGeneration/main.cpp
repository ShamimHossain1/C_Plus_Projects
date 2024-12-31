// Password Generation in C++
//=====================================

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

string getPass(int length){
    string pass = "";
    string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-";
    int charSize = characters.size();
    srand(time(0));
    int randomIndex;
    for(int i = 0; i < length; i++){
        randomIndex = rand() % charSize;
        pass += characters[randomIndex];
        }
        return pass;
}
    

int main(){

    cout<<"Enter the length of the Password :: ";
    int length;
    cin>>length;
    string pass = getPass(length);
    cout<<"Generated Password :: "<<pass;



    return 0;
}