#include "Meeting.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// QUESTION 2
int meetingCount = 1;
const int nMeetings = 3;
Meeting meetings[nMeetings];
int capacities[nMeetings];
Meeting::Meeting()  {
    setName("COMP218");
    setDate("2022-02-12");
    setCapacity(100);
    setMode(0);
}
Meeting::Meeting(string n) : Name(n) {
    setName(n);
    setDate("2022-02-22");
    setCapacity(1);
    setMode(1);
}
Meeting::Meeting(string n , string d , int c , int m) : Name(n) , Date(d) , Capacity(c) , Mode(m) {
    setName(n);
    setDate(d);
    setCapacity(c);
    setMode(m);
}

string Meeting::getName() {
    return Name;
}

string Meeting::getDate() {
    return Date;
}
int Meeting::getMode() {
    return Mode;
}
int Meeting::getCapacity() {
    return Capacity;
}
bool Meeting::isOnline(int m) {
    if (m==1){
        return true;
    }
    else if (m!=1){
        return false;
    }
    return 0;
}
bool Meeting::equals(Meeting M) {
    if (Name == M.Name && Date == M.Date && Mode ==M.Mode &&Capacity==M.Capacity )
    {
        return true;
    }

    return false;
    }

void Meeting::setName(string n) {
    Name = n;
}
void Meeting::setDate(string d) {
    Date = d;
}
void Meeting::setMode(int m) {
    Mode = m;
}
void Meeting::setCapacity(int c) {
    Capacity = c;
}

void Meeting::changeOnline(int number) {
    
    if(isOnline(meetings[number].Mode)==false){
        string userInput;
        cout<<"Would you like to change the meeting "<<number+1<<" online? ";
        getline(cin,userInput);
        if (userInput=="yes"){
            meetings[number].Mode = 1;
        }
    }
}

void Meeting::postpone(string newDate) {
    Date=newDate;
}

void Meeting::printInfo() {
    string capacityStr;
    string onlineStr;

    if (isOnline(Mode)==true){
        onlineStr = " online.";
    }
    else if (isOnline(Mode) == false){
        onlineStr = " in person.";
    }

    if (Capacity>1){
        capacityStr = " students";
    }
    else if(Capacity==1){
        capacityStr = " student";
    }

    cout<<"Meeting"<<" "<<meetingCount<<" is "<<Name<<" on "<<Date<<" with capacity:  "<<Capacity<<capacityStr<<onlineStr<<endl;
    meetingCount=meetingCount+1;
}


int main()
{
    //PART c) 
    Meeting meeting1{};
    string infoStr;
    string userInput;
    int tmpMode;
    int tmpCapacity;
    int totalCapacity = 0;
    meetings[0] = meeting1;

    cout<<"   *******************************"<<endl;
    cout<<"Welcome to Meeting Information Program"<<endl;
    cout<<"   *******************************"<<endl;
    cout<<""<<endl;
    cout<<"Please enter the name of meeting2 please:  ";
    getline(cin,userInput);
    Meeting meeting2{userInput};
    meetings[1] = meeting2;
    cout<<"Please enter the name, date, made and capacity of meeting3 please:  "<<endl;
    
    getline(cin,userInput);
    cout<<endl;
    string delimiter = " ";
    string inputName = userInput.substr(0, userInput.find(delimiter));
    userInput.erase(0, userInput.find(delimiter) + delimiter.length());
    string inputDate = userInput.substr(0, userInput.find(delimiter));
    userInput.erase(0, userInput.find(delimiter) + delimiter.length());

    string inputMode = userInput.substr(0, userInput.find(delimiter));
    userInput.erase(0, userInput.find(delimiter) + delimiter.length());
    string inputCapacity = userInput.substr(0, userInput.find(delimiter));
    stringstream(inputCapacity) >> tmpCapacity;
    stringstream(inputMode) >> tmpMode;
    Meeting meeting3(inputName,inputDate,tmpCapacity,tmpMode);
    meetings[2] = meeting3;




    for (int i = 0; i < nMeetings; i++){

        meetings[i].printInfo();
        capacities[i] = meetings[i].getCapacity();
        totalCapacity = totalCapacity + capacities[i];
    }

    cout<<endl;

    for (int i = 0; i < nMeetings; i++){

        if(meetings[i].isOnline(meetings[i].getMode())==false){
            meetings[i].changeOnline(i);

        }
    } 

    cout<<endl;
    cout<<"The total capacity of 3 meetings is: "<<totalCapacity;
    cout<<endl;
    
    meetings[1].setCapacity(meetings[0].getCapacity()+meetings[2].getCapacity());
    cout<<"\nNow the capacity of meeting2 is changed..."<<endl;

    totalCapacity = 0;
    for (int i = 0; i < nMeetings; i++){

        capacities[i] = meetings[i].getCapacity();
        totalCapacity = totalCapacity + capacities[i];
    }

    cout<<"The total capacity of 3 meetings is: "<<totalCapacity<<endl;
    cout<<endl;

    cout<<"Would you like to postpone the meeting1? ";
    getline(cin,userInput);
    if(userInput == "yes"){
        cout<<"Please enter the new date: ";
        getline(cin,userInput);
        meetings[0].postpone(userInput);
    }
    cout<<endl;
    if(meetings[0].equals(meetings[1])==false)
    {
        cout<<"Meeting 1 & 2 are not equal."<<endl;
    }
    if(meetings[0].equals(meetings[1])==true)
    {
        cout<<"Meeting 1 & 2 are equal."<<endl;
    }
    if(meetings[0].equals(meetings[2])==false)
    {
        cout<<"Meeting 1 & 3 are not equal."<<endl;
    }
    if(meetings[0].equals(meetings[2])==true)
    {
        cout<<"Meeting 1 & 3 are equal."<<endl;
    }
    if(meetings[1].equals(meetings[2])==false)
    {
        cout<<"Meeting 2 & 3 are not equal."<<endl;
    }
    else if(meetings[1].equals(meetings[2])==true)
    {
        cout<<"Meeting 2 & 3 are equal."<<endl;
    }

    cout<<endl;
    meetingCount=1;
    for (int i = 0; i < nMeetings; i++){
        meetings[i].printInfo();
    }
    cout<<endl;
    cout<<"Thank you for using Meeting Information Program!";
    return 0; 
}
