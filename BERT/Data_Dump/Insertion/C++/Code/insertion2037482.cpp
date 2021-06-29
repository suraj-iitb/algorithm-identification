#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

void printv(vector<int> a){
	for (int i = 0; i < a.size(); i++){
		cout << a[i];
		if (i != a.size() - 1) cout << " ";
	}
	cout << endl;
}

void insertionSort(vector<int> &a, int n){
	int v, j;
	for (int i = 1; i < n; i++){
		printv(a);
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	insertionSort(a, n);
	printv(a);
}
