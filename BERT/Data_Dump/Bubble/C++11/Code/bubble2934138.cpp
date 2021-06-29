//============================================================================
// Name        : BubbleSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int BubbleSort(vector<int>&);
void writeVector(const vector<int>&);

int BubbleSort(vector<int>& v){
	int flag = 1;
	int n_swp = 0;
	while(flag){
		flag = 0;
		for(int i=v.size()-1; i>=1; i--){
			if(v.at(i-1)>v.at(i)){
				int tmp = v.at(i);
				v.at(i) = v.at(i-1);
				v.at(i-1) = tmp;
				flag = 1;
				n_swp = n_swp + 1;
			}
		}
	}
	return n_swp;
}


void writeVector(const vector<int>& v){
	for(int i=0; i<v.size(); i++){
		if(i==v.size()-1){
			cout << v.at(i);
			break;
		}
		cout << v.at(i) << " ";
	}
	cout << "\n";
}

int main() {
	int n_elem;
	cin >> n_elem;
	vector<int> v;
	int input;
	for(int i=0; i<n_elem; i++){
		cin >> input;
		v.push_back(input);
	}

	int n_swp;
	n_swp = BubbleSort(v);

    writeVector(v);
    cout << n_swp << "\n";


	return 0;
}

