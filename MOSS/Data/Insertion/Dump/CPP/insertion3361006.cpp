#include<iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
         if (i) cout << " ";
         cout << a[i];
    }
    cout << endl;
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (a[j + 1] < a[j]) {
                swap(a[j + 1], a[j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i) cout << " ";
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}

