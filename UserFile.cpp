#include "UserFile.h"

using namespace std;

void UserFile::addUserToTheFile (User actualUser) {

    CMarkup xml;

    xml.Load(USER_FILE_NAME);

    if (!xml.IsWellFormed()) {

        xml.AddElem("USERS");
        xml.Save(USER_FILE_NAME);

    }

    xml.FindElem("USERS");
    xml.IntoElem();
    xml.AddElem("USER");
    xml.IntoElem();
    xml.AddElem("USER_ID", actualUser.userIdGetter());
    xml.AddElem("FIRST_NAME", actualUser.userFirstNameGetter());
    xml.AddElem("LAST_NAME", actualUser.userLastNameGetter());
    xml.AddElem("USER_LOGIN", actualUser.userLoginGetter());
    xml.AddElem("USER_PASSWORD", actualUser.userPasswordGetter());

    xml.Save(USER_FILE_NAME);

}

vector <User> UserFile::loadUsersFromFile (vector <User> &users) {

    CMarkup xml;
    xml.Load(USER_FILE_NAME);

    while (xml.FindChildElem("USER")) {

        User actualUser;
    xml.IntoElem();
        xml.FindChildElem("USER_ID");
        actualUser.userIdSetter(SupportMethods::conversionStringToInt(xml.GetChildData()));

        xml.FindChildElem("FIRST_NAME");
        actualUser.userFirstNameSetter(xml.GetChildData());

        xml.FindChildElem("LAST_NAME");
        actualUser.userLastNameSetter(xml.GetChildData());

        xml.FindChildElem("USER_LOGIN");
        actualUser.userLoginSetter(xml.GetChildData());

        xml.FindChildElem("USER_PASSWORD");
        actualUser.userPasswordSetter(xml.GetChildData());

        users.push_back(actualUser);
        xml.OutOfElem();
    }

    return users;
}

void  UserFile::changePasswordInFile(int userID, string newPassword) {

    CMarkup xml;
    xml.Load(USER_FILE_NAME);

    while (true) {
        xml.FindChildElem("USER");
        xml.IntoElem();
        xml.FindChildElem("USER_ID");
        if (SupportMethods::conversionStringToInt(xml.GetChildData())==userID) {
            xml.FindChildElem("USER_PASSWORD");
            xml.RemoveChildElem();
            xml.ResetChildPos();
            xml.FindChildElem("USER_LOGIN");
            xml.AddChildElem("USER_PASSWORD", newPassword);
            xml.Save(USER_FILE_NAME);

            break;

        }
        xml.OutOfElem();
    }

}
