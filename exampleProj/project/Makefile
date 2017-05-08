CC = g++
CFLAGS = -O2 -std=c++11 -I ./include/controller -I ./include/interface -I ./include/model -I ./include/utils --coverage

ODIR = ./src/obj 
DEP =  LoginController.hpp ReportController.hpp FileReader.hpp UserInterface.hpp Date.hpp Report.hpp Transaction.hpp User.hpp DateParser.hpp Splitter.hpp
_OBJ = LoginController.o ReportController.o FileReader.o UserInterface.o Date.o Report.o Transaction.o User.o DateParser.o Splitter.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))


vpath
vpath %.hpp include/controller include/interface include/model include/utils
vpath %.cpp src src/controller src/interface src/model src/utils
vpath %.o src/obj


all: build test runtest

# $(ODIR)/%.o: %.cpp $(DEP)
# 	$(CC) -c -o $@ $< $(CFLAGS)

# build: $(OBJ)
# 	$(CC) src/main.cpp -o main $^ $(CFLAGS)

test: FORCE
	$(CC) src/**/*.cpp test/src/*.cpp $(CFLAGS) -o test/main -isystem googletest/googletest/include -pthread googletest/googletest/libgtest.a 
	

runtest:
	test/main


build:
	$(CC) src/**/*.cpp src/main.cpp $(CFLAGS) -o main
	$(CC) src/**/*.cpp src/datagen.cpp $(CFLAGS) -o datagen
	

clean:
	rm -f *.o main datagen

reset: clean
	rm -f *.txt
	rm -f *.out

FORCE: