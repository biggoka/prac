ERR_FILE = err.txt

INCLDIRS = \
	include/model \
	include/interface \
	include/logic \
	include/utils \
	include/model/predicate \
	include/model/schedule

SRCDIR = src test

SRCDIRS = \
	$(SRCDIR) \
	src/model \
	src/interface \
	src/logic \
	src/utils \
	src/model/predicate \
	src/model/schedule \
	test/src

OBJDIR = \
	obj

TESTOBJDIR = \
	test/obj



DEPS = BinaryPredicate.hpp LogicPredicate.hpp NegatePredicate.hpp Predicate.hpp \
	RelationPredicate.hpp UnaryPredicate.hpp Splitter.hpp Interface.hpp UserInterface.hpp \
	AdminInterface.hpp InfoBank.hpp Request.hpp Schedule.hpp \
	ScheduleCell.hpp ScheduleCellEntry.hpp ScheduleTime.hpp ScheduleController.hpp



OBJS_ = $(DEPS:.hpp=.o)
OBJS = $(patsubst %, $(OBJDIR)/%, $(OBJS_)) 

MAINS_ = user_main admin_main
MAIN_OBJS = $(patsubst %, $(OBJDIR)/%.o, $(MAINS_))


TESTS_ = test_all.cpp SplitterTest.cpp InfoBankTest.cpp RequestTest.cpp ScheduleControllerTest.cpp

TESTS = $(TESTS_:.cpp=.o)
TEST_OBJS = $(patsubst %, $(TESTOBJDIR)/%, $(TESTS))


CC = g++
DEBUG = --coverage -Wall 
CFLAGS = -O2 -std=c++14 $(patsubst %, -I%, $(INCLDIRS)) $(DEBUG) 
LFLAGS = $(CFLAGS)


vpath
vpath %.hpp $(INCLDIRS)
vpath %.cpp $(SRCDIRS)
vpath %.o $(OBJDIR)


all: folders googletest lcov build test

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


test: googletest build $(TEST_OBJS) $(OBJS)
	@ $(CC) $(CFLAGS) -o test_main $(TEST_OBJS) $(OBJS) -pthread libgtest.a
	@ ./test_main


$(TESTOBJDIR)/%.o: %.cpp
	@ echo "compiling $@"
	@ $(CC) $(CFLAGS) -c -o $@ $< -isystem googletest/googletest/include 

rebuild: clean build FORCE

clean:
	@ echo Cleaning
	@ rm -f obj/*.o main *.out *.o err.txt *.html admin_main user_main test_main tests obj/*.gcno obj/*.gcda \
	test/obj/*.gcda test/obj/*.gcno app.info
	@ rm -f test/obj/* libgtest.a
	@ rm -rf coverage
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



coverage: lcov FORCE
	@ echo Generating coverage
	@ lcov/bin/lcov --directory obj --directory test/obj --capture --output-file app.info -q 
	@ lcov/bin/genhtml app.info --output-directory coverage/ -q
	@ xdg-open coverage/index.html



lcov: lcov/README

lcov/README:
	@ echo Downloading Lcov
	@ git clone https://github.com/linux-test-project/lcov.git 
