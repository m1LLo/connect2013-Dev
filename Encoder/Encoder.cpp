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

	//Auffangen der geworfenen Fehler
	try
	{
		//argc ist immer mindestens 1!
		if (argc >3)
		{
			throw ZUVIELE_PARAMETER;
		}
		if (argc < 2)
		{
			throw KEINE_PARAMETER_UEBERGEBEN;
		}
		if (argc < 3)
		{
			throw KEINE_AUSGABE_DATEI_ANGEGEBEN;
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

