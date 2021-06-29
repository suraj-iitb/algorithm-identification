#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int>&, const int);
void writeVector(const vector<int>&);
void readStdIn(int&, vector<int>&);

void SelectionSort(vector<int>& v, const int n_elem){
	int n_swp = 0;
	for(int i=0; i<n_elem; i++){
		int min_i = i;
		for(int j=i; j<n_elem; j++){
			if(v.at(j) < v.at(min_i)){
				min_i = j;
			}
		}

		if(i != min_i){
		    int tmp = v.at(i);
		    v.at(i) = v.at(min_i);
		    v.at(min_i) = tmp;
		    n_swp = n_swp + 1;
		}
	}
	writeVector(v);
	cout << n_swp << "\n";
}

void readStdIn(int& n_elem, vector<int>& v){
	cin >> n_elem;
	for(int i; i<n_elem; i++){
		int input;
		cin >> input;
		v.push_back(input);
	}
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
	vector<int> v;
	readStdIn(n_elem, v);

	SelectionSort(v, n_elem);

	return 0;
}

