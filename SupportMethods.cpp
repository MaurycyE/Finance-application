#include "SupportMethods.h"

using namespace std;

SupportMethods::SupportMethods() {
    //ctor
}

string SupportMethods::conversionIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int SupportMethods::conversionStringToInt(string number) {
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

float SupportMethods::conversionStringToFloat (string number) {


    float num_float = stof(number);

    return num_float;
}

string SupportMethods::loadTextLine() {
    string entrance = "";
    getline(cin, entrance);
    return entrance;
}

string SupportMethods::convertCommaToDot(string incomeExpanseAmout) {

    for (int i=0; i<incomeExpanseAmout.length(); i++ ) {
        if (incomeExpanseAmout[i]==',')
            incomeExpanseAmout[i]='.';
    }

    return incomeExpanseAmout;
}

char SupportMethods::loadSingleCharacter () {

    string charFromKeyboard = "";
    char character  = {0};

    while (true) {
        getline(cin, charFromKeyboard);

        if (charFromKeyboard.length() == 1) {
            character = charFromKeyboard[0];
            break;
        }
        cout << "Not a single character. Try again." << endl;
    }
    return character;

}

string SupportMethods::conversionFloatToString (float number) {

    stringstream stream;
    stream.precision(2);
    stream << fixed;

    stream<<number;
    string str  = stream.str();

    return str;

}
