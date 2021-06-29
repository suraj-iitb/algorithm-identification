#include <iostream>
using namespace std;

int main() {
    int n,i,j,count,c[100];
    count=0;
    cin >> n;
    for (i=0; i<n; i++) {
        cin >> c[i];
    }
    for (i=n-1; i>=1; i--) {
        for (j=0; j<i; j++) {
            if (c[j] > c[j + 1]) {
                c[j] += c[j + 1];
                c[j + 1] = c[j] - c[j + 1];
                c[j] = c[j] - c[j + 1];
                count++;
            }
        }
    }
    for (i=0; i<n; i++) {
        if (i < n-1) { cout << c[i] << " ";}
            else {
            cout << c[i] << endl;
        }
    }
    cout << count << endl;
}

