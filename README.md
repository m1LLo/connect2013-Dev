# Einsendung für Consistec HTW Connect2013 Programmierwettbewerb

##Info
Hallo, ich habe mich für eine OOP C++ Lösung Entschieden mit 7 verschiedenen Klassen welche jede
eine eigene Funktionalität abdeckt.

Die verschlüsselte Lorem Ipsum Datei befindet sich im Ordner [TestOutput].

Mit freundlichen Grüßen 
Markus Leitz

##Benutzte Klassen
-  ReadFileClass   		(Liest Dateien ein und Speichert deren Inhalt in einem String Attribut)
-  DecoderClass			(Verschlueselt einen String um mittels vorgebener Methode und Speichert ihn in Objekt Attribut)
-  EncoderClass			(Entschluesselt einen String analog zu DecoderClass)
-  EncodingCheckClass		(Kontrolliert zwei Strings auf Gleichheit)
-  FunctionsClass			(Beinhaltet die Funktionen des Programms und stellt sie der MAIN zu verfügung)
-  ParameterCheckClass	(Kontrolliert die an die Main übergebenen Parameter auf Fehleingaben und setzt den ausgewählten Programmmodus)
-  WriteFileClass			(Schreibt den übergeben String in eine Datei deren Pfad übergeben wurde)

##Integrierte Funktionen und Aufrufe
-  Hilfs Modus (Gibt Hilfsmenü für Benutzer aus)

<code>[PROGRAMMNAME] -h</code>
-  Encoder Modus (Verschlüsselt den Inhalt der Quelldatei und Speichert in in der Zieldatei.)

<code>[PROGRAMMNAME] [QUELLDATEI] [ZIELDATEI]</code>
-  Decoder Modus (Entschlüsselt analag zu Encodermodus.)

<code>[PROGRAMMNAME] -d [QUELLDATEI] [ZIELDATEI]</code>
-  Encoder Test Modus (Verschlüsselt den Inhalt der Quelldatei und vergleicht ihn mit der Vorlagendatei. MIT oder OHNE Ausgabedatei.)

<code>[PROGRAMMNAME] -t [QUELLDATEI] [VORLAGENDATEI]</code>
<code>[PROGRAMMNAME] -t [QUELLDATEI] [ZIELDATEI] [VORLAGENDATEI]</code>
-  Check Modus (Vergleicht zwei Dateien auf Gleichheit.)

<code>[PROGRAMMNAME] -c [VERGLEICHSDATEI] [VORLAGENDATEI]</code>

##Kompilierung des Programms
> Zuerst sollte man sich im gleichen Ordner befinden wie das Makefile: 
  Falls nicht mit:

```
cd src
```
>in Quellcode Ordner wechseln.

###Kompilieren des Programms:
```
make all
```

###Löschen der Objektdateien und der ausführbaren Datei
```
make clean
```

##Testen der Verschlüsselung
Zum Testen der Verschlüsselung gibt es 2 Möglichkeiten:

1.  Datei Encoden und mit Check-Modus mit Vorlagendatei vergleichen.
2.  Datei im Test-Modus Encoden und mit Vorlagendatei vergleichen.

##Abgefangen Fehler

-  Zu viele Parameter angeben
-  zu wenig Parameter angeben
-  Datei ist nicht vorhanden
-  Datei ist leer

###Nicht abgefangen
Das Programm liest auch Dateien die nicht im *.txt Format vorliegen.

##Dokumentation
Für die Dokumentation wurde Doxygen verwendet. Das Doxyfile liegt bei und ist so eingestellt dass die Dokumentation im HTML Format im Ordner "Doku" erstellt wird.

##Kontaktdaten
Markus Leitz

m.leitz@freenet.de

 
