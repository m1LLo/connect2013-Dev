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
	try {
		ReadFileClass lesen(argv[1]);
		DecoderClass decodieren(lesen.getGelesenerInhalt());
		WriteFileClass schreiben(decodieren.getDecodeterString(),argv[2]);

	} catch (const char* e) {
		cout << e;
	}
	//parameterUeberpruefen(argc, argv);

//	//Auffangen der geworfenen Fehler
//	try
//	{
//
//		//Setzt den Programmmodus: 0 Encoden, 1 Vergleichen
//		int modus = 0;
//
//		//ueberpruefen ob ein Modus gesetzt wurde (-c am schluss)
//		if (argc > 3)
//		{
//			if (strcmp(argv[3], "-c") == 0)
//			{
//				/* Auch Fehler werfen falls -c gesetzt wurde aber mehr als
//				 * 3 Parameter gesetzt wurden!
//				 */
//				if (argc > 4)
//				{
//					throw ZUVIELE_PARAMETER;
//				}
//				//Ansonsten setze den Vergleichsmodus
//				modus = 1;
//			}
//			else
//			{
//				throw ZUVIELE_PARAMETER;
//			}
//		}
//
//		if (argc < 2)
//		{
//			throw KEINE_PARAMETER_UEBERGEBEN;
//		}
//		if (argc < 3)
//		{
//			throw KEINE_AUSGABE_DATEI_ANGEGEBEN;
//		}
//
//		//Encoding Modus
//		if (modus == 0)
//		{
//			//Oeffnen der Datei und einlesen des Inhalts
//			ReadFileClass lesen(argv[1]);
//
//			//Encoden des Inhalts
//			EncoderClass encoden(lesen.getGelesenerInhalt());
//
//			//Schreiben in Ausgabedatei
//			WriteFileClass schreiben(encoden.getCodierterString(), argv[2]);
//
//			//Bestaetigung fuer den Nutzer
//			cout << "ENCODEN ERFOLGREICH" << endl;
//		}
//
//		//Vergleichs Modus
//		if (modus == 1)
//		{
//			//Oeffnen der Dateien und einlesen der Inhalte
//			ReadFileClass ersteDatei(argv[1]);
//			ReadFileClass zweiteDatei(argv[2]);
//
//			//Vergleichen der Dateien
//			EncodingCheckClass vergleichen(ersteDatei.getGelesenerInhalt(),
//					zweiteDatei.getGelesenerInhalt());
//		}
//
//	} catch (const char* fehler)
//	{
//		cout << fehler << endl;
//	}

	return 0;
}

int parameterUeberpruefen(int anzahl, char* parameterArray[])
{
	int modus;

	if (anzahl == 4)
	{

		if(strcmp(parameterArray[1], "-c")
		{
			//checkmodus
		}
		if(strcmp(parameterArray[1], "-c")
				{
					//checkmodus
				}


	}

	return modus;
}

void encoden(char* quellDatei, char* zielDatei)
{
}

void decoden(char* quellDatei, char* zielDatei)
{
}

void encodenTesten(char* quellDatei, char* vergleichsDatei)
{
}

void dateienVergleichen(char* zuVergleichendeDatei, char* VorlageDatei)
{
}
