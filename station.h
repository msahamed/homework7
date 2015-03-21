/* 
*   Sabber Ahamed
*   Homework - 7
*   Programming tools for Eanginners and scientists
*   Spring 2015
*   Github link : https://github.com/msahamed/homework7
*/


//Libraries
#include <string>

using namespace std;


enum bandType { LongPeriod, ShortPeriod, Broadband };
enum InstrumentType { HighGain, LowGain, Accelerometer };
enum networkCode { CE, CI, FA, NP, WR};

class station {
    
    public :

    	bool IsStation(string stationName);
    	bool IsNCode(string NCode);
    	bool IsBand(string bandName, string& bandInitial);
    	bool IsInstrument(string instrumentName, string& instInitial);
    	bool IsOrientation(string orName);
        string uppercase (string s);

    private :
    	networkCode str2Ncode(string NCode);
    	bandType str2bandName(string bandName);
    	InstrumentType str2InstrumentType (string instrumentName);
    	


};