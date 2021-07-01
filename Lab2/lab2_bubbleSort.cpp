/* Author: Christopher Guzman
 * Class: CSE330 - MURPHY
 * File: Lab2 - BubbleSort
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void bubbleSort(vector<int>& v){
	int n = v.size();
	for(int i = n-1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j] > v[j+1]){
				swap(v[j], v[j+1]);
			}
		}
	}
}

int main(){
	clock_t start, finish;
	srand(time(NULL));
	vector<int> v;

	int n = 0;
	cout << "Enter the size of input: " ;
	cin >> n;

	for(int i = 0; i < n; i++){
		v.push_back(rand());
	}
	start = clock();
	bubbleSort(v);
	finish = clock();

	cout << "Time = " << finish - start << endl;
	

	/* TESTING THE SORT FUNCTION

	int n = 15;
	for(int i = 0; i < n; i++){
		v.push_back(rand()%100);
	}
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << "\n";
	bubbleSort(v);
	
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << "\n";
	
	TESTING DONE */
	return 0;
}
