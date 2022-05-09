#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include "Incomes.h"
#include "DateManager.h"
#include "IncomesFiles.h"

using namespace std;

class IncomesManager {
public:

    IncomesManager(int LOGGED_USER_ID, string incomesFileName): loggedUserId(LOGGED_USER_ID), incomesFile(incomesFileName) {

        incomes=incomesFile.loadLoggedUserIncomes(incomes, loggedUserId);
        lastIncomeID=loadLastIncomeId ();
    };
    float sumOfIncomes();
    void addIncome();
    void displayAllIncomesFromCurrentOrPreviousMonth(int currentOrPreviousMonth);
    void displayAllIncomesFromSelectedPeriodOfTime();
    void loadIncomeRecords ();
    int loadLastIncomeId ();
    void lastIncomeIdSetter(int newLastIncomeId);
    int giveCurrentMonth();
    int giveCurrentYear();
    int obtainMonthFromFullDate (int fullDate);
    int obtainYearFromFullDate (int fullDate);
    float totalIncomeGetter();
    int firstUserDateConvertedToIntGetter();
    int secondUserDateConvertedToIntGetter();

private:
    IncomesFiles incomesFile;
    const int loggedUserId;
    float totalIncome;
    vector <Incomes> incomes;
    vector <Incomes> incomesToDisplayFromSelectedPeriod;
    int lastIncomeID;
    int firstUserDateConvertedToInt;
    int secondUserDateConvertedToInt;

};

#endif // INCOMESMANAGER_H
