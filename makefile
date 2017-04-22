CC = g++
#CFLAGS = -O2 -std=c++11 -I ./include/controller -I ./include/interface -I ./include/model -I ./include/utils

ODIR = ./src/obj 
# DEP =  LoginController.hpp ReportController.hpp FileReader.hpp UserInterface.hpp Date.hpp Report.hpp Transaction.hpp User.hpp DateParser.hpp Splitter.hpp
# _OBJ = LoginController.o ReportController.o FileReader.o UserInterface.o Date.o Report.o Transaction.o User.o DateParser.o Splitter.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

INCLDIRS = \
	include/model \
	include/interface \
	include/logic 

SRCDIR = src

SRCDIRS = \
	$(SRCDIR) \
	src/model \
	src/interface \
	src/logic

OBJDIR = \
	obj

DEPS = controller.hpp

MAINS_ = main
MAIN_OBJS = $(patsubst %, $(OBJDIR)/%.o, $(MAINS_))

OBJS_ = $(DEPS:.hpp=.o)
OBJS = $(patsubst %, $(OBJDIR)/%, $(OBJS_))

CFLAGS = -O2 -std=c++11 $(patsubst %, -I%, $(INCLDIRS))
LFLAGS = 


vpath
vpath %.hpp $(INCLDIRS)
vpath %.cpp $(SRCDIRS)
vpath %.o $(OBJDIR)


all: build

info:
	@echo "$(MAIN_OBJS)"


# .PHONY: build
build: $(OBJS) $(MAIN_OBJS)
#	@$(CC) $(CFLAGS) -o main $(MAIN_OBJS) $(OBJS)
#	@echo "linking $^"
	$(foreach M, $(MAINS_), @$(CC) $(CFLAGS) -o $(M) $(OBJDIR)/$(M).o $(OBJS))



$(OBJDIR)/%.o: %.cpp $(DEPS)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "compiling $@"

clean:
	@rm -f obj/*.o main a.out


# # build: $(OBJ)
# # 	$(CC) src/main.cpp -o main $^ $(CFLAGS)


# build:
# #	$(CC) src/**/*.cpp src/main.cpp $(CFLAGS) -o main
# #	$(CC) src/**/*.cpp src/datagen.cpp $(CFLAGS) -o datagen
# #	$(CC) src/**/*.cpp test/src/*.cpp $(CFLAGS) -o test/main -isystem googletest/googletest/include -pthread googletest/googletest/libgtest.a 

# clean:
# #	rm -f *.o main datagen

# reset: clean
# #	rm -f *.txt