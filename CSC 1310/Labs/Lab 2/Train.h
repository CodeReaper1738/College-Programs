#ifndef TRAIN_H
#define TRAIN_H

#include<iostream>
#include<string>

using namespace std;

template<typename Hello>
class Train {
	private: 
		string nameTrain;
		string homeTrain;
		
		int capacityTrain;
		int numPassengers;
		
		
		Hello* passengers;
	public: 
		Train(string name, string home, int totPass) {
			nameTrain = name;
			homeTrain = home;
			capacityTrain = totPass;
			
			passengers = new Hello[capacityTrain];
			
			numPassengers = 0;
		}
		~Train() {
			delete [] passengers;
		}
		
		string getTrainName() {
			return nameTrain;
		}
		
		void addPassenger(Hello num) {
			if(numPassengers == capacityTrain) {
				cout << "\nNo more passengers can board the train\n";
			} else {
				passengers[numPassengers] = num;
				numPassengers++;
			}
		}
		
		void printPassengers() {
			for(int i = 0; i < numPassengers; i++){
				cout << *passengers[i];
			}
		}
	
	
};
#endif