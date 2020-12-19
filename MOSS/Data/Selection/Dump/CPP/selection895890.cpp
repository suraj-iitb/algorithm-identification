#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int suretu[100];
	int counter = 0;
	int mini;
	
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		cin >> suretu[i];
	}

	for (int i = 0; i < n; ++i) {
		mini = i; 
		for (int j = i; j < n; j++) {
			if (suretu[j] < suretu[mini]) {
				mini = j;
			}
		}
		if (i != mini) {
			swap(suretu[i], suretu[mini]);
			counter++;
		}
	}

	cout << suretu[0] << flush;

	for (int i = 1; i < n; i++) {
		cout << ' ' << suretu[i];
	}

	cout << endl << counter << endl; 

	return 0;
}
