/*List.h*/

#include "List.h"
#include "time.h"

List::List(){
	this->size = 0;
	cout << "Object (type List) was created by default constructor" << endl;
}

//List::List(int size){
//	this->size = size;
//	this->workers = (Worker*)malloc((this->size)*sizeof(Worker));
//	cout << "Object (type List) was created by constructor with parameters" << endl;
//}

//List::~List(){
//	this->size = 0;
//	free(this->workers);
//	cout << "Object (type List) was deleted" << endl;
//}

int List::getSize(){
	return this->size;
}

//void List::setSize(int size){
//	this->size = size;
//}


void List::add(){

	Worker *wr = new Worker();
	cin >> *wr;
	this->size++;
	Worker **copy = new Worker*[this->size-1];
	for (int i = 0; i < this->size-1; i++){
		copy[i] = this->workers[i];
	}
	this->workers = new Worker*[this->size];
	for (int i = 0; i < this->size - 1; ++i) {
		this->workers[i] = copy[i];
	}
	this->workers[this->size - 1] = wr;
	delete[]copy;
	//return *this;
}

//ostream& operator<<(ostream &is, List &list){
//	try {
//		if (list.getSize() == 0){
//			cout << "Empty list" << endl;
//			return is;
//		}
//		for (int i = 0; i < list.getSize(); i++){
//			cout << *list.workers[i] << endl;
//		}
//	}
//	catch (exception ex) {
//		cout << "List is empty" << endl;
//	}
//	return is;
//}

void List::print() {
	if (this->size == 0)
		cout << "Empty list" << endl;
	else{
		for (int i = 0; i < this->size; ++i) {
			cout << *this->workers[i] << endl;
		}
	}
}

void List::sort(){
	for (int i = 0; i < this->size; i++){
		for (int j = 0; j < this->size; j++){
			if ((*this->workers[i]).getName().compare((*this->workers[j]).getName())>0){
				Worker *worker = this->workers[i];
				this->workers[i] = this->workers[j];
				this->workers[j] = worker;
			}
		}
	}
	//return *this;
}

void List::find(int value){
	time_t t;
	struct tm *current;
	time(&t);
	current = localtime(&t);
	int curyear = current->tm_year + 1900;
	int fl = 0;
	for (int i = 0; i < this->size; i++){
		if (curyear - (*this->workers[i]).getYear() > value){
			cout << workers[i] << endl << endl;
			fl = 1;
		}
	}
	if (fl == 0)
		cout << "no workers with such work experience";
}