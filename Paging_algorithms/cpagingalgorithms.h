/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cpagingalgorithms.h
 */

#ifndef CPAGINGALGORITHMS_H
#define CPAGINGALGORITHMS_H

#include "constantsandtypes.h"
#include "cpage.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

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
     * typePaging tabReferences[constSeries][constReference] -
     * tablica kolejnych wywolan stron.
     */
    typePaging tabReferences[constSeries][constReference];

    /*
     * cPage tabFrames[constFrame] - tablica dostepnych ramek.
     */
    typePaging tabFrames[constFrame];

    /*
     * double tabAverageNumberOfLack[constSeries] - tablica
     * sum brakow stron w poszczegolnych seriach.
     */
    typePaging tabSumNumberOfLack[constSeries];

    /*
     * typePaging vTotalNumberOfLacks - calkowita suma
     * brakow stron.
     */
    typePaging vTotalNumberOfLacks;

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
     * void mMakeLIFO() - metoda realizujaca algorytm LIFO.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeLIFO();

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
     * i zwracajaca numer najdawniej uzywanej strony.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie numeru strony sposrod stron znajdujacych sie
     * w ramkach (typ: typePaging).
     */
    typePaging mGetTheOldestPage();

    /*
     * typePaging mGetLeastFrequentlyUsed() - metoda znajdujaca
     * i zwracajaca numer najrzadziej uzywanej strony.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie numeru strony sposrod stron znajdujacych sie
     * w ramkach (typ: typePaging).
     */
    typePaging mGetLeastFrequentlyUsed();

    /*
     * typePaging mGetMostFrequentlyUsed() - metoda znajdujaca
     * i zwracajaca numer naczesciej uzywanej strone.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie numeru strony sposrood stron znajdujacych sie
     * w ramkach (typ: typePaging).
     */
    typePaging mGetMostFrequentlyUsed();

    /*
     * void mInitializePages() - metoda inicjalizujaca strony.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mInitializePages();

    /*
     * void mInitailizeFrames() - metoda inicjalizujaca ramki.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mInitailizeFrames();



    /*
     * cPage getPage(typePaging aIndex) - metoda zwracajaca wskazana
     * strone.
     * PRE:
     * - podanie numeru indeksu (typ: typePaging);
     * POST:
     * - zwrocenie strony (typ: cPage).
     */
    inline cPage getPage(typePaging aIndex)
    {
        return tabPages[aIndex];
    }

    /*
     * typePaging getReference(typePaging aSeries, typePaging aIndex) -
     * metoda zwracajaca wartosc wskazanej referencji.
     * PRE:
     * - podanie numeru serii (typ: typePaging), podanie
     * indeksu referencji w serii (typ: typePaging);
     * POST:
     * - zwrocenie referencji (typ: cPage).
     */
    inline typePaging getReference(typePaging aSeries, typePaging aIndex)
    {
        return tabReferences[aSeries][aIndex];
    }

    /*
     * typePaging getFrame(typePaging aIndex) - metoda zwracajaca
     * zawartosc wskazanej ramki.
     * PRE:
     * - podanie numeru indeksu (typ: typePaging);
     * POST:
     * - zwrocenie zawartosci ramki (typ: cPage).
     */
    inline typePaging getFrame(typePaging aIndex)
    {
        return tabFrames[aIndex];
    }

    /*
     * typePaging getSumNumberOfLacks(typePaging aSeries) -
     * metoda zwracajaca liczbe brakow stron we wskazanej
     * serii.
     * PRE:
     * - podanie numeru serii (typ: typePaging);
     * POST:
     * - zwrocenie liczby brakow (typ: typePaging).
     */
    inline typePaging getSumNumberOfLacks(typePaging aSeries)
    {
        return tabSumNumberOfLack[aSeries];
    }

    /*
     * typePaging getTotalNumberOfLacks() - metoda zwracajaca
     * calkowita liczbe brakow ze wszystkich serii.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTotalNumberOfLacks (typ:
     * typePaging).
     */
    inline typePaging getTotalNumberOfLacks()
    {
        return vTotalNumberOfLacks;
    }

    /*
     * double getAverageNumberOfLacks() - metoda zwracajaca
     * srednia liczbe brakow stron ze wszystkich serii.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie zawartosci pola vAverageNumberOfLacks
     * (typ: typePaging).
     */
    inline double getAverageNumberOfLacks()
    {
        return vAverageNumberOfLack;
    }



    /*
     * void setPage(typePaging aIndex, cPage aPage) - metoda
     * ustawiajaca strone we wskazanym miejscu tablicy stron.
     * PRE:
     * - podanie indeksu (typ: typePaging), podanie strony
     * (typ: cPage);
     * POST:
     * - brak.
     */
    inline void setPage(typePaging aIndex, cPage aPage)
    {
        tabPages[aIndex] = aPage;
    }

    /*
     * void setReference(typePaging aSeries, typePaging aIndex, typePaging aPageIndex) -
     * metoda ustawiajaca referencje we wskazanym miejscu
     * tablicy referencji.
     * PRE:
     * - podanie numeru serii (typ: typePaging), podanie
     * indeksu (typ: typePaging), podanie wartosci (typ: typePaging);
     * POST:
     * - brak.
     */
    inline void setReference(typePaging aSeries, typePaging aIndex, typePaging aPageIndex)
    {
        tabReferences[aSeries][aIndex] = aPageIndex;
    }

    /*
     * void setFrame(typePaging aIndex, typePaging aPageIndex) - metoda
     * ustawiajaca zawartosc wskazanej ramki.
     * PRE:
     * - podanie indeksu (typ: typePaging), podanie numeru strony
     * (typ: typePaging);
     * POST:
     * - brak.
     */
    inline void setFrame(typePaging aIndex, typePaging aPageIndex)
    {
        tabFrames[aIndex] = aPageIndex;
    }



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
    inline void mResetReference(typePaging aSeries, typePaging aReference)
    {
        tabReferences[aSeries][aReference] = constPage;
    }

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
    inline void mPrintReference(typePaging aSeries, typePaging aReference)
    {
        cout << tabReferences[aSeries][aReference];
    }

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
    inline void mResetSumNumberOfLack(typePaging aSeries)
    {
        tabSumNumberOfLack[aSeries] = 0;
    }

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
    inline void mResetTotalNumberOfLacks()
    {
        vTotalNumberOfLacks = 0;
    }

    /*
     * void mCalculateAverageNumberOfLacks() - metoda obliczajaca
     * srednia liczba brakow stron.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void mCalculateAverageNumberOfLacks()
    {
        vAverageNumberOfLack = vTotalNumberOfLacks / constSeries;
    }

    /*
     * void mResetAverageNumberOfLacks() - metoda resetujaca
     * srednia liczba brakow stron.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void mResetAverageNumberOfLacks()
    {
        vAverageNumberOfLack = 0;
    }



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
