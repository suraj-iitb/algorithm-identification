#include <iostream>
using namespace std;

void insertionSort(int a[], int n){
    int i,j,k,v;
    
    // print
    for(k=0; k<n; k++){
        // cout << a[k] << " ";
        cout << a[k];
        if(k != n-1){cout << " ";}
    }
    cout << endl;
    
    for(i=1; i<n; i++){
        v = a[i];
        j = i-1;
        while( j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;

        // print
        for(k=0; k<n; k++){
            // cout << a[k] << " ";
            cout << a[k];
            if(k != n-1){cout << " ";}
        }
        // if(i != n-1){cout << endl;}
        cout << endl;
    }
}

int main(){
    int n;
    int a[100];
    cin >> n;
    // input
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    insertionSort(a,n);

    return 0;
}
