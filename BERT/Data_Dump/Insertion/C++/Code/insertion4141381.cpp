#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void trace(int n, vector<int> &a){
    for (int k = 0; k < n; k++){
        if (k != n-1) cout << a[k] << " ";
        else cout << a[n-1] << endl;
    }
}


void insertionSort(int n, vector<int> & a){
    for (int i = 1; i < n; i++){
        int j = i - 1;
        int temp = a[i];
        
        while(j >= 0 && a[j] > temp){
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = temp;
        
        trace(n, a);
    }
    
}


int main(void){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n; i++){
        if (i != n-1) cout << a[i] << " ";
        else cout << a[i] << endl;
    }
    
    insertionSort(n, a);
}

