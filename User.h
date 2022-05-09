#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User {
public:
    /** Default constructor */
    User();
    void userFirstNameSetter(string userFirstName);
    void userLastNameSetter(string userLastName);
    void userLoginSetter(string userLogin);
    void userPasswordSetter(string userPassword);
    void userIdSetter (int id);
    string userLoginGetter();
    string userPasswordGetter();
    int userIdGetter();
    string userFirstNameGetter();
    string userLastNameGetter();

private:
    string userFirstName;
    string userLastName;
    string userLogin;
    string userPassword;
    int userId;

};

#endif // USER_H
