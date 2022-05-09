#include "ExpansesManager.h"

void ExpansesManager::addExpanse() {

    Expanses actualRecord;

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

        actualRecord.fullDateSetter(SupportMethods::conversionStringToInt(giveActualDate.giveActualDate('2')));
    }

    if (userAnswer=='n') {
        string userDate="";
        DateManager checkUserDate;
        bool validationCheck;
        do {

            cout<<"Enter date in format rrrr-mm-dd and from 01-01-2000 to last day of current month period: "<<endl;
            userDate="";
            userDate=SupportMethods::loadTextLine();
            validationCheck = checkUserDate.isGivenDateVaild(userDate);

            if (validationCheck==false)
                cout<<"Wrong date. Please use format rrrr-mm-dd"<<endl;

            if (validationCheck==true) {

                DateManager gateFullDate;
                DatesAndFinances dateToSave;
                dateToSave=gateFullDate.obtainYearMonthAndDayFromFullDate(userDate);
                actualRecord.fullDateSetter(dateToSave.fullDateGetter());

            }

        } while (validationCheck==false);

    }

    cout<<"Enter expanse amount. Use dot to separate: ";
    string userAmountOfExpanse="";
    userAmountOfExpanse=SupportMethods::loadTextLine();
    userAmountOfExpanse=SupportMethods::convertCommaToDot(userAmountOfExpanse);
    actualRecord.expanseAmoutSetter(SupportMethods::conversionStringToFloat(userAmountOfExpanse));

    cout<<endl<<"Enter description to added expanse: ";
    string userDescriptionToAddedExpanse="";
    userDescriptionToAddedExpanse=SupportMethods::loadTextLine();
    actualRecord.descriptionSetter(userDescriptionToAddedExpanse);

    actualRecord.expanseIDsetter(lastExpanseID+1);
    actualRecord.userIdSetter(loggedUserId);

    expanses.push_back(actualRecord);
    expansesFile.addExpansesToTheFile(actualRecord);
    lastExpanseIdSetter(lastExpanseID+1);

    cout<<endl;
    cout<<"Following expanse has been added to the file:"<<endl<<endl;
    cout<<actualRecord.fullDateGetter()<<endl;
    cout<<actualRecord.expanseAmoutGetter()<<endl;
    cout<<actualRecord.descriptionGetter()<<endl;
    cout<<actualRecord.expanseIDgetter()<<endl;
    cout<<actualRecord.userIdGetter()<<endl;
    getchar();

}

void ExpansesManager::loadExpanseRecords () {

    expansesFile.loadLoggedUserExpanses(expanses, loggedUserId);
}

int ExpansesManager::loadLastExpanseId () {

    if (expanses.empty()==true)
        lastExpanseID=0;

    else {
        lastExpanseID=expansesFile.lastExpansesIDgetter();
    }

    return lastExpanseID;
}

void ExpansesManager::lastExpanseIdSetter(int newLastExpanseId) {

    lastExpanseID=newLastExpanseId;
}

