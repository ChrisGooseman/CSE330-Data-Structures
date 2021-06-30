/*
 * Author: Christopher Guzman
 * File: Lab1 - Part 1
 * Course: Murphy - CSE330
 */

#include <iostream>
#include <unistd.h>

using namespace std;

class Time{
	public:
		Time(int h, int m);
		int gethours() const;
		int getminutes() const;
		void addminute();
		void subtractminute();
		bool operator==(Time t);
		void operator++(); //prefix
		void operator++(int); // postfix
		void operator--(); //prefix
		void operator--(int); // postfix
	private:
		int hours;
		int minutes;
};

Time::Time(int h, int m){
	hours = h;
	minutes = m;
}

int Time::gethours() const{
	return hours;
}

int Time::getminutes() const{
	return minutes;
}

void Time::addminute(){
	minutes++;
	if(minutes == 60){
		minutes = 0;
		hours++;
	}
	if(hours == 13){
		hours = 1;
	}
}

void Time::subtractminute(){
	minutes--;
	if(minutes == -1){
		minutes = 59;
		hours--;
	}
	if(hours == 0)
		hours = 12;
}

bool Time::operator==(Time t){
	if(this->gethours() != t.gethours())
		return false;
	if(this->getminutes() != t.getminutes())
		return false;
	
	return true;
}

void Time::operator++(){
	this->addminute();
}

void Time::operator++(int){
	this->addminute();
}

void Time::operator--(){
	this->subtractminute();
}

void Time::operator--(int){
	this->subtractminute();
}

/**** MAIN PROGRAM ****/
int main(){
	// declare Time objects
	Time time = Time(1, 15);	
	
	cout << "Starting time - " << time.gethours() << ":" << time.getminutes()
		<< endl;
	// Testing prefix and postfix 
	for(int i = 0; i < 30; i++)
		--time;
    cout << "Time after 30 minutes subtracted with prefix notation - " 
		<< time.gethours() << ":" << time.getminutes() << endl;
	
	for(int i = 0; i < 30; i++)
		time--;
	cout << "Time after 30 more minutes subtracted with postfix notation - "
		<< time.gethours() << ":" << time.getminutes() << endl;
	return 0;
}
