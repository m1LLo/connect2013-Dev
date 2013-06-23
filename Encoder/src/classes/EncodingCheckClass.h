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
using namespace std;

/**
 * @author Markus Leitz (3543994)
 * @version
 * @date 18.06.2013
 */
class EncodingCheckClass
{
public:
	static const char* STRINGS_NICHT_GLEICHLANG;
	EncodingCheckClass(string testString, string vergleichsString);

	bool stringVergleichen(string testString, string vergleichsString);
};

#endif /* ENCODINGCHECKCLASS_H_ */
