CXX = g++
TESTU01FLAGS = -std=c++11 -ltestu01 -lprobdist -lmylib -lm
RDRANDFLAGS = -std=c++11 -mrdrnd -mrdseed
INSTALLDIRECTORY = /usr/local
FILENAME = main.cpp

randTest: main.o
	$(CXX) main.o -o randTest $(TESTU01FLAGS)

main.o: $(FILENAME)
	$(CXX) $(FILENAME) -c $(RDRANDFLAGS)

clean:
	rm main.o
