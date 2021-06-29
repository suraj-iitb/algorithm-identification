
#include<iostream>
#include<string>
#include<algorithm>
#define _USE_MATH_DEFINES
#include<math.h>
#include<iomanip>

using namespace std;



int main() {
	int i,j,k,n,v;
	int box[100] = {};
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> box[i];
	}
	for (i = 0; i < n; i++) {
		if (i == (n - 1)) { cout << box[i]; }
		else { cout << box[i] << " "; }
	}
	cout << endl;
	for (i = 1; i < n ;i++) {
		v = box[i];
		j = i - 1;
		while (j >= 0 && box[j] > v) {
			box[j+1] = box[j];
			j--;
		}
		box[j + 1] = v;
		for (k = 0 ;k < n; k++) {
			if (k == (n - 1)) { cout << box[k]; }
			else { cout << box[k] << " "; }
		}
		cout << endl;
	}
	return 0;
}

