/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: constantsandtypes.h
 */

#ifndef CONSTANTSANDTYPES_H
#define CONSTANTSANDTYPES_H

using namespace std;

/*
 * enum enumAlgorithms - zdefiniowany typ wyliczeniowy
 * do znormalizowania argumentow potrzebnych do wywolywania
 * wskazanych metod.
 */
enum enumAlgorithms {fifo, lru, lfu, mfu};



/*
 * unsigned short typePaging - zdefiniowanie synonimu dla typu
 * liczby stron i ramek.
 */
typedef unsigned short typePaging;



/*
 * typePaging constPage - zdefiniowanie liczby stron
 */
const typePaging constPage = 5;

/*
 * typePaging constFram - zdefiniowanie liczby ramek
 */
const typePaging constFrame = 3;

/*
 * typePaging constReference - zdefiniowanie liczby referencji
 */
const typePaging constReference = 10;

/*
 * typePaging constSeries - zdefiniowanie liczby serii
 */
const typePaging constSeries = 10;

#endif // CONSTANTSANDTYPES_H

/* constantsandtypes.h */
/********** END_OF_FILE **********/
