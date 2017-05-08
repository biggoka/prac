CC = g++

ERR_FILE = err.txt

INCLDIRS = \
	include/model \
	include/interface \
	include/logic \
	include/utils

SRCDIR = src test

SRCDIRS = \
	$(SRCDIR) \
	src/model \
	src/interface \
	src/logic \
	src/utils \
	test/src

OBJDIR = \
	obj

TESTOBJDIR = \
	test/obj

DEPS = Splitter.hpp Interface.hpp UserInterface.hpp AdminInterface.hpp InfoBank.hpp Request.hpp

OBJS_ = $(DEPS:.hpp=.o)
OBJS = $(patsubst %, $(OBJDIR)/%, $(OBJS_)) 

MAINS_ = user_main admin_main
MAIN_OBJS = $(patsubst %, $(OBJDIR)/%.o, $(MAINS_))

TESTS_ = test_all.cpp SplitterTest.cpp InfoBankTest.cpp RequestTest.cpp
TESTS = $(TESTS_:.cpp=.o)
TEST_OBJS = $(patsubst %, $(TESTOBJDIR)/%, $(TESTS))

DEBUG = 
CFLAGS = -O2 -std=c++11 $(patsubst %, -I%, $(INCLDIRS)) $(DEBUG) 2>$(ERR_FILE)
LFLAGS = $(CFLAGS)


vpath
vpath %.hpp $(INCLDIRS)
vpath %.cpp $(SRCDIRS)
vpath %.o $(OBJDIR)


all: folders build test


# .PHONY: build
build: $(OBJS) $(MAIN_OBJS) $(MAINS_)
#	@$(CC) $(CFLAGS) -o main $(MAIN_OBJS) $(OBJS)
#	@echo "linking $^"
	#$(foreach M, $(MAINS_), $(CC) $(CFLAGS) -o $(M) $(OBJDIR)/$(M).o $(OBJS) ;)

$(MAINS_): $(OBJS) $(MAIN_OBJS)
	$(CC) $(CFLAGS) -o $(@) $(OBJDIR)/$(@).o $(OBJS)

$(OBJDIR)/%.o: %.cpp $(DEPS)
	@echo "compiling $@"
	@$(CC) $(CFLAGS) -c -o $@ $<

runadmin:
	@./admin_main

runuser:
	@./user_main

test: $(TEST_OBJS) $(OBJS)
	@$(CC) $(CFLAGS) -o tests $(TEST_OBJS) $(OBJS) -pthread googletest/googletest/libgtest.a
	@./tests
#	$(CC) src/**/*.cpp test/src/*.cpp $(CFLAGS) -o test/main -isystem googletest/googletest/include -pthread googletest/googletest/libgtest.a

$(TESTOBJDIR)/%.o: %.cpp
	@echo "compiling $@"
	@$(CC) $(CFLAGS) -c -o $@ $< -isystem googletest/googletest/include 

rebuild: clean build FORCE

clean:
	@rm -f obj/*.o main *.out *.o err.txt *.html
	@rm -f test/obj/*
	@echo "Cleaned"

FORCE:

folders: test/obj obj

obj:
	@mkdir $@

test/obj:
	@mkdir $@


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