#ifndef TEXT_H_
#define TEXT_H_

/* CText Klasse:
 * Diese Klasse gibt unterschiedliche Texte waehrend des Spielablaufs aus.
 */

class CText
{
public:
	string welcome_text();		//Funktion zur Ausgabe des Willkommenstexts beim Start des Programms
	string info_text();			//Funktion zur Ausgabe der Spielinformationen und -regeln
	string singleplayer();		//Funktion zur Ausgabe des Informationstextes zum Singleplayer-Mode
	string multiplayer();		//Funktion zur Ausgabe des Informationstextes zum Multiplayer-Mode
};
#endif
