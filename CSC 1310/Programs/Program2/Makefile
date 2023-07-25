all				:	DinasaurFight

DinasaurFight	:	DinasaurFight.o
					g++ -o DinasaurFight.exe DinasaurFight.o
				
DinasaurFight.o	:	DinasaurFight.cpp
					g++ -I ./ -c DinasaurFight.cpp
				
clean			:	DinasaurFight.exe
					del *.o
					del DinasaurFight.exe