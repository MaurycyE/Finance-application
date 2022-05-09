#ifndef EXPANSES_H
#define EXPANSES_H
#include <iostream>

#include "DatesAndFinances.h"

using namespace std;

class Expanses : public DatesAndFinances {
public:
    /** Default constructor */
    Expanses();
    void expanseAmoutSetter(float amout);
    void expanseIDsetter(int recordId);
    float expanseAmoutGetter();
    int expanseIDgetter();

private:
    float expanseAmout;
    int expanseID;


};

#endif // EXPANSES_H
