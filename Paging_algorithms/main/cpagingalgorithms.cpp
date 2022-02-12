/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cpagingalgorithms.cpp
 */

#include "cpagingalgorithms.hpp"

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
    switch (aAlgorithm) // wywolanie odpowiedniej metody, zgodnie z podanym argumentem
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
    mResetAllSumNumberOfLack(); // zresetowanie wszystkich czastkowych sum brakow stron
    mResetTotalNumberOfLacks(); // zresetowanie calkowitej sumy brakow stron
    mResetAverageNumberOfLacks(); // zresetowanie sredniej liczby brakow stron
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        mResetFrames(); // zresetowanie zawartosci ramek
        mClearAllUsings(); // wyzerowanie wieku wszystkich stron
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
                    setFrame(tabPages[mGetLeastFrequentlyUsed()].getNumberUsingFrame(), tabPages[tabReferences[i][j]].getNumberPage()); // podstawiamy nowa zawartosc
                    mMakePage(i, j); // "wykonujemy strone"
                }
            }
        }
    }
    mCalculateTotalNumberOfLacks(); // obliczenie calkowitej liczby brakow stron
    mCalculateAverageNumberOfLacks(); // obliczenie sredniej liczby brakow stron
    mWriteResultsToFile(lfu); // wypisanie rezultatow do pliku
}

/*
 * void mMakeMFU()
 */
void cPagingAlgorithms::mMakeMFU()
{
    mResetAllSumNumberOfLack(); // zresetowanie wszystkich czastkowych sum brakow stron
    mResetTotalNumberOfLacks(); // zresetowanie calkowitej sumy brakow stron
    mResetAverageNumberOfLacks(); // zresetowanie sredniej liczby brakow stron
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        mResetFrames(); // zresetowanie zawartosci ramek
        mClearAllUsings(); // wyzerowanie wieku wszystkich stron
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
                    setFrame(tabPages[mGetMostFrequentlyUsed()].getNumberUsingFrame(), tabPages[tabReferences[i][j]].getNumberPage()); // podstawiamy nowa zawartosc
                    mMakePage(i, j); // "wykonujemy strone"
                }
            }
        }
    }
    mCalculateTotalNumberOfLacks(); // obliczenie calkowitej liczby brakow stron
    mCalculateAverageNumberOfLacks(); // obliczenie sredniej liczby brakow stron
    mWriteResultsToFile(mfu); // wypisanie rezultatow do pliku
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
    typePaging vTheOldestPage = tabPages[tabFrames[0]].getAgeOfPage(); // ustanawiamy, ze na poczatku najstarsza strona jest w pierwszej ramce i przypisujemy jej wiek
    typePaging vIndex = 0; // przypisujemy indeks ustanowionej ramki
    for (typePaging i = 1; i < constFrame; i++) // przechodzimy przez wszystkie ramki pomijajac pierwsza
    {
        if (tabPages[tabFrames[i]].getAgeOfPage() > vTheOldestPage) // sprawdzamy czy wiek strony z porownywanej ramki jest wiekszy
        {
            vTheOldestPage = tabPages[tabFrames[i]].getAgeOfPage(); // jesli strona jest starsza to przypisujemy jej wiek
            vIndex = i; // mamy nowy indeks najstarszej ramki
        }
    }
    return vIndex; // zwracamy indeks najstarszej strony
}

/*
 * typePaging mGetTheYoungestPage()
 */
typePaging cPagingAlgorithms::mGetTheYoungestPage()
{
    typePaging vTheYoungestPage = tabPages[tabFrames[0]].getAgeOfPage(); // ustanawiamy, ze na poczatku najmlodsza strona jest w pierwszej ramce i przypisujemy jej wiek
    typePaging vIndex = 0; // przypisujemy indeks ustanowionej ramki
    for (typePaging i = 1; i < constFrame; i++) // przechodzimy przez wszystkie ramki pomijajac pierwsza
    {
        if (tabPages[tabFrames[i]].getAgeOfPage() < vTheYoungestPage) // sprawdzamy czy wiek strony z porownywanej ramki jest mniejszy
        {
            vTheYoungestPage = tabPages[tabFrames[i]].getAgeOfPage(); // jesli strona jest mlodsza to przypisujemy jej wiek
            vIndex = i; // mamy nowy indeks najmlodszej ramki
        }
    }
    return vIndex; // zwracamy indeks najmlodszej strony
}


/*
 * typePaging mGetLeastFrequentlyUsed()
 */
typePaging cPagingAlgorithms::mGetLeastFrequentlyUsed()
{
    typePaging vLeastFrequentlyUsed = tabPages[tabFrames[0]].getNumberOfUsing(); // ustanawiamy, ze na poczatku najrzadziej uzywana strona jest w pierwszej ramce i przypisujemy jej wiek
    typePaging vIndex = 0; // przypisujemy indeks ustanowionej ramki
    for (typePaging i = 1; i < constFrame; i++) // przechodzimy przez wszystkie ramki pomijajac pierwsza
    {
        if (tabPages[tabFrames[i]].getNumberOfUsing() < vLeastFrequentlyUsed) // sprawdzamy czy liczba uzyc strony z porownywanej ramki jest mniejsza
        {
            vLeastFrequentlyUsed = tabPages[tabFrames[i]].getAgeOfPage(); // jesli strona jest rzadziej uzywana to przypisujemy jej liczbe uzyc
            vIndex = i; // mamy nowy indeks najrzadziej uzywanej ramki
        }
    }
    return vIndex; // zwracamy indeks najrzadziej uzywanej strony
}

/*
 * typePaging mGetMostFrequentlyUsed()
 */
typePaging cPagingAlgorithms::mGetMostFrequentlyUsed()
{
    typePaging vMostFrequentlyUsed = tabPages[tabFrames[0]].getNumberOfUsing(); // ustanawiamy, ze na poczatku najczesciej uzywana strona jest w pierwszej ramce i przypisujemy jej wiek
    typePaging vIndex = 0; // przypisujemy indeks ustanowionej ramki
    for (typePaging i = 1; i < constFrame; i++) // przechodzimy przez wszystkie ramki pomijajac pierwsza
    {
        if (tabPages[tabFrames[i]].getNumberOfUsing() > vMostFrequentlyUsed) // sprawdzamy czy liczba uzyc strony z porownywanej ramki jest wieksza
        {
            vMostFrequentlyUsed = tabPages[tabFrames[i]].getAgeOfPage(); // jesli strona jest czesciej uzywana to przypisujemy jej liczbe uzyc
            vIndex = i; // mamy nowy indeks najczesciej uzywanej ramki
        }
    }
    return vIndex; // zwracamy indeks najczesciej uzywanej strony
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
    using namespace std; //zapowiedz wykorzystania elementow ze standardowej przestrzeni nazw
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
    using namespace std; //zapowiedz wykorzystania elementow ze standardowej przestrzeni nazw
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
        std::cout << tabReferences[aSeries][i] << " "; // wypisanie referencji
}

/*
 * void mPrintAllReferences()
 */
void cPagingAlgorithms::mPrintAllReferences()
{
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        mPrintSeries(i); // wywolanie metody wypisujacej referencje ze wskazanej serii
        std::cout <<'\n'; // nowa seria - nowa linijka tekstu
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
        std::cout << "    " << "Frame " << i << ": " << tabFrames[i];
    std::cout << '\n';
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
    using namespace std; //zapowiedz wykorzystania elementow ze standardowej przestrzeni nazw
    // fifo, lifo, lfu, mfu
    ofstream StreamOut; // zdefiniowanie strumienia
    switch (aAlgorithms)
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
