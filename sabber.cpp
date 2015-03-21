
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

using namespace std;

enum months { January = 1, February, March, April, May, June , July, 
            August, September, October, November, December };

enum magnitudeType { ML, Ms, Mb, Mw };


struct header {

    string EQID;
    string date;
    string day;
    string year;
    string time;
    string timeZone;
    string earthquakeName;
    string lat;
    string lon;
    string magType;
    string magnitude;
    string Enumber;

};

struct signalInfo {

    string NCode;
    string stationName;
    string bandName;
    string instrumentName;
    string orName;
    string bandInitial;
    string instInitial;

};


string uppercase (string s) {

    string result = s;
    for (int i=0; i < (int)result.size(); i++)
        result[i] = toupper(result[i]);
    return result;

}


bool IsDate(string date1, string& day1, string& monthNmae, string& year1) {

    for (int i = 0 ; i< 4; i++) year1 += date1[i+6];

    if (!isdigit(date1[3]) && !isdigit(date1[4]))  return false;
    
    for (int i = 0 ; i< 2; i++) day1 += date1[i+3];

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
bool IsTime (string time, string timeZone) {
    
    if (timeZone.length() != 3) return false;
    
    string hh, mm, ss;
    for (int i = 0; i< 2; i++) {
        hh += time[i];
        mm += time[i+3];
        ss += time[i+6];
    }

    if (isdigit(hh[0]) == 0 || isdigit(hh[1]) == 0 ) return false;
    if (isdigit(mm[0]) == 0 || isdigit(mm[1]) == 0 ) return false;
    if (isdigit(ss[0]) == 0 || isdigit(ss[1]) == 0 ) return false;

    return true;

}

magnitudeType strToMagnitude(string magType) {

    if (magType == "ML") return ML;   
    else if (magType == "MS") return Ms;
    else if (magType == "MB") return Mb;
    else if (magType == "MW") return Mw;

}

// Check magnitude type AND magnitude value
bool IsMagnitude(string& magType, string magnitude) {

   int number;
   bool mag;
   istringstream(magnitude) >> number;
   if (number < 0) return false;

    magnitudeType mag1;
    mag1 = strToMagnitude(uppercase(magType));

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



// Open Input File and check
void open_input(ifstream& inputFile, string inputFileName) {

   inputFile.open(inputFileName.c_str());

    if (inputFile.fail()) {
        cout << "Error reading the file  " << inputFileName << endl;
        exit(EXIT_FAILURE);
    }
}


// Print the header information
void printHeader (int EntryNumber, string EQID, string day, string monthNmae, string year,
                  string time1,string timeZone, string earthquakeName, string lat, string lon, 
                  string magType, string magnitude, string Enumber) {

    ofstream outputFile;
    string outputFileName = "sabber.out" ;
    if (EntryNumber == 0)
       outputFile.open(outputFileName.c_str()); 
    else
       outputFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);

       outputFile << "# " << day << " " << monthNmae << " " << year << "  "<< time1 << " " 
                  << timeZone << " " << magType << "  " << magnitude << " " << earthquakeName 
                  << " [" <<EQID << "] " << " (" << lat <<" , " <<lon << " " << Enumber << ")" << endl;
}

// Print to File 
void printToFile(string array[300], int totalSignal) {
    
    ofstream outputFile;
    string outputFileName = "sabber.out" ;
    
    outputFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);

    outputFile << totalSignal;
    outputFile << endl;

    for (int unsigned i = 0 ; i < 300; i++) { 
        if (array[i].length() > 1) outputFile << array[i] << endl;;

    }
}

// Print error to log file 
void printError(int EntryNUmber, int validEntries, int invalidEntries, int totalSignal, 
                bool a, bool b, bool c, bool d, bool e, bool h1, bool h2, bool h3) {

    ofstream outputErrorFile;
    string outputFileName = "sabber.log" ;
    if (EntryNUmber > 0)
       outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
    else
       outputErrorFile.open(outputFileName.c_str()); 

    
    if (h1 == false) {
        outputErrorFile << "Error # Date format wrong !" << endl;
        cout << "Error # Date format wrong !" << endl;
    }
    else if (h2 == false){
        outputErrorFile << "Error # Either Magnitude_type or Magnitude is wrong !" << endl;
        cout << "Error # Either Magnitude_type or Magnitude is wrong !" << endl;
    }
    else if (h3 == false) {
        outputErrorFile << "Error # Either time format or time zone is wrong !" << endl;
        cout << "Error # Either time format or time zone is wrong !" << endl;
    }
    else if (a == false) {
        outputErrorFile << "Entry # " << EntryNUmber << " Invalid Network" << endl;
        cout << "Entry # " << EntryNUmber << " Invalid Network" << endl;
    }
    else if (b == false) {
        outputErrorFile << "Entry # " << EntryNUmber << " Invalid Station" << endl;
        cout << "Entry # " << EntryNUmber << " Invalid Station" << endl;
    }
    else if (c == false) {
        outputErrorFile << "Entry # " << EntryNUmber << " Invalid Band type" << endl;
        cout << "Entry # " << EntryNUmber << " Invalid Band type" << endl;
    }
    else if (d == false) {
        outputErrorFile << "Entry # " << EntryNUmber << " Invalid Instrument" << endl;
        cout << "Entry # " << EntryNUmber << " Invalid Instrument" << endl;
    }
    else if (e == false) {
        outputErrorFile << "Entry # " << EntryNUmber << " Invalid Orientation" << endl;
        cout << "Entry # " << EntryNUmber << " Invalid Orientation" << endl;
    }

}

