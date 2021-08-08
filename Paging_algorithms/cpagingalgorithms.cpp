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
    mInitializePages(); // inicjalizowanie stron
    mResetAllReferences(); // wyczyszczenie tablicy referencji
    mDrawReferences(); // wylosowanie referencji
    mWriteReferencesToFile(); // wypisanie referencji do pliku
    mMakeFIFO(); // wywolanie metody implmentujacej dzialanie algorytmu FIFO
    mMakeLIFO(); // wywolanie metody implmentujacej dzialanie algorytmu LIFO
    mMakeLFU(); // wywolanie metody implmentujacej dzialanie algorytmu LFU
    mMakeMFU(); // wywolanie metody implmentujacej dzialanie algorytmu MFU
}

/*
 * cPagingAlgorithms(enumAlgorithms aAlgorithm)
 */
cPagingAlgorithms::cPagingAlgorithms(enumAlgorithms aAlgorithm)
{
    mInitializePages(); // inicjalizowanie stron
    mResetAllReferences(); // wyczyszczenie tablicy referencji
    mDrawReferences(); // wylosowanie referencji
    mWriteReferencesToFile(); // wypisanie referencji do pliku
      //mPrintAllReferences();
    switch(aAlgorithm) // wywolanie odpowiedniej metody, zgodnie z podanym argumentem
    {
        case fifo: mMakeFIFO(); break; // wywolanie metody implmentujacej dzialanie algorytmu FIFO
        case lifo: mMakeLIFO(); break; // wywolanie metody implmentujacej dzialanie algorytmu LIFO
        case lfu: mMakeLFU(); break; // wywolanie metody implmentujacej dzialanie algorytmu LFU
        case mfu: mMakeMFU(); break; // wywolanie metody implmentujacej dzialanie algorytmu MFU
    }
}



/*
 * void mMakeFIFO()
 */
void cPagingAlgorithms::mMakeFIFO()
{
    mResetAllSumNumberOfLack(); // zresetowanie wszystkich czastkowych sum brakow stron
    mResetTotalNumberOfLacks(); // zresetowanie calkowitej sumy brakow stron
    mResetAverageNumberOfLacks(); // zresetowanie sredniej liczby brakow stron
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        mResetFrames(); // zresetowanie zawartosci ramek
        mClearAllAges(); // wyzerowanie wieku wszystkich stron
        for (typePaging j = 0; j < constReference; j++) // przejscie po wszystkich referencjach w serii
        {
            if (tabPages[tabReferences[i][j]].getInFrame() == true) // sprawdzenie czy strona jest juz w ramce
            {
                mMakePage(i, j); // jesli tak to "wykonujemy strone"
            }
            else // strony nie ma aktualnie w zadnej ramce
            {
                if (mBusyAllFrames() == false) // sprawdzamy czy mamy przynajmniej jedna wolna ramke
                {
                    tabPages[tabReferences[i][j]].setInFrame(true); // ustanawiamy obecnosc strony w ramce
                    setFrame(mGetFirstEmptyFrame(), tabPages[tabReferences[i][j]].getNumberPage()); // umieszczamy strone w pierwszej wolnej ramce
                    mMakePage(i, j); // "wykonujemy strone"
                }
                else // przypadek kiedy wszystkie ramki sa zajete
                {
                    tabPages[tabReferences[i][j]].mIncrementNumberOfLacks(); // nie mamy strony w ramce wiec wzrasta liczba brakow
                    (tabSumNumberOfLack[i])++; // zwiekszenie sumy brakow w serii
                    setFrame(tabPages[mGetTheOldestPage()].getNumberUsingFrame(), tabPages[tabReferences[i][j]].getNumberPage()); // podstawiamy nowa zawartosc
                    mMakePage(i, j); // "wykonujemy strone"
                }
            }
        }
    }
    mCalculateTotalNumberOfLacks(); // obliczenie calkowitej liczby brakow stron
    mCalculateAverageNumberOfLacks(); // obliczenie sredniej liczby brakow stron
    mWriteResultsToFile(fifo); // wypisanie rezultatow do pliku
}

/*
 * void mMakeLIFO()
 */
