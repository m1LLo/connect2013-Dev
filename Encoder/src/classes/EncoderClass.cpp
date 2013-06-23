/**
 * Implementierung der Methoden der Klasse EncoderClass.
 * Aufgabe ist das Verschluesseln eines Strings und das Speichern des
 * verschluesselten Strings im Attribut.
 * Kleinbuchstaben: 	a-k werden um 2 erhoeht
 * 					p-z werden um 2 verringert
 * 					l=a, m=b,n=y,o=z
 * Grossbuchstaben:	B-M werden um 1 verringert
 * 					N-Y werden um 1 erhoeht
 * 					A=M, Z=N
 *	
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		EncoderClass.cpp
 * @date: 		12.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#include "EncoderClass.h"

const int EncoderClass::VERSCHIEBUNG_GROSSBUCHSTABE_B_M = -1;
const int EncoderClass::VERSCHIEBUNG_GROSSBUCHSTABE_N_Y = 1;
const int EncoderClass::VERSCHIEBUNG_KLEINBUCHSTABE_A_K = 2;
const int EncoderClass::VERSCHIEBUNG_KLEINBUCHSTABE_P_Z = -2;

//Konstanten fuer Groessen der Buchstaben
const int EncoderClass::GROSSBUCHSTABE_A_ALS_INT = 65;
const int EncoderClass::GROSSBUCHSTABE_B_ALS_INT = 66;
const int EncoderClass::GROSSBUCHSTABE_M_ALS_INT = 77;
const int EncoderClass::GROSSBUCHSTABE_N_ALS_INT = 78;
const int EncoderClass::GROSSBUCHSTABE_Y_ALS_INT = 89;
const int EncoderClass::GROSSBUCHSTABE_Z_ALS_INT = 90;

const int EncoderClass::KLEINBUCHSTABE_A_ALS_INT = 97;
const int EncoderClass::KLEINBUCHSTABE_K_ALS_INT = 107;
const int EncoderClass::KLEINBUCHSTABE_P_ALS_INT = 112;
const int EncoderClass::KLEINBUCHSTABE_Z_ALS_INT = 122;
const int EncoderClass::KLEINBUCHSTABE_L_ALS_INT = 108;
const int EncoderClass::KLEINBUCHSTABE_M_ALS_INT = 109;
const int EncoderClass::KLEINBUCHSTABE_N_ALS_INT = 110;
const int EncoderClass::KLEINBUCHSTABE_O_ALS_INT = 111;

const char* EncoderClass::KEIN_GROSSBUCHSTABE =
		"Es sind nur Grossbuchstaben zulaessig";
const char* EncoderClass::KEIN_KLEINBUCHSTABE =
		"Es sind nur Kleinbuchstaben zulaessig";

EncoderClass::EncoderClass(string zuEncoden)
{
	stringEncoden(zuEncoden);
}

void EncoderClass::stringEncoden(string zuEncoden)
{
	//Zwischenspeicher fuer encodete Zeichen
	ostringstream buffer;
	char encodeterBuchstabe;

	for (int i = 0; i < zuEncoden.length(); ++i)
	{
		//Umwandeln des aktuelle vergleichen Zeichens zu Int
		int buchstabeAlsInt = static_cast<int>(zuEncoden[i]);

		/* Vordefinieren von encodeterBuchstabe mit dem nicht
		 * verschluesselten Zeichen da nur Gross- und Kleinbuchstaben
		 * verschluesselt werden.
		 */
		encodeterBuchstabe = zuEncoden[i];

		//Untersuchen auf Klein- oder Grossbuchstaben

		//Grossbuchstabe
		if (buchstabeAlsInt >= GROSSBUCHSTABE_A_ALS_INT
				&& buchstabeAlsInt <= GROSSBUCHSTABE_Z_ALS_INT)
		{
			//Grossbuchstabe verschluesseln
			encodeterBuchstabe = grossBuchstabeEncoden(buchstabeAlsInt);
		}

		//Kleinbuchstabe
		if (buchstabeAlsInt >= KLEINBUCHSTABE_A_ALS_INT
				&& buchstabeAlsInt <= KLEINBUCHSTABE_Z_ALS_INT)
		{
			//Kleinbuchstabe verschluesseln
			encodeterBuchstabe = kleinBuchstabeEncoden(buchstabeAlsInt);
		}

		//Anhaengen des verschlusselten Buchstaben in den Buffer
		buffer << encodeterBuchstabe;
	}

	//Buffer in Attribut speichern
	(this->CodierterString) = buffer.str();
}

