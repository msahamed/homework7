
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

#include "station.h"
#include "earthquake.h"

using namespace std;


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
    station stn;
    earthquake eq;
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
    
    //header head;
    getline(inputFile, line);
    stringstream headInfo1 (line);
    headInfo1 >> eq.EQID;
    
    getline(inputFile, line);
    stringstream headInfo2 (line);
    headInfo2 >> eq.date;
    headInfo2 >> eq.time;
    headInfo2 >> eq.timeZone;

    getline(inputFile, line);
    eq.earthquakeName = line;

    getline(inputFile, line);
    stringstream headInfo4 (line);
    headInfo4 >> eq.lat;
    headInfo4 >> eq.lon;
    headInfo4 >> eq.Enumber;
    headInfo4 >> eq.magType;
    headInfo4 >> eq.magnitude;

    string monthNmae;
    string day, year;
    int validEntries = 0;
    int invalidEntries = 0;
    int totalSignal = 0;
    bool a, b, c, d, e, h1, h2, h3; 

    // checking header information
    if (eq.IsDate(eq.date, eq.day, monthNmae, eq.year)) h1 = true;
    else h1 = false;

    if (eq.IsMagnitude(eq.magType, eq.magnitude)) h2 = true;
    else h2 = false;

    if (eq.IsTime (eq.time, eq.timeZone)) h3 = true;
    else h3 = false;

    if (h1 && h2 && h3) {

        outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
        outputErrorFile << "header read correctly "<< endl;
        outputErrorFile.close();

        printHeader (EntryNumber, eq.EQID, eq.day, monthNmae, eq.year, eq.time,
                    eq.timeZone, eq.earthquakeName, eq.lat, eq.lon, 
                    eq.magType, eq.magnitude, eq.Enumber);
    }
    else {

        outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
        outputErrorFile << "header infromation in not correct "<< endl;
        outputErrorFile.close();

        printError(EntryNumber, validEntries, invalidEntries, totalSignal, a, b, c, d, e, h1, h2, h3);

        exit(EXIT_FAILURE);
        
    }

    // if header information is correct following code will be executed
    EntryNumber = 1;
    while (getline(inputFile, line) && !line.empty()) {

        //getline(inputFile, line);
        istringstream number (line);
        number >> stn.NCode;
        number >> stn.stationName;
        number >> stn.bandName;
        number >> stn.instrumentName;
        number >> stn.orName;

        if (stn.IsNCode(stn.NCode)) {
            stn.NCode = stn.uppercase(stn.NCode);
            a = true;
        }
        else a = false;


        if (stn.IsStation(stn.stationName)) {
            stn.stationName = stn.uppercase(stn.stationName);
            b = true;
        }
        else b = false;

        if (stn.IsBand(stn.bandName, stn.bandInitial)) {
            stn.bandName = stn.bandInitial;
            c = true;
        }
        else c = false;

        if (stn.IsInstrument(stn.instrumentName , stn.instInitial)) {
            stn.instrumentName = stn.instInitial;
            d = true;
        }
        else d = false;

        if (stn.IsOrientation(stn.orName)) {
            stn.orName = stn.uppercase(stn.orName);
            e = true;
        }
        else e = false;
        
        if ((a) && (b) && (c) && (d) && (e)) {
           
            string or_1 = stn.orName; 
            for (int i = 0 ; i < or_1.length(); i++) {

                array[totalSignal] = eq.EQID + "." + stn.NCode + "." + stn.stationName + "." 
                                     + stn.uppercase(stn.bandName) + stn.uppercase(stn.instrumentName) + or_1[i] ;
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

