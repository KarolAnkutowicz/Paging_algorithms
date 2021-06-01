/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cdata.h
 */

#ifndef CDATA_H
#define CDATA_H

#include "constantsandtypes.h"

using namespace std;

class cData
{
/********** PRIVATE: BEGINNING **********/

    /*
     * typePaging tableReference[constSeries][constReference] -
     * tablica referencji przekazywana do stronicowania
     */
    typePaging tableReference[constSeries][constReference];

/********** PRIVATE: END **********/

/********** PUBLIC: BEGINNING **********/
public:
    /*
     * cData() - konstruktor wywolywany bez parametrow
     * PRE:
     * - brak;
     * POST:
     * - utworzenie obiektu klasy cData.
     */
    cData();



    /*
     * getReference(typePaging parSeries, typePaging parReference) -
     * metoda zwracajaca wskazana referencje.
     * PRE:
     * - podanie numeru serii (typ: typePaging) i numeru referencji
     * (typ: typePaging);
     * POST:
     * - zwrocenie wartosci referencji (typ: typePaging).
     */
    typePaging getReference(typePaging parSeries, typePaging parReference);



    /*
     * mDrawReference() - metoda losujaca referencje.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mDrawReference();

    /*
     * mClearSeries(typePaging parSeries) - metoda czyszczaca zawartosc
     * wskazanej serii referencji.
     * PRE:
     * - podanie numeru serii (typ: typePaging);
     * POST:
     * - brak.
     */
    void mClearSeries(typePaging parSeries);

    /*
     * mClearAllSeries() - metoda czyszczaca zawartosc wszystkich serii
     * referencji.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mClearAllSeries();



    /*
     * mPrintReferenceToFile() - metoda wypisujaca wylosowane referencje
     * do pliku.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mPrintReferenceToFile();

/********** PUBLIC: END **********/
};

#endif // CDATA_H

/* cdata.h */
/********** END_OF_FILE **********/
