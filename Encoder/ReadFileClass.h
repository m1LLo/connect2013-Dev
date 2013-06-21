/**
 * Klasse liest eine uebergebene Datei ein und Speichert deren Inhalt in
 * einem String.
 * Der Pfad der Quelle muss als Pointer auf Char uebergeben werden!
 * Zugriff auf gelesenen Inhalt ueber GET-Methode.
 * KEINE toString Methode notwendig da Attribut ein String ist.
 * KEINE Destruktor Methode da nur Standard-Datentypen destruiert werden.
 *
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		ReadFileClass.h
 * @date: 		14.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#ifndef READFILECLASS_H_
#define READFILECLASS_H_

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

/**
 * @author Markus Leitz (3543994)
 * @version
 * @date 14.06.2013
 */
class ReadFileClass
{
public:
	//Fehlermeldungen
	static const char* FEHLER_BEIM_OEFFNEN_DER_DATEI;

	/**
	 * Standard Konstruktor. Ist der einzig Moegliche.
	 *
	 * @param quelldatei		Pfad der Quelldatei als Char
	 */
	ReadFileClass(char* quelldatei);

	bool stringIstLeer(const ifstream& zuUntersuchenderString) const;

	/**
	 * GET-Methode zum Auslesen des Inhalts fuer andere Objekte.
	 * Somit wird FRIEND unnoetig und der Inhalt ist trotzdem nicht
	 * veraenderbar.
	 *
	 * @return		Gibt String zurueck des Inhalts der Quelldatei
	 */
	const string& getGelesenerInhalt() const
	{
		return gelesenerInhalt;
	}

private:

	//Inhalt der gelesenen Datei
	string gelesenerInhalt;
};

#endif /* READFILECLASS_H_ */
