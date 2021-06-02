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
    /*
     * cPaging() - konstruktor wywolywany bez parametrow
     * PRE:
     * - brak;
     * POST:
     * - utworzenie obiektu klasy cPaging.
     */
    cPaging();

    /*
     * cPaging(typePaging parNumberAlgorithm) - konstruktor
     * wywolywany z jednym parametrem - wskazanym algorytmem.
     * PRE:
     * - podanie algorytmu (typ: typePaging);
     * POST:
     * - utworzenie obiektu klasy cPaging.
     */
    cPaging(typePaging parNumberAlgorithm);



    /*
     * mClearAllFrames() - metoda czyszczaca tablice ramek.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mClearAllFrames();

    /*
     * getFrame(typePaging parIndex) - metoda zwracajaca
     * zawartosc wskazanej ramki (strone).
     * PRE:
     * - podanie indeksu ramki (typ: typePaging);
     * POST:
     * - zwrocenie numeru strony (typ: typePaging).
     */
    typePaging getFrame(typePaging parIndex);

    /*
     * setPage(typePaging parFrame, typePaging parPage) -
     * metoda wstawiajaca okreslona strone do wskazanej ramki.
     * PRE:
     * - podanie numeru ramki (typ: typePaging), podanie
     * numeru strony (typ: typePaging);
     * POST:
     * - brak.
     */
    void setPage(typePaging parFrame, typePaging parPage);






/********** PUBLIC: END **********/
};

#endif // CPAGING_H

/* cpaging.h */
/********** END_OF_FILE **********/
