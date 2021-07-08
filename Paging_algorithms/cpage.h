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
    /*
     * cPage() - konstruktor wywolywany bez argumentow
     * PRE:
     * - brak;
     * POST:
     * - tworzenie obiektu klasy cPage.
     */
    cPage();

    /*
     * cPage(typePaging aNumberpage) - konstruktor wywolywany
     * z jednym argumentem - numerem strony.
     * PRE:
     * - podanie numeru strony (typ: typePaging);
     * POST:
     * - tworzenie obiektu klasy cPage.
     */
    cPage(typePaging aNumberpage);



    /*
     * friend ostream & operator << (ostream & StreamOut, cPage & P) -
     * przeladowanie operatora wyjscia (wypisanie obiektu).
     * PRE:
     * - referencja obiektu klasy ostream, referencja obiektu
     * klasy cPage;
     * POST:
     * - referencja do obiektu klasy ostream.
     */
    friend ostream & operator << (ostream & StreamOut, cPage & P);

    /*
     * friend istream & operator >> (istream & StreamIn, cPage & P) -
     * przeladowanie operatora wejscia (wczytanie obiektu).
     * PRE:
     * - referencja obiektu klasy istream, referencja obiektu
     * klasy cPage;
     * POST:
     * - referencja do obiektu klasy istream.
     */
    friend istream & operator >> (istream & StreamIn, cPage & P);



    /*
     * typePaging getNumberPage() - metoda zwracajaca numer strony.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vNumberPage (typ: typePaging).
     */
    inline typePaging getNumberPage()
    {
        return vNumberPage;
    }

    /*
     * bool getInFrame() - metoda zwracajaca informacje czy strona
     * jest aktualnie w jakiejs ramce.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vInFrame (typ: bool).
     */
    inline bool getInFrame()
    {
        return vInFrame;
    }

    /*
     * typePaging getNuberUsingFrame() - metoda zwracajaca
     * informacje o zajmowanej ramce (o ile dana strona jest
     * w uzyciu!).
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vNumberUsingFrame (typ:
     * typePaging).
     */
    inline typePaging getNuberUsingFrame()
    {
        return vNumberUsingFrame;
    }

    /*
     * typePaging getNumberOfLacks() - metoda zwracajaca liczbe
     * brakow strony.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vNumberOfLacks (typ: typePaging).
     */
    inline typePaging getNumberOfLacks()
    {
        return vNumberOfLacks;
    }



    /*
     * void setNumberPage(typePaging aNumberPage) - metoda
     * ustawiajaca numer strony.
     * PRE:
     * - podanie numeru strony (typ: typePaging);
     * POST:
     * - brak.
     */
    inline void setNumberPage(typePaging aNumberPage)
    {
        vNumberPage = aNumberPage;
    }

    /*
     * void setInFrame(bool aInFrame) - metoda ustanawiajaca
     * aktualny status strony tzn. podana jest wartosc "true"
     * jezeli dana strona jest w jakiejkolwiek ramce.
     * PRE:
     * - podanie informacji o uzyciy strony (typ: bool);
     * POST:
     * - brak.
     */
    inline void setInFrame(bool aInFrame)
    {
        vInFrame = aInFrame;
    }

    /*
     * void setNumberUsingFrame(typePaging aNumberUsingFrame) -
     * metoda ustanawiajaca numer aktualnie uzywanej ramki
     * (o ile jakakolwiek jest uzywana!).
     * PRE:
     * - podanie numeru ramki (typ: typePaging);
     * POST:
     * - brak.
     */
    inline void setNumberUsingFrame(typePaging aNumberUsingFrame)
    {
        vNumberUsingFrame = aNumberUsingFrame;
    }



    /*
     * void mIncrementNumberOfLacks() - metoda inkrementujaca
     * wartosc brakow strony.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void mIncrementNumberOfLacks()
    {
        vNumberOfLacks++;
    }

    /*
     * void mResetNumberOfLacks() - metoda resetujaca wartosc
     * brakow strony.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void mResetNumberOfLacks()
    {
        vNumberOfLacks = 0;
    }
};

#endif // CPAGE_H

/* cpage.h */
/********** END_OF_FILE **********/
