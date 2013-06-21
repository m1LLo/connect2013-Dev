/**
 * TODO
 *	
 * @file:		Encoder.h
 * @date: 		12.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include <string>
#include <iostream>
#include "ReadFileClass.h"
#include "WriteFileClass.h"
#include "EncoderClass.h"
#include "EncodingCheckClass.h"
#include "DecoderClass.h"
using namespace std;

//Fehlermeldungen
const char* KEINE_PARAMETER_UEBERGEBEN = "-Keine Dateien Mitgegeben-";
const char* KEINE_AUSGABE_DATEI_ANGEGEBEN = "-Keine Ausgabedatei angeben-";
const char* ZUVIELE_PARAMETER = "-Zu viele Parameter-";
const char* KEINE_VORLAGEN_DATEI = "-Keine Verlagendatei angeben-";

//Parameter Modi
const char* CHECK_MODUS_PARAMETER = "-c";
const char* DECODER_MODUS_PARAMETER = "-d";
const char* TEST_MODUS_PARAMETER = "-t";
const char* HILFS_MODUS_PARAMETER = "-h";
enum MODUS
{
	ENCODER_MODUS = 0,
	CHECK_MODUS,
	DECODER_MODUS,
	TEST_MODUS1,
	TEST_MODUS2,
	HILFS_MODUS,
};

//Prototyp
int parameterUeberpruefen(int anzahl, char* parameterArray[]);
void encoden(char* quellDatei, char* zielDatei);
void decoden(char* quellDatei, char* zielDatei);
void encodenTestenOhneAusgabe(char* quellDatei, char* vergleichsDatei);
void encodenTestenMitAusgabe(char* quellDatei, char* zielDatei,
		char* vergleichsDatei);
void dateienVergleichen(char* zuVergleichendeDatei, char* vorlageDatei);
void hilfsMenuAusgeben();

#endif /* ENCODER_H_ */
