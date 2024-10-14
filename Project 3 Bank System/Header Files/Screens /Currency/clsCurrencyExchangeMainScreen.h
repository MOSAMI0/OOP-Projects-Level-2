#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen : protected clsScreen
{

private:
    enum enCurrencyExchangeMenue {
        eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short ReadCurrencyExchangeMenue()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrencyExchangeMenue()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menue...";
        system("pause>0");
        ShowCurrenciesMenue();
    }

    static void _ShowListCurrencyScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrenciesMainMenueOptions(enCurrencyExchangeMenue CurrencyExchangeMenue)
    {

        switch (CurrencyExchangeMenue)
        {
        case enCurrencyExchangeMenue::eListCurrency:
            system("cls");
            _ShowListCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;

        case enCurrencyExchangeMenue::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;

        case enCurrencyExchangeMenue::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenue();
            break;

        case enCurrencyExchangeMenue::eCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenue();
            break;

        case enCurrencyExchangeMenue::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        } 
         
        }

    }

public:

    static void ShowCurrenciesMenue()
    {

        system("cls");
        _DrawScreenHeader("    Currancy Exhange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrenciesMainMenueOptions((enCurrencyExchangeMenue)ReadCurrencyExchangeMenue());
    }
};