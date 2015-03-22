/* 
*   Sabber Ahamed
*   Homework - 7
*   Programming tools for Eanginners and scientists
*   Spring 2015
*   Github link : https://github.com/msahamed/homework7
*/


//Libraries
#include <string>
#include <sstream>
#include "earthquake.h"
#include "station.h"



bool earthquake::IsDate(string date1, string& day1, string& monthNmae, string& year1) {

    for (int i = 0 ; i< 4; i++) year1 += date1[i+6];

    if (!isdigit(date1[3]) && !isdigit(date1[4]))  return false;
    
    for (int i = 0 ; i< 2; i++) day1 += date1[i+3];

    int dd ; std::istringstream(day1) >> dd;
    if (dd<1 || dd >31) return false;

    string mm ;
    for (int i = 0; i< 2; i++) mm += date1[i];
    int number;
    std::istringstream(mm) >> number;

    if      ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)1))  monthNmae = "January";
    else if ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)2))  monthNmae = "February";
    else if ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)3))  monthNmae = "March";
    else if ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)4))  monthNmae = "April";
    else if ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)5))  monthNmae = "May";
    else if ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)6))  monthNmae = "June";
    else if ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)7))  monthNmae = "July";
    else if ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)8))  monthNmae = "August";
    else if ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)9))  monthNmae = "September";
    else if ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)10)) monthNmae = "October";
    else if ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)11)) monthNmae = "November";
    else if ((isdigit(date1[0]) &&  (isdigit(date1[1])) && number == (months)12)) monthNmae = "December";
    else return false;

    return true;

}


// Check if the time is not formated and timeZone is wrong. 
bool earthquake::IsTime (string time, string timeZone) {
    
    if (timeZone.length() != 3) return false;
    
    int hh, mm, ss;
    string a, b ,c;

    for (int i = 0; i< 2; i++) {
        a += time[i];
        b += time[i+3];
        c += time[i+6];
    }

    if (isdigit(a[0]) == 0 || isdigit(a[1]) == 0 ) return false;
    if (isdigit(b[0]) == 0 || isdigit(b[1]) == 0 ) return false;
    if (isdigit(c[0]) == 0 || isdigit(c[1]) == 0 ) return false;

    std::istringstream(a) >> hh;
    if (hh < 0 || hh > 24) return false;

    std::istringstream(b) >> mm;
    if (mm < 0 || mm > 59) return false;

    std::istringstream(c) >> ss;
    if (ss < 0 || ss > 59.999) return false;

    return true;

}

magnitudeType earthquake::strToMagnitude(string magType) {

    if (magType == "ML") return ML;   
    else if (magType == "MS") return Ms;
    else if (magType == "MB") return Mb;
    else if (magType == "MW") return Mw;

}

// Check magnitude type AND magnitude value
bool earthquake::IsMagnitude(string& magType, string magnitude) {

   int number;
   bool mag;
   istringstream(magnitude) >> number;
   if (number < 0) return false;

    magnitudeType mag1;
    station stn;
    mag1 = strToMagnitude(stn.uppercase(magType));

    switch (mag1) {
        case ML :
            { mag = true; magType = "ML" ; break;}
        case Ms :
            { mag = true; magType = "Ms" ;  break;}
        case Mb :
            { mag = true; magType = "Mb" ;  break;}
        case Mw : 
            { mag = true; magType = "Mw" ; break;}
        default :
            return false;
    }

    return mag;

}

