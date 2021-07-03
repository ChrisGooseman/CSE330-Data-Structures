/*
 * Author: Christopher Guzman
 * Assignment: Lab 7 - part 2
 * File: lab7_2.cpp
 * Course: CSE330 - Murphy
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

template <typename T>
class Tnode{
	public:
		T data;
		Tnode *lptr;
		Tnode *rptr;
};

template <typename T>
class Mtree{
	public:
		Mtree();
		void add(T x);
		bool find(T x);
		int size();
		vector<T> inorder();
		vector<T> preorder();
		vector<T> postorder();
		void print();
	private:
		Tnode<T> *root;
		void add(Tnode<T> *ptr, T x);
		bool find(Tnode<T> *ptr, T x);
		void inorder(Tnode<T> *ptr);
		void preorder(Tnode<T> *ptr);
		void postorder(Tnode<T> *ptr);
		int tsize;
		vector<T> v;
};

//Function Definitions
template <typename T>
Mtree<T>::Mtree(){
	root = 0;
	tsize = 0;
}

template <typename T>
void Mtree<T>::add(T x){
	if(tsize == 0){
		Tnode<T> *ptr = new Tnode<T>;
		ptr->lptr = 0;
		ptr->rptr = 0;
		ptr->data = x;
		root = ptr;
	}
	else{
		add(root, x);
	}
	tsize++;
}

template <typename T>
void Mtree<T>::add(Tnode<T> *ptr, T x){
	if(ptr->lptr == 0 and x <= ptr->data){
		Tnode<T> *nptr = new Tnode<T>;
		ptr->lptr = nptr;
		nptr->data = x;
		nptr->lptr = 0;
		nptr->rptr = 0;
		return;
	}
	else if(ptr->rptr == 0 and x > ptr->data){
		Tnode<T> *nptr = new Tnode<T>;
		ptr->rptr = nptr;
		nptr->data = x;
		nptr->lptr = 0;
		nptr->rptr = 0;
		return;
	}
	else if(x <= ptr->data){
		add(ptr->lptr, x);
	}
	else{
		add(ptr->rptr, x);
	}
}

template <typename T>
bool Mtree<T>::find(T x){
	if(tsize == 0)
		return false;
	else
		return find(root, x);
}

template <typename T>
bool Mtree<T>::find(Tnode<T> *ptr, T x){
	if(ptr  == 0)
		return false;
	if(ptr->data == x)
		return true;
	if(x <= ptr->data)
		return find(ptr->lptr, x);
	else
		return find(ptr->rptr, x);
}

template <typename T>
vector<T> Mtree<T>::inorder(){
	v.clear();
	if(tsize == 0)
		return v;
	else{
		inorder(root);
		return v;
	}
}

template <typename T>
void Mtree<T>::inorder(Tnode<T> *ptr){
	if(ptr == 0)
		return;
	else{
		inorder(ptr->lptr);
		v.push_back(ptr->data);
		inorder(ptr->rptr);
	}
}

template <typename T>
vector<T> Mtree<T>::preorder(){
	v.clear();
	if(tsize == 0)
		return v;
	else{
		preorder(root);
		return v;
	}
}

template <typename T>
void Mtree<T>::preorder(Tnode<T> *ptr){
	if(ptr == 0)
		return;
	else{
		v.push_back(ptr->data);
		preorder(ptr->lptr);
		preorder(ptr->rptr);
	}
}


template <typename T>
vector<T> Mtree<T>::postorder(){
	v.clear();
	if(tsize == 0)
		return v;
	else{
		postorder(root);
		return v;
	}
}

template <typename T>
void Mtree<T>::postorder(Tnode<T> *ptr){
	if(ptr == 0)
		return;
	else{
		postorder(ptr->lptr);
		postorder(ptr->rptr);
		v.push_back(ptr->data);
	}
}

template <typename T>
int Mtree<T>::size(){
	return tsize;
}

template <typename T>
void Mtree<T>::print(){
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int main(){
	srand(time(NULL));
	Mtree<int> m = Mtree<int>();
	for(int i = 0; i < 10; i++)
		m.add(rand() % 10);

	m.inorder();
	cout << m.size() << endl;
	
	cout << "Printing Tree in order form:\n";
	m.print();

	cout << "Printing Tree in preorder form:\n";
	m.preorder();
	m.print();

	cout << "Printing Tree in postorder formL\n";
	m.postorder();
	m.print();

	//find 1 in tree
	cout << "Is the number 1 in the list?" << endl;
	if(m.find(1))
		cout << "Yes it is\n";
	else
		cout << "No it is not.\n";
	return 0;
}
