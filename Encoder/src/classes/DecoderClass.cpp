/**
 * Mehtoden- und Konstantendefinition der Klasse DecoderClass.
 * Klasse entschluesselt einen verschluesselten String und speichert es
 * enschluesselt in einem String als Klassenattribut.
 *	
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		DecoderClass.cpp
 * @date: 		19.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#include "DecoderClass.h"

//Konstanten fuer Fallunterscheidung Gross- Kleinbuchstabe. ASCII Tabelle
const int DecoderClass::GROSS_BUCHSTABE_A = 65;
const int DecoderClass::GROSS_BUCHSTABE_B = 66;
const int DecoderClass::GROSS_BUCHSTABE_L = 76;
const int DecoderClass::GROSS_BUCHSTABE_M = 77;
const int DecoderClass::GROSS_BUCHSTABE_N = 78;
const int DecoderClass::GROSS_BUCHSTABE_O = 79;
const int DecoderClass::GROSS_BUCHSTABE_Z = 90;

const int DecoderClass::KLEIN_BUCHSTABE_A = 97;
const int DecoderClass::KLEIN_BUCHSTABE_B = 98;
const int DecoderClass::KLEIN_BUCHSTABE_C = 99;
const int DecoderClass::KLEIN_BUCHSTABE_M = 109;
const int DecoderClass::KLEIN_BUCHSTABE_N = 110;
const int DecoderClass::KLEIN_BUCHSTABE_X = 120;
const int DecoderClass::KLEIN_BUCHSTABE_Y = 121;
const int DecoderClass::KLEIN_BUCHSTABE_Z = 122;

//Konstruktor
DecoderClass::DecoderClass(string zuDecodenderString)
{
	//Uebergebenen String Decodieren
	stringDecoden(zuDecodenderString);
}

void DecoderClass::stringDecoden(string zuDecodenderString)
{
	//aktuelle untersuchtes Zeichen.
	int aktuellesZeichenAlsInt;
	char aktuellesZeichenDecodet;

	//Speichert den Entschluesselten String bevor er im Attribut gespeichert wird
	ostringstream buffer;

	//Laeuft den ganzen String Zeichen fuer Zeichen ab
	for (int i = 0; i < zuDecodenderString.length(); ++i)
	{
		//Vorbelegen! Falls das Zeichen nicht veraendert wird = original
		aktuellesZeichenDecodet = zuDecodenderString[i];
		aktuellesZeichenAlsInt = static_cast<int>(zuDecodenderString[i]);

		//Pruefen ob Grossbuchstabe
		if (aktuellesZeichenAlsInt >= GROSS_BUCHSTABE_A
				&& aktuellesZeichenAlsInt <= GROSS_BUCHSTABE_Z)
		{
			//Decodieren des Zeichens
			aktuellesZeichenDecodet = grossBuchStabeDecoden(
					aktuellesZeichenAlsInt);
		}

		//Pruefen ob Kleinbuchstabe
		if (aktuellesZeichenAlsInt >= KLEIN_BUCHSTABE_A
				&& aktuellesZeichenAlsInt <= KLEIN_BUCHSTABE_Z)
		{
			//Decodieren
			aktuellesZeichenDecodet = kleinBuchStabeDecoden(
					aktuellesZeichenAlsInt);
		}
		//in buffer schieben
		buffer << aktuellesZeichenDecodet;
	}
	//Nachdem der String fertig untersucht ist wir in Attribut gespeichert
	this->decodeterString = buffer.str();
}

char DecoderClass::grossBuchStabeDecoden(char charZuDecoden)
{
	char decodeterBuchstabe;
	int charAlsInt = static_cast<int>(charZuDecoden);

	//Buchstaben zwischen A-L um 1 erhoehen
	if (charAlsInt >= GROSS_BUCHSTABE_A && charZuDecoden <= GROSS_BUCHSTABE_L)
	{
		decodeterBuchstabe = static_cast<char>(charAlsInt + 1);
	}

	//Buchstaben zwischen O-Z um 1 verringern
	if (charAlsInt >= GROSS_BUCHSTABE_O && charAlsInt <= GROSS_BUCHSTABE_Z)
	{
		decodeterBuchstabe = static_cast<char>(charAlsInt - 1);
	}

	//Sonderfaelle fuer M & N
	switch (charAlsInt)
	{
	case GROSS_BUCHSTABE_M:
		decodeterBuchstabe = 'A';
		break;
	case GROSS_BUCHSTABE_N:
		decodeterBuchstabe = 'Z';
		break;
	default:	 //Ansonsten mache nichts.
		break;
	}

	return decodeterBuchstabe;
}

char DecoderClass::kleinBuchStabeDecoden(char charZuDecoden)
{
	char decodeterBuchstabe;
	int charAlsInt = static_cast<int>(charZuDecoden);

	//Buchstaben von c-m um 2 verringern
	if (charAlsInt >= KLEIN_BUCHSTABE_C && charAlsInt <= KLEIN_BUCHSTABE_M)
	{
		decodeterBuchstabe = static_cast<char>(charAlsInt - 2);
	}
	//Buchstaben von n-x um 2 erhoehen
	if (charAlsInt >= KLEIN_BUCHSTABE_N && charAlsInt <= KLEIN_BUCHSTABE_X)
	{
		decodeterBuchstabe = static_cast<char>(charAlsInt + 2);
	}

	//Sonderregelung fuer a=l,b=m,y=n,z=o . Waere auch mit +/- 11 moeglich.
	switch (charAlsInt)
	{
	case KLEIN_BUCHSTABE_A:
		decodeterBuchstabe = 'l';
		break;
	case KLEIN_BUCHSTABE_B:
		decodeterBuchstabe = 'm';
		break;
	case KLEIN_BUCHSTABE_Y:
		decodeterBuchstabe = 'n';
		break;
	case KLEIN_BUCHSTABE_Z:
		decodeterBuchstabe = 'o';
		break;
	default:		//nichts passiert
		break;
	}

	return decodeterBuchstabe;
}
