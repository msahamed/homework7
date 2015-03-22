/* 
*   Sabber Ahamed
*   Homework - 7
*   Programming tools for Eanginners and scientists
*   Spring 2015
*   Github link : https://github.com/msahamed/homework7
*/


//Libraries
#include <string>
#include "station.h"


string station::uppercase (string s) {

    string result = s;
    for (int i=0; i < (int)result.size(); i++)
        result[i] = toupper(result[i]);
    return result;

}

networkCode station::str2Ncode(string NCode) {

    if (NCode == uppercase("CI")) return CI;   
    else if (NCode == uppercase("CE")) return CE;
    else if (NCode == uppercase("FA")) return FA;
    else if (NCode == uppercase("NP")) return NP;
    else if (NCode == uppercase("WR")) return WR;

}


bool station::IsNCode(string NCode) {

    networkCode NCode1 = str2Ncode(NCode);

    switch (NCode1) {
        case CI :
            { return true; break;}
        case CE :
            { return true; break;}
        case FA :
            { return true; break;}
        case NP : 
            { return true; break;}
        case WR :
            { return true; break;}
        default :
             return false;
    }

}


// Check the station name
bool station::IsStation(string stationName) {
     
    bool rightStation = false;
    if (stationName.length() == 3 || stationName.length() == 5) {
         
        if (stationName.length() == 3) {
            for (int i =0; i< 3; i++){
                if (isalpha(stationName[i]) && isupper(stationName[i])) rightStation = true;
                else return false;
            }
        }
        else if (stationName.length() == 5) {
            for (int i =0; i< 5; i++){
                if (isdigit(stationName[i])) rightStation = true;
                else return false;
            }
        }
    }
    else return false;
    return rightStation;
}

bandType station::str2bandName(string bandName) {

    if (bandName == uppercase("Long-Period")) return LongPeriod;   
    else if (bandName == uppercase("Short-Period")) return ShortPeriod;
    else if (bandName == uppercase("Broadband")) return Broadband;
}

// Check bancd name 
bool station::IsBand(string bandName, string& bandInitial) {
    bool band = false;
    bandType bandName1 = str2bandName(uppercase(bandName));

    switch (bandName1) {
        case LongPeriod : { band = true ; bandInitial = "L"; return true; }
        case ShortPeriod : { band = true ; bandInitial = "B"; return true; }
        case Broadband : { band = true ; bandInitial = "H"; return true; }
    }
    return band;
}


InstrumentType station::str2InstrumentType (string instrumentName) {

    if (instrumentName == uppercase("High-Gain")) return HighGain;   
    else if (instrumentName == uppercase("Low-Gain")) return LowGain;
    else if (instrumentName == uppercase("Accelerometer")) return Accelerometer;

}

// Check instrument type and name 
bool station::IsInstrument(string instrumentName, string& instInitial) {

    bool isint = false;
    InstrumentType instrumentName1 = str2InstrumentType(uppercase(instrumentName));
    
    switch (instrumentName1) {
        case HighGain : { isint = true ; instInitial= "H"; return true; }
        case LowGain : { isint = true ; instInitial= "L"; return true; }
        case Accelerometer : { isint = true ; instInitial= "N"; return true; }
    }
    return isint;
}


// Check the orientation of signal
bool station::IsOrientation(string orName) {
    
    bool isAlphabatic = false;
    bool isNumeric = false;
    string orientation = "ENZ123";
     
    for (int unsigned i = 0 ; i < orName.length(); i++){
        if (orName[i] == orientation[0]) isAlphabatic = true;
        else if (orName[i] == orientation[1]) isAlphabatic = true;
        else if (orName[i] == orientation[2]) isAlphabatic = true;
        else if (orName[i] == orientation[3]) isNumeric = true;
        else if (orName[i] == orientation[4]) isNumeric = true;
        else if (orName[i] == orientation[5]) isNumeric = true;
        else return false;
    }

    if ((isAlphabatic) && (isNumeric)) return false;
    else return true;
}