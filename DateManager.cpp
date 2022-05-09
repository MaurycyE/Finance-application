#include "DateManager.h"

using namespace std;

DateManager::DateManager() {
    //ctor
}

bool DateManager::isYearIntercalary(int year) {

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;

    return false;
}


int DateManager::amountOfDaysInCurrentMonth(int year, int month) {

    int amountOfDaysInCurrentMonth=0;
    if (month == 2) {

        if (isYearIntercalary(year)==true) // sprawdzenie warunku na przestepny miesi¹c
            amountOfDaysInCurrentMonth=29;
        else
            amountOfDaysInCurrentMonth=28;
    }

    else if (((month < 8)&&(month%2==1))||((month >7)&&(month%2==0)))
        amountOfDaysInCurrentMonth=31;

    else
        amountOfDaysInCurrentMonth=30;

    return amountOfDaysInCurrentMonth;

}


string DateManager::keepValidFormat(int dateComponent) {

    string convertedDateComponent=SupportMethods::conversionIntToString(dateComponent);

    if (dateComponent<10) {
        convertedDateComponent = '0'+convertedDateComponent;
        return convertedDateComponent;
    }

    return convertedDateComponent;
}


string DateManager::giveActualDate(int userSelection) {

    string actualDate="";
    time_t actualTime = time( 0 );
    tm * currentTime = localtime( & actualTime );

    int actualYear = 1900 + currentTime->tm_year;
    int actualMonth = 1 + currentTime->tm_mon;
    int actualDay = currentTime->tm_mday;

    switch (userSelection) {

    case '1':
        actualDate = SupportMethods::conversionIntToString(actualYear)+'-'+keepValidFormat(actualMonth)+'-'+keepValidFormat(actualDay);
        return actualDate;

    case '2':
        actualDate = SupportMethods::conversionIntToString(actualYear)+keepValidFormat(actualMonth)+keepValidFormat(actualDay);
        return actualDate;

    case '3':
        return SupportMethods::conversionIntToString(actualMonth);

    case '4':
        return SupportMethods::conversionIntToString(actualYear);

    }

}


DatesAndFinances DateManager::obtainYearMonthAndDayFromFullDate(string fullDate) {

    DatesAndFinances dates;

    string dateComponent="";
    int currentChar=0;
    int separationCharIndicator = 0;

    while (1) {

        if(fullDate[currentChar]=='-') {

            switch (separationCharIndicator) {

            case 0:
                dates.yearSetter(SupportMethods::conversionStringToInt(dateComponent));
                break;
            case 1:
                dates.monthSetter(SupportMethods::conversionStringToInt(dateComponent));
                break;

            }
            dateComponent="";
            currentChar++;
            separationCharIndicator++;

        }
        if (separationCharIndicator==2) {
            dateComponent=dateComponent+fullDate[currentChar];
            currentChar++;
            dateComponent=dateComponent+fullDate[currentChar];
            dates.daySetter(SupportMethods::conversionStringToInt(dateComponent));
            break;

        }

        dateComponent=dateComponent+fullDate[currentChar];
        currentChar++;

    }

    string dateWithoutSeparationChar=keepValidFormat(dates.yearGetter())+keepValidFormat(dates.monthGetter())+keepValidFormat(dates.dayGetter());
    dates.fullDateSetter(SupportMethods::conversionStringToInt(dateWithoutSeparationChar));

    return dates;
}

bool DateManager::isGivenDateVaild(string writtenDate) {

    DatesAndFinances dateToVerify = obtainYearMonthAndDayFromFullDate(writtenDate);
    DatesAndFinances dateFromSystem = obtainYearMonthAndDayFromFullDate(giveActualDate('1'));

    const int oldestPossibleYear = 2000;
    const int numberOfLastMonth = 12;

    if ((dateToVerify.monthGetter()>numberOfLastMonth)||(dateToVerify.monthGetter()<1)) {
        cout<<"Wrong month number"<<endl;
        system("pause");
        return false;
    }

    if((dateToVerify.dayGetter()>amountOfDaysInCurrentMonth(dateToVerify.yearGetter(), dateToVerify.monthGetter()))||(dateToVerify.dayGetter()<1)) {
        cout<<"Day number is bigger than amount of days in given month. You could also enter number lesser than 1"<<endl;
        system("pause");
        return false;
    }

    if ((dateToVerify.dayGetter()>amountOfDaysInCurrentMonth(dateFromSystem.yearGetter(), dateFromSystem.monthGetter()))) {
        cout<<"Day number is bigger than amount of days in current month. You could also enter number lesser than 1"<<endl;
        system("pause");
        return false;

    }

    if((dateToVerify.yearGetter()<oldestPossibleYear)||(dateToVerify.yearGetter()>dateFromSystem.yearGetter())) {
        cout<<"You can enter date from 2000-01-01 to last day of actual month"<<endl;
        system("pause");
        return false;
    }

    if ((dateToVerify.yearGetter()==dateFromSystem.yearGetter())&&(dateToVerify.monthGetter()>dateFromSystem.monthGetter())) {
        cout<<"You can't enter date from future month"<<endl;
        system("pause");
        return false;
    }

    return true;
}
