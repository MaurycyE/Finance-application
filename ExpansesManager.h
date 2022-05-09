#ifndef EXPANSESMANAGER_H
#define EXPANSESMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include "Expanses.h"
#include "ExpansesFile.h"
#include "DateManager.h"

using namespace std;

class ExpansesManager
{
    public:
        /** Default constructor */
        ExpansesManager();

         ExpansesManager(int LOGGED_USER_ID, string expansesFileName): loggedUserId(LOGGED_USER_ID), expansesFile(expansesFileName) {

    expanses=expansesFile.loadLoggedUserExpanses(expanses, loggedUserId);
    lastExpanseID=loadLastExpanseId ();
        };
        float sumOfExpanses();
        void addExpanse();
        void displayAllExpansesFromCurrentOrPreviousMonth(int currentOrPreviousMonth);
        void displayAllExpansesFromSelectedPeriodOfTime(int firstUserDateConvertedToInt, int secondUserDateConvertedToInt);
        void loadExpanseRecords ();
        int loadLastExpanseId ();
        void lastExpanseIdSetter(int newLastExpanseId);
        int giveCurrentMonth();
        int giveCurrentYear();
        int obtainMonthFromFullDate (int fullDate);
        int obtainYearFromFullDate (int fullDate);
        float totalExpanseGetter();

    private:
        ExpansesFile expansesFile;
        const int loggedUserId;
        float totalExpanse;
        vector <Expanses> expanses;
        vector <Expanses> expansesToDisplayFromSelectedPeriod;
        int lastExpanseID;

};

#endif // EXPANSESMANAGER_H
