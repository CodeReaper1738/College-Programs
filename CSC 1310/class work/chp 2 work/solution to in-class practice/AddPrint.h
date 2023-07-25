#ifndef ADDPRINT_H
#define ADDPRINT_H

#include <iostream>
using namespace std;

template <typename HELLO>
class AddPrint
{
	private:
	public:
		HELLO add(HELLO x, HELLO y)
		{
			return x+y;
		}
		void print(HELLO x)
		{
			cout << x << endl;
		}
};


#endif
