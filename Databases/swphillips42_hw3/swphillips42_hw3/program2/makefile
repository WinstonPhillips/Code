.PHONY: run

all: run
	
run: program2.exe
	mono program2.exe

program2.exe: program2.cs
	dmcs program2.cs -r:System.Data.dll -r:/usr/lib/cli/MySql.Data.6.4/MySql.Data.dll
