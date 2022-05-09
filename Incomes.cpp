#include "Incomes.h"

Incomes::Incomes() {
    //ctor
}

void Incomes::incomeAmoutSetter(float amout) {

    incomeAmout=amout;

}


void Incomes::incomeIDsetter(int recordId) {

    incomeID = recordId;

}

float Incomes::incomeAmoutGetter() {

    return incomeAmout;
}


int Incomes::incomeIDgetter() {

    return incomeID;
}
