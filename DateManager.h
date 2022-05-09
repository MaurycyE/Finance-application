#ifndef DATEMANAGER_H
#define DATEMANAGER_H
#include <iostream>
#include <time.h>
#include "DatesAndFinances.h"
#include "SupportMethods.h"

using namespace std;

class DateManager {
public:
    /** Default constructor */
    DateManager();

    bool isYearIntercalary(int year);
    int amountOfDaysInCurrentMonth(int year, int month);
    string giveActualDate(int userSelection);
    DatesAndFinances obtainYearMonthAndDayFromFullDate(string fullDate);
    void sortDates();
    bool isGivenDateVaild(string writtenDate);
    string keepValidFormat(int dateComponent);


private:
};

#endif // DATEMANAGER_H
