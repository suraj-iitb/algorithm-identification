#include <iostream>

using namespace std;

int main() {
	int a; cin >> a;
	int b[a];
	for (int i = 0; i < a; i++) {
	    cin >> b[i];
	}
	int c, d = 0;
	do {
	    c = 0;
	    for (int o = 1; o < a; o++) {
	        int u = o - 1;
	        if (b[u] > b[o]) {
	            int x = b[u];
	            b[u] = b[o];
	            b[o] = x;
	            c++;
	        }
	    }
        d += c;
    } while (c > 0);
    for (int i = 0; i < a - 1; i++) cout << b[i] << " ";
    cout << b[a - 1] << endl << d << endl;
}

