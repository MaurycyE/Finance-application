#ifndef INCOMES_H
#define INCOMES_H
#include <iostream>
#include "DatesAndFinances.h"

using namespace std;

class Incomes : public DatesAndFinances
{
    public:
        /** Default constructor */
        Incomes();
        void incomeAmoutSetter(float amout);
        void incomeIDsetter(int recordId);
        float incomeAmoutGetter();
        int incomeIDgetter();

    private:
       float incomeAmout;
       int incomeID;

};

#endif // INCOMES_H
