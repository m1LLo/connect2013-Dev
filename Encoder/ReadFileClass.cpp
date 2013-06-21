/**
 * Deklarationen der Klasse ReadFileClass welche aus einer Quelldatei den
 * Inhalt ausliest und in einem String Attribut speichert.
 *	
 * @file:		ReadFileClass.cpp
 * @date: 		14.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#include "ReadFileClass.h"

const char* ReadFileClass::FEHLER_BEIM_OEFFNEN_DER_DATEI =
		"Datei konnte nicht geoeffnet werden";

//Einziger gueltiger/moeglicher Konstruktor
ReadFileClass::ReadFileClass(char* quelldatei)
{
	ifstream quelle;
	quelle.open(quelldatei);
	if (!quelle)
	{
		throw FEHLER_BEIM_OEFFNEN_DER_DATEI;
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

bool ReadFileClass::stringIstLeer(const ifstream& dateiZuOeffnen) const
{
	//erstes Zeichen gleich EOF
	//if (dateiZuOeffnen.peek() == ifstream::traits_type::eof())
	//{
		return true;
	//}
	return false;
}
