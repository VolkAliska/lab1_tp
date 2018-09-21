/*List.h*/

#include "List.h"
#include "time.h"

List::List(){
	this->size = 0;
	this->workers = (Worker*)malloc((this->size)*sizeof(Worker));
	cout << "Object (type List) was created by default constructor" << endl;
}

List::List(int size){
	this->size = size;
	this->workers = (Worker*)malloc((this->size)*sizeof(Worker));
	cout << "Object (type List) was created by constructor with parameters" << endl;
}

List::~List(){
	this->size = 0;
	free(this->workers);
	cout << "Object (type List) was deleted" << endl;
}

int List::getSize(){
	return size;
}

void List::setSize(int size){
	this->size = size;
}

istream& operator>>(istream &s, List &list){
	try {
		list.size++;
		list.workers = (Worker*)realloc(list.workers, (list.size)*sizeof(Worker));
		Worker wr;
		cin >> wr;
		list.workers[list.size - 1] = wr;
	}
	catch (exception e) {
		printf_s("Cant add Student object to list");
	}
}

void List::Sort(){
	for (int i = 0; i < this->size; i++){
		for (int j = 0; j < this->getSize; j++){
			if (this->workers[i].getName() > this->workers[j].getName()){
				string buf = workers[i].getName();
				workers[i].setName(workers[j].getName());
				workers[j].setName(buf);
			}
		}
	}
}

void List::Find(int value){
	time_t t;
	struct tm *current;
	time(&t);
	current = localtime(&t);
	int curyear = current->tm_year + 1900;
	int fl = 0;
	for (int i = 0; i < this->size; i++){
		if (curyear - workers[i].getYear() > value){
			cout << workers[i] << endl << endl;
			fl = 1;
		}
	}
	if (fl == 0)
		cout << "no workers with such work experience";
}