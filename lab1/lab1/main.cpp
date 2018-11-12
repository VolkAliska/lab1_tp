/*main.cpp*/

#include <iostream>
#include "Worker.h"
#include "List.h"

using namespace std;

int main(){
	
	char mode;
	List *finded = new List();
	List *wlist = new List();
	Worker *wr = new Worker();
	int flagout = 0;
	while (true){
		if (flagout)
			break;
		cout << "1 - Show list" << endl;
		cout << "2 - Add worker" << endl;
		cout << "3 - Find workers by work experience" << endl;
		cout << "4 - Escape" << endl;
		cin >> mode;
    	switch (mode){
		case '1':
			wlist->sort();
			wlist->print();
			break;
		case '2':
			cin >> *wr;
			wlist->add(wr);
			break;
		case '3':
			cout << "Enter value" << endl;
			int value;
			cin >> value;
			wlist->sort();
			*finded = wlist->find(value, finded);
			finded->print();
			break;
		case '4':
			flagout = 1;
			break;
		}
	}
	delete finded;
	delete wlist;
	delete wr;
	return 0;
}