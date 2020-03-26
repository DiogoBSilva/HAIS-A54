#################### MakeFile ######################

all: hais
hais: readConfig.o LerSensor.o hais.o DevConfig.o controlador.o
	@echo " A compilar... "
	gcc -o hais readConfig.o LerSensor.o hais.o DevConfig.o controlador.o -lm
	@echo " ...Terminado "
	
readConfig.o: ./src/readConfig.c
	gcc -o readConfig.o -c ./src/readConfig.c -W -Wall

LerSensor.o: ./src/LerSensor.c
	gcc -o LerSensor.o -c ./src/LerSensor.c -W -Wall 

hais.o: ./src/hais.c
	gcc -o hais.o -c ./src/hais.c -W -Wall

DevConfig.o: ./src/LerSensor.c
	gcc -o DevConfig.o -c ./src/DevConfig.c -W -Wall 

controlador.o: ./src/controlador.c
	gcc -o controlador.o -c ./src/controlador.c -W -Wall

clean:
	rm -rf *.o

