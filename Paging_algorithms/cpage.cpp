/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cpage.cpp
 */

#include "cpage.h"

using namespace std;

/*
 * cPage()
 */
cPage::cPage()
{
    vNumberPage = 0; // ustanowienie numeru strony
    vInFrame = false; // ustanawiamy, ze strona jeszcze nie jest uzywana
    vNumberOfLacks = 0; // strona jeszcze nie ma brakow
}

/*
 * cPage(typePaging aNumberPage)
 */
cPage::cPage(typePaging aNumberPage)
{
    vNumberPage = aNumberPage; // ustanowienie numeru strony
    vInFrame = false; // ustanawiamy, ze strona jeszcze nie jest uzywana
    vNumberOfLacks = 0; // strona jeszcze nie ma brakow
}



/*
 * ostream & operator << (ostream & StreamOut, cPage & P)
 */
ostream & operator << (ostream & StreamOut, cPage & P)
{
    StreamOut << P.getNumberPage() << " "; // wypisanie numeru strony
    return StreamOut; // zwrocenie strumienia
}

/*
 * istream & operator >> (istream & StreamIn, cPage & P)
 */
istream & operator >> (istream & StreamIn, cPage & P)
{
    typePaging aNumberPage; // utworzenie zmiennej dla ustanowienia numeru stront
    StreamIn >> skipws >> aNumberPage; // wczytanie zmiennej
    P.setNumberPage(aNumberPage); // ustanowienie numeru strony
    P.setInFrame(false); // strona jeszcze nie jest w uzyciu
    P.mResetNumberOfLacks(); // strona jeszcze nie ma brakow
    return StreamIn; // zwrocenie strumienia
}

/* cpage.cpp */
/********** END_OF_FILE **********/
