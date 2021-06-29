#include <iostream>
using namespace std;

int selectionSort(int a[], int n){
    int i,j,t,sw = 0, minj;
    for(int i=0;i<n;i++){
        minj = i;
        for(j = i; j < n; j++){
            if(a[j] < a[minj] ) minj = j;
            }
            t = a[i];
            a[i] = a[minj];
            a[minj] = t;
            if( i != minj) sw++;
    }
    return sw;
}

int main(){
    int n, i, sw;
    int a[100];

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    sw = selectionSort(a, n);

    for(i=0;i<n;i++){
        if(i>0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}

