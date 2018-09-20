/*main.cpp*/

#include <iostream>
#include "Worker.h"

using namespace std;

int main(){
	Worker wr1;
	Worker wr2("Denisov A.S.", "dantist", 2003);
	cin >> wr1;
	cout << wr2;
	cout << wr1;
	wr1.setPost("therapist");
	cout << wr1;
	return 0;
}