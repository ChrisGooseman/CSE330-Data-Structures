/* 
 * Author: Christopher Guzman
 * Assignment: Lab 6 - Part 1
 * File: lab6_1.cpp
 * Course: CSE330 - Murphy
 */ 

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cassert>

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
		void insert(int i, T x);
		void del(T x);
		void del();
		void erase(int i);
		T getFront();
		T getBack();
		T operator[] (unsigned int i);
		void print();

	private:
		Lnode<T> *first;
		Lnode<T> *last;
		int lsize;
};

// FUNCTION DEFINITIONS
template<typename T>
Mlist<T>::Mlist(){
	this->first = 0;
	this->last = 0;
	this->lsize = 0;
}

template<typename T>
void Mlist<T>::add(T x){
	Lnode<T> *ptr = new Lnode<T>;
	ptr->data = x;

	if(lsize == 0){
		ptr->lptr = 0;
		ptr->rptr = 0;
		this->first = ptr;
		this->last = ptr;
	}
	else{
		ptr->lptr = this->last;
		ptr->rptr = 0;
		this->last->rptr = ptr;
		this->last = ptr;
	}
	lsize++;
}

template <typename T>
void Mlist<T>::insert(int i, T x){
	Lnode<T> *nptr = new Lnode<T>;
	nptr->data = x;
	assert(i >= 0 and i <= lsize);
	if(i == 0 and lsize == 0){
		first = nptr;
		last = nptr;
		nptr->lptr = 0;
		nptr->rptr = 0;
		lsize++;
		return;
	}
	if( i == 0){
		nptr->lptr = 0;
		nptr->rptr = first;
		first = nptr;
		lsize++;
		return;
	}
	if(i == lsize){
		nptr->lptr = last;
		last->rptr = nptr;
		nptr->rptr = 0;
		last = nptr;
		lsize++;
		return;
	}

	Lnode<T> *ptr = first;
	for(int j = 0; j < i; j++)
		ptr = ptr->rptr;
	Lnode<T> *previous = ptr->lptr;
	nptr->rptr = ptr;
	nptr->lptr = previous;
	previous->rptr = nptr;
	ptr->lptr = nptr;
	lsize++;
	return;
}

template<typename T>
void Mlist<T>::del(T x){
	if(lsize == 0)
		return;
	Lnode<T> *ptr = first;
	while(ptr != 0){
		if(ptr->data == x){
			Lnode<T> *next = ptr->rptr;
			Lnode<T> *previous = ptr->lptr;
			if(previous == 0 and next == 0){
				delete first;
				first = 0;
				last = 0;
				lsize--;
				return;
			}
			if(next == 0){
				last = previous;
				last->rptr = 0;
				delete ptr;
				lsize--;
				return;
			}
			if(previous == 0){
				first = ptr->rptr;
				first->lptr = 0;
				delete ptr;
				lsize--;
			}
			else{
				previous->rptr = ptr->rptr;
				next->lptr = ptr->lptr;
				delete ptr;
				ptr = next;
				lsize--;
			}
		}
		else{
			ptr = ptr->rptr;
		}
	}
	
}

template<typename T>
void Mlist<T>::del(){
	Lnode<T> *cur = this->first;
	this->first = this->first->rptr;
	delete cur;
	lsize--;
}

template <typename T>
void Mlist<T>::erase(int i){
	Lnode<T> *ptr = first;
	for(int j = 0; j < i; j++)
		ptr = ptr->rptr;
	Lnode<T> *next = ptr->rptr;
	Lnode<T> *previous = ptr->lptr;
	if(previous == 0 and next == 0){
		delete first;
		first = 0;
		last = 0;
		lsize--;
		return;
	}
	if(next == 0){
		last = previous;
		last->rptr = 0;
		delete ptr;
		lsize--;
		return;
	}
	if(previous == 0){
		first = ptr->rptr;
		first->lptr = 0;
		delete ptr;
		lsize--;
		ptr = first;
	}
	else{
		previous->rptr = ptr->rptr;
		next->lptr = ptr->lptr;
		delete ptr;
		lsize--;
	}
}


template<typename T>
T Mlist<T>::getFront(){
	return this->first->data;
}

template <typename T>
T Mlist<T>::getBack(){
	return this->last->data;
}

template <typename T>
T Mlist<T>::operator[] (unsigned int i){
	assert(lsize > 0);
	Lnode<T> *ptr;
	ptr = first;
	for(int j =0 ; j < i; j++)
		ptr = ptr->rptr;
	return ptr->data;
}

template<typename T>
void Mlist<T>::print(){
	Lnode<T> *ptr;
	ptr = first;
	for(ptr; ptr != 0; ptr = ptr->rptr){
		cout << ptr->data << " ";
	}
	cout << endl;
}

int main(){
	
	srand(time(0));
	Mlist<int> list;

	// add 10 elements to the list.
	for(int i = 0; i < 10; i++){
		list.add(rand() % 10);
	}
	// print list
	cout << "Printing List of random integers.\n";
	list.print();

	// delete first element and print.
	cout << "Deleting first element of list and printing new list\n";
	list.del();
	list.print();

	// print first element of list
	cout << "Printing First element of list.\n";
	cout << list.getFront() << endl;

	// add element using insert function
	cout << "Inserting element at position 3 and printing.\n";
	list.insert(3, 1000);
	list.print();

	// deleting number at postion
	cout << "Erasing number at position 3 and printing.\n";
	list.erase(3);
	list.print();

	// retrieve last element
	cout << "Printing last element.\n";
	cout << list.getBack() << endl;

	// using operator[] to get data
	cout << "Printing list[2]\n";
	cout << list[2] << endl;

	// delete all elements of int 3
	cout << "Removing all elements with value 3 if any.\n";
	list.del(3);
	list.print();

	return 0;
}
