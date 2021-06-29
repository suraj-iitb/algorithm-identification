#include<iostream>
using namespace std;

int main() {
    int n, v, j;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (i==n-1) {
            cout << a[i] << endl;
        } else {
            cout << a[i] << " "; 
        }
    }
    for (int i=1; i<n; i++) {
        v = a[i];
        j = i-1;
        while (j>=0 && a[j]>v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        cout << a[0];
        for (int k=1; k<n; k++){
        cout << " " << a[k];
        }
        cout << endl;
    }
}
