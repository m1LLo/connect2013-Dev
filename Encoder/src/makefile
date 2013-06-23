# Makefile fuer Connect 2013 Gewinnspiel by Consistec.
# Created on: 12.06.2012
#     Author: Markus Leitz (3543994)

#Compilerflags
CFLAGS = -g -std=c++11 -pedantic -Wall

#Zu loeschende Objektdateien
DELOBJ = *.o

#Hauptprogramm
APPLICATION = encoder

#Objekte fuer kompilierung
OBJEKTS = classes/ReadFileClass.o classes/WriteFileClass.o classes/EncoderClass.o\
classes/EncodingCheckClass.o classes/DecoderClass.o classes/ParameterCheckClass.o\
classes/FunctionsClass.o

#Benutzerinfos ausgeben
OBJEKTEERSTELLEN = @echo "==OBJEKTDATEIEN WERDEN ERSTELLT=="
ZUSAMMENFUEGEN =@echo "==AUSFUEHRBARE WIRD ERSTELLT=="

#Nacheinander: Benutzerausgabe, Objektdateien erstellen,  Benutzerausgabe, Ausfuehrbare erstellen
all: objekteerstellen objekte zusammenfuegen encoder

objekteerstellen:
	@echo ""
	$(OBJEKTEERSTELLEN)
	
zusammenfuegen:
	@echo ""
	$(ZUSAMMENFUEGEN)
	
objekte: $(OBJEKTS)

encoder: encoder.cpp $(OBJEKTS)

ReadFileClass.o: classes/ReadFileClass.cpp classes/ReadFileClass.h

WriteFileClass.o: classes/WriteFileClass.cpp classes/WriteFileClass.h

EncoderClass.o: classes/EncoderClass.cpp classes/EncoderClass.h

EncodingCheckClass.o: classes/EncodingCheckClass.cpp classes/EncodingCheckClass.h

DecoderClass.o: classes/DecoderClass.cpp classes/DecoderClass.h

ParameterCheckClass.o: classes/ParameterCheckClass.cpp classes/ParameterCheckClass.h

FunctionsClass.o: classes/FunctionsClass.cpp classes/FunctionsClass.h


# Loeschen der Objektdateien und der Binary
clean:
	@echo "FOLGENDE DATEN WERDEN GELOESCHT:"
	@echo "Objektdateien:"
	@echo $(DELOBJ)
	rm -f classes/$(DELOBJ)
	
	@echo "ausfuehrbaren Datei:"
	@echo $(APPLICATION)
	rm -f $(APPLICATION)
	