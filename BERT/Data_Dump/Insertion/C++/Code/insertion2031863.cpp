#include <iostream>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

void trace(int a[], int n){
    REP(i, n) {
        if (i>0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

void insertionSort(int a[], int n){
    int key;
    REP(i, n) {
        key = a[i];
        int j = i-1;
        while ((j>=0) && (a[j]>key)) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        trace(a, n);
    }
}

int main () {
    int n;
    cin >> n;

    int a[100];
    REP(i, n) {
        cin >> a[i];
    }

    insertionSort(a, n);

    return 0;
}
