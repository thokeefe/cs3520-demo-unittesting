CXXTEST_HOME?=cxxtest-4.4
CXXTEST_GEN=$(CXXTEST_HOME)/bin/cxxtestgen
CXXTEST_INCLUDE=$(CXXTEST_HOME)

PROGRAMS=runner

CXXFLAGS=-std=c++17 -O0 -fno-inline -g -Wall -Wextra -Wpedantic -Werror -Wno-ignored-qualifiers -pedantic-errors
LDFLAGS=-std=c++17

## for gcov
#CXXFLAGS:=$(CXXFLAGS) -fprofile-arcs -ftest-coverage
#LDFLAGS:=$(LDFLAGS) -fprofile-arcs



all: $(PROGRAMS)

runner: runner.o Example.cxxtest.o CStrings.cxxtest.o CIVec2D.cxxtest.o CIVec2D.o
	g++ $(LDFLAGS) $^ -o $@

%.o: %.cpp *.hpp Makefile
	g++ -I$(CXXTEST_INCLUDE) $(CXXFLAGS) -c $< -o $@

%.cxxtest.cpp: %.cxxtest.hpp
	python3 $(CXXTEST_GEN) --part --error-printer $< -o $@

runner.cpp:
	python3 $(CXXTEST_GEN) --root --error-printer -o $@

clean:
	rm -rf test.log *~ .vscode/*~ *.o *.dSYM $(PROGRAMS) *.gcda *.gcno *.gcov callgrind.out.* runner.cpp *.cxxtest.cpp
