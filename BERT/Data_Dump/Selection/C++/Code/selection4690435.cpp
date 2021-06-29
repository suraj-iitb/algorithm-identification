#include <bits/stdc++.h>
using namespace std;

int selectionSort(int a[], int n){
    int sw = 0, minj, i, j;
    for (i=0; i<n-1; i++){
        minj = i;
        for (j=i; j<n; j++){
            if (a[j] < a[minj])
                minj = j;
        }
        swap(a[i], a[minj]);
        if (i != minj) sw++;
    }
    return sw;
}

int main(void){
    int i, n, sw;
    cin >> n;
    int a[n];
    for (i=0; i<n; i++) cin >> a[i];
    
    sw = selectionSort(a, n);
    
    for (i=0; i<n; i++){
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << endl;
    cout << sw << endl;
    
    return 0;
}

