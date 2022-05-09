#ifndef INCOMESFILES_H
#define INCOMESFILES_H
#include <iostream>
#include <vector>
#include "Incomes.h"
#include "Markup.h"
#include "SupportMethods.h"

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

private:
    int lastIncomeID;
    const string USER_FILE_NAME;
    int getLastIncomeId();

};

#endif // INCOMESFILES_H
