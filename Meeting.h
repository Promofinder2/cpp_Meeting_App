#ifndef MEETING_H
#define MEETING_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
// QUESTION 2

class Meeting 
{
    //PART a) DECLARE Meeting object reflecting UML Diagram
    string Name;
    string Date;
    int Capacity;
    int Mode ; 


public:
    Meeting();
    Meeting(string n);
    Meeting(string n , string d , int m , int c);

    string getName();
    string getDate();
    int getMode();
    int getCapacity();
    bool isOnline(int m);
    bool equals(Meeting M); 
    void setName(string n);
    void setDate(string d);
    void setMode(int m);
    void setCapacity(int c);
    void changeOnline(int number);
    void postpone (string newDate);
    void printInfo();
};

#endif 
