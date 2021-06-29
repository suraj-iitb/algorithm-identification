#include<iostream>

using namespace std;

void swap(int& a, int& b){
    a = a ^ b; b = a ^ b; a = a ^ b;
}

int selectSort(int a[], int n){
    int cnt = 0;
    for(int i = 1; i <n; ++i){
        a[0] = i;
        for(int j = i + 1; j <= n; ++j){
            if(a[j] < a[a[0]]) a[0] = j;
        }
        if(a[0] != i) { swap(a[a[0]], a[i]); ++cnt; }
    }
    return cnt;
}

int main(){
    int n, cnt = 0;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) cin >> a[i];
    cnt = selectSort(a, n);
    for(int i = 1; i < n; ++i) cout << a[i] << " ";
    cout << a[n] << endl << cnt << endl;
    return 0;
}
