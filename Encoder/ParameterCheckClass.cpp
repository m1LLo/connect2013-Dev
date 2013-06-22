/**
 * Klasse kontrolliert die Parameter die der Main uebergeben wurden.
 * Klasse ist nur fuer das Encoderprojekt Connect 2013 von Consistec
 * gueltig. Gueltige Parameter sind:
 * 	-h											(HILFMENU AUSGEBEN)
 * 	-c [VERGLEICHSDATEI][VORLAGENDATEI]			(Zwei Dateien vergleichen)
 * 	-d [QUELLDATEI][ZIELDATEI]					(Datei entschluesseln)
 * 	-t [QUELLDATEI][VORLAGENDATEI]				(Encoder Testen mit Vorlagendatei)
 * 	-t [QUELLDATEI][ZIELDATEI][VORLAGENDATEI]	(Encoder Testen mit Vorlagendatei &
 * 												Schreiben in Ausgabedatei)
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		ParameterCheckClass.cpp
 * @date: 		21.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#include "ParameterCheckClass.h"

//Fehlermeldungen fuer ParameterCheck
const string ParameterCheckClass::KEINE_PARAMETER_UEBERGEBEN =
		"-Keine Dateien Mitgegeben-";
const string ParameterCheckClass::KEINE_AUSGABE_DATEI_ANGEGEBEN =
		"-Keine Ausgabedatei angeben-";
const string ParameterCheckClass::ZUVIELE_PARAMETER = "-Zu viele Parameter-";
const string ParameterCheckClass::KEINE_VORLAGEN_DATEI =
		"-Keine Verlagendatei angeben-";

//Parameter Modi
const char* ParameterCheckClass::CHECK_MODUS_PARAMETER = "-c";
const char* ParameterCheckClass::DECODER_MODUS_PARAMETER = "-d";
const char* ParameterCheckClass::TEST_MODUS_PARAMETER = "-t";
const char* ParameterCheckClass::HILFS_MODUS_PARAMETER = "-h";

int ParameterCheckClass::parameterUeberpruefen(int anzahl,
		char* parameterArray[])
{
	//Standard Encoder Modus!
	int modus = 0;

	//Falls garkeine Parameter uebergeben wurden
	if (anzahl == 1)
	{
		throw logic_error(KEINE_PARAMETER_UEBERGEBEN);
	}

	if (anzahl > 5)
	{
		throw logic_error(ZUVIELE_PARAMETER);
	}

	//Gibt das Hilfsmenu aus
	if (strcmp(parameterArray[1], HILFS_MODUS_PARAMETER) == 0)
	{
		modus = HILFS_MODUS;
		return modus;
	}

	//Setzt den Checkmodus
	if (strcmp(parameterArray[1], CHECK_MODUS_PARAMETER) == 0)
	{
		if (anzahl < 4)
		{
			if (anzahl == 3)
			{
				throw logic_error(KEINE_VORLAGEN_DATEI);
			}
			if (anzahl == 2)
			{
				throw logic_error(KEINE_PARAMETER_UEBERGEBEN);
			}
		}
		// anzahl > 5 bereits oben abgefangen!
		modus = CHECK_MODUS;
		return modus;
	}

	//setzt den DecoderModus
	if (strcmp(parameterArray[1], DECODER_MODUS_PARAMETER) == 0)
	{
		if (anzahl > 4)
		{
			throw logic_error(ZUVIELE_PARAMETER);
		}
		if (anzahl == 3)
		{
			throw logic_error(KEINE_AUSGABE_DATEI_ANGEGEBEN);
		}
		if (anzahl == 2)
		{
			throw logic_error(KEINE_PARAMETER_UEBERGEBEN);
		}
		modus = DECODER_MODUS;
		return modus;
	}

	//TESTMODUS erkennen
	if (strcmp(parameterArray[1], TEST_MODUS_PARAMETER) == 0)
	{
		if (anzahl == 4)
		{
			modus = TEST_MODUS1;
			return modus;
		}

		if (anzahl == 5)
		{
			modus = TEST_MODUS2;
			return modus;
		}

		if (anzahl == 3)
		{
			throw logic_error(KEINE_VORLAGEN_DATEI);
		}

		if (anzahl == 2)
		{
			throw logic_error(KEINE_PARAMETER_UEBERGEBEN);
		}

		return modus;
	}

	//Wenn bis hier kein Modus gesetz wurde ist der Modus Encoder
	if (anzahl == 2)
	{
		throw logic_error(KEINE_AUSGABE_DATEI_ANGEGEBEN);
	}
	if (anzahl == 1)
	{
		throw logic_error(KEINE_PARAMETER_UEBERGEBEN);
	}

	return modus;
}

void ParameterCheckClass::hilfsMenuAusgeben()
{
	cout << "HILFSMENU" << endl;
}