void cPagingAlgorithms::mMakeLIFO()
{
    mResetAllSumNumberOfLack(); // zresetowanie wszystkich czastkowych sum brakow stron
    mResetTotalNumberOfLacks(); // zresetowanie calkowitej sumy brakow stron
    mResetAverageNumberOfLacks(); // zresetowanie sredniej liczby brakow stron
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        mResetFrames(); // zresetowanie zawartosci ramek
        mClearAllAges(); // wyzerowanie wieku wszystkich stron
        for (typePaging j = 0; j < constReference; j++) // przejscie po wszystkich referencjach w serii
        {
            if (tabPages[tabReferences[i][j]].getInFrame() == true) // sprawdzenie czy strona jest juz w ramce
            {
                mMakePage(i, j); // jesli tak to "wykonujemy strone"
            }
            else // strony nie ma aktualnie w zadnej ramce
            {
                if (mBusyAllFrames() == false) // sprawdzamy czy mamy przynajmniej jedna wolna ramke
                {
                    tabPages[tabReferences[i][j]].setInFrame(true); // ustanawiamy obecnosc strony w ramce
                    setFrame(mGetFirstEmptyFrame(), tabPages[tabReferences[i][j]].getNumberPage()); // umieszczamy strone w pierwszej wolnej ramce
                    mMakePage(i, j); // "wykonujemy strone"
                }
                else // przypadek kiedy wszystkie ramki sa zajete
                {
                    tabPages[tabReferences[i][j]].mIncrementNumberOfLacks(); // nie mamy strony w ramce wiec wzrasta liczba brakow
                    (tabSumNumberOfLack[i])++; // zwiekszenie sumy brakow w serii
                    setFrame(tabPages[mGetTheYoungestPage()].getNumberUsingFrame(), tabPages[tabReferences[i][j]].getNumberPage()); // podstawiamy nowa zawartosc
                    mMakePage(i, j); // "wykonujemy strone"
                }
            }
        }
    }
    mCalculateTotalNumberOfLacks(); // obliczenie calkowitej liczby brakow stron
    mCalculateAverageNumberOfLacks(); // obliczenie sredniej liczby brakow stron
    mWriteResultsToFile(lifo); // wypisanie rezultatow do pliku


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
    for (typePaging i = 0; i < constPage; i++) // przechodzimy po wszystkich stronach
    {
        if (tabPages[i].getInFrame() == true) // sprawdzamy czy strona zajmuje jakakolwiek ramke
        {
            if (tabPages[i].getNumberPage() == tabReferences[aSeries][aIndex]) // sprawdzamy czy wskazana strona to ta do ktorej sie odnosimy
            {
                tabPages[i].mResetAgeOfPage(); // wiek strony sie zeruje
                tabPages[i].mIncrementNumberOfUsing(); // wzrasta liczba uzyc strony
            }
            else
                tabPages[i].mIncrementAgeOfPage(); // rosnie wiek strony
        }
        else // jesli strona nie zajmuje zadnej ramki
            continue; // przechodzimy do wykonania kolejnego cyklu petli
    }
}

/*
 * typePaging mGetTheOldestPage()
 */
typePaging cPagingAlgorithms::mGetTheOldestPage()
{
    typePaging vTheOldestPage = tabFrames[0]; // ustanawiamy, ze na poczatku najstarsza strona jest w pierwszej ramce
    for (typePaging i = 0; i < (constFrame - 1); i++) // przechodzimy po wszystkich ramkach za wyjatkiem ostatniej
    {
        for (typePaging j = i + 1; j < constFrame; j++) // przechodzimy po wszystkich ramkach poczawszy od wskazanej
        {
            //cout << "    i = " << tabPages[tabFrames[i]].getAgeOfPage() << ", j = " << tabPages[tabFrames[j]].getAgeOfPage() << endl;
            if (tabPages[tabFrames[i]].getAgeOfPage() < tabPages[tabFrames[j]].getAgeOfPage()) // porownujemy "wiek" wskazanych stron
                vTheOldestPage = tabFrames[j]; // ustanawiamy nowa, najstarsza strone
        }
    }
    //cout << "    The oldest: " << vTheOldestPage << endl;
    return vTheOldestPage; // zwracamy numer najstarszej strony
}

/*
 * typePaging mGetTheYoungestPage()
 */
typePaging cPagingAlgorithms::mGetTheYoungestPage()
{
    typePaging vTheYoungestPage = tabFrames[0]; // ustanawiamy, ze na poczatku najmlodsza strona jest w pierwszej ramce
    for (typePaging i = 0; i < (constFrame - 1); i++) // przechodzimy po wszystkich ramkach za wyjatkiem ostatniej
        for (typePaging j = i + 1; j < constFrame; j++) // przechodzimy po wszystkich ramkach poczawszy od wskazanej
            if (tabPages[tabFrames[i]].getAgeOfPage() > tabPages[tabFrames[j]].getAgeOfPage()) // porownujemy "wiek" wskazanych stron
                vTheYoungestPage = tabFrames[j]; // ustanawiamy nowa, najmlodsza strone
    return vTheYoungestPage; // zwracamy numer najmlodszej strony
}


