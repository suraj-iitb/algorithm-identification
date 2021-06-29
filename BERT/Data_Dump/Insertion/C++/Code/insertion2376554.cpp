#include <iostream>

using namespace std;

const int MAX_N = 100;

int main() {
    int n;
    int a[MAX_N];

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) {
            cout << " ";
        }
    }

    cout << endl;

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int v = a[i];
        
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = v;
        
        for (int k = 0; k < n; k++) {
            cout << a[k];
            if (k < n - 1) {
                cout << " ";
            }
        }

        cout << endl;
    }

}
