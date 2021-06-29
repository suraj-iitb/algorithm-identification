#include <iostream>
#include <vector>
#include<algorithm>
#include <sstream>

using namespace std;

void writeVector(const vector<int>&);

int main() {
	int n_elem;
	cin >> n_elem;
    vector<int> v;
    int input;
    for(int i=0; i<n_elem; i++){
    	cin >> input;
    	v.push_back(input);
    }

	for(int i=0; i<v.size(); i++){
		int key = v.at(i);
		int j = i - 1;
		while(j>=0 and v.at(j)>key){
			v.at(j+1) = v.at(j);
			j--;
		}
		v.at(j+1) = key;
		writeVector(v);
	}

	return 0;
}

void writeVector(const vector<int>& v){
	for(int i=0; i<v.size(); i++){
		if(i==v.size()-1){
			cout << v.at(i);
			break;
		}
		cout << v.at(i) << " ";
	}
	cout << endl;
}
