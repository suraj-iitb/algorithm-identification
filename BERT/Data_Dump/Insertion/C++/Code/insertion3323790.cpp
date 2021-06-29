#include <iostream>
#include <algorithm>
using namespace std;

void InsertionSort(int* a, int n){
    int i, v, j, k;

    for (i=1; i<n; i++){
        for (k=0; k<n; k++){
            if (k == n-1){ cout << a[k] <<endl; }
            else { cout << a[k] << " "; }
        }

        v = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = v;
    }
}

int main(){
    int n;

    cin >> n;

    int a[n];
    int* ap;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    ap = a;

    InsertionSort(ap, n);
    for (int k=0; k<n; k++){
        if (k == n-1){ cout << a[k] << endl; }
        else { cout << a[k] << " "; }
    }

    return 0;
}

