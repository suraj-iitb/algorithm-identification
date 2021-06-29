#include <iostream>
using namespace std;

void display(int a[], int n);

int main() {
    int num;
    cin >> num;

    int a[num];
    for ( int i = 0; i < num; i++ ) cin >> a[i];

    display(a, num);

    for ( int i = 1; i < num; i++ ) {
        int j = i - 1;
        int key = a[i];

        while ( j >= 0 && a[j] > key ) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        display(a, num);
    }
}

void display(int a[], int n) {
    for ( int i = 0; i < n - 1; i++ ) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}