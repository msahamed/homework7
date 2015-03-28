

#include <string>
using namespace std;


class inputoutput {

    public : 
            void open_input(ifstream& inputFile, string inputFileName);
            void printHeader (int EntryNumber, string EQID, string day, string monthNmae, string year,
                              string time1,string timeZone, string earthquakeName, string lat, string lon, 
                              string magType, string magnitude, string Enumber);

            void printToFile(string array[300], int totalSignal);

            void printError(int EntryNUmber, int validEntries, int invalidEntries, int totalSignal, 
                            bool a, bool b, bool c, bool d, bool e, bool h1, bool h2, bool h3);

};