char EncoderClass::kleinBuchstabeEncoden(const int& kleinBuchstabeAlsInt)
{
	//verschluesseltes Zeichen
	char kleinBuchstabeEncoded;

	//verschluesseltes Zeichen als Int
	int kleinBuchstabeEncodedInt;

	//Abfangen von ungueltigen Werten
	if (kleinBuchstabeAlsInt < KLEINBUCHSTABE_A_ALS_INT
			|| kleinBuchstabeAlsInt > KLEINBUCHSTABE_Z_ALS_INT)
	{
		throw KEIN_KLEINBUCHSTABE;
	}

	// Von a-k wird alles um 2 erhoeht. -> alles unter K
	if (kleinBuchstabeAlsInt <= KLEINBUCHSTABE_K_ALS_INT)
	{
		kleinBuchstabeEncodedInt = (kleinBuchstabeAlsInt
				+ VERSCHIEBUNG_KLEINBUCHSTABE_A_K);
	}

	//Von p-z wird alles um 2 verringert. ->alles ueber P
	if (kleinBuchstabeAlsInt >= KLEINBUCHSTABE_P_ALS_INT)
	{
		kleinBuchstabeEncodedInt = (kleinBuchstabeAlsInt
				+ VERSCHIEBUNG_KLEINBUCHSTABE_P_Z);
	}

	/* Fuer die Buchstaben k,l,m,o gelten Sonderregeln da sie zwischen den
	 * zwei Verschiebungen liegen. Waere auch mit +/-11 moeglich gewesen.
	 */
	switch (kleinBuchstabeAlsInt)
	{
	case KLEINBUCHSTABE_L_ALS_INT:
		kleinBuchstabeEncodedInt = KLEINBUCHSTABE_A_ALS_INT;	//l->a
		break;
	case KLEINBUCHSTABE_M_ALS_INT:
		kleinBuchstabeEncodedInt = 98;	//m->b, 98 = b
		break;
	case KLEINBUCHSTABE_N_ALS_INT:
		kleinBuchstabeEncodedInt = 121;	//n->y, 121 = y
		break;
	case KLEINBUCHSTABE_O_ALS_INT:
		kleinBuchstabeEncodedInt = KLEINBUCHSTABE_Z_ALS_INT;	//o->z
		break;
	}

	//Umwandeln des Ints zurueck in ein Zeichen
	kleinBuchstabeEncoded = static_cast<char>(kleinBuchstabeEncodedInt);

	//Rueckgabe verschluesseltes Zeichen
	return kleinBuchstabeEncoded;
}

char EncoderClass::grossBuchstabeEncoden(const int& grossBuchstabeAlsInt)
{
	char grossBuchstabeEncoded;
	int grossBuchstabeEncodedInt;

	//Abfangen von ungueltigen Werten. Alles was nicht Grossbuchstabe ist
	if (grossBuchstabeAlsInt < GROSSBUCHSTABE_A_ALS_INT
			|| grossBuchstabeAlsInt > GROSSBUCHSTABE_Z_ALS_INT)
	{
		throw KEIN_GROSSBUCHSTABE;
	}

	// Von B-M wird alles um 1 verringert
	if (grossBuchstabeAlsInt >= GROSSBUCHSTABE_B_ALS_INT
			&& grossBuchstabeAlsInt <= GROSSBUCHSTABE_M_ALS_INT)
	{
		grossBuchstabeEncodedInt = (grossBuchstabeAlsInt
				+ VERSCHIEBUNG_GROSSBUCHSTABE_B_M);
	}

	//Von N-Y wird alles um 1 erhoeht
	if (grossBuchstabeAlsInt >= GROSSBUCHSTABE_N_ALS_INT
			&& grossBuchstabeAlsInt <= GROSSBUCHSTABE_Y_ALS_INT)
	{
		grossBuchstabeEncodedInt = (grossBuchstabeAlsInt
				+ VERSCHIEBUNG_GROSSBUCHSTABE_N_Y);
	}

	// Fuer die Buchstaben A,Z gelten Sonderregeln
	switch (grossBuchstabeAlsInt)
	{
	case 65:
		grossBuchstabeEncodedInt = GROSSBUCHSTABE_M_ALS_INT;	//a->m
		break;
	case 90:
		grossBuchstabeEncodedInt = GROSSBUCHSTABE_N_ALS_INT;	//z->n
		break;
	}

	//Umwandeln von Integer zu Char
	grossBuchstabeEncoded = static_cast<char>(grossBuchstabeEncodedInt);

	//Rueckgabe des Verschluesselten Grossbuchstaben
	return grossBuchstabeEncoded;
}

