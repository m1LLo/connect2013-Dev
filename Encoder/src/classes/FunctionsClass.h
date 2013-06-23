/**
 * Enthaelt alle Funktionen des Encoder-Programms fuer das Consistec
 * Connect2013 Gewinnspiel. Funktionen werden aus:
 * 		-ReadFileClass
 * 		-EncoderClas
 * 		-DecoderClass
 * 		-EncoderCheckClass
 * 		-WriteFileClass
 *
 * 	aufgebaut.
 * 	Klasse lagert die Funktionen/Methoden aus der eigentlichen main aus.
 * 	Objekt wird nie Konstruiert!
 *	
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		FunctionsClass.h
 * @date: 		23.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#ifndef FUNCTIONSCLASS_H_
#define FUNCTIONSCLASS_H_

#include <iostream>
#include "ReadFileClass.h"
#include "WriteFileClass.h"
#include "EncoderClass.h"
#include "EncodingCheckClass.h"
#include "DecoderClass.h"
using namespace std;

/**
 * @author Markus Leitz (3543994)
 * @version 1.0
 * @date 23.06.2013
 */
class FunctionsClass
{
public:

	/**
	 * Verschluesselt den Inhalt einer Eingabedatei und Speichert es in
	 * einer Ausgabedatei
	 *
	 * @param quellDatei		Zu verschluesselende Datei
	 * @param zielDatei		Zu schreibende Datei
	 */
	static void encoden(char* quellDatei, char* zielDatei);

	/**
	 * Entschluesselt analog zu encoden.
	 *
	 * @param quellDatei
	 * @param zielDatei
	 */
	static void decoden(char* quellDatei, char* zielDatei);

	/**
	 * Verschluesselt den Inhalt der Quelldatei und vergleicht ihn mit
	 * dem Inhalt einer Vorlagendatei.
	 *
	 * @param quellDatei
	 * @param vergleichsDatei
	 */
	static void encodenTestenOhneAusgabe(char* quellDatei, char* vergleichsDatei);

	/**
	 * Verschluesselt den Inhalt der Quelldatei und vergleicht ihn mit
	 * dem Inhalt einer Vorlagendatei. Danach wird der verschluesselte
	 * Inhalt in einer Ausgabedatei gespeichert.
	 *
	 * @param quellDatei			Zu verschluesselne Datei
	 * @param zielDatei			Ausgabedatei
	 * @param vergleichsDatei	Vorlagendatei
	 */
	static void encodenTestenMitAusgabe(char* quellDatei, char* zielDatei,
			char* vergleichsDatei);

	/**
	 * Vergleicht zwei Dateien auf Gleichheit.
	 *
	 * @param zuVergleichendeDatei
	 * @param vorlageDatei
	 */
	static void dateienVergleichen(char* zuVergleichendeDatei, char* vorlageDatei);
};

#endif /* FUNCTIONSCLASS_H_ */
