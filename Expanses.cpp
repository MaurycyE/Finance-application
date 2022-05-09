#include "Expanses.h"

using namespace std;

Expanses::Expanses() {
    //ctor
}

void Expanses::expanseAmoutSetter(float amout) {

    expanseAmout=amout;

}


void Expanses::expanseIDsetter(int recordId) {

    expanseID = recordId;

}

float Expanses::expanseAmoutGetter() {

    return expanseAmout;
}


int Expanses::expanseIDgetter() {

    return expanseID;
}
