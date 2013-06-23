/**
 * Definitionen der Methoden der Klasse FunctionsClass.
 * Stellt die Funktionen fuer das Encoder-Projekt bereit.
 * Lagert die Funktionen aus der main aus.
 *	
 * @file:		FunctionsClass.cpp
 * @date: 		23.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#include "FunctionsClass.h"


void FunctionsClass::encoden(char* quellDatei, char* zielDatei)
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

void FunctionsClass::decoden(char* quellDatei, char* zielDatei)
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

void FunctionsClass::encodenTestenOhneAusgabe(char* quellDatei, char* vergleichsDatei)
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

void FunctionsClass::encodenTestenMitAusgabe(char* quellDatei, char* zielDatei,
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

void FunctionsClass::dateienVergleichen(char* zuVergleichendeDatei, char* vorlageDatei)
{
	//zuvergleichende Datei einlesen
	ReadFileClass zuVergleichen(zuVergleichendeDatei);

	//Vorlagendatei einlesen
	ReadFileClass vorlage(vorlageDatei);

	//Klasse gibt ueber cout aus ob Datei gleich oder nicht
	EncodingCheckClass checken(zuVergleichen.getGelesenerInhalt(),
			vorlage.getGelesenerInhalt());

}
