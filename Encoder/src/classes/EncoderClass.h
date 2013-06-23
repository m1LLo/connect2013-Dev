/**
 * Klasse Encodet einen String nach folgender Methode und speichert
 * verschlusselt in Attribut:
 * Kleinbuchstaben: 	a-k werden um 2 erhoeht
 * 					p-z werden um 2 verringert
 * 					l=a, m=b,n=y,o=z
 * Grossbuchstaben:	B-M werden um 1 verringert
 * 					N-Y werden um 1 erhoeht
 * 					A=M, Z=N
 *	
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		EncoderClass.h
 * @date: 		12.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#ifndef ENCODERCLASS_H_
#define ENCODERCLASS_H_

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

/**
 * @author Markus Leitz (3543994)
 * @version 1.0
 * @date 12.06.2013
 */
class EncoderClass
{
public:

	/**
	 * Konstruktor fuer den Encoder.
	 * Erstellt Objekt zum Encoden von Strings.
	 *
	 * @param zuEncoden		String welcher zu Encoden ist.
	 */
	EncoderClass(string zuEncoden);

	/**
	 * Geht den String Zeichen fuer Zeichen durch und untersucht jedes
	 * Zeichen auf Gross- und Kleinbuchstaben. Findest die Methode einen
	 * Gross- oder Kleinbuchstaben ruft es die entsprechende Methode zum
	 * encoden des Zeichens auf und schiebt speichert es im Attribut fuer
	 * den Encodeten String.
	 *
	 * @param zuEncoden		String welcher Encodet werden soll.
	 */
	void stringEncoden(string zuEncoden);

	/**
	 * Methode zum Encoden eines Grossbuchstaben.
	 * Beinhaltet den Algorithmus wie welcher Grossbuchstabe verschluesselt
	 * werden soll.
	 *
	 * @param grossBuchstabeAlsInt		Zu verschluesselner Buchstabe
	 * 									als int-Wert.
	 * @return							Liefter Buchstaben verschluesselt
	 * 									als Buchstaben zurueck.
	 */
	char grossBuchstabeEncoden(const int& grossBuchstabeAlsInt);

	/**
	 * Methode zum Encoden eines Kleinbuchstaben.
	 * Beinhaltet den Algorithmus wie welcher Kleinbuchstabe verschluesselt
	 * werden soll.
	 *
	 * @param kleinBuchstabeAlsInt		Zu verschluesselner Buchstabe
	 * 									als int-Wert.
	 * @return							Liefter Buchstaben verschluesselt
	 * 									als Buchstaben zurueck.
	 */
	char kleinBuchstabeEncoden(const int& kleinBuchstabeAlsInt);

	/**
	 * GET-Methode zum weiter geben des verschluesselten Strings an andere
	 * Klassen oder Funktionen. Waere auch mit FRIEND moeglich gewesen ist
	 * aber als FRIEND weniger universell.
	 *
	 * @return			Gibt das Attribut Codierter String als String aus.
	 */
	const string& getCodierterString() const
	{
		return CodierterString;
	}

private:
	//Verschiebungskontanten fuer Verschluesselungsverfahren
	static const int VERSCHIEBUNG_GROSSBUCHSTABE_B_M;
	static const int VERSCHIEBUNG_GROSSBUCHSTABE_N_Y;
	static const int VERSCHIEBUNG_KLEINBUCHSTABE_A_K;
	static const int VERSCHIEBUNG_KLEINBUCHSTABE_P_Z;

	//Konstanten fuer Groessen der Buchstaben
	static const int GROSSBUCHSTABE_A_ALS_INT;
	static const int GROSSBUCHSTABE_B_ALS_INT;
	static const int GROSSBUCHSTABE_M_ALS_INT;
	static const int GROSSBUCHSTABE_N_ALS_INT;
	static const int GROSSBUCHSTABE_Y_ALS_INT;
	static const int GROSSBUCHSTABE_Z_ALS_INT;

	static const int KLEINBUCHSTABE_A_ALS_INT;
	static const int KLEINBUCHSTABE_K_ALS_INT;
	static const int KLEINBUCHSTABE_P_ALS_INT;
	static const int KLEINBUCHSTABE_Z_ALS_INT;
	static const int KLEINBUCHSTABE_L_ALS_INT;
	static const int KLEINBUCHSTABE_M_ALS_INT;
	static const int KLEINBUCHSTABE_N_ALS_INT;
	static const int KLEINBUCHSTABE_O_ALS_INT;

	//Fehlermelungen
	static const char* KEIN_GROSSBUCHSTABE;
	static const char* KEIN_KLEINBUCHSTABE;

	/* Speichert den String nach dem Verschluesseln durch die Methode
	 * "stringEncoden"
	 */
	string CodierterString;
};

#endif /* ENCODERCLASS_H_ */
