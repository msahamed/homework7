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


enum magnitudeType { ML, Ms, Mb, Mw };
enum months { January = 1, February, March, April, May, June , July, 
            August, September, October, November, December };

class earthquake {

    public :

        bool IsDate(string date1, string& day1, string& monthNmae, string& year1);
        bool IsTime (string time, string timeZone);
        bool IsMagnitude(string& magType, string magnitude);

    private :

        magnitudeType strToMagnitude(string magType);

        

};