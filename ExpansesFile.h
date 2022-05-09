#ifndef EXPANSESFILE_H
#define EXPANSESFILE_H
#include <iostream>
#include "Expanses.h"
#include <vector>
#include "Markup.h"
#include "SupportMethods.h"

using namespace std;

class ExpansesFile {
public:
    /** Default constructor */
    //ExpansesFile();
    ExpansesFile(string fileName): USER_FILE_NAME(fileName) {
    } ;

    void addExpansesToTheFile(Expanses actualRecord);
    vector<Expanses> loadLoggedUserExpanses(vector<Expanses> expanses, int loggedUserId);
    void lastExpansesIDSetter(int incomeIDtoSet);
    int lastExpansesIDgetter();
    string displayDateWithSeparationSign (int dateWithoutSeparationSigns);

private:

    int lastExpansesID;
    const string USER_FILE_NAME;
    int getLastExpansesId();

};

#endif // EXPANSESFILE_H