/*
 * typePaging mGetLeastFrequentlyUsed()
 */
typePaging cPagingAlgorithms::mGetLeastFrequentlyUsed()
{
    typePaging vLeastFrequentlyUsed = tabFrames[0]; // ustanawiamy, ze na poczatku najrzadziej uzywana strona jest w pierwszej ramce
    for (typePaging i = 0; i < (constFrame - 1); i++) // przechodzimy po wszystkich ramkach za wyjatkiem ostatniej
        for (typePaging j = i + 1; j < constFrame; j++) // przechodzimy po wszystkich ramkach poczawszy od wskazanej
            if (tabPages[tabFrames[i]].getNumberUsingFrame() > tabPages[tabFrames[j]].getNumberUsingFrame()) // porownujemy liczbe uzyc wskazanych stron
                vLeastFrequentlyUsed = tabFrames[j]; // ustanawiamy nowa, najrzadziej uzywana strone
    return vLeastFrequentlyUsed; // zwracamy numer najrzadziej uzywanej strony
}

/*
 * typePaging mGetMostFrequentlyUsed()
 */
typePaging cPagingAlgorithms::mGetMostFrequentlyUsed()
{
    typePaging vMostFrequentlyUsed = tabFrames[0]; // ustanawiamy, ze na poczatku najczesciej uzywana strona jest w pierwszej ramce
    for (typePaging i = 0; i < (constFrame - 1); i++) // przechodzimy po wszystkich ramkach za wyjatkiem ostatniej
        for (typePaging j = i + 1; j < constFrame; j++) // przechodzimy po wszystkich ramkach poczawszy od wskazanej
            if (tabPages[tabFrames[i]].getNumberUsingFrame() < tabPages[tabFrames[j]].getNumberUsingFrame()) // porownujemy liczbe uzyc wskazanych stron
                vMostFrequentlyUsed = tabFrames[j]; // ustanawiamy nowa, najczesciej uzywana strone
    return vMostFrequentlyUsed; // zwracamy numer najczesciej uzywanej strony
}

/*
 * void mInitializePages()
 */
void cPagingAlgorithms::mInitializePages()
{
    for (typePaging i = 0; i < constPage; i++) // przejscie po wszystkich stronach
        tabPages[i] = cPage(i); // utworzenie strony
}

/*
 * bool mBusyAllFrames()
 */
bool cPagingAlgorithms::mBusyAllFrames()
{
    for (typePaging i = 0; i < constFrame; i++) // przechodzimy po wszystkich ramkach
        if (tabFrames[i] == constPage) // sprawdzamy czy ramka ma przypisana resetujaca wartosc
            return false; // jesli tak to oznacza, ze nie wszystkie ramki sa zapelnione i zwracamy o tym informacje
    return true; // domyslnie zwracamy informacje o tym, ze wszystkie ramki sa zajete
}

/*
 * typePaging mGetFirstEmptyFrame()
 */
typePaging cPagingAlgorithms::mGetFirstEmptyFrame()
{
    if (mBusyAllFrames() != true) // sprawdzamy czy wszystkie ramki sa zajete
    {
        for (typePaging i = 0; i < constFrame; i++) // przechodzimy po wszystkich ramkach
            if (tabFrames[i] == constPage) // sprawdzamy czy ramka jest wolna
                return i; // jesli tak to zwracamy numer ramki
    }
    return constPage; // domyslnie zwracamy numer strony spoza zakresu
}

/*
 * void mClearAllAges()
 */
void cPagingAlgorithms::mClearAllAges()
{
    for (typePaging i = 0; i < constPage; i++) // przejscie po wszystkich stronach
        tabPages[i].mResetAgeOfPage(); // zrestowanie wieku wskazanej strony
}

/*
 * void mClearAllUsings()
 */
void cPagingAlgorithms::mClearAllUsings()
{
    for (typePaging i = 0; i < constPage; i++) // przejscie po wszystkich stronach
        tabPages[i].mResetNumberOfUsing(); // zresetowanie liczby uzyc wskazanej strony
}




/*
 * void setFrame(typePaging aIndex, typePaging aPageIndex)
 */
