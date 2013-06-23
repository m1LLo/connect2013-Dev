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
 * Project:		Consistec Connect2013 Gewinnspiel
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
		//Programmmodus 0 fuer Encoder
		int modus;
		modus = ParameterCheckClass::parameterUeberpruefen(argc, argv);

		//ueberprueft die von main uebergeben Parameter
		switch (modus)
		{
		case ParameterCheckClass::ENCODER_MODUS:
			FunctionsClass::encoden(argv[1], argv[2]);
			break;

		case ParameterCheckClass::CHECK_MODUS:
			FunctionsClass::dateienVergleichen(argv[2], argv[3]);
			break;

		case ParameterCheckClass::DECODER_MODUS:
			FunctionsClass::decoden(argv[2], argv[3]);
			break;

		case ParameterCheckClass::TEST_MODUS1:
			FunctionsClass::encodenTestenOhneAusgabe(argv[2], argv[3]);
			break;

		case ParameterCheckClass::TEST_MODUS2:
			FunctionsClass::encodenTestenMitAusgabe(argv[2], argv[3], argv[4]);
			break;

		case ParameterCheckClass::HILFS_MODUS:
			cout << ParameterCheckClass::hilfsMenuAusgeben();
			break;
		}

	}
	//Faengt Standard Exceptions
	catch (const exception& error)
	{
		cout << error.what() << endl;

	}
	//Alle Unvohergesehen Fehler werden hier gefangen
	catch (...)
	{
		cout << UNBEKANNTER_FEHLER << endl;
	}
	return 0;
}

