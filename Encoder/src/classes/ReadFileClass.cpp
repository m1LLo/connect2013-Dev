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
	//Ueberpruefen ob Leere Datei
	if (dateiIstLeer(quelldatei))
	{
		throw logic_error(DATEI_IST_LEER + quelldatei);
	}

	ifstream quelle;
	quelle.open(quelldatei);

	//Testen ob Datei vorhanden
	if (!quelle)
	{
		throw runtime_error(DATEI_NICHT_VORHANDEN + quelldatei);
	}

	string zeile;
	ostringstream gesammt;

	//Zeilenweise Lesen aus Datei und in ostringstream schieben
	while (getline(quelle, zeile))
	{
		gesammt << zeile << endl;
	}

	//gelesener Inhalt in Attribut speichern
	this->gelesenerInhalt = gesammt.str();

	quelle.close();
}

//Ueberpruefen ob Datei leer ist
bool ReadFileClass::dateiIstLeer(const char* dateiZuOeffnen) const
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
