/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cpagingalgorithms.h
 */

#ifndef CPAGINGALGORITHMS_H
#define CPAGINGALGORITHMS_H

#include "constantsandtypes.h"
#include "cpage.h"

using namespace std;

/*
 * cPagingAlgorithms - klasa modelujaca realizacje
 * algorytmow stronicowania.
 */
class cPagingAlgorithms
{
/********** PRIVATE: BEGINNING **********/

    /*
     * cPage tabPages[constPage] - tablica dostepnych procesow.
     */
    cPage tabPages[constPage];

    /*
     * cPage tabReferences[constSeries][constReference] -
     * tablica kolejnych wywolan stron.
     */
    cPage tabReferences[constSeries][constReference];

    /*
     * cPage tabFrames[constFrame] - tablica dostepnych ramek.
     */
    cPage tabFrames[constFrame];

/********** PRIVATE: END **********/

/********** PUBLIC: BEGINNING **********/
public:
    /*
     * cPagingAlgorithms() - konstruktor wywolywane bez argumentow.
     * PRE:
     * - brak;
     * POST:
     * - utworzenie obiektu klasy cPagingAlgorithms.
     */
    cPagingAlgorithms();

    /*
     * cPagingAlgorithms(enumAlgorithms aAlgorithm) - konstruktor
     * wywolywany z jednym argumentem.
     * PRE:
     * - podanie wykorzystywanego algorytmu;
     * POST:
     * - utworzenie obiektu klasy cPagingAlgorithms.
     */
    cPagingAlgorithms(enumAlgorithms aAlgorithm);

    /*
     *  void mMakeFIFO() - metoda realizujaca algorytm FIFO.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeFIFO();

    /*
     * void mMakeLRU() - metoda realizujaca algorytm LRU.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeLRU();

    /*
     * void mMakeLFU() - metoda realizujaca algorytm LFU.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeLFU();

    /*
     * void mMakeMFU() - metoda realizujaca algorytm MFU.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeMFU();

/********** PUBLIC: END **********/
};

#endif // CPAGINGALGORITHMS_H

/* cpagingalgorithms.h */
/********** END_OF_FILE **********/
