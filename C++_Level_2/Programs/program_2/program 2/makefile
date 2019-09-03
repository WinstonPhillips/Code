all	:	DogHealth.exe

DogHealth.exe	:	Driver.o DogHealth.o ArrayHelper.o
						g++ -o DogHealth.exe Driver.o DogHealth.o ArrayHelper.o

#Pre .o files

Driver.o	:	Driver.cpp	
					g++ -c Driver.cpp

DogHealth.o	:	DogHealth.cpp
					g++ -c DogHealth.cpp

ArrayHelper.o	:	ArrayHelper.cpp
					g++ -c ArrayHelper.cpp

clean	:	DogHealth.exe
			del *.o
			del	*.exe