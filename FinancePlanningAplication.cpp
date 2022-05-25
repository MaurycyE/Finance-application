#include "FinancePlanningAplication.h"

char FinancePlanningAplication::selectOptionFromMainMenu() {

    char userSelection;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Sign in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter Your choice: ";
    userSelection = SupportMethods::loadSingleCharacter();

    return userSelection;
}

char FinancePlanningAplication::selectOptionFromUserMenu() {

    char userSelection;
    string firstName = userMenager.loggedUserFirstNameGetter();
    string lastName = userMenager.loggedUserLastNameGetter();

    system("cls");
    cout << " >>> USER MENU <<<                        Logged as: "<<firstName<<" "<<lastName<< endl;
    cout << "---------------------------               ---------------------------" << endl;
    cout << "1. Add Income" << endl;
    cout << "2. Add Expense" << endl;
    cout << "3. Balance sheet from current month" << endl;
    cout << "4. Balance sheet from previous month" << endl;
    cout << "5. Balance sheet from selected period of time" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter Your choice: ";
    userSelection = SupportMethods::loadSingleCharacter();

    return userSelection;

}

bool FinancePlanningAplication::isUserSingedIn() {

    return userMenager.isUserSingedIn();

}

void FinancePlanningAplication::userRegistration() {

    userMenager.userRegistration();

}

void FinancePlanningAplication::userLogging() {

    userMenager.userLogging();

    if (userMenager.isUserSingedIn()) {

        incomesManager = new IncomesManager(userMenager.loggedUserIdGetter(), INCOMES_FILE_NAME);
        expanseManager = new ExpansesManager(userMenager.loggedUserIdGetter(), EXPANSES_FILE_NAME);
    }
}

void FinancePlanningAplication::changeLoggedUserPassword() {

    userMenager.changeLoggedUserPassword();

}

void FinancePlanningAplication::addIncome() {

    incomesManager->addIncome();

}

void FinancePlanningAplication::addExpense() {

    expanseManager->addExpanse();
}

void FinancePlanningAplication::BalanceSheetFromCurrentMonth() {

    incomesManager->displayAllIncomesFromCurrentOrPreviousMonth(0);  /**0 - current month */
    cout<<"Total income: "<<incomesManager->totalIncomeGetter()<<endl<<endl;
    expanseManager->displayAllExpansesFromCurrentOrPreviousMonth(0);
    cout<<"Total expanse: "<<expanseManager->totalExpanseGetter()<<endl;
    cout<<endl<<"Difference between income and expanse: "<<incomesManager->totalIncomeGetter()- expanseManager->totalExpanseGetter()<<endl;

    getchar();
}

void FinancePlanningAplication::BalanceSheetFromPreviousMonth() {

    incomesManager->displayAllIncomesFromCurrentOrPreviousMonth(1);  /**1 - previous month */
    cout<<"Total income: "<<incomesManager->totalIncomeGetter()<<endl<<endl;
    expanseManager->displayAllExpansesFromCurrentOrPreviousMonth(1);
    cout<<"Total expanse: "<<expanseManager->totalExpanseGetter()<<endl;
    cout<<endl<<"Difference between income and expanse: "<<incomesManager->totalIncomeGetter()- expanseManager->totalExpanseGetter()<<endl;

    getchar();
}

void FinancePlanningAplication::BalanceSheetFromSelectedPeriodOfTime() {

    incomesManager->displayAllIncomesFromSelectedPeriodOfTime();
    cout<<"Total income: "<<incomesManager->totalIncomeGetter()<<endl<<endl;
    expanseManager->displayAllExpansesFromSelectedPeriodOfTime(incomesManager->firstUserDateConvertedToIntGetter(), incomesManager->secondUserDateConvertedToIntGetter());
    cout<<"Total expanse: "<<expanseManager->totalExpanseGetter()<<endl;
    cout<<endl<<"Difference between income and expanse: "<<incomesManager->totalIncomeGetter()- expanseManager->totalExpanseGetter()<<endl;

    getchar();
}

void FinancePlanningAplication::logOutUser() {

    userMenager.logOutUser();
    delete incomesManager;
    incomesManager= NULL;
    delete expanseManager;
    expanseManager=NULL;
}
