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



DEPS = Splitter.hpp Interface.hpp UserInterface.hpp AdminInterface.hpp InfoBank.hpp Request.hpp Schedule.hpp \
	ScheduleCell.hpp ScheduleCellEntry.hpp ScheduleTime.hpp



OBJS_ = $(DEPS:.hpp=.o)
OBJS = $(patsubst %, $(OBJDIR)/%, $(OBJS_)) 

MAINS_ = user_main admin_main
MAIN_OBJS = $(patsubst %, $(OBJDIR)/%.o, $(MAINS_))


TESTS_ = test_all.cpp SplitterTest.cpp InfoBankTest.cpp RequestTest.cpp

TESTS = $(TESTS_:.cpp=.o)
TEST_OBJS = $(patsubst %, $(TESTOBJDIR)/%, $(TESTS))


CC = g++
DEBUG = 
CFLAGS = -O2 -std=c++14 $(patsubst %, -I%, $(INCLDIRS)) $(DEBUG) 
LFLAGS = $(CFLAGS)


vpath
vpath %.hpp $(INCLDIRS)
vpath %.cpp $(SRCDIRS)
vpath %.o $(OBJDIR)


all: folders googletest build test

runadmin:
	@./admin_main

runuser:
	@./user_main


build: folders $(OBJS) $(MAIN_OBJS) $(MAINS_)
	@ $(foreach M, $(MAINS_), echo Linking $(M) && $(CC) $(CFLAGS) -o $(M) $(OBJDIR)/$(M).o $(OBJS) ;)

$(MAINS_): $(OBJS) $(MAIN_OBJS)
	@ $(CC) $(CFLAGS) -o $(@) $(OBJDIR)/$(@).o $(OBJS)

$(OBJDIR)/%.o: %.cpp $(DEPS)
	@ echo "compiling $@"
	@ $(CC) $(CFLAGS) -c -o $@ $<


test: googletest $(TEST_OBJS) $(OBJS)
	@ $(CC) $(CFLAGS) -o test_main $(TEST_OBJS) $(OBJS) -pthread libgtest.a
	@ ./test_main


$(TESTOBJDIR)/%.o: %.cpp
	@ echo "compiling $@"
	@ $(CC) $(CFLAGS) -c -o $@ $< -isystem googletest/googletest/include 

rebuild: clean build FORCE

clean:
	@ echo Cleaning
	@ rm -f obj/*.o main *.out *.o err.txt *.html admin_main user_main test_main tests
	@ rm -f test/obj/* libgtest.a
	@ echo "Cleaned"

FORCE:

folders: test/obj obj

obj:
	@ mkdir $@

test/obj:
	@ mkdir $@

libgtest.a: 
	@ echo Compiling Google Test
	@ g++ -isystem googletest/googletest/include -Igoogletest/googletest/ \
	-pthread -c googletest/googletest/src/gtest-all.cc
	@ ar -rv libgtest.a gtest-all.o
	@ rm gtest-all.o

googletest: googletest/googletest/src/gtest-all.cc libgtest.a

googletest/googletest/src/gtest-all.cc:
	@ echo Downloading Google Test
	@ git clone https://github.com/google/googletest.git
