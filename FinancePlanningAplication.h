#ifndef FINANCEPLANNINGAPLICATION_H
#define FINANCEPLANNINGAPLICATION_H
#include <iostream>
#include "UserMenager.h"
#include "User.h"
#include "IncomesManager.h"
#include "ExpansesManager.h"

using namespace std;

class FinancePlanningAplication {
public:

    FinancePlanningAplication(string usersFileName, string incomesFileName, string expansesFileName): userMenager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPANSES_FILE_NAME(expansesFileName) {
        incomesManager=NULL;
        expanseManager=NULL;

    };

    ~FinancePlanningAplication() {
        delete incomesManager;
        incomesManager=NULL;
        delete expanseManager;
        expanseManager=NULL;

    };
    char selectOptionFromUserMenu();
    char selectOptionFromMainMenu();
    bool isUserSingedIn();
    void userRegistration();
    void userLogging();
    void changeLoggedUserPassword();
    void addIncome();
    void addExpense();
    void BalanceSheetFromCurrentMonth();
    void BalanceSheetFromPreviousMonth();
    void BalanceSheetFromSelectedPeriodOfTime();
    void logOutUser();

private:
    const string INCOMES_FILE_NAME;
    const string EXPANSES_FILE_NAME;
    UserMenager userMenager;
    IncomesManager *incomesManager;
    ExpansesManager *expanseManager;

};

#endif // FINANCEPLANNINGAPLICATION_H
