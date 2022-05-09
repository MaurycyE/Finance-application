#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>
#include "User.h"
#include <vector>
#include "SupportMethods.h"
#include "UserFile.h"

using namespace std;

class UserMenager {
public:
    UserMenager(string usersFileName): userFile(usersFileName) {
        loggedUserId=0;
        users=userFile.loadUsersFromFile(users);

    };
    /** Default destructor */
    ~UserMenager();

    void userRegistration();
    int userLogging();
    void changeLoggedUserPassword();
    int getIdLoggedUser();
    void logOutUser();
    bool isUserSingedIn();
    void loadUsersFromTheFile();
    int loggedUserIdGetter();
    void loggedUserFirstNameSetter(string firstNameToSet);
    void loggedUserLastNameSetter(string lastNameToSet);
    string loggedUserFirstNameGetter();
    string loggedUserLastNameGetter();

private:
    int loggedUserId;
    vector <User> users;
    User passNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);
    UserFile userFile;
    string loggedUserFirstName;
    string loggedUserLastName;
};

#endif // USERMENAGER_H
