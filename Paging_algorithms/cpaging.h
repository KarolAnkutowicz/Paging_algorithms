/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cpaging.h
 */

#ifndef CPAGING_H
#define CPAGING_H

#include "cdata.h"
#include "constantsandtypes.h"

using namespace std;

class cPaging
{
/********** PRIVATE: BEGINNING **********/

    /*
     * cData D - zestaw danych wykorzystywanych w algorytmach
     * stronicowania.
     */
    cData D;

    /*
     * tableFrame[constFrame] - tablica ramek.
     */
    typePaging tableFrame[constFrame];

    /*
     * tableNumberOfLack[constSeries] - tablica brakow
     * ramek.
     */
    typePaging tableNumberOfLack[constSeries];

    /*
     * vAverageNumberOfLack - srednia wartosc brakow ramek.
     */
    double vAverageNumberOfLack;



    /*
     * tableTypingOrder[constFrame] - tablica ramek
     * wytypowanych do zastapienia.
     */
    typePaging tableTypingOrder[constFrame];



    /*
     * tableTimeSchronology[constFrame] - tablica
     * kolejnosci chronologicznej stron w ramkach.
     */
    typePaging tableTimeSchronology[constFrame];



    /*
     * tablePage[constPage] - tablica uzycia poszczegolnych
     * stron.
     */
    typePaging tablePage[constPage];

/********** PRIVATE: END **********/

/********** PUBLIC: BEGINNING **********/
public:
    cPaging();

/********** PUBLIC: END **********/
};

#endif // CPAGING_H

/* cpaging.h */
/********** END_OF_FILE **********/
