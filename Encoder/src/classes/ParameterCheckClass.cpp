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
		"Keine Dateien Mitgegeben\n";
const string ParameterCheckClass::KEINE_AUSGABE_DATEI_ANGEGEBEN =
		"Keine Ausgabedatei angeben\n";
const string ParameterCheckClass::ZUVIELE_PARAMETER = "Zu viele Parameter\n";
const string ParameterCheckClass::KEINE_VORLAGEN_DATEI =
		"Keine Verlagendatei angeben\n";

//Benutzerinfo Aufrufe
const string ParameterCheckClass::ENCODER_AUFRUF =
		"Encoder:\t[PROGRAMMNAME] [QUELLDATEI] [ZIELDATEI]\n";
const string ParameterCheckClass::DECODER_AUFRUF =
		"Decoder:\t[PROGRAMMNAME] -d [QUELLDATEI] [ZIELDATEI]\n";
const string ParameterCheckClass::ENCODER_TEST_EINS_AUFRUF =
		"Encoder Test:\t[PROGRAMMNAME] -t [QUELLDATEI] [VORLAGENDATEI]\n";
const string ParameterCheckClass::ENCODER_TEST_ZWEI_AUFRUF =
		"Encoder Test:\t[PROGRAMMNAME] -t [QUELLDATEI] [ZIELDATEI] [VORLAGENDATEI]\n";
const string ParameterCheckClass::CHECK_AUFRUF =
		"Checkmodus:\t[PROGRAMMNAME] -c [VERGLEICHSDATEI] [VORLAGENDATEI]\n";

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
		throw logic_error(KEINE_PARAMETER_UEBERGEBEN + ENCODER_AUFRUF);
	}

	if (anzahl > 5)
	{
		throw logic_error(ZUVIELE_PARAMETER + ENCODER_AUFRUF);
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
				throw logic_error(KEINE_VORLAGEN_DATEI + CHECK_AUFRUF);
			}
			if (anzahl == 2)
			{
				throw logic_error(KEINE_PARAMETER_UEBERGEBEN + CHECK_AUFRUF);
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
			throw logic_error(ZUVIELE_PARAMETER + DECODER_AUFRUF);
		}

		if (anzahl == 3)
		{
			throw logic_error(KEINE_AUSGABE_DATEI_ANGEGEBEN + DECODER_AUFRUF);
		}

		if (anzahl == 2)
		{
			throw logic_error(KEINE_PARAMETER_UEBERGEBEN + DECODER_AUFRUF);
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
			throw logic_error(
					KEINE_VORLAGEN_DATEI + ENCODER_TEST_EINS_AUFRUF
							+ ENCODER_TEST_ZWEI_AUFRUF);
		}

		if (anzahl == 2)
		{
			throw logic_error(
					KEINE_PARAMETER_UEBERGEBEN + ENCODER_TEST_EINS_AUFRUF
							+ ENCODER_TEST_ZWEI_AUFRUF);
		}

		return modus;
	}

	//Wenn bis hier kein Modus gesetz wurde ist der Modus Encoder
	if (anzahl > 3)
	{
		throw logic_error(ZUVIELE_PARAMETER + ENCODER_AUFRUF);
	}

	if (anzahl == 2)
	{
		throw logic_error(KEINE_AUSGABE_DATEI_ANGEGEBEN + ENCODER_AUFRUF);
	}

	if (anzahl == 1)
	{
		throw logic_error(KEINE_PARAMETER_UEBERGEBEN + hilfsMenuAusgeben());
	}

	return modus;
}

string ParameterCheckClass::hilfsMenuAusgeben()
{
	ostringstream buffer;

	buffer << endl;
	buffer << "---------HILFSMENU---------" << endl;
	buffer << ENCODER_AUFRUF;
	buffer << DECODER_AUFRUF;
	buffer << ENCODER_TEST_EINS_AUFRUF;
	buffer << ENCODER_TEST_ZWEI_AUFRUF;
	buffer << CHECK_AUFRUF;
	buffer << endl;

	return buffer.str();
}
