#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std; 

void printArray(int a[], int n, int cnt){
    rep(i,n - 1) cout << a[i] << " ";
    cout << a[n - 1] << endl;
    cout << cnt << endl;
}

void selectionSort(int a[], int n){
    int cnt = 0;
    rep(i,n){
        int minj = i;
        for(int j = i; j < n; j++){
            if(a[j] < a[minj])
                minj = j;
        }
        swap(a[minj],a[i]);
    
        if(i != minj)
            cnt++;
    }
    printArray(a,n,cnt);
}

int main(){
    int n;
    cin >> n;

   int a[n];
    rep(i,n) cin >> a[i];

    selectionSort(a,n);

    return 0;
}
