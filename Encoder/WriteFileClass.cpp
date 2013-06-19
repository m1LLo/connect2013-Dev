/**
 * Methoden- und Konstantendeklaration der Methoden der Klasse
 * WriteFileClass. Schreibt einen String in eine Zieldatei.
 *
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		WriteFileClass.cpp
 * @date: 		14.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#include "WriteFileClass.h"

const char* WriteFileClass::FEHLER_BEI_SCHREIBEN_IN_DATEI = "Fehler bei Schreiben in Datei!";

WriteFileClass::WriteFileClass(string zuSchreibenderInhalt, char* zielDatei)
{
	ofstream ziel;
	ziel.open(zielDatei);

	if (!ziel)
	{
		throw FEHLER_BEI_SCHREIBEN_IN_DATEI;
	}

	ziel << zuSchreibenderInhalt;

	ziel.close();
}
