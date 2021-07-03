#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

template<typename T>
class Lnode{

	public:
		T data;
		Lnode *lptr;
		Lnode *rptr;
};

template<typename T>
class Mlist{
	public:
		Mlist();
		void add(T x);
		void del(T x);
		void del();
		T getFront();

	private:
		Lnode<T> *first;
		Lnode<T> *last;
		int lsize;
};


// Mlist Function Definitions
template<typename T>
Mlist<T>::Mlist(){
	first = 0;
	last = 0;
	lsize = 0;
}

template<typename T>
void Mlist<T>::add(T x){
	Lnode<T> *ptr =  new Lnode<T>;
	ptr->data = x;

	if(lsize == 0){
		ptr->lptr = 0;
		ptr->rptr = 0;
		first = ptr;
		last = ptr;
	}
	else{
		ptr->lptr = last;
		ptr->rptr = 0;
		last->rptr = ptr;
		last = ptr;
	}
	lsize++;
}

template<typename T>
void Mlist<T>::del(T x){

}

template<typename T>
void Mlist<T>::del(){
	Lnode<T> *cur = first;
	first = first->rptr;
	delete cur;
	first->lptr = 0;
	--lsize;
}

template<typename T>
T Mlist<T>::getFront(){
	return first->data;
}

int main(){
	srand(time(NULL));
	Mlist<int> list;

	for(int i = 0; i < 10; i++){
		list.add(rand() % 10 + 1);
	}

	cout << list.getFront() << endl;

	return 0;
}
