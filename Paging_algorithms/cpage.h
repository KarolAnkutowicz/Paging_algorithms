/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cpage.h
 */

#ifndef CPAGE_H
#define CPAGE_H

#include "constantsandtypes.h"
#include <iomanip>
#include <iostream>

using namespace std;

/*
 * cPage - klasa modelujaca pojedyncza strone
 */
class cPage
{
    /********** PRIVATE: BEGINNING **********/

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
     * typePaging vNumberOfUsing - liczba uzyc strony.
     */
    typePaging vNumberOfUsing;

    /*
     * typePaging vNumberOfLacks - calkowity numer brakow
     * strony
     */
    typePaging vNumberOfLacks;

    /*
     * typePaging vAgeOfPage - "wiek" danej strony tzn. liczba
     * cykli przebywania w ramce.
     */
    typePaging vAgeOfPage;

/********** PRIVATE: END **********/

/********** PUBLIC: BEGINNING **********/
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
     * cPage(typePaging aNumberPage) - konstruktor wywolywany
     * z jednym argumentem - numerem strony.
     * PRE:
     * - podanie numeru strony (typ: typePaging);
     * POST:
     * - tworzenie obiektu klasy cPage.
     */
    cPage(typePaging aNumberPage);



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
     * typePaging getNumberUsingFrame() - metoda zwracajaca
     * informacje o zajmowanej ramce (o ile dana strona jest
     * w uzyciu!).
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vNumberUsingFrame (typ:
     * typePaging).
     */
    inline typePaging getNumberUsingFrame()
    {
        return vNumberUsingFrame;
    }

    /*
     * typePaging getNumberOfUsing() - metoda zwracajaca liczbe
     * uzyc strony.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vNumberOfUsing (typ:
     * typePaging).
     */
    inline typePaging getNumberOfUsing()
    {
        return vNumberOfUsing;
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
     * typePaging getAgeOfPage() - metoda zwracajaca "wiek"
     * danej strony.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vAgeOfPage (typ: typePaging).
     */
    inline typePaging getAgeOfPage()
    {
        return vAgeOfPage;
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
     * void mIncrementNumberOfUsing() - metoda inkrementujaca
     * liczbe uzyc strony.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void mIncrementNumberOfUsing()
    {
        vNumberOfUsing++;
    }

    /*
     * void mIncrementNumberOfLacks() - metoda inkrementujaca
     * liczbe brakow strony.
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
     * void mIncrementAgeOfPage() - metoda inkrementujaca wiek
     * strony.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void mIncrementAgeOfPage()
    {
        vAgeOfPage++;
    }



    /*
     * void mResetNumberOfUsing() - metoda resetujaca liczbe
     * uzyc strony.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void mResetNumberOfUsing()
    {
        vNumberOfUsing = 0;
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

    /*
     * void mResetAgeOfPage() - metoda resetujaca wiek strony.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void mResetAgeOfPage()
    {
        vAgeOfPage = 0;
    }

/********** PUBLIC: END **********/
};

#endif // CPAGE_H

/* cpage.h */
/********** END_OF_FILE **********/
