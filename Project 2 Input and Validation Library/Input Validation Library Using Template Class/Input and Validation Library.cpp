#include "clsInputValidate.h"
#include "clsDate.h"
#include <iostream>

int main()
{
    // Test IsNumberBetween
    cout << "Testing IsNumberBetween:\n";
    int num = 5;
    if (clsInputValidate<int>::IsNumberBetween(num, 1, 10))
        cout << num << " is between 1 and 10.\n";
    else
        cout << num << " is not between 1 and 10.\n";

    // Test ReadNumber
    cout << "\nTesting ReadNumber:\n";
    cout << "Please enter a number: ";
    int inputNumber = clsInputValidate<int>::ReadNumber();
    cout << "You entered: " << inputNumber << "\n";

    // Test ReadShortNumberBetween
    cout << "\nTesting ReadShortNumberBetween:\n";
    cout << "Please enter a number between 1 and 5: ";
    int validNumber = clsInputValidate<int>::ReadShortNumberBetween(1, 5);
    cout << "You entered a valid number: " << validNumber << "\n";

    // Test IsDateBetween
    cout << "\nTesting IsDateBetween:\n";
    clsDate date1(2024, 10, 14); // Assume this creates a date object
    clsDate date2(2024, 1, 1);
    clsDate date3(2024, 12, 31);
    if (clsInputValidate<clsDate>::IsDateBetween(date1, date2, date3))
        cout << "The date is between 1st Jan 2024 and 31st Dec 2024.\n";
    else
        cout << "The date is not between 1st Jan 2024 and 31st Dec 2024.\n";

    // Test IsValidDate
    cout << "\nTesting IsValidDate:\n";
    clsDate validDate(2024, 10, 14); // Valid date
    if (clsInputValidate<clsDate>::IsValidDate(validDate))
        cout << "The date is valid.\n";
    else
        cout << "The date is invalid.\n";

    // Test ReadString
    cout << "\nTesting ReadString:\n";
    cout << "Please enter a string: ";
    string userInput = clsInputValidate<string>::ReadString();
    cout << "You entered: " << userInput << "\n";

    return 0;
}
