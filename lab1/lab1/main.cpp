/*main.cpp*/

#include <iostream>
#include "Worker.h"
#include "List.h"

using namespace std;

int main(){
	List wlist;
	cout << "1 - Show list" << endl;
	cout << "2 - Add worker" << endl;
	cout << "3 - Find workers by work experience" << endl;
	cout << "4 - Escape" << endl;
	char mode;
	while (true){

		mode = getchar();
		switch (mode){
		case '1':
			wlist.Sort();
			cout << wlist << endl;
			break;
		case '2':
			cin >> wlist;
			break;
		case '3':
			cout << "Enter value" << endl;
			int value;
			cin >> value;
			wlist.Find(value);
			break;
		case '4':
			break;
		}
	}
	return 0;
}