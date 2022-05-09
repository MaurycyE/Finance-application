#include "DatesAndFinances.h"

using namespace std;

DatesAndFinances::DatesAndFinances() {
    //ctor
}

int DatesAndFinances::yearGetter() {

    return year;

}

int DatesAndFinances::monthGetter() {

    return month;
}

int DatesAndFinances::dayGetter() {

    return day;
}

void DatesAndFinances::yearSetter(int yearToSet) {

    year=yearToSet;

}

void DatesAndFinances::monthSetter(int monthToSet) {

    month=monthToSet;
}


void DatesAndFinances::daySetter(int dayToSet) {

    day=dayToSet;
}

void DatesAndFinances::fullDateSetter (int dateInIntFormat) {

    fullDate=dateInIntFormat;
}

int DatesAndFinances::fullDateGetter() {

    return fullDate;

}

string DatesAndFinances::descriptionGetter() {
    return description;

}

void DatesAndFinances::descriptionSetter(string descriptionToSet) {

    description=descriptionToSet;
}

int DatesAndFinances::userIdGetter() {
    return userID;

}


void DatesAndFinances::userIdSetter(int userIdToSet) {

    userID=userIdToSet;
}
