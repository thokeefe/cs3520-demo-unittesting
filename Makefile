CXXTEST_HOME?=cxxtest-4.4
CXXTEST_GEN=$(CXXTEST_HOME)/bin/cxxtestgen
CXXTEST_INCLUDE=$(CXXTEST_HOME)

PROGRAMS=runner

CXXFLAGS=-std=c++11 -Wall -Werror
LDFLAGS=-std=c++11

## for gdb or valgrind
#CXXFLAGS:=$(CXXFLAGS) -O0 -ggdb -fno-inline
#LDFLAGS:=$(LDFLAGS)

## for gcov
#CXXFLAGS:=$(CXXFLAGS) -O0 -fprofile-arcs -ftest-coverage
#LDFLAGS:=$(LDFLAGS) -fprofile-arcs

## for gprof
#CXXFLAGS:=$(CXXFLAGS) -O0 -ggdb -pg
#LDFLAGS:=$(LDFLAGS) -pg

all: $(PROGRAMS)

runner: runner.o Example.cxxtest.o CStrings.cxxtest.o CIVec2D.cxxtest.o CIVec2D.o
	g++ $(LDFLAGS) $^ -o $@

%.o: %.cpp *.hpp Makefile
	g++ -c $(CXXFLAGS) -I$(CXXTEST_INCLUDE) $< -o $@

%.cxxtest.cpp: %.cxxtest.hpp
	$(CXXTEST_GEN) --part --error-printer $< -o $@

runner.cpp:
	$(CXXTEST_GEN) --root --error-printer -o $@

clean:
	rm -f log.txt *~ *.o $(PROGRAMS) *.gcda *.gcno *.gcov gmon.out runner.cpp *.cxxtest.cpp
