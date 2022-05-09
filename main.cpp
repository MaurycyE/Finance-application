#include <iostream>
#include "Markup.h"
#include "UserFile.h"
#include "UserMenager.h"
#include "FinancePlanningAplication.h"
#include "DateManager.h"
#include "IncomesManager.h"

using namespace std;

int main()
{
    FinancePlanningAplication financePlanningAplication ("Users.xml", "Incomes.xml", "Expanses.xml");
    char userSelection;

    while (true) {
        if (financePlanningAplication.isUserSingedIn()==false) {
            userSelection = financePlanningAplication.selectOptionFromMainMenu();

            switch (userSelection) {
            case '1':
                financePlanningAplication.userRegistration();
                break;
            case '2':
                financePlanningAplication.userLogging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in Main Menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            userSelection = financePlanningAplication.selectOptionFromUserMenu();

            switch (userSelection) {
            case '1':
                financePlanningAplication.addIncome();
                break;
            case '2':
                financePlanningAplication.addExpense();
                break;
            case '3':
                financePlanningAplication.BalanceSheetFromCurrentMonth();
                break;
            case '4':
                financePlanningAplication.BalanceSheetFromPreviousMonth();
                break;
            case '5':
                financePlanningAplication.BalanceSheetFromSelectedPeriodOfTime();
                break;
            case '6':
                 financePlanningAplication.changeLoggedUserPassword();
                break;
            case '7':
                financePlanningAplication.logOutUser();
                break;

            }
        }
    }

    return 0;
}

