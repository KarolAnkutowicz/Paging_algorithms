/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cdata.cpp
 */

#include "cdata.h"

using namespace std;

/********** PUBLIC: BEGINNING **********/
/*
 * cData()
 */
cData::cData()
{

}



/*
 * mDrawReference()
 */
void cData::mDrawReference()
{

}

/*
 * mClearSeries(typePaging parSeries)
 */
void cData::mClearSeries(typePaging parSeries)
{
    for (typePaging j = 0; j < constReference; j++) // przejscie po wszystkich kolumnach w serii
        tableReference[parSeries][j] = 0; // wyzerowanie referencji
}

/*
 * mClearAllSeries()
 */
void cData::mClearAllSeries()
{
    for (typePaging i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mClearSeries(i); // wyzerowanie wskazanej serii
}



/*
 * mPrintReferenceToFile()
 */
void cData::mPrintReferenceToFile()
{

}

/********** PUBLIC: END **********/

/* cdata.cpp */
/********** END_OF_FILE **********/
