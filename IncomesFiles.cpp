#include "IncomesFiles.h"

void IncomesFiles::addIncomesToTheFile (Incomes actualRecord) {

    CMarkup xml;

    xml.Load(USER_FILE_NAME);

    if (!xml.IsWellFormed()) {

        xml.AddElem("INCOMES");
        xml.Save(USER_FILE_NAME);

    }

    xml.FindElem("INCOMES");
    xml.IntoElem();
    xml.AddElem("INCOME");
    xml.IntoElem();
    xml.AddElem("INCOME_ID", actualRecord.incomeIDgetter());
    xml.AddElem("USER_ID", actualRecord.userIdGetter());
    //xml.AddElem("INCOME_ID", actualRecord.incomeIDgetter());
    xml.AddElem("INCOME_AMOUT", SupportMethods::conversionFloatToString(actualRecord.incomeAmoutGetter()));
    xml.AddElem("DATE", addDateToFileWithSeparationSign(actualRecord.fullDateGetter()));
    xml.AddElem("DESCRIPTION", actualRecord.descriptionGetter());

    xml.Save(USER_FILE_NAME);

}

string IncomesFiles::addDateToFileWithSeparationSign (int dateWithoutSeparationSigns) {

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

vector<Incomes> IncomesFiles::loadLoggedUserIncomes(vector<Incomes> incomes, int loggedUserId) {


    CMarkup xml;
    //cout<<xml.IsWellFormed()<<endl;
    //getchar();
    xml.Load(USER_FILE_NAME);

    while (xml.FindElem("INCOME")) {

            Incomes actualRecord;



        xml.FindChildElem("INCOME_ID");
            actualRecord.incomeIDsetter(SupportMethods::conversionStringToInt(xml.GetChildData()));
            lasIncomeIDSetter(SupportMethods::conversionStringToInt(xml.GetChildData()));

            xml.FindChildElem("USER_ID");
        if (SupportMethods::conversionStringToInt(xml.GetChildData())==loggedUserId) {

            //Incomes actualRecord;

            //actualRecord.userIdSetter(SupportMethods::conversionStringToInt(xml.GetChildData()));

            //xml.FindChildElem("INCOME_ID");
            //actualRecord.incomeIDsetter(SupportMethods::conversionStringToInt(xml.GetChildData()));
            //lasIncomeIDSetter(SupportMethods::conversionStringToInt(xml.GetChildData()));

                    //xml.FindChildElem("USER_ID");
        actualRecord.userIdSetter(SupportMethods::conversionStringToInt(xml.GetChildData()));



            xml.FindChildElem("INCOME_AMOUT");
            actualRecord.incomeAmoutSetter(SupportMethods::conversionStringToFloat(xml.GetChildData()));

            xml.FindChildElem("DATE");

//            DateManager gateFullDate;
//                DatesAndFinances dateToSave;
//                dateToSave=gateFullDate.obtainYearMonthAndDayFromFullDate(xml.GetChildData());
//
//                actualRecord.fullDateSetter(dateToSave.fullDateGetter());


            actualRecord.fullDateSetter(SupportMethods::conversionStringToInt(xml.GetChildData()));

            cout<<actualRecord.fullDateGetter()<<endl;
                getchar();

            xml.FindChildElem("DESCRIPTION");
            actualRecord.descriptionSetter(xml.GetChildData());

            incomes.push_back(actualRecord);
        }

    }

    return incomes;
}

void IncomesFiles::lasIncomeIDSetter(int incomeIDtoSet) {

    lastIncomeID=incomeIDtoSet;
}

int IncomesFiles::lastIncomeIDgetter() {

    return lastIncomeID;
}

bool IncomesFiles::isIncomeFileEmpty () {

    CMarkup xml;
    xml.Load(USER_FILE_NAME);

    if (xml.FindElem("INCOME"))
        return true;

        else
            return false;

}
