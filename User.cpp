#include "User.h"

using namespace std;

User::User() {
    //ctor
}

void User::userFirstNameSetter(string FirstName) {

    userFirstName=FirstName;

}

void User::userLastNameSetter(string LastName) {
    userLastName=LastName;
}

void User::userLoginSetter(string Login) {
    userLogin=Login;
}

void User::userPasswordSetter(string Password) {
    userPassword=Password;
}

void User::userIdSetter (int id) {
    userId=id;
}

string User::userLoginGetter() {
    return userLogin;
}

string User::userPasswordGetter() {
    return userPassword;
}

int User::userIdGetter() {
    return userId;
}

string User::userFirstNameGetter() {

    return userFirstName;
}

string User::userLastNameGetter() {

    return userLastName;
}
