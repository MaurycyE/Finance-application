#include "IncomesManager.h"

void IncomesManager::addIncome() {

    Incomes actualRecord;
    char userAnswer;

    cout<<"Enter current date?"<<endl;
    cout<<"y/n: ";
    while (1) {
        userAnswer= SupportMethods::loadSingleCharacter();
        if ((userAnswer=='y')||(userAnswer=='n'))
            break;
        else
            cout<<"Please enter y or n"<<endl;

        Sleep(2000);

    }
    if (userAnswer=='y') {
        DateManager giveActualDate;
        //actualRecord.fullDateSetter(giveActualDate.giveActualDate('1'));
        actualRecord.fullDateSetter(SupportMethods::conversionStringToInt(giveActualDate.giveActualDate('2')));
    }

    if (userAnswer=='n') {
        string userDate="";
        DateManager checkUserDate;
        bool validationCheck;
        cout<<"Enter date in format rrrr-mm-dd and from 2000-01-01 to last day of current month period: "<<endl;
        do {

            //cout<<"Enter date in format rrrr-mm-dd and from 2000-01-01 to last day of current month period: "<<endl;
            userDate="";
            userDate=SupportMethods::loadTextLine();
            validationCheck = checkUserDate.isGivenDateVaild(userDate);

            if (!validationCheck)
                cout<<"Wrong date. Please use format rrrr-mm-dd"<<endl;

            if (validationCheck) {

                DateManager gateFullDate;
                DatesAndFinances dateToSave;
                dateToSave=gateFullDate.obtainYearMonthAndDayFromFullDate(userDate);

                actualRecord.fullDateSetter(dateToSave.fullDateGetter());

            }

        } while (!validationCheck);

    }

    cout<<"Enter income amount. Use dot to separate: ";
    string userAmountOfIncome="";
    userAmountOfIncome=SupportMethods::loadTextLine();
    userAmountOfIncome=SupportMethods::convertCommaToDot(userAmountOfIncome);
    actualRecord.incomeAmoutSetter(SupportMethods::conversionStringToFloat(userAmountOfIncome));

    cout<<endl<<"Enter description to added income: ";
    string userDescriptionToAddedIncome="";
    userDescriptionToAddedIncome=SupportMethods::loadTextLine();
    actualRecord.descriptionSetter(userDescriptionToAddedIncome);

    actualRecord.incomeIDsetter(lastIncomeID+1);
    actualRecord.userIdSetter(loggedUserId);

    incomes.push_back(actualRecord);
    incomesFile.addIncomesToTheFile(actualRecord);
    lastIncomeIdSetter(lastIncomeID+1);

    cout<<endl;
    cout<<"Income has been added to the file, press enter to continue."<<endl;

    getchar();

}

void IncomesManager::loadIncomeRecords () {

    incomesFile.loadLoggedUserIncomes(incomes, loggedUserId);
}

int IncomesManager::loadLastIncomeId () {

    //if (incomes.empty())
        if (!incomesFile.isIncomeFileEmpty())
        lastIncomeID=0;

    else {
        lastIncomeID=incomesFile.lastIncomeIDgetter();
    }

    return lastIncomeID;
}

void IncomesManager::lastIncomeIdSetter(int newLastIncomeId) {

    lastIncomeID=newLastIncomeId;
}

void IncomesManager::displayAllIncomesFromCurrentOrPreviousMonth(int currentOrPreviousMonth) {

    totalIncome=0;
    int currentMonth=giveCurrentMonth()-currentOrPreviousMonth;
    int currentYear=giveCurrentYear();

    vector <Incomes>::iterator it;

    for (auto it=incomes.begin(); it!=incomes.end(); ++it) {

        if((obtainMonthFromFullDate(it->Incomes::fullDateGetter())==currentMonth)&&(obtainYearFromFullDate(it->Incomes::fullDateGetter())==currentYear)) {

            Incomes incomeRecordToDisplay;
            incomeRecordToDisplay.incomeAmoutSetter(it->Incomes::incomeAmoutGetter());
            incomeRecordToDisplay.fullDateSetter(it->Incomes::fullDateGetter());
            incomeRecordToDisplay.descriptionSetter(it->Incomes::descriptionGetter());
            incomesToDisplayFromSelectedPeriod.push_back(incomeRecordToDisplay);

            totalIncome+=it->Incomes::incomeAmoutGetter();

        }

    }

    sort(incomesToDisplayFromSelectedPeriod.begin(), incomesToDisplayFromSelectedPeriod.end(), []( Incomes &incomeCompared,  Incomes &incomeToCompare) {
        return incomeCompared.fullDateGetter() < incomeToCompare.fullDateGetter();
    });

    for (auto it=incomesToDisplayFromSelectedPeriod.begin(); it!=incomesToDisplayFromSelectedPeriod.end(); ++it) {

        cout<<"Income amout: "<<it->Incomes::incomeAmoutGetter()<<"      "<<"Date: "<<incomesFile.addDateToFileWithSeparationSign(it->Incomes::fullDateGetter())<<"     "<<"Description: "<<it->Incomes::descriptionGetter()<<endl;

    }
    if (incomesToDisplayFromSelectedPeriod.empty())
        cout<<"There is no income records from given period of time"<<endl;

    incomesToDisplayFromSelectedPeriod.erase(incomesToDisplayFromSelectedPeriod.begin(), incomesToDisplayFromSelectedPeriod.end());
}

