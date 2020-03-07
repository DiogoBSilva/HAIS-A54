#################### MakeFile ######################

all: hais
hais: readConfig.o LerSensor.o hais.o
	@echo " A compilar... "
	gcc -o hais readConfig.o LerSensor.o hais.o -lm
	@echo " ...Terminado "
	
readConfig.o: readConfig.c
	gcc -o readConfig.o -c readConfig.c -W -Wall

LerSensor.o: LerSensor.c
	gcc -o LerSensor.o -c LerSensor.c -W -Wall

hais.o: hais.c
	gcc -o hais.o -c hais.c -W -Wall
clean:
	rm -rf *.o

