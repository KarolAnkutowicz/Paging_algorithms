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

    /*
     * double tabAverageNumberOfLack[constSeries] - tablica
     * sum brakow stron w poszczegolnych seriach.
     */
    typePaging tabSumNumberOfLack[constSeries];

    /*
     * typePaging tabTotalNumberOfLacks - calkowita suma
     * brakow stron.
     */
    typePaging tabTotalNumberOfLacks;

    /*
     * double vAverageNumberOfLack - srednia wartosc brakow stron.
     */
    double vAverageNumberOfLack;

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
     * void mMakeFIFO() - metoda realizujaca algorytm FIFO.
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

    /*
     * void mMakePage(typePaging aSeries, typePaging aIndex) -
     * metoda wykonujaca wskazana strone.
     * PRE:
     * - podanie numeru serii (typ: typePaging), podanie
     * numeru referencji (typ: typePaging);
     * POST:
     * - brak.
     */
    void mMakePage(typePaging aSeries, typePaging aIndex);

    /*
     * typePaging mGetTheOldestPage() - metoda znajdujaca
     * i zwracajaca najdawniej uzywana strone.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie numeru strony sposrod stron znajdujacych sie
     * w ramkach (typ: typePaging).
     */
    typePaging mGetTheOldestPage();

    /*
     * typePaging mGetLeastFrequentlyUsed() - metoda znajdujaca
     * i zwracajaca najrzadziej uzywana strone.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie numeru strony sposrod stron znajdujacych sie
     * w ramkach (typ: typePaging).
     */
    typePaging mGetLeastFrequentlyUsed();

    /*
     * typePaging mGetMostFrequentlyUsed() - metoda znajdujaca
     * i zwracajaca naczesciej uzywana strone.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie numeru strony sposrood stron znajdujacych sie
     * w ramkach (typ: typePaging).
     */
    typePaging mGetMostFrequentlyUsed();



    /*
     * void mDrawReferences() - metoda losujaca referencje.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mDrawReferences();

    /*
     * void mResetReference(typePaging aSeries, typePaging aReference) -
     * metodda resetujaca wskazana referencje.
     * PRE:
     * - podanie numeru serii (typ: typePaging), podanie numeru
     * referencji (typ: typePaging);
     * POST:
     * - brak.
     */
    void mResetReference(typePaging aSeries, typePaging aReference);

    /*
     * void mResetSeries(typePaging aSeries) - metoda resetujaca
     * wskazana serie referencji.
     * PRE:
     * - podanie numeru serii (typ: typePaging);
     * POST:
     * - brak.
     */
    void mResetSeries(typePaging aSeries);

    /*
     * void mResetAllReferences() - metoda resetujaca wszystkie
     * referencje.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllReferences();

    /*
     * void mReadReferencesFromFile() - metoda wczytujaca referencje
     * z pliku.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mReadReferencesFromFile();

    /*
     * void mWriteReferencesToFile() - metoda wypisujaca referencje
     * do pliku.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mWriteReferencesToFile();

    /*
     * void mPrintReference(typePaging aSeries, typePaging aReference) -
     * metoda wypisujaca wskazana referencje.
     * PRE:
     * - podanie numeru serii (typ: typePaging), podanie numeru
     * referencji (typ: typePaging);
     * POST:
     * - brak.
     */
    void mPrintReference(typePaging aSeries, typePaging aReference);

    /*
     * void mPrintSeries(typePaging aSeries) - metoda wypisujaca
     * wskazana serie referencji.
     * PRE:
     * - podanie numeru serii (typ: typePaging);
     * POST:
     * - brak.
     */
    void mPrintSeries(typePaging aSeries);

    /*
     * void mPrintAllReferences() - metoda wypisujaca wszystkie
     * referencje.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mPrintAllReferences();



    /*
     * void mResetFrames() - metoda resetujaca ramki.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetFrames();

    /*
     * void mPrintFrames() - metoda wypisujaca zawartosc ramek.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mPrintFrames();



    /*
     * void mResetSumNumberOfLack(typePaging aSeries) - metoda
     * resetujaca wskazana sume brakow stron.
     * PRE:
     * - podanie numeru serii (typ: typePaging);
     * POST:
     * - brak.
     */
    void mResetSumNumberOfLack(typePaging aSeries);

    /*
     * void mResetAllSumNumberOfLack() - metoda resetujaca
     * wszystkie sumy brakow stron.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllSumNumberOfLack();

    /*
     * void mCalculateTotalNumberOfLacks() - metoda wyliczajaca
     * calkowita sumer brakow stron.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mCalculateTotalNumberOfLacks();

    /*
     * void mResetTotalNumberOfLacks() - metoda resetujaca
     * calkowita sume brakow stron.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetTotalNumberOfLacks();

    /*
     * void mCalculateAverageNumberOfLacks() - metoda obliczajaca
     * srednia liczba brakow stron.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mCalculateAverageNumberOfLacks();

    /*
     * void mResetAverageNumberOfLacks() - metoda resetujaca
     * srednia liczba brakow stron.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAverageNumberOfLacks();



    /*
     * void mWriteResultsToFile(enumAlgorithms aAlgorithms) -
     * metoda wypisujaca wyniki dzialan wskazanego algorytmu.
     * PRE:
     * - podanie kodu algorytmu (typ: enumAlgorithms);
     * POST:
     * - brak.
     */
    void mWriteResultsToFile(enumAlgorithms aAlgorithms);

/********** PUBLIC: END **********/
};

#endif // CPAGINGALGORITHMS_H

/* cpagingalgorithms.h */
/********** END_OF_FILE **********/
