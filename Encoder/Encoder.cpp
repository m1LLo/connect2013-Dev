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
		int modus;
		modus = parameterUeberpruefen(argc, argv);

		//ueberprueft die von main uebergeben Parameter
		switch (modus)
		{
		case ENCODER_MODUS:
			encoden(argv[1], argv[2]);
			break;

		case CHECK_MODUS:
			dateienVergleichen(argv[2], argv[3]);
			break;

		case DECODER_MODUS:
			decoden(argv[2], argv[3]);
			break;

		case TEST_MODUS1:
			encodenTestenOhneAusgabe(argv[2], argv[3]);
			break;

		case TEST_MODUS2:
			encodenTestenMitAusgabe(argv[2], argv[3], argv[4]);
			break;

		case HILFS_MODUS:
			hilfsMenuAusgeben();
			break;
		}

	} catch (const char* fehler)
	{
		cout << fehler << endl;
	}

	return 0;
}

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
int parameterUeberpruefen(int anzahl, char* parameterArray[])
{
	//Standard Encoder Modus!
	int modus = 0;

	//Falls garkeine Parameter uebergeben wurden
	if (anzahl == 1)
	{
		throw KEINE_PARAMETER_UEBERGEBEN;
	}

	if (anzahl > 5)
	{
		throw ZUVIELE_PARAMETER;
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
				throw KEINE_VORLAGEN_DATEI;
			}
			if (anzahl == 2)
			{
				throw KEINE_PARAMETER_UEBERGEBEN;
			}
			modus = CHECK_MODUS;
			return modus;
		}
	}

	//setzt den DecoderModus
	if (strcmp(parameterArray[1], DECODER_MODUS_PARAMETER) == 0)
	{
		if (anzahl > 4)
		{
			throw ZUVIELE_PARAMETER;
		}
		if (anzahl == 3)
		{
			throw KEINE_AUSGABE_DATEI_ANGEGEBEN;
		}
		if (anzahl == 2)
		{
			throw KEINE_PARAMETER_UEBERGEBEN;
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
			throw KEINE_VORLAGEN_DATEI;
		}

		if (anzahl == 2)
		{
			throw KEINE_PARAMETER_UEBERGEBEN;
		}

		return modus;
	}

	//Wenn bis hier kein Modus gesetz wurde ist der Modus Encoder
	if (anzahl == 2)
	{
		throw KEINE_AUSGABE_DATEI_ANGEGEBEN;
	}
	if (anzahl == 1)
	{
		throw KEINE_PARAMETER_UEBERGEBEN;
	}

	return modus;
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
//Dateien einlesen
	ReadFileClass zuVergleichen(zuVergleichendeDatei);
	ReadFileClass vorlage(vorlageDatei);

//Klasse gibt ueber cout aus ob Datei gleich oder nicht
	EncodingCheckClass checken(zuVergleichen.getGelesenerInhalt(),
			vorlage.getGelesenerInhalt());
}

void hilfsMenuAusgeben()
{
	cout << "HILFSMENU" << endl;
}
