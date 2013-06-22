/**
 * Deklarationen der Klasse ReadFileClass welche aus einer Quelldatei den
 * Inhalt ausliest und in einem String Attribut speichert.
 *	
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		ReadFileClass.cpp
 * @date: 		14.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#include "ReadFileClass.h"

const string ReadFileClass::DATEI_NICHT_VORHANDEN =
		"Datei nicht gefunden: ";
const string ReadFileClass::DATEI_IST_LEER = "Leere Datei: ";

//Einziger gueltiger/moeglicher Konstruktor
ReadFileClass::ReadFileClass(char* quelldatei)
{
	if (stringIstLeer(quelldatei))
	{
		throw logic_error(DATEI_IST_LEER + quelldatei);
	}

	ifstream quelle;
	quelle.open(quelldatei);
	if (!quelle)
	{
		throw runtime_error(DATEI_NICHT_VORHANDEN + quelldatei);
	}

	string zeile;
	ostringstream gesammt;
	while (getline(quelle, zeile))
	{
		gesammt << zeile << endl;
	}
	this->gelesenerInhalt = gesammt.str();

	quelle.close();
}

bool ReadFileClass::stringIstLeer(const char* dateiZuOeffnen) const
{
	ifstream datei;
	string ersteZeile;

	datei.open(dateiZuOeffnen);
	if (!datei)
	{
		throw runtime_error(DATEI_NICHT_VORHANDEN + dateiZuOeffnen);
	}

	getline(datei, ersteZeile);
	datei.close();
	if (ersteZeile.length() == 0)
	{
		return true;
	}
	//Wenn nicht leer gib false aus!
	return false;
}