void ExpansesManager::displayAllExpansesFromCurrentOrPreviousMonth(int currentOrPreviousMonth) {

    totalExpanse=0;
    int currentMonth=giveCurrentMonth()-currentOrPreviousMonth;
    int currentYear=giveCurrentYear();

    vector <Expanses>::iterator it;

    for (auto it=expanses.begin(); it!=expanses.end(); ++it) {

        if((obtainMonthFromFullDate(it->Expanses::fullDateGetter())==currentMonth)&&(obtainYearFromFullDate(it->Expanses::fullDateGetter())==currentYear)) {

            Expanses expanseRecordToDisplay;
            expanseRecordToDisplay.expanseAmoutSetter(it->Expanses::expanseAmoutGetter());
            expanseRecordToDisplay.fullDateSetter(it->Expanses::fullDateGetter());
            expanseRecordToDisplay.descriptionSetter(it->Expanses::descriptionGetter());
            expansesToDisplayFromSelectedPeriod.push_back(expanseRecordToDisplay);

            totalExpanse+=it->Expanses::expanseAmoutGetter();

        }

    }

    sort(expansesToDisplayFromSelectedPeriod.begin(), expansesToDisplayFromSelectedPeriod.end(), []( Expanses &expanseCompared,  Expanses &expanseToCompare) {
        return expanseCompared.fullDateGetter() < expanseToCompare.fullDateGetter();
    });

    for (auto it=expansesToDisplayFromSelectedPeriod.begin(); it!=expansesToDisplayFromSelectedPeriod.end(); ++it) {

        cout<<"Expanse amout: "<<it->Expanses::expanseAmoutGetter()<<"      "<<"Date: "<<expansesFile.displayDateWithSeparationSign(it->Expanses::fullDateGetter())<<"     "<<"Description: "<<it->Expanses::descriptionGetter()<<endl;

    }
    if (expansesToDisplayFromSelectedPeriod.empty())
        cout<<"There is no expanse records from given period of time"<<endl;

    expansesToDisplayFromSelectedPeriod.erase(expansesToDisplayFromSelectedPeriod.begin(), expansesToDisplayFromSelectedPeriod.end());
}

void ExpansesManager::displayAllExpansesFromSelectedPeriodOfTime(int firstUserDateConvertedToInt, int secondUserDateConvertedToInt) {

    totalExpanse=0;

    vector <Expanses>::iterator it;

    for (auto it=expanses.begin(); it!=expanses.end(); ++it) {

        if((it->Expanses::fullDateGetter()>=firstUserDateConvertedToInt)&&(it->Expanses::fullDateGetter()<=secondUserDateConvertedToInt)) {

            Expanses expanseRecordToDisplay;
            expanseRecordToDisplay.expanseAmoutSetter(it->Expanses::expanseAmoutGetter());
            expanseRecordToDisplay.fullDateSetter(it->Expanses::fullDateGetter());
            expanseRecordToDisplay.descriptionSetter(it->Expanses::descriptionGetter());
            expansesToDisplayFromSelectedPeriod.push_back(expanseRecordToDisplay);
            totalExpanse+=it->Expanses::expanseAmoutGetter();

        }
    }

    sort(expansesToDisplayFromSelectedPeriod.begin(), expansesToDisplayFromSelectedPeriod.end(), []( Expanses &expanseCompared,  Expanses &expanseToCompare) {
        return expanseCompared.fullDateGetter() < expanseToCompare.fullDateGetter();
    });

    for (auto it=expansesToDisplayFromSelectedPeriod.begin(); it!=expansesToDisplayFromSelectedPeriod.end(); ++it) {

        cout<<"Expanse amout: "<<it->Expanses::expanseAmoutGetter()<<"      "<<"Date: "<<expansesFile.displayDateWithSeparationSign(it->Expanses::fullDateGetter())<<"     "<<"Description: "<<it->Expanses::descriptionGetter()<<endl;

    }
    if (expansesToDisplayFromSelectedPeriod.empty())
        cout<<"There is no expanse records from given period of time"<<endl;

    expansesToDisplayFromSelectedPeriod.erase(expansesToDisplayFromSelectedPeriod.begin(), expansesToDisplayFromSelectedPeriod.end());

}

int ExpansesManager::giveCurrentMonth() {

    DateManager actualMonth;
    int currentMonth = SupportMethods::conversionStringToInt(actualMonth.giveActualDate('3'));

    return currentMonth;
}

int ExpansesManager::giveCurrentYear() {

    DateManager actualYear;
    int currentYear = SupportMethods::conversionStringToInt(actualYear.giveActualDate('4'));

    return currentYear;
}

int ExpansesManager::obtainMonthFromFullDate (int fullDate) {

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

int ExpansesManager::obtainYearFromFullDate (int fullDate) {

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

float ExpansesManager::totalExpanseGetter() {

    return totalExpanse;
}
