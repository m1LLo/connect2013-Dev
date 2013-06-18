/**
 * Implimentieren der Methoden der Klasse EncodingCheckClass.
 * Klasse vergleicht zwei Strings
 *	
 * @file:		EncodingCheckClass.cpp
 * @date: 		18.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#include "EncodingCheckClass.h"

const char* EncodingCheckClass::STRINGS_NICHT_GLEICHLANG =
		"Strings muessen gleichlang sein zum Vergleichen!";

//Konstruktor
EncodingCheckClass::EncodingCheckClass(string testString,
		string vergleichsString)
{
	//Gleichheit der Strings nur wenn gleichlang und alle Zeichen gleich.
	if (testString.length() == vergleichsString.length()
			&& stringVergleichen(testString, vergleichsString))
	{
		cout << "Dateien sind gleich!" << endl;

	}
	else
	{
		cout << "Dateien sind nicht gleich!" << endl;
	}
}

bool EncodingCheckClass::stringVergleichen(string testString,
		string vergleichsString)
{
	//Nur gleichlange Strings vergleichen
	if (testString.length() != vergleichsString.length())
	{
		throw STRINGS_NICHT_GLEICHLANG;
	}

	for (int i = 0; i < testString.length(); ++i)
	{
		//Ueberpruefung jedes Zeichens auf ungleichheit.
		if(testString[i]!= vergleichsString[i])
		{
			return false;
		}
	}
	return true;
}
