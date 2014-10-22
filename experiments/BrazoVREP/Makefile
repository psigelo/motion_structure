VPATH = ./VREP/remoteApi/ ./VREP/include
CC = g++ -O3
CFLAGS = -g -Wall -fPIC -I./VREP/remoteApi/ -I./VREP/include


all: brazo.cpp
	cd VREP; make
	@mkdir -p bin
	$(CC) $(CFLAGS)  ./brazo.cpp  ./VREP/remoteApi/extApi.o ./VREP/remoteApi/extApiPlatform.o -o ./bin/brazo -lpthread  -lmotionstructure -DNON_MATLAB_PARSING -DMAX_EXT_API_CONNECTIONS=255

run: 
	./bin/brazo ./brazo_vrep.txt

clean:
	rm -Rf ./bin
	rm -f VREP/remoteApi/*.o