CPP := g++ -Wall -pedantic -o

.PHONY: clean

all: problems tools

problems: 001 002 003 004 005 006 007 008 009 010 011

tools: integers matrixtest

integers:
	$(CPP) $@.exe $@.cpp
matrixtest:
	$(CPP) $@.exe $@.cpp
001:
	$(CPP) $@.exe $@.cpp
002:
	$(CPP) $@.exe $@.cpp
003:
	$(CPP) $@.exe $@.cpp
004:
	$(CPP) $@.exe $@.cpp
005:
	$(CPP) $@.exe $@.cpp
006:
	$(CPP) $@.exe $@.cpp
007:
	$(CPP) $@.exe $@.cpp
008:
	$(CPP) $@.exe $@.cpp
009:
	$(CPP) $@.exe $@.cpp
010:
	$(CPP) $@.exe $@.cpp
011:
	$(CPP) $@.exe $@.cpp
012:
	$(CPP) $@.exe $@.cpp
013:
	$(CPP) $@.exe $@.cpp
014:
	$(CPP) $@.exe $@.cpp
015:
	$(CPP) $@.exe $@.cpp
016:
	$(CPP) $@.exe $@.cpp
017:
	$(CPP) $@.exe $@.cpp
018:
	$(CPP) $@.exe $@.cpp
019:
	$(CPP) $@.exe $@.cpp
020:
	$(CPP) $@.exe $@.cpp

clean:
	rm -r *.exe
