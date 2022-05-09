#ifndef USERFILE_H
#define USERFILE_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include "User.h"
#include "Markup.h"
#include "SupportMethods.h"


using namespace std;

class UserFile {
public:
    UserFile(string fileName): USER_FILE_NAME(fileName) {
    } ;
    void addUserToTheFile (User actualUser);
    vector <User> loadUsersFromFile (vector <User> &users);
    void findPhrase();
    void  changePasswordInFile(int userID, string newPassword);

private:
    const string USER_FILE_NAME;
};

#endif // USERFILE_H
