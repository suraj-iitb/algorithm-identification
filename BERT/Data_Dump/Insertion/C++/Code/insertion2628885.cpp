#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>

typedef long long ll;

using namespace std;

void printArray(int n, int *x){
    for(int i = 0; i < n; i++){
        cout << x[i];
        if(i < n-1){
            cout << " ";
        }
    }
    cout << endl;
}

void insertionSort(int *a, int n){
    for(int i = 1; i < n; i++){
        int v = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        printArray(n, a);
    }
}

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    printArray(n, a);
    insertionSort(a, n);
}

int main() {
    solve();
    return 0;
}
