#include <iostream>
using namespace std;
int a[100], n;
int main(void){
    // Your code here!
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < n - 1; k++) cout << a[k] << ' ';
        cout << a[n - 1] << endl;
        int j = i - 1, v = a[i];
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            a[j] = v;
            j--;
        }
    }
    for (int i = 0; i < n - 1; i++) cout << a[i] << ' ';
    cout << a[n - 1] << endl;
}

