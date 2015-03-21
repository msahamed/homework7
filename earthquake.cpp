/* 
*   Sabber Ahamed
*   Homework - 7
*   Programming tools for Eanginners and scientists
*   Spring 2015
*   Github link : https://github.com/msahamed/homework7
*/


//Libraries
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> 
#include <fstream>
#include <iomanip>
#include <ctype.h>

#include "earthquake.h"


string earthquke::uppercase (string s) {

    string result = s;
    for (int i=0; i < (int)result.size(); i++)
        result[i] = toupper(result[i]);
    return result;

}

networkCode earthquke::str2Ncode(string NCode) {

    if (NCode == uppercase("CI")) return CI;   
    else if (NCode == uppercase("CE")) return CE;
    else if (NCode == uppercase("FA")) return FA;
    else if (NCode == uppercase("NP")) return NP;
    else if (NCode == uppercase("WR")) return WR;

}


bool earthquke::IsNCode(string NCode) {

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
bool earthquke::IsStation(string stationName) {
     
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

bandType earthquke::str2bandName(string bandName) {

    if (bandName == uppercase("Long-Period")) return LongPeriod;   
    else if (bandName == uppercase("Short-Period")) return ShortPeriod;
    else if (bandName == uppercase("Broadband")) return Broadband;
}

// Check bancd name 
bool earthquke::IsBand(string bandName, string& bandInitial) {
    bool band = false;
    bandType bandName1 = str2bandName(uppercase(bandName));

    switch (bandName1) {
        case LongPeriod : { band = true ; bandInitial = "L"; return true; }
        case ShortPeriod : { band = true ; bandInitial = "B"; return true; }
        case Broadband : { band = true ; bandInitial = "H"; return true; }
    }
    return band;
}


InstrumentType earthquke::str2InstrumentType (string instrumentName) {

    if (instrumentName == uppercase("High-Gain")) return HighGain;   
    else if (instrumentName == uppercase("Low-Gain")) return LowGain;
    else if (instrumentName == uppercase("Accelerometer")) return Accelerometer;

}

// Check instrument type and name 
bool earthquke::IsInstrument(string instrumentName, string& instInitial) {

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
bool earthquke::IsOrientation(string orName) {
    
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