all:	Zoo.exe

Zoo.exe: Creature.o Zoo.o
			g++ -o Zoo.exe Creature.o Zoo.o

#-----------------------------------------------------------

Zoo.o:	Zoo.cpp
		g++ -c Zoo.cpp

Creature.o:	Creature.cpp
		g++ -c Creature.cpp

#-----------------------------------------------------------

clean: 
		del *.o
		del *.exe
		del RESULT_OF_TEST_CASE.txt
		del newCreatureList.txt