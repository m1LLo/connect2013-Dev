/**
 * Kodierungsprogramm liest eine .txt Datei ein und veraendert die Zeichen
 * nach dem vorgegeben Muster.
 * Kleinbuchstaben: 	a-k werden um 2 erhoeht
 * 					p-z werden um 2 verringert
 * 					l=a, m=b,n=y,o=z
 * Grossbuchstaben:	B-M werden um 1 verringert
 * 					N-Y werden um 1 erhoeht
 * 					A=M, Z=N
 *
 * Programmaufrufe: Encode Modus:
 * 					programmname quelldatei zeildatei
 *
 * 					Vergleichs Modus: (-c hinter den Dateien!)
 * 					programmname datei1 datei2 -c
 *
 *	
 * @file:		Encoder.cpp
 * @date: 		12.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#include "Encoder.h"

//int argc = Anzahl Parameter
//char* argv[] = Die einzelnen Parameter in Array
//char* argv[0] ist immer der Name des Programms!
int main(int argc, char* argv[])
{

	//Auffangen der geworfenen Fehler
	try
	{
		//Ueberpruefung auf Fehleingaben des Benutzers
		if (argc < 2)
		{
			throw KEINE_PARAMETER_UEBERGEBEN;
		}
		if (argc < 3)
		{
			throw KEINE_AUSGABE_DATEI_ANGEGEBEN;
		}

		//Werfe immer einen Fehler wenn mehr als 3 Parameter uebergeben
		if (argc > 4)
		{
			throw ZUVIELE_PARAMETER;
		}

		if (argc > 3)
		{
			/* Startet den Vergleichsmodus um Verschluesslung mit Vorlage
			 * zu vergleichen.
			 */
			if (strcmp(argv[3], "-c") == 0)
			{

				//Auslesen beider Dateien
				ReadFileClass ersteDatei(argv[1]);
				ReadFileClass zweiteDatei(argv[2]);

				EncodingCheckClass vergleichen(ersteDatei.getGelesenerInhalt(),
						zweiteDatei.getGelesenerInhalt());
			}
			else
			{
				throw ZUVIELE_PARAMETER;
			}

		}

		ReadFileClass lesen(argv[1]);
		EncoderClass encoden(lesen.getGelesenerInhalt());
		WriteFileClass schreiben(encoden.getCodierterString(), argv[2]);

	} catch (const char* fehler)
	{
		cout << fehler << endl;
	}

	return 0;
}

