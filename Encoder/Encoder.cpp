/**
 * Kodierungsprogramm liest eine .txt Datei ein und veraendert die Zeichen
 * nach dem vorgegeben Muster.
 * Kleinbuchstaben: 	a-k werden um 2 erhoeht
 * 					p-z werden um 2 verringert
 * 					l=a, m=b,n=y,o=z
 * Grossbuchstaben:	B-M werden um 1 verringert
 * 					N-Y werden um 1 erhoeht
 * 					A=M, Z=N
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

		int modus;
		modus = ParameterCheckClass::parameterUeberpruefen(argc, argv);

		//ueberprueft die von main uebergeben Parameter
		switch (modus)
		{
		case ParameterCheckClass::ENCODER_MODUS:
			encoden(argv[1], argv[2]);
			break;

		case ParameterCheckClass::CHECK_MODUS:
			dateienVergleichen(argv[2], argv[3]);
			break;

		case ParameterCheckClass::DECODER_MODUS:
			decoden(argv[2], argv[3]);
			break;

		case ParameterCheckClass::TEST_MODUS1:
			encodenTestenOhneAusgabe(argv[2], argv[3]);
			break;

		case ParameterCheckClass::TEST_MODUS2:
			encodenTestenMitAusgabe(argv[2], argv[3], argv[4]);
			break;

		case ParameterCheckClass::HILFS_MODUS:
			ParameterCheckClass::hilfsMenuAusgeben();
			break;
		}

	} catch (const runtime_error& rError)
	{
		cout << rError.what() << endl;

	} catch (const logic_error& lError)
	{
		cout << lError.what() << endl;
	} catch (const exception& otherErrors)
	{
		cout << otherErrors.what() << endl;
	}
	return 0;
}

void encoden(char* quellDatei, char* zielDatei)
{
//Oeffnen der Datei und einlesen des Inhalts
	ReadFileClass lesen(quellDatei);

//Encoden des Inhalts
	EncoderClass encoden(lesen.getGelesenerInhalt());

//Schreiben in Ausgabedatei
	WriteFileClass schreiben(encoden.getCodierterString(), zielDatei);

//Bestaetigung fuer den Nutzer
	cout << "ENCODEN ERFOLGREICH" << endl;
}

void decoden(char* quellDatei, char* zielDatei)
{
//Oeffnen der Datei und einlesen des Inhalts
	ReadFileClass lesen(quellDatei);

//Decoden des Inhalts
	DecoderClass decoden(lesen.getGelesenerInhalt());

//Schreiben in Ausgabedatei
	WriteFileClass schreiben(decoden.getDecodeterString(), zielDatei);

//Decoden erfolgreich wenn voher kein Fehler geworden wurde
	cout << "DECODEN ERFOLGREICH" << endl;

}

void encodenTestenOhneAusgabe(char* quellDatei, char* vergleichsDatei)
{
	//Oeffnen der Quelldatei und einlesen des Inhalts
	ReadFileClass quelle(quellDatei);

	//Oeffnen der Vergleichsdatei
	ReadFileClass vergleichDatei(vergleichsDatei);

	//Encoden des Inhalts
	EncoderClass encoden(quelle.getGelesenerInhalt());

	//Klasse gibt ueber cout aus ob Dateien gleich oder nicht!
	EncodingCheckClass checken(encoden.getCodierterString(),
			vergleichDatei.getGelesenerInhalt());
}

void encodenTestenMitAusgabe(char* quellDatei, char* zielDatei,
		char* vergleichsDatei)
{
	//Oeffnen der Quelldatei und einlesen des Inhalts
	ReadFileClass quelle(quellDatei);

	//Oeffnen der Vergleichsdatei
	ReadFileClass vergleichDatei(vergleichsDatei);

	//Encoden des Inhalts
	EncoderClass encoden(quelle.getGelesenerInhalt());

	//Klasse gibt ueber cout aus ob Dateien gleich oder nicht!
	EncodingCheckClass checken(encoden.getCodierterString(),
			vergleichDatei.getGelesenerInhalt());

	//Decodeten Inhalt schreiben
	WriteFileClass schreiben(encoden.getCodierterString(), zielDatei);
}

void dateienVergleichen(char* zuVergleichendeDatei, char* vorlageDatei)
{
	//zuvergleichende Datei einlesen
	ReadFileClass zuVergleichen(zuVergleichendeDatei);

	//Vorlagendatei einlesen
	ReadFileClass vorlage(vorlageDatei);

	//Klasse gibt ueber cout aus ob Datei gleich oder nicht
	EncodingCheckClass checken(zuVergleichen.getGelesenerInhalt(),
			vorlage.getGelesenerInhalt());

}
