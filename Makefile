VPATH = ./src ./headers ./objects
CC = g++ -std=c++11 -O3
CFLAGS = -g -Wall -fPIC -I./headers -I./objects -I./src 

all: motion_structure.o motor.o movement.o link_segment.o RotMatrix.o mathematicTools.o solverLinear.o
	@echo "Ready"

test: test.cpp motion_structure.o solverLinear.o mathematicTools.o motor.o movement.o link_segment.o
	mkdir -p bin
	$(CC) $(CFLAGS)  ./src/test.cpp ./objects/motion_structure.o ./objects/mathematicTools.o ./objects/solverLinear.o ./objects/movement.o ./objects/link_segment.o ./objects/motor.o  -o ./bin/test -larmadillo

motion_structure.o: ./src/motion_structure.cpp 
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/motion_structure.cpp -o ./objects/motion_structure.o 

RotMatrix.o: RotMatrix.cpp 
	mkdir -p bin
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/RotMatrix.cpp -o ./objects/RotMatrix.o 

motor.o: ./src/motor.cpp 
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/motor.cpp -o ./objects/motor.o 
	
movement.o: ./src/movement.cpp
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/movement.cpp -o ./objects/movement.o 


link_segment.o: ./src/link_segment.cpp
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/link_segment.cpp -o ./objects/link_segment.o 

solverLinear.o: solverLinear.cpp
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/solverLinear.cpp -o ./objects/solverLinear.o 

mathematicTools.o: mathematicTools.cpp
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/mathematicTools.cpp -o ./objects/mathematicTools.o 

clean:
	rm -Rf build* ./objects ./executables ./bin ./Documentacion
	cd experiments/BrazoVREP/; make clean

doc:
	doxygen Doxyfile

install:
	g++ -shared -Wl,-soname,libmotionstructure.so.1 -o libmotionstructure.so.1.0 ./objects/motion_structure.o ./objects/movement.o ./objects/RotMatrix.o ./objects/mathematicTools.o ./objects/solverLinear.o ./objects/motor.o ./objects/link_segment.o 
	ln -sf libmotionstructure.so.1.0 libmotionstructure.so
	ln -sf libmotionstructure.so.1.0 libmotionstructure.so.1
	mv libmotionstructure.so.1.0 libmotionstructure.so libmotionstructure.so.1 /usr/lib
	rm -rf /usr/include/motionstructure_headers/
	mkdir -p /usr/include/motionstructure_headers/
	cp ./headers/* /usr/include/motionstructure_headers/
	cp motionstructure /usr/include


prueba: probandoRotmatrix.cpp rotmatrix.o solverLinear.o
	$(CC) $(CFLAGS) ./src/probandoRotmatrix.cpp ./objects/rotmatrix.o   ./objects/solverLinear.o  -o ./bin/prueba -larmadillo

run:
	./bin/prueba