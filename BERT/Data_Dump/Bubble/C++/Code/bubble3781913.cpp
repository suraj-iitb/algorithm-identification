#include<iostream>

using namespace std;

void swap(int& a, int& b){
    a = a ^ b; b = a ^ b; a = a ^ b;
}

int bubbleSort(int a[], int n){
    int cnt = 0;
    for(int i = 1; i < n; ++i){
        int f = 1;
        for(int j = n; j > i; --j){
            if(a[j] < a[j - 1]) { swap(a[j], a[j - 1]); ++cnt; f = 0;}
        }
        if(f) break;
    }
    return cnt;
}

int main(){
    int n, cnt = 0; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) cin >> a[i];
    cnt = bubbleSort(a, n);
    for(int i = 1; i < n; ++i) cout << a[i] << " ";
    cout << a[n] << endl << cnt << endl;
    return 0;
}