// Main function 
int main() {

    ofstream outputErrorFile;
    string outputFileName = "sabber.log" ;
    outputErrorFile.open(outputFileName.c_str());
    cout << "starts reading ...." <<endl;
    outputErrorFile << "starts reading ...." <<endl;
    outputErrorFile.close();
    earthquke eq;
    string array[300];
    for (int i =0; i< 300; i++) array[i] = "E" ;

    //================== starts reading ====================
    int EntryNumber = 0;
    string line;
    string inputFileName;
    
    outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
    outputErrorFile << "Please provide the Input File Name : "<< endl;
    outputErrorFile.close();
    cout << "Please provide the Input File Name : "<< endl;

    cin >> inputFileName ;
    ifstream inputFile;
    open_input(inputFile, inputFileName);
    
    header head;
    getline(inputFile, line);
    stringstream headInfo1 (line);
    headInfo1 >> head.EQID;
    
    getline(inputFile, line);
    stringstream headInfo2 (line);
    headInfo2 >> head.date;
    headInfo2 >> head.time;
    headInfo2 >> head.timeZone;

    getline(inputFile, line);
    head.earthquakeName = line;

    getline(inputFile, line);
    stringstream headInfo4 (line);
    headInfo4 >> head.lat;
    headInfo4 >> head.lon;
    headInfo4 >> head.Enumber;
    headInfo4 >> head.magType;
    headInfo4 >> head.magnitude;

    string monthNmae;
    string day, year;
    int validEntries = 0;
    int invalidEntries = 0;
    int totalSignal = 0;
    bool a, b, c, d, e, h1, h2, h3; 

    // checking header information
    if (IsDate(head.date, head.day, monthNmae, head.year)) h1 = true;
    else h1 = false;

    if (IsMagnitude(head.magType, head.magnitude)) h2 = true;
    else h2 = false;

    if (IsTime (head.time, head.timeZone)) h3 = true;
    else h3 = false;

    if (h1 && h2 && h3) {

        outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
        outputErrorFile << "header read correctly "<< endl;
        outputErrorFile.close();

        printHeader (EntryNumber, head.EQID, head.day, monthNmae, head.year, head.time,
                    head.timeZone, head.earthquakeName, head.lat, head.lon, 
                    head.magType, head.magnitude, head.Enumber);
    }
    else {

        outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
        outputErrorFile << "header infromation in not correct "<< endl;
        outputErrorFile.close();

        printError(EntryNumber, validEntries, invalidEntries, totalSignal, a, b, c, d, e, h1, h2, h3);

        exit(EXIT_FAILURE);
        
    }

    // if header information is correct following code will be executed
    signalInfo signal;
    EntryNumber = 1;
    while (getline(inputFile, line) && !line.empty()) {

        //getline(inputFile, line);
        istringstream number (line);
        number >> signal.NCode;
        number >> signal.stationName;
        number >> signal.bandName;
        number >> signal.instrumentName;
        number >> signal.orName;

        if (eq.IsNCode(signal.NCode)) {
            signal.NCode = uppercase(signal.NCode);
            a = true;
        }
        else a = false;


        if (eq.IsStation(signal.stationName)) {
            signal.stationName = uppercase(signal.stationName);
            b = true;
        }
        else b = false;

        if (eq.IsBand(signal.bandName, signal.bandInitial)) {
            signal.bandName = signal.bandInitial;
            c = true;
        }
        else c = false;

        if (eq.IsInstrument(signal.instrumentName , signal.instInitial)) {
            signal.instrumentName = signal.instInitial;
            d = true;
        }
        else d = false;

        if (eq.IsOrientation(signal.orName)) {
            signal.orName = uppercase(signal.orName);
            e = true;
        }
        else e = false;
        
        if ((a) && (b) && (c) && (d) && (e)) {
           
            string or_1 = signal.orName; 
            for (int i = 0 ; i < or_1.length(); i++) {

                array[totalSignal] = head.EQID + "." + signal.NCode + "." + signal.stationName + "." 
                                     + uppercase(signal.bandName) + uppercase(signal.instrumentName) + or_1[i] ;
                totalSignal += 1;

            }
           
           validEntries ++;
        }
        else {
            printError(EntryNumber, validEntries, invalidEntries, totalSignal, 
            a, b, c, d, e, h1, h2, h3);
            invalidEntries ++;
        }


        EntryNumber++;

    }
    
    printToFile(array, totalSignal);

    outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
    outputErrorFile << "validEntries = "   << validEntries   << endl;
    outputErrorFile << "invalidEntries = " << invalidEntries << endl;
    outputErrorFile << "totalSignal = "    << totalSignal    << endl;
    outputErrorFile << "Finished " << endl;
    outputErrorFile.close();

    cout << "validEntries = "   << validEntries   << endl;
    cout << "invalidEntries = " << invalidEntries << endl;
    cout << "totalSignal = "    << totalSignal    << endl;
    cout << "Finished" << endl;

}

