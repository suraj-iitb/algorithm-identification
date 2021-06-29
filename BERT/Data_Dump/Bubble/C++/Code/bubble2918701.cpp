#include <iostream>
#include "algorithm"
using namespace std;

int main() {
    int n;
    int *a;

    cin >> n;
    a = new int [n];
    for ( int i = 0; i <n ; i++ ) {
        cin >> a[i] ;
    }

    int sw = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n -1; j >= i + 1; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                sw++;
            }
        }
    }

    for (int i = 0; i < n ; i++) {
        if (i) cout << " ";
        cout << a[i] ;
    }
    cout << endl << sw << endl;
    return 0;
}

