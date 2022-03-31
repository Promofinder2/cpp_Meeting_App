#include "Meeting.h"
using namespace std;
//QUESTION 2
int meetingCount=1;
const int nMeetings = 3;
Meeting meetings[nMeetings];
//PART b) IMPLEMENT Meeting member functions
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

    cout<<"Meeting"<<meetingCount<<" is "<<Name<<" on "<<Date<<" with capacity:  "<<Capacity<<capacityStr<<onlineStr<<endl;
}
