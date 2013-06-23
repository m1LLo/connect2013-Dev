/**
 * Implimentieren der Methoden der Klasse EncodingCheckClass.
 * Klasse vergleicht zwei Strings welche aus zwei Dateien gelesen wurden
 * auf ungleichheit. Wurde keine Ungleichheit gefunden muessen sie
 * logischer gleich sein.
 *
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		EncodingCheckClass.cpp
 * @date: 		18.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#include "EncodingCheckClass.h"

const string EncodingCheckClass::NICHT_GLEICH_LANG =
		"Daten muessen gleichlang sein";
const string EncodingCheckClass::SIND_GLEICH = "Daten sind Gleich";
const string EncodingCheckClass::NICHT_GLEICH = "Daten sind Ungleich";

//Konstruktor
EncodingCheckClass::EncodingCheckClass(string testString,
		string vergleichsString)
{
	//Gleichheit der Strings nur wenn gleichlang und alle Zeichen gleich.
	if (testString.length() == vergleichsString.length()
			&& stringVergleichen(testString, vergleichsString))
	{
		cout << SIND_GLEICH << endl;

	}
	else
	{
		cout << NICHT_GLEICH << endl;
	}
}

bool EncodingCheckClass::stringVergleichen(string testString,
		string vergleichsString)
{
	//Nur gleichlange Strings vergleichen
	if (testString.length() != vergleichsString.length())
	{
		throw logic_error(NICHT_GLEICH_LANG);
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
