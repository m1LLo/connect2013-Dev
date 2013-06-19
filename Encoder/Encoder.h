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

const char* KEINE_PARAMETER_UEBERGEBEN =
		"Keine Parameter angeben!\n2 Parameter noetig!\nBsp.: Programmname Quelldatei.txt Ausgabedatei.txt";
const char* KEINE_AUSGABE_DATEI_ANGEGEBEN = "Keine Ausgabedatei angeben!";
const char* ZUVIELE_PARAMETER = "Zu viele Parameter.\n2 Parameter noetig!\nBsp.: Programmname Quelldatei.txt Ausgabedatei.txt";

//Prototyp
int parameterUeberpruefen(int anzahl, char* parameterArray[]);
void encoden(char* quellDatei, char* zielDatei);
void decoden(char* quellDatei, char* zielDatei);
void encodenTesten(char* quellDatei,char* vergleichsDatei);
void dateienVergleichen(char* zuVergleichendeDatei,char* VorlageDatei);

#endif /* ENCODER_H_ */
