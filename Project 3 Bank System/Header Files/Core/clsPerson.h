#pragma once
#include <iostream>
#include <string>
#include "InterfaceCommunication.h"
using namespace std;

class clsPerson : InterfaceCommunication
{

private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    //Property Get
    string GetFirstName()
    {
        return _FirstName;
    }

    //Property Set
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    __declspec(property(get = GetFirstName, put = setFirstName)) string FirstName;

    //Property Get
    string GetLastName()
    {
        return _LastName;
    }

    //Property Set
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }
    __declspec(property(get = GetLastName, put = setLastName)) string LastName;

    //Property Get
    string GetEmail()
    {
        return _Email;
    }

    //Property Set
    void setEmail(string Email)
    {
        _Email = Email;
    }
    __declspec(property(get = GetEmail, put = setEmail)) string Email;


    //Property Get
    string GetPhone()
    {
        return _Phone;
    }

    //Property Set
    void setPhone(string Phone)
    {
        _Phone = Phone;
    }
    __declspec(property(get = GetPhone, put = setPhone)) string Phone;

    //Property Set
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "\nInfo\n";
        cout << "_______________________________\n";
        cout << "First Name  : " << _FirstName << endl;
        cout << "Last Name   : " << _LastName << endl;
        cout << "Full Name   : " << FullName() << endl;
        cout << "Email       : " << _Email << endl;
        cout << "Phone       : " << _Phone << endl;
        cout << "_______________________________\n";
    }
    
    void SendEmail(string Title, string Body)
    {


     }
    void SendFax(string Title, string Body)
    {

     }
    void SendSMS(string Title, string Body)
    {

     }


   

};

