CPP := g++ -Wall -o

all: problems tools

problems: 001 002 003 005 006 007 008 009 010

tools: integers

integers:
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
