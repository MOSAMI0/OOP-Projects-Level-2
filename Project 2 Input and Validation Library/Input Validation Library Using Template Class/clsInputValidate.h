#pragma once
#include<iostream>
#include "clsDate.h"

using namespace std;

template <typename T> class clsInputValidate
{
public:

    static bool IsNumberBetween(T Number, T From, T To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        // Assumes that From <= To or From >= To is handled
        return (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            && (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To));
    }

    static T ReadNumber(string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        T Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static T ReadShortNumberBetween(T From, T To, string ErrorMessage = "Invalid Number, Enter again\n")
    {
        T Number = ReadNumber();
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadNumber();
        }
        return Number;
    }

    static bool IsValidDate(clsDate Date)  // Fixed Typo
    {
        return clsDate::IsValidDate(Date);
    }

    static string ReadString()
    {
        string S1 = "";
        getline(cin >> ws, S1);  // ws to extract leading whitespaces
        return S1;
    }
};
