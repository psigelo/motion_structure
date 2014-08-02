VPATH = ./src ./headers ./objects
CC = g++ -O3
CFLAGS = -g -Wall -fPIC -I./headers -I./objects -I./src 

all: motion_structure.o cinematica.o motor.o movement.o link_segment.o
	@echo "Ready"

test: test.cpp motion_structure.o cinematica.o motor.o movement.o link_segment.o
	mkdir -p bin
	$(CC) $(CFLAGS)  ./src/test.cpp ./objects/motion_structure.o ./objects/cinematica.o ./objects/movement.o ./objects/link_segment.o ./objects/motor.o  -o ./bin/test -larmadillo

motion_structure.o: ./src/motion_structure.cpp 
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/motion_structure.cpp -o ./objects/motion_structure.o -larmadillo

cinematica.o: ./src/cinematica.cpp
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/cinematica.cpp -o ./objects/cinematica.o -larmadillo

motor.o: ./src/motor.cpp cinematica.o
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/motor.cpp -o ./objects/motor.o -larmadillo

movement.o: ./src/movement.cpp
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/movement.cpp -o ./objects/movement.o 

link_segment.o: ./src/link_segment.cpp
	mkdir -p objects
	$(CC) $(CFLAGS) -c ./src/link_segment.cpp -o ./objects/link_segment.o 

clean:
	rm -Rf build* ./objects ./executables ./bin ./Documentacion
	cd experiments/BrazoVREP/; make clean

doc:
	doxygen Doxyfile

install:
	g++ -shared -Wl,-soname,libmotionstructure.so.1 -o libmotionstructure.so.1.0 ./objects/motion_structure.o ./objects/movement.o ./objects/cinematica.o ./objects/motor.o ./objects/link_segment.o 
	ln -sf libmotionstructure.so.1.0 libmotionstructure.so
	ln -sf libmotionstructure.so.1.0 libmotionstructure.so.1
	mv libmotionstructure.so.1.0 libmotionstructure.so libmotionstructure.so.1 /usr/lib
	mkdir -p /usr/include/motionstructure_headers/
	cp ./headers/* /usr/include/motionstructure_headers/
	cp motionstructure /usr/include