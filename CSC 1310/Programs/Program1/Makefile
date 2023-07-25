#Makefile for program 1 - video game library

all					:	Program1

Program1			:	Program1.o VideoGame.o VideoGameLibrary.o Text.o
						g++ -o Program1.exe Program1.o VideoGame.o VideoGameLibrary.o Text.o

Program1.o			:	Program1.cpp
						g++ -I ./ -c Program1.cpp
				
VideoGame.o			:	VideoGame.cpp
						g++ -I ./ -c VideoGame.cpp
			
VideoGameLibrary.o	:	VideoGameLibrary.cpp
						g++ -I ./ -c VideoGameLibrary.cpp
			
Text.o				:	Text.cpp
						g++ -I ./ -c Text.cpp