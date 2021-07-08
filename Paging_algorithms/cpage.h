/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cpage.h
 */

#ifndef CPAGE_H
#define CPAGE_H

#include "constantsandtypes.h"
#include <iostream>

using namespace std;

/*
 * cPage - klasa modelujaca pojedyncza strone
 */
class cPage
{
    /*
     * typePaging vNumberPage - numer strony.
     */
    typePaging vNumberPage;

    /*
     * bool vUsingNow - zmienna okreslajaca czy strona
     * jest aktualnie w jakiejkolwiek ramce tzn. czy jest
     * lub za chwile moze byc w uzyciu.
     */
    bool vInFrame;

    /*
     * typePaging vNumberUsingFrame - numer ramki w jakiej jest
     * lub ostatnio byla strona.
     */
    typePaging vNumberUsingFrame;

    /*
     * typePaging vNumberOfLacks - calkowity numer brakow
     * strony
     */
    typePaging vNumberOfLacks;

public:
    cPage();

    cPage(typePaging aNumberpage);

    friend ostream & operator << (ostream & StreamOut, cPage & P);

    friend istream & operator >> (istream & StreamIn, cPage & P);


};

#endif // CPAGE_H

/* cpage.h */
/********** END_OF_FILE **********/
