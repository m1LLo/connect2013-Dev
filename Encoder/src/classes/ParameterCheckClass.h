/**
 * Diese Klasse kontrolliert Parameter auf Eingabefehler fuer das
 * Encoder-Projekt des Consistec Connect 2013 Gewinnspiels.
 * Setzt die verschiedenen Modi:
 * 	-h											(HILFMENU AUSGEBEN)
 * 	-c [VERGLEICHSDATEI][VORLAGENDATEI]			(Zwei Dateien vergleichen)
 * 	-d [QUELLDATEI][ZIELDATEI]					(Datei entschluesseln)
 * 	-t [QUELLDATEI][VORLAGENDATEI]				(Encoder Testen mit Vorlagendatei)
 * 	-t [QUELLDATEI][ZIELDATEI][VORLAGENDATEI]	(Encoder Testen mit Vorlagendatei &
 * 												Schreiben in Ausgabedatei)
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		ParameterCheckClass.h
 * @date: 		21.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#ifndef PARAMETERCHECKCLASS_H_
#define PARAMETERCHECKCLASS_H_

#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * @author Markus Leitz (3543994)
 * @version
 * @date 21.06.2013
 */
class ParameterCheckClass
{
public:

	//Fehlermeldungen
	static const string KEINE_PARAMETER_UEBERGEBEN;
	static const string KEINE_AUSGABE_DATEI_ANGEGEBEN;
	static const string ZUVIELE_PARAMETER;
	static const string KEINE_VORLAGEN_DATEI;

	//Benutzerausgabe fuer Aufrufe
	static const string ENCODER_AUFRUF;
	static const string DECODER_AUFRUF;
	static const string ENCODER_TEST_EINS_AUFRUF;
	static const string ENCODER_TEST_ZWEI_AUFRUF;
	static const string CHECK_AUFRUF;

	//Parameter Modi
	static const char* CHECK_MODUS_PARAMETER;
	static const char* DECODER_MODUS_PARAMETER;
	static const char* TEST_MODUS_PARAMETER;
	static const char* HILFS_MODUS_PARAMETER;

	//Int Werte fuer Modi
	enum MODUS
	{
		ENCODER_MODUS = 0,
		CHECK_MODUS,
		DECODER_MODUS,
		TEST_MODUS1,
		TEST_MODUS2,
		HILFS_MODUS,
	};

	/**
	 * Funktion ueberprueft die von der main uebergeben Parameter auf Fehler
	 * und setzt den vom Benutzer gewaehlten Modus.
	 * Modi:	-Encoding:	0	(Datei verschluesseln)
	 * 		-Check:		1		(Vergleichen zweier verschluesselter Dateien)
	 * 		-Decoding:	2	(Datei entschluesseln)
	 * 		-Testmodus:	3	(Testet ob die Verschluesselung richtig funktioniert)
	 *					4	(Testen mit Ausgabedatei)
	 *
	 * @param anzahl				Anzahl der uebergeben Parameter
	 * @param parameterArray		Char* Array mit einzelen Parametern
	 * @return					Modus als Int
	 */
	static int parameterUeberpruefen(int anzahl, char* parameterArray[]);

	/**
	 * Gibt eine Hilfmenu aus um den Benutzer ueber alle Funktionen zu
	 * informieren.
	 *
	 * @return		String mit moeglichen Funktionen
	 */
	static string hilfsMenuAusgeben();
};

#endif /* PARAMETERCHECKCLASS_H_ */
