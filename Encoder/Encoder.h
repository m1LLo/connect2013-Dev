/**
 * Includes & Konstanten fuer Encoder.cpp
 *	
 * Project:		Consistec Connect2013 Gewinnspiel
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
#include "ParameterCheckClass.h"
using namespace std;

//Prototyp
void encoden(char* quellDatei, char* zielDatei);
void decoden(char* quellDatei, char* zielDatei);
void encodenTestenOhneAusgabe(char* quellDatei, char* vergleichsDatei);
void encodenTestenMitAusgabe(char* quellDatei, char* zielDatei,
		char* vergleichsDatei);
void dateienVergleichen(char* zuVergleichendeDatei, char* vorlageDatei);

#endif /* ENCODER_H_ */
