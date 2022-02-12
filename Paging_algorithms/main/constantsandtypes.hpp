/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: constantsandtypes.hpp
 */

#ifndef CONSTANTSANDTYPES_HPP
#define CONSTANTSANDTYPES_HPP

using namespace std;

/*
 * enum enumAlgorithms - zdefiniowany typ wyliczeniowy
 * do znormalizowania argumentow potrzebnych do wywolywania
 * wskazanych metod.
 */
enum enumAlgorithms { fifo, lifo, lfu, mfu };



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

#endif // CONSTANTSANDTYPES_HPP

/* constantsandtypes.hpp */
/********** END_OF_FILE **********/
