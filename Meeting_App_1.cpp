#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// QUESTION 1

struct Meeting
{
    //PART a) Declare Meeting with information
    string Name ;
    string Date ;
    int Capacity ; 
    int Mode ;
    bool isOnline ; 
};
Meeting newMeeting()

{
    //PART b) Declare meeting1 as Meeting type
    Meeting meeting1;
    //PART c) Funtion for taking in and reading (Name, Date, Capacity, and Mode) of Meeting member variables
    string tmpCapacity;
    string tmpMode;
    cout<<"Please enter the following information:"<<endl;
    cout<<"Meeting's name:  ";
    getline (cin, meeting1.Name);
    cout<<"Meeting's date:  ";
    getline (cin, meeting1.Date);
    cout<<"Meeting's capacity:  ";
    getline (cin, tmpCapacity);
    cout<<"Meeting's mode:  ";
    getline (cin, tmpMode);
    cout<<""<<endl;

    stringstream(tmpCapacity) >> meeting1.Capacity;
    stringstream(tmpMode) >> meeting1.Mode;
    meeting1.isOnline = false;
    return meeting1;
};
void displayNewMeeting(Meeting);

int main()
{
    cout<<"*******************************"<<endl;
    cout<<"|     Meeting Information     |"<<endl;
    cout<<"*******************************"<<endl;
    cout<<""<<endl;
    int i = 1;
    string userInput;
    while(i == 1){
    Meeting meeting1 = newMeeting();
    displayNewMeeting(meeting1);
    //PART d) Ask for user to enter another meeting until input is "no"
    cout<<"\nWould you like to set up another meeting?  ";
    getline (cin, userInput);
    if (userInput!="no"){
        i=1;
    }
    if (userInput=="no"){
        i=0;
        cout<<""<<endl;
        cout<<"Thank you for using Meeting Information Program!";
    }
    }
    return 0; 
}

void displayNewMeeting(Meeting meeting1) {
    string tmpCapacity;
    string tmpMode;
    cout<<"The meeting name is:  "<< meeting1.Name<<endl;
    cout<<"The meeting date is:  "<< meeting1.Date<<endl;
    if (meeting1.Capacity==1){
        cout<<"The meeting capacity is:  "<< meeting1.Capacity<<" student"<<endl;
        tmpCapacity="1 student";
    }
    else if (meeting1.Capacity>1){
        cout<<"The meeting capacity is:  "<< meeting1.Capacity<<" students"<<endl;
        string tmpStr = to_string(meeting1.Capacity);

        tmpCapacity=tmpStr+" students";
    }
    if (meeting1.Mode==1){
        cout<<"The meeting mode is:  "<< "online"<<endl;
        tmpMode=" online.";
    }
    else if (meeting1.Mode!=1){
        cout<<"The meeting mode is:  "<< "in person"<<endl;
        tmpMode=" in person.";
    }
    cout<<""<<endl;
    cout<<"Here is the summary of the meeting:"<<endl;
    cout<<meeting1.Name<<" is on "<<meeting1.Date<<" with the capacity of "<<tmpCapacity<< tmpMode<<endl;
}

