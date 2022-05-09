#ifndef SUPPORTMETHODS_H
#define SUPPORTMETHODS_H
#include <iostream>
#include <sstream>
//#include <string>


using namespace std;

class SupportMethods {
public:
    /** Default constructor */
    SupportMethods();
    static string conversionIntToString(int number);
    static string loadTextLine();
    static int conversionStringToInt(string number);
    static string convertCommaToDot (string incomeExpanseAmout);
    static char loadSingleCharacter ();
    static float conversionStringToFloat (string number);
    static string conversionFloatToString (float number);

};

#endif // SUPPORTMETHODS_H
