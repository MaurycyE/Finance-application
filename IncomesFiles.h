#ifndef INCOMESFILES_H
#define INCOMESFILES_H
#include <iostream>
#include <vector>
#include "Incomes.h"
#include "Markup.h"
#include "SupportMethods.h"
#include "DateManager.h"
#include "IncomesFiles.h"
//#include <cstdlib>

using namespace std;

class IncomesFiles {
public:

    IncomesFiles(string fileName): USER_FILE_NAME(fileName) {
    } ;
    void addIncomesToTheFile(Incomes actualRecord);
    vector<Incomes> loadLoggedUserIncomes(vector<Incomes> incomes, int loggedUserId);
    void lasIncomeIDSetter(int incomeIDtoSet);
    int lastIncomeIDgetter();
    string addDateToFileWithSeparationSign (int dateWithoutSeparationSigns);
    bool isIncomeFileEmpty ();

private:
    int lastIncomeID;
    const string USER_FILE_NAME;
    int getLastIncomeId();


};

#endif // INCOMESFILES_H
