#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

void printArray(int a[], int n, int cnt){
    for(int i = 0; i < n - 1; i++) cout << a[i] << " ";
    cout << a[n - 1] << endl;
    cout << cnt << endl;
}

void bubbleSort(int n, int a[]){
    bool flag = true;
    int cnt = 0;
    int idx = 0;
    while(flag){
        flag = false;
        for(int i = n - 1; i >= idx + 1; i--){
            if(a[i] < a[i - 1]){
                swap(a[i], a[i - 1]);
                cnt++;
                flag = true;
            }
        }
        idx++;
    }
    printArray(a,n,cnt);
}

int main(){
    int n;
    cin >> n;

    int a[n];
    rep(i,n) cin >> a[i];

    bubbleSort(n,a);  

    return 0;
}
