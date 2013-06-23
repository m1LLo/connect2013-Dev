/**
 * Klasse vergleicht die encodete Datei mit einer Vorlagen Datei auf richtige
 * verschluesselung.
 *	
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		EncodingCheckClass.h
 * @date: 		18.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#ifndef ENCODINGCHECKCLASS_H_
#define ENCODINGCHECKCLASS_H_

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * @author Markus Leitz (3543994)
 * @version
 * @date 18.06.2013
 */
class EncodingCheckClass
{
public:
	//Fehlermeldungen
	static const string NICHT_GLEICH_LANG;
	static const string SIND_GLEICH;
	static const string NICHT_GLEICH;

	/**
	 * Konstruktor vergleicht die beiden Strings auf Gleichheit.
	 *
	 * @param testString			der zu Vergleichede String
	 * @param vergleichsString	der Vorlagen String
	 */
	EncodingCheckClass(string testString, string vergleichsString);

	/**
	 * Vergleicht zwei Strings auf Gleichheit
	 *
	 * @param testString			Der zu testende String
	 * @param vergleichsString	Vorlagen String
	 * @return
	 */
	bool stringVergleichen(string testString, string vergleichsString);
};

#endif /* ENCODINGCHECKCLASS_H_ */
