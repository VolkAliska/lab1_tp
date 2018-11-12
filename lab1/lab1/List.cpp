/*List.cpp*/

#include "List.h"
#include "time.h"

List::List(){
	this->size = 0;
	cout << "Object (type List) was created by default constructor" << endl;
}

List::~List(){
	this->size = 0;
	delete[] workers;
	cout << "Object (type List) delete" << endl;
}

int List::getSize(){
	return this->size;
}

void List::add(Worker *wr){
	Worker *buf = new Worker(*wr);
	this->size++;
	Worker **copy = new Worker*[this->size-1];
	for (int i = 0; i < this->size-1; i++){
		copy[i] = this->workers[i];
	}
	this->workers = new Worker*[this->size];
	for (int i = 0; i < this->size - 1; ++i) {
		this->workers[i] = copy[i];
	}
	this->workers[this->size - 1] = buf;
	delete[]copy;
}
 
void List::print() {
	if (this->size == 0)
		cout << "Empty list" << endl;
	else{
		for (int i = 0; i < this->size; ++i) {
			cout << *this->workers[i] << endl;
		}
	}
}

List& List::sort(){
	for (int i = 0; i < this->size; i++){
		for (int j = 0; j < this->size; j++){
			if ((*this->workers[i]).getName().compare((*this->workers[j]).getName())<0){
				Worker *worker = this->workers[i];
				this->workers[i] = this->workers[j];
				this->workers[j] = worker;
			}
		}
	}
	return *this;
}

List& List::find(int value, List *finded){
	time_t t;
	struct tm *current;
	time(&t);
	current = localtime(&t);
	int curyear = current->tm_year + 1900;
	int fl = 0;
	for (int i = 0; i < this->size; i++){
		if (curyear - (*this->workers[i]).getYear() > value){
			finded->add(workers[i]);
			//cout << *workers[i] << endl << endl;
			fl = 1;
		}
	}
	if (fl == 0)
		cout << "no workers with such work experience";
	return *finded;
}