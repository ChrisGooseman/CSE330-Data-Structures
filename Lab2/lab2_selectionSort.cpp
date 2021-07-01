/* Author: Christopher Guzman
 * Class: CSE330 - MURPHY
 * File: Lab-2 - Selection Sort
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void selectionSort(vector<int>& v){
	int n = v.size();
	for(int i = 0; i < n-1; i++){
		for(int j =i+1; j < n; j++){
			if(v[i] > v[j]){
				swap(v[i], v[j]);
			}
		}
	}
}

int main(){
	clock_t start, finish;
	srand(time(NULL));
	vector<int> v;

	int n = 0; 
	cout << "Enter the size of input: ";
	cin >> n;

	for(int i = 0; i < n; i++){
		v.push_back(rand());
	}

	start= clock();
	selectionSort(v);
	finish = clock();

	cout << "Time = " << finish - start << endl;

/*	// For testing sort
	
	int n = 15;
	for(int i = 0; i < n; i++){
		v.push_back(rand() % 100);
	}

	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;

	selectionSort(v);

	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;

*/	// Testing done

	return 0;
}
