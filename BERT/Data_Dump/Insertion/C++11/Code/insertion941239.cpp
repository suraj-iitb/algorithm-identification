#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>v(n);
	for (auto pv = v.begin(); pv != v.end(); ++pv){
		cin >> *pv;
	}
	int key;
	for (auto pv = v.begin(); pv != v.end() - 1; ++pv){
		cout << *pv << " ";
	}
	cout << v[n - 1] << endl;
	for (int i = 1; i < n; i++){
		key = v[i];
		int j = i - 1;
		while (j >= 0 && v[j]>key){
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;
		for (auto pv = v.begin(); pv != v.end() - 1; ++pv){
			cout << *pv << " ";
		}
		cout << v[n - 1] << endl;
	}
	return 0;
}
