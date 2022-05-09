#ifndef DATESANDFINANCES_H
#define DATESANDFINANCES_H
#include <iostream>

using namespace std;

class DatesAndFinances {
public:
    /** Default constructor */
    DatesAndFinances();
    int yearGetter();
    int monthGetter();
    int dayGetter();
    int fullDateGetter();
    string descriptionGetter();
    int userIdGetter();
    void yearSetter(int yearToSet);
    void monthSetter(int monthToSet);
    void daySetter(int dayToSet);
    void fullDateSetter (int dateInIntFormat);
    void descriptionSetter(string descriptionToSet);
    void userIdSetter(int userIdToSet);

protected:
    int year;
    int month;
    int day;
    int userID;
    string description;
    int fullDate;

};

#endif // DATESANDFINANCES_H
