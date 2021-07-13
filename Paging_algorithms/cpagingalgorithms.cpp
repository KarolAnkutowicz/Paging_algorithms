/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cpagingalgorithms.cpp
 */

#include "cpagingalgorithms.h"

using namespace std;

/********** PUBLIC: BEGINNING **********/

/*
 * cPagingAlgorithms()
 */
cPagingAlgorithms::cPagingAlgorithms()
{
    mResetAllReferences(); // wyczyszczenie tablicy referencji
    mDrawReferences(); // wylosowanie referencji
    mWriteReferencesToFile(); // wypisanie referencji do pliku
    mMakeFIFO(); // wywolanie metody implmentujacej dzialanie algorytmu FIFO
    mMakeLRU(); // wywolanie metody implmentujacej dzialanie algorytmu LRU
    mMakeLFU(); // wywolanie metody implmentujacej dzialanie algorytmu LFU
    mMakeMFU(); // wywolanie metody implmentujacej dzialanie algorytmu MFU
}

/*
 * cPagingAlgorithms(enumAlgorithms aAlgorithm)
 */
cPagingAlgorithms::cPagingAlgorithms(enumAlgorithms aAlgorithm)
{
    mResetAllReferences(); // wyczyszczenie tablicy referencji
    mDrawReferences(); // wylosowanie referencji
    mWriteReferencesToFile(); // wypisanie referencji do pliku
    switch(aAlgorithm) // wywolanie odpowiedniej metody, zgodnie z podanym argumentem
    {
        case fifo: mMakeFIFO(); break; // wywolanie metody implmentujacej dzialanie algorytmu FIFO
        case lru: mMakeLRU(); break; // wywolanie metody implmentujacej dzialanie algorytmu LRU
        case lfu: mMakeLFU(); break; // wywolanie metody implmentujacej dzialanie algorytmu LFU
        case mfu: mMakeMFU(); break; // wywolanie metody implmentujacej dzialanie algorytmu MFU
    }
}



/*
 * void mMakeFIFO()
 */
void cPagingAlgorithms::mMakeFIFO()
{

}

/*
 * void mMakeLRU()
 */
void cPagingAlgorithms::mMakeLRU()
{

}

/*
 * void mMakeLFU()
 */
void cPagingAlgorithms::mMakeLFU()
{

}

/*
 * void mMakeMFU()
 */
void cPagingAlgorithms::mMakeMFU()
{

}

/*
 * void mMakePage(typePaging aSeries, typePaging aIndex)
 */
void cPagingAlgorithms::mMakePage(typePaging aSeries, typePaging aIndex)
{

}

/*
 * typePaging mGetTheOldestPage()
 */
typePaging cPagingAlgorithms::mGetTheOldestPage()
{
    return 0;
}

/*
 * typePaging mGetLeastFrequentlyUsed()
 */
typePaging cPagingAlgorithms::mGetLeastFrequentlyUsed()
{
    return 0;
}

/*
 * typePaging mGetMostFrequentlyUsed()
 */
typePaging cPagingAlgorithms::mGetMostFrequentlyUsed()
{
    return 0;
}



/*
 * void mDrawReferences()
 */
void cPagingAlgorithms::mDrawReferences()
{

}

/*
 * void mResetSeries(typePaging aSeries)
 */
void cPagingAlgorithms::mResetSeries(typePaging aSeries)
{
    for (typePaging i = 0; i < constReference; i++) // przejscie po wszystkich referencjach
        mResetReference(aSeries, i); // resetowanie wskazanej referencji
}

/*
 * void mResetAllReferences()
 */
void cPagingAlgorithms::mResetAllReferences()
{
    for (typePaging i = 0; i < constReference; i++) // przejscie po wszystkich seriach
        mResetSeries(i); // resetowanie wskazanej serii
}

/*
 * void mReadReferencesFromFile()
 */
void cPagingAlgorithms::mReadReferencesFromFile()
{
    mResetAllReferences(); // wyczyszczenie aktualnej tablicy referencji
    ifstream StreamIn; // utworzenie wejsciowego strumienia plikowego
    StreamIn.open("references.txt"); // otwarcie strumienia
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        for (typePaging j = 0; j < constReference; j++) // przejscie po wszystkich referencjach
            StreamIn >> skipws >> tabReferences[i][j]; // wczytanie pojedynczej referencji
    StreamIn.close(); // zamkniecie strumienia
}

/*
 * void mWriteReferencesToFile()
 */
void cPagingAlgorithms::mWriteReferencesToFile()
{
    ofstream StreamOut; // utworzenie wyjsciowego strumienia plikowego
    StreamOut.open("references"); // otwarcie strumienia
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        for (typePaging j = 0; j < constReference; j++) // przejscie po wszystkich referencjach
            StreamOut << tabReferences[i][j]; // wypisanie referencji
        StreamOut << endl; // nowa seria - nowa linijka tekstu
    }
    StreamOut.close(); // zamkniecie strumienia
}

/*
 * void mPrintSeries(typePaging aSeries)
 */
void cPagingAlgorithms::mPrintSeries(typePaging aSeries)
{

}

/*
 * void mPrintAllReferences()
 */
void cPagingAlgorithms::mPrintAllReferences()
{

}



/*
 * void mResetFrames()
 */
void cPagingAlgorithms::mResetFrames()
{
}

/*
 * void mPrintFrames()
 */
void cPagingAlgorithms::mPrintFrames()
{
    for (typePaging i = 0; i < constFrame; i++) // przejscie po wszystkich ramkach
        cout << "Frame " << i << ": " << tabFrames[i] << endl; // sformatowane wypisanie zawartosci kolejnej ramki
}



/*
 * void mResetAllSumNumberOfLack()
 */
void cPagingAlgorithms::mResetAllSumNumberOfLack()
{
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mResetSumNumberOfLack(i); // wywolanie metody resetujacej sume brakow stron wskazanej serii
}

/*
 * void mCalculateTotalNumberOfLacks()
 */
void cPagingAlgorithms::mCalculateTotalNumberOfLacks()
{
    typePaging vSum = 0; // nadanie sumy poczatkowej
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        vSum += getSumNumberOfLacks(i); // dodanie do sumy liczby brakow ze wskazanej serii
    vTotalNumberOfLacks = vSum; // ustanowienie ostatecznej sumy
}



/*
 * void mWriteResultsToFile(enumAlgorithms aAlgorithms)
 */
void cPagingAlgorithms::mWriteResultsToFile(enumAlgorithms aAlgorithms)
{
    // fifo, lru, lfu, mfu
    ofstream StreamOut; // zdefiniowanie strumienia
    switch(aAlgorithms)
    {
        case fifo: StreamOut.open("resultsFIFO.txt"); break; // otwarcie strumienia dla wynikow algorytmu FIFO
        case lru: StreamOut.open("resultsLRU.txt"); break; // otwarcie strumienia dla wynikow algorytmu LRU
        case lfu: StreamOut.open("resultsLFU.txt"); break; // otwarcie strumienia dla wynikow algorytmu LFU
        case mfu: StreamOut.open("resultsMFU.txt"); break; // otwarcie strumienia dla wynikow algorytmu MFU
    }
    StreamOut << "Total number of lacks: " << setw(5)
              << getTotalNumberOfLacks() << "    "
              << "Average number of lacks: " << setw(4)
              << getAverageNumberOfLacks() << endl;
    StreamOut.close();
}

/********** PUBLIC: END **********/

/* cpagingalgorithms.cpp */
/********** END_OF_FILE **********/
