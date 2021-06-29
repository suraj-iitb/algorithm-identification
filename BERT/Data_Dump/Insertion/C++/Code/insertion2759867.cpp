#include <iostream>
using namespace std;

int main() {
	int a; cin >> a;
	int b[a];
	for (int i = 0; i < a; i++) cin >> b[i];
	for (int i = 0; i < a - 1; i++) cout << b[i] << " ";
    cout << b[a - 1] << endl;
	for (int i = 1; i < a; i++) {
	    int key = b[i], j = i - 1;
	    while (j >= 0 && b[j] > key) {
	        b[j + 1] = b[j];
	        j--;
	    }
	    b[j + 1] = key;
	    for (int i = 0; i < a - 1; i++) cout << b[i] << " ";
    	cout << b[a - 1] << endl;
	}
}

