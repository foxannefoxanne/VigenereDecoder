mp2: main.o Decoder.o
	g++ -g  -std=c++11 -o mp2 main.o Decoder.o

main.o:main.cpp
	g++ -g -c -std=c++11 main.cpp

Decoder.o:  Decoder.h Decoder.cpp
	g++ -g -c -std=c++11 Decoder.cpp

clean: 
	rm -f *.o mp2

