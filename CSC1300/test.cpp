#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>

using namespace std;

int main() {
	
	char word[21] = "Hello";
	char underScores[21] = "________";
	int x = strlen(word);
	char letter;
	cout << "letter?";
	cin >> letter;
	
	for (int r = 0; r < x; r++) {
		if(letter == word[r]) {
			underScores[r] = word[r];
			cout << underScores[r] << endl;
			cout << word[r] << endl;
		}
	}
	cout << "hello";
			
}