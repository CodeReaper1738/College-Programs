# this is the Makefile for the Planet program
# all you have to do is type the word "make" in the command prompt to compile

all			:	Planet

Planet		:	Planet.o Driver.o
			g++ -o Planet.exe Planet.o Driver.o

#here is how to generate the .o file
#if any of the files listed has been altered since the last compile, generate a new .o file
Planet.o	:	Planet.cpp
			g++ -std=c++11 -c Planet.cpp
			
Driver.o	:	Driver.cpp
			g++ -std=c++11 -c Driver.cpp
			
			