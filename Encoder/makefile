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
OBJEKTS = ReadFileClass.o WriteFileClass.o EncoderClass.o EncodingCheckClass.o DecoderClass.o

all: encoder

encoder: encoder.cpp $(OBJEKTS)

ReadFileClass.o: ReadFileClass.cpp ReadFileClass.h

WriteFileClass.o: WriteFileClass.cpp WriteFileClass.h

EncoderClass.o: EncoderClass.cpp EncoderClass.h

EncodingCheckClass.o: EncodingCheckClass.cpp EncodingCheckClass.h

DecoderClass.o: DecoderClass.cpp DecoderClass.h


# Loeschen der Objektdateien und der Binary
clean:
	@echo "Folgende Daten werden geloescht"
	@echo $(DELOBJ) $(APPLICATION)
	rm  $(DELOBJ)
	rm $(APPLICATION)
	