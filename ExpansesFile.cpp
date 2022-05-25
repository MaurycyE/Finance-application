#include "ExpansesFile.h"

void ExpansesFile::addExpansesToTheFile (Expanses actualRecord) {

    CMarkup xml;
    xml.Load(USER_FILE_NAME);

      if (!xml.IsWellFormed()) {

        xml.AddElem("EXPANSES");
        xml.Save(USER_FILE_NAME);

    }
xml.FindElem("EXPANSES");
    xml.IntoElem();
    xml.AddElem("EXPANSE");
    xml.IntoElem();
    xml.AddElem("EXPANSE_ID", actualRecord.expanseIDgetter());
    xml.AddElem("USER_ID", actualRecord.userIdGetter());
    //xml.AddElem("EXPANSE_ID", actualRecord.expanseIDgetter());
    xml.AddElem("EXPANSE_AMOUT", SupportMethods::conversionFloatToString(actualRecord.expanseAmoutGetter()));
    xml.AddElem("DATE", displayDateWithSeparationSign(actualRecord.fullDateGetter()));
    xml.AddElem("DESCRIPTION", actualRecord.descriptionGetter());

    xml.Save(USER_FILE_NAME);
}

string ExpansesFile::displayDateWithSeparationSign (int dateWithoutSeparationSigns) {

    string dateWithSeparationSign = SupportMethods::conversionIntToString(dateWithoutSeparationSigns);
    string year="";
    string month="";
    string day="";

    for (int i=0; i<8; i++) {
        if(i<4) {
            year+=dateWithSeparationSign[i];
        }
        if ((i>3)&&(i<6)) {
            month+=dateWithSeparationSign[i];
        }
        if(i>5) {
            day+=dateWithSeparationSign[i];
        }

    }
    dateWithSeparationSign=year+'-'+month+'-'+day;
    return dateWithSeparationSign;
}

vector<Expanses> ExpansesFile::loadLoggedUserExpanses(vector<Expanses> expanses, int loggedUserId) {

    CMarkup xml;
    xml.Load(USER_FILE_NAME);

    while (xml.FindChildElem("EXPANSE")) {
            Expanses actualRecord;
            xml.IntoElem();
    //actualRecord.userIdSetter(SupportMethods::conversionStringToInt(xml.GetChildData()));

    xml.FindChildElem("EXPANSE_ID");
            actualRecord.expanseIDsetter(SupportMethods::conversionStringToInt(xml.GetChildData()));
            lastExpansesIDSetter(actualRecord.expanseIDgetter());


        xml.FindChildElem("USER_ID");
        if (SupportMethods::conversionStringToInt(xml.GetChildData())==loggedUserId) {

        //xml.FindChildElem("USER_ID");
         actualRecord.userIdSetter(SupportMethods::conversionStringToInt(xml.GetChildData()));

           // Expanses actualRecord;
            //actualRecord.userIdSetter(SupportMethods::conversionStringToInt(xml.GetChildData()));

            //xml.FindChildElem("EXPANSE_ID");
           // actualRecord.expanseIDsetter(SupportMethods::conversionStringToInt(xml.GetChildData()));
           // lastExpansesIDSetter(SupportMethods::conversionStringToInt(xml.GetChildData()));

            xml.FindChildElem("EXPANSE_AMOUT");
            actualRecord.expanseAmoutSetter(SupportMethods::conversionStringToFloat(xml.GetChildData()));

            xml.FindChildElem("DATE");
            //actualRecord.fullDateSetter(SupportMethods::conversionStringToInt(xml.GetChildData()));
            DateManager gateFullDate;
                DatesAndFinances dateToSave;
                dateToSave=gateFullDate.obtainYearMonthAndDayFromFullDate(xml.GetChildData());
                actualRecord.fullDateSetter(dateToSave.fullDateGetter());


            xml.FindChildElem("DESCRIPTION");
            actualRecord.descriptionSetter(xml.GetChildData());

            expanses.push_back(actualRecord);
        }
        xml.OutOfElem();
    }

    return expanses;
}

void ExpansesFile::lastExpansesIDSetter(int expanseIDtoSet) {

    lastExpansesID=expanseIDtoSet;

}

int ExpansesFile::lastExpansesIDgetter() {

    return lastExpansesID;
}

bool ExpansesFile::isExpanseFileEmpty () {

    CMarkup xml;
    xml.Load(USER_FILE_NAME);

    if (xml.FindElem("EXPANSES")&&(xml.FindChildElem("EXPANSE"))){

    //xml.FindElem("INCOME");
        return true;
    }

        else
            return false;

}
