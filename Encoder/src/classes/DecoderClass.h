/**
 * Klasse entschluesselt einen verschluesselten String und macht ihn wieder
 * lesbar. Dafuer wird der Verschluesselungsalgorithmus aus EncoderClass
 * rueckwaerts angewendet. Gross- und Kleinbuchstaben werden dabei
 * verschieden behandelt und dabei werden bestimmte Intervalle dieser auch
 * wieder anderst verschluesselt/entschluesselt.
 *
 *		-Buchstaben zwischen A-L um 1 erhoehen
 *		-Buchstaben zwischen O-Z um 1 verringern
 *		-M & N werden zu A & Z
 *
 *		-Buchstaben von c-m um 2 verringern
 *		-Buchstaben von n-x um 2 erhoehen
 *		-Sonderregelung fuer a=l,b=m,y=n,z=o
 *	
 * Project:		Consistec Connect2013 Gewinnspiel
 * @file:		DecoderClass.h
 * @date: 		19.06.2013
 * @author:	 	Markus Leitz (3543994)
 */

#ifndef DECODERCLASS_H_
#define DECODERCLASS_H_

#include <string>
#include <sstream>
using namespace std;

/**
 * @author Markus Leitz (3543994)
 * @version 1.0
 * @date 19.06.2013
 */
class DecoderClass
{
public:

	/* Konstanten fuer Fallunterscheidung fuer Gross- und Kleinbuchstaben.
	 * Werte aus der ASCII-Tabelle. Sehr umständlich aber wurde mir so
	 * eingetrichtert.
	 */
	static const int GROSS_BUCHSTABE_A;
	static const int GROSS_BUCHSTABE_B;
	static const int GROSS_BUCHSTABE_L;
	static const int GROSS_BUCHSTABE_O;
	static const int GROSS_BUCHSTABE_M;
	static const int GROSS_BUCHSTABE_N;
	static const int GROSS_BUCHSTABE_Z;

	static const int KLEIN_BUCHSTABE_A;
	static const int KLEIN_BUCHSTABE_B;
	static const int KLEIN_BUCHSTABE_C;
	static const int KLEIN_BUCHSTABE_M;
	static const int KLEIN_BUCHSTABE_N;
	static const int KLEIN_BUCHSTABE_X;
	static const int KLEIN_BUCHSTABE_Y;
	static const int KLEIN_BUCHSTABE_Z;

	/**
	 * Konstruktor zum erstellen eines Decoder-Objekts.
	 * Benoetig als Uebergabe einen String sonder gibt es eine Fehlermeldung.
	 *
	 * @param zuDecodenderString		String aus Datei welcher entschluesselt
	 * 								werden soll.
	 */
	DecoderClass(string zuDecodenderString);

	/**
	 * Funktion durchlauft den String Zeichenweise und ruft je nach Zeichen
	 * den Decoder fuer das entsprechende Zeichen auf.
	 *
	 * @param zuDecodenderString		String aus Datei welcher entschluesselt
	 * 								werden soll.
	 */
	void stringDecoden(string zuDecodenderString);

	/**
	 * Methode bekommt einen Grossbuchstaben uebergeben und liefert einen
	 * Decodeten/entschluesselten Grossbuchstabe zurueck.
	 *
	 * @param charZuDecoden		Grossbuchstabe welcher entschluesselt
	 * 							werden soll.
	 *
	 * @return					Liefert enschluesselten Grossbuchstaben
	 * 							zurueck.
	 */
	char grossBuchStabeDecoden(char charZuDecoden);

	/**
	 * Methode bekommt einen Kleinbuchstaben uebergeben und liefert einen
	 * Decodeten/entschluesselten Kleinbuchstabe zurueck.
	 *
	 * @param charZuDecoden		Grossbuchstabe welcher entschluesselt
	 * 							werden soll.
	 *
	 * @return					Liefert enschluesselten Grossbuchstaben
	 * 							zurueck.
	 */
	char kleinBuchStabeDecoden(char charZuDecoden);

	/**
	 * GET-Methode liefert das Attribut DecodeterString.
	 * Zur Wertabfrage für andere Klassen.
	 *
	 * @return	String entschlüsselt
	 */
	const string& getDecodeterString() const
	{
		return decodeterString;
	}

private:

	//Der Eingabestring nach dem Entschluesseln
	string decodeterString;
};

#endif /* DECODERCLASS_H_ */