void cPagingAlgorithms::setFrame(typePaging aIndex, typePaging aPageIndex)
{
    for (typePaging i = 0; i < constFrame; i++) // przechodzimy przez wszystkie ramki
    {
        if (i == aIndex) // sprawdzamy czy to jest numer ramki w ktorym chcemy umiescic nowa zawartosc
        {
            if (tabFrames[i] != constPage) // sprawdzamy czy w ramce jest cokolwiek
            {
                tabPages[tabFrames[aIndex]].mResetAgeOfPage(); // jesli tak to zerujemy jej wiek...
                tabPages[tabFrames[aIndex]].mResetNumberOfUsing(); // ...zerujemy jej liczbe uzyc...
                tabPages[tabFrames[aIndex]].setInFrame(false); // ...i usuwamy ja z ramki
                tabPages[aPageIndex].mIncrementNumberOfLacks(); // zwiekszamy liczbe brakow strony
            }
            tabFrames[i] = aPageIndex; // do ramki wstawiamy indeks wstawianej strony
            tabPages[tabFrames[i]].setInFrame(true); // potwierdzamy, ze strona znajduje sie w jakiejs ramce
            tabPages[tabFrames[i]].setNumberUsingFrame(aIndex); // ustanowienie numeru zajmowanej ramki
            tabPages[tabFrames[i]].mResetAgeOfPage(); // bedziemy liczyc jej "wiek" od nowa
        }
    }
}



/*
 * void mDrawReferences()
 */
void cPagingAlgorithms::mDrawReferences()
{
    //mResetAllReferences(); // wyczyszczenie tablicy referencji
    srand(time_t(NULL)); // ustanowienie zmiennej losowej
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        for (typePaging j = 0; j < constReference; j++) // przejscie po wszystkich procesach
            tabReferences[i][j] = rand() % constPage; // losowanie i przypisanie referencji
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
    StreamOut.open("references.txt"); // otwarcie strumienia
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        for (typePaging j = 0; j < constReference; j++) // przejscie po wszystkich referencjach
            StreamOut << tabReferences[i][j] << " "; // wypisanie referencji
        StreamOut << endl; // nowa seria - nowa linijka tekstu
    }
    StreamOut.close(); // zamkniecie strumienia
}

/*
 * void mPrintSeries(typePaging aSeries)
 */
void cPagingAlgorithms::mPrintSeries(typePaging aSeries)
{
    for (typePaging i = 0; i < constReference; i++) // przejscie po wszystkich referencjach w serii
        cout << tabReferences[aSeries][i] << " "; // wypisanie referencji
}

/*
 * void mPrintAllReferences()
 */
void cPagingAlgorithms::mPrintAllReferences()
{
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        mPrintSeries(i); // wywolanie metody wypisujacej referencje ze wskazanej serii
        cout << endl; // nowa seria - nowa linijka tekstu
    }
}



/*
 * void mResetFrames()
 */
void cPagingAlgorithms::mResetFrames()
{
    for (typePaging i = 0; i < constFrame; i++) // przejscie po wszystkich ramkach
        tabFrames[i] = constPage; // ustanowienie wartosci ramek
    for (typePaging i = 0; i < constPage; i++) // przejscie po wszystkich stronach
        tabPages[i].setInFrame(false); // ustanowienie braku przypisanie do jakiejkolwiek ramki
}

/*
 * void mPrintFrames()
 */
void cPagingAlgorithms::mPrintFrames()
{
    for (typePaging i = 0; i < constFrame; i++) // przejscie po wszystkich ramkach
        //cout << "Frame " << i << ": " << tabFrames[i] << endl; // sformatowane wypisanie zawartosci kolejnej ramki
        cout << "    " << "Frame " << i << ": " << tabFrames[i];
    cout << endl;
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
    // fifo, lifo, lfu, mfu
    ofstream StreamOut; // zdefiniowanie strumienia
    switch(aAlgorithms)
    {
        case fifo: StreamOut.open("resultsFIFO.txt"); break; // otwarcie strumienia dla wynikow algorytmu FIFO
        case lifo: StreamOut.open("resultsLIFO.txt"); break; // otwarcie strumienia dla wynikow algorytmu LIFO
        case lfu: StreamOut.open("resultsLFU.txt"); break; // otwarcie strumienia dla wynikow algorytmu LFU
        case mfu: StreamOut.open("resultsMFU.txt"); break; // otwarcie strumienia dla wynikow algorytmu MFU
    }
    for (typePaging i = 0; i < constSeries; i++)
        StreamOut << "Lacks series " << i << ": " << tabSumNumberOfLack[i] << endl;
    StreamOut << "Total number of lacks: " << setw(5) // wypisanie calkowitej liczby brakow stron
              << getTotalNumberOfLacks() << "    " << endl
              << "Average number of lacks: " << setw(4) // wypisanie sredniej liczby brakow stron
              << getAverageNumberOfLacks() << endl;
    StreamOut.close();
}

/********** PUBLIC: END **********/

/* cpagingalgorithms.cpp */
/********** END_OF_FILE **********/