void IncomesManager::displayAllIncomesFromSelectedPeriodOfTime() {

    totalIncome=0;
    string firstUserDate="";
    string secondUserDate="";

    DateManager checkUserDate;
    bool validationCheck;
    cout<<"Enter first date in format rrrr-mm-dd and from 2000-01-01 to last day of current month period: "<<endl;

    do {

        firstUserDate="";
        firstUserDate=SupportMethods::loadTextLine();
        validationCheck = checkUserDate.isGivenDateVaild(firstUserDate);

        if (!validationCheck)
            cout<<"Wrong date. Please use format rrrr-mm-dd"<<endl;

        if (validationCheck) {

            DateManager gateFullDate;
            DatesAndFinances dateToSave;
            dateToSave=gateFullDate.obtainYearMonthAndDayFromFullDate(firstUserDate);

            firstUserDateConvertedToInt=dateToSave.fullDateGetter();

        }

    } while (!validationCheck);

    cout<<"Enter second date in format rrrr-mm-dd and from 2000-01-01 to last day of current month period: "<<endl;
    do {

        secondUserDate="";
        secondUserDate=SupportMethods::loadTextLine();
        validationCheck = checkUserDate.isGivenDateVaild(secondUserDate);

        if (!validationCheck)
            cout<<"Wrong date. Please use format rrrr-mm-dd"<<endl;

        if (validationCheck) {

            DateManager getFullDate;
            DatesAndFinances dateToSave;
            dateToSave=getFullDate.obtainYearMonthAndDayFromFullDate(secondUserDate);

            secondUserDateConvertedToInt=dateToSave.fullDateGetter();

        }

        if (secondUserDateConvertedToInt<firstUserDateConvertedToInt) {

            cout<<"Second date can't be before first date"<<endl;
            validationCheck=false;
        }

    } while (!validationCheck);

    vector <Incomes>::iterator it;

    for (auto it=incomes.begin(); it!=incomes.end(); ++it) {

        if((it->Incomes::fullDateGetter()>=firstUserDateConvertedToInt)&&(it->Incomes::fullDateGetter()<=secondUserDateConvertedToInt)) {

            Incomes incomeRecordToDisplay;
            incomeRecordToDisplay.incomeAmoutSetter(it->Incomes::incomeAmoutGetter());
            incomeRecordToDisplay.fullDateSetter(it->Incomes::fullDateGetter());
            incomeRecordToDisplay.descriptionSetter(it->Incomes::descriptionGetter());
            incomesToDisplayFromSelectedPeriod.push_back(incomeRecordToDisplay);
            totalIncome+=it->Incomes::incomeAmoutGetter();

        }
    }

    sort(incomesToDisplayFromSelectedPeriod.begin(), incomesToDisplayFromSelectedPeriod.end(), []( Incomes &incomeCompared,  Incomes &incomeToCompare) {
        return incomeCompared.fullDateGetter() < incomeToCompare.fullDateGetter();
    });

    for (auto it=incomesToDisplayFromSelectedPeriod.begin(); it!=incomesToDisplayFromSelectedPeriod.end(); ++it) {

        cout<<"Income amout: "<<it->Incomes::incomeAmoutGetter()<<"      "<<"Date: "<<incomesFile.addDateToFileWithSeparationSign(it->Incomes::fullDateGetter())<<"     "<<"Description: "<<it->Incomes::descriptionGetter()<<endl;

    }
    if (incomesToDisplayFromSelectedPeriod.empty())
        cout<<"There is no income records from given period of time"<<endl;

    incomesToDisplayFromSelectedPeriod.erase(incomesToDisplayFromSelectedPeriod.begin(), incomesToDisplayFromSelectedPeriod.end());

}

int IncomesManager::giveCurrentMonth() {

    DateManager actualMonth;
    int currentMonth = SupportMethods::conversionStringToInt(actualMonth.giveActualDate('3'));

    return currentMonth;
}

int IncomesManager::giveCurrentYear() {

    DateManager actualYear;
    int currentYear = SupportMethods::conversionStringToInt(actualYear.giveActualDate('4'));

    return currentYear;
}

int IncomesManager::obtainMonthFromFullDate (int fullDate) {

    string fullDateConvertedToString = SupportMethods::conversionIntToString(fullDate);
    string monthToConvertToInt="";
    int month=0;

    for (int i=0; i<8; i++) {

        if((i>3)&&(i<6)) {

            monthToConvertToInt+=fullDateConvertedToString[i];

        }
    }

    month=SupportMethods::conversionStringToInt(monthToConvertToInt);

    return month;
}

int IncomesManager::obtainYearFromFullDate (int fullDate) {

    string fullDateConvertedToString = SupportMethods::conversionIntToString(fullDate);
    string yearToConvertToInt="";
    int year=0;

    for (int i=0; i<8; i++) {

        if(i<4) {
            yearToConvertToInt+=fullDateConvertedToString[i];
        }
    }

    year=SupportMethods::conversionStringToInt(yearToConvertToInt);

    return year;
}

float IncomesManager::totalIncomeGetter() {

    return totalIncome;
}

int IncomesManager::firstUserDateConvertedToIntGetter() {
    return firstUserDateConvertedToInt;

}

int IncomesManager::secondUserDateConvertedToIntGetter() {

    return secondUserDateConvertedToInt;
}

