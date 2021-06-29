#include <iostream>
using namespace std;
static const int MAX = 1000;

void trace(int *a, int n) {
    for (int i = 0; i < n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}

void insertionSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        trace(a, n);
    }
}

int main() {    
    int a[MAX], n;

    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    trace(a, n);
    insertionSort(a, n);

    return 0;
}

