/**
 * Klasse schreibt einen uebergeben String in eine angebene Datei.
 * Benoetigt werden der String und der Name der Zieldatei.
 *	
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		WriteFileClass.h
 * @date: 		14.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#ifndef WRITEFILECLASS_H_
#define WRITEFILECLASS_H_

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * @author Markus Leitz (3543994)
 * @version 1.0
 * @date 14.06.2013
 */
class WriteFileClass
{
public:

	//Fehlermeldungen
	static const string FEHLER_BEI_SCHREIBEN_IN_DATEI;

	/**
	 * Erstell ein Objekt der Klasse WriteFileClass und schreibt den ueber-
	 * gebenen Inhalt in die uebergebene Datei.
	 *
	 * @param zuSchreibenderInhalt		Inhalt der geschrieben werden soll
	 * @param zielDatei					Datei in die geschreiben wird
	 */
	WriteFileClass(string zuSchreibenderInhalt, char* zielDatei);
};

#endif /* WRITEFILECLASS_H_ */
