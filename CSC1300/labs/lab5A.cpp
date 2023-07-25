/* 
	File Name: lab5A.cpp
	Author: Yago Romano, Tyler Bradshaw
	Date: September 25, 2019
	Purpose: Text message expander
*/

#include<iostream> 
#include<string>

using namespace std;

int main() {
	
	
	string BFF = "best friend forever";
	string IDK = "I don't know";
	string JK = "just kidding";
	string TMI = "too much information";
	string TTYL = "talk to you later";
	string YMMD = "you made my Day";
	string W8 = "wait";
	string QT = "cutie";
	string AYTMTB = "and you're telling me this because";
	string M8 = "mate";
	
	string text;
	
	cout << "Enter text: ";
	getline(cin, text);
	cout << "\nYou entered: " << text << endl;
	
	if(text.find("IDK") != string::npos) {
		cout << " Expanded: " << text.replace(text.find("IDK"), 3, IDK) << endl;
	}
	if(text.find("W8") != string::npos) {
		cout << " Expanded: " << text.replace(text.find("W8"), 2, W8) << endl;
	}
	if(text.find("AYTMTB") != string::npos) {
		cout << " Expanded: " << text.replace(text.find("AYTMTB"), 6, AYTMTB) << endl;
	}
	if(text.find("QT") != string::npos) {
		cout << " Expanded: " << text.replace(text.find("QT"), 2, QT) << endl;
	}
	if(text.find("BFF") != string::npos) {
		cout << " Expanded: " << text.replace(text.find("BFF"), 3, BFF) << endl;
	}
	if(text.find("JK") != string::npos) {
		cout << " Expanded: " << text.replace(text.find("JK"), 2, JK) << endl;
	}
	if(text.find("TMI") != string::npos) {
		cout << " Expanded: " << text.replace(text.find("TMI"), 3, TMI) << endl;
	}
	if(text.find("TTYL") != string::npos) {
		cout << " Expanded: " << text.replace(text.find("TTYL"), 4, TTYL) << endl;
	}
	if(text.find("YMMD") != string::npos) {
		cout << " Expanded: " << text.replace(text.find("YMMD"), 4, YMMD) << endl;
	}
	if(text.find("M8") != string::npos) {
		cout << " Expanded: " << text.replace(text.find("M8"), 2, M8) << endl;
	}
	return 0;
}