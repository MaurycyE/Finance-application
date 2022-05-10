#include "UserMenager.h"
#include <windows.h>

using namespace std;

UserMenager::~UserMenager() {
    //dtor
}

void UserMenager::userRegistration () {

    User user = passNewUserData();
    users.push_back(user);
    userFile.addUserToTheFile(user);

    cout << endl << "The account has been created successfully" << endl << endl;
    system("pause");

}

User UserMenager::passNewUserData() {

    User user;
    user.userIdSetter(getNewUserId());

    string login;
    do {
        cout<< "Type in login: ";
        cin>>login;
        user.userLoginSetter(login);

    } while (isLoginExist(user.userLoginGetter()));

    string password;
    cout << "Type in password: ";
    cin>>password;
    user.userPasswordSetter(password);

    string firstName;
    cout<<"Enter Your first name: ";
    cin>>firstName;
    user.userFirstNameSetter(firstName);

    string lastName;
    cout<<"Enter Your last name: ";
    cin>>lastName;
    user.userLastNameSetter(lastName);

    return user;
}

int UserMenager::getNewUserId() {

    if (users.empty())
        return 1;
    else
        return users.back().userIdGetter() + 1;
}

bool  UserMenager::isLoginExist(string login) {

    for (int i=0; i<users.size(); i++) {

        if (users[i].userLoginGetter()==login) {
            cout << endl << "User "<<login<<" already exist"<< endl;
            return true;
        }

    }
    return false;
}

int UserMenager::userLogging() {

    string login = "", password = "";

    cout << "Type in login: ";
    login = SupportMethods::loadTextLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> User::userLoginGetter() == login) {
            for (int attemptAmount = 3; attemptAmount > 0; attemptAmount--) {
                cout << "Enter password. Attepmt remain: " << attemptAmount << ": ";
                password = SupportMethods::loadTextLine();

                if (itr -> User::userPasswordGetter() == password) {
                    cout << endl << "You signed in." << endl << endl;
                    system("pause");
                    loggedUserId=itr -> User::userIdGetter();
                    loggedUserFirstNameSetter(itr->User::userFirstNameGetter());
                    loggedUserLastNameSetter(itr->User::userLastNameGetter());
                    return loggedUserId;

                }
            }
            cout << "Wrong passwor was entered 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }

    cout << "There is no such user" << endl << endl;
    system("pause");
    return 0;
}

void UserMenager::changeLoggedUserPassword() {

    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = SupportMethods::loadTextLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> User::userIdGetter() == loggedUserId) {
            itr -> User::userPasswordSetter(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    userFile.changePasswordInFile(loggedUserId, newPassword);
}


int UserMenager::getIdLoggedUser() {

    return loggedUserId;

}

void UserMenager::logOutUser () {

    loggedUserId=0;

}

bool UserMenager::isUserSingedIn() {

    if (loggedUserId>0)
        return true;
    else
        return false;

}

void UserMenager::loadUsersFromTheFile() {

    userFile.loadUsersFromFile(users);

}

int UserMenager::loggedUserIdGetter() {

    return loggedUserId;
}

void UserMenager::loggedUserFirstNameSetter(string firstNameToSet) {
    loggedUserFirstName=firstNameToSet;
}
void UserMenager::loggedUserLastNameSetter(string lastNameToSet) {
    loggedUserLastName=lastNameToSet;
}

string UserMenager::loggedUserFirstNameGetter() {
    return loggedUserFirstName;
}

string UserMenager::loggedUserLastNameGetter() {
    return loggedUserLastName;
}
