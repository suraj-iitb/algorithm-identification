#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int cnt;
#define rep(i,n) for(int i=0;i<(n);i++)
const long long mod = 1e9 + 7;
#define inf 1000000001
void merge(int a[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int l[n1 + 1], r[n2 + 1];
    rep(i, n1) l[i] = a[left + i];
    rep(i, n2) r[i] = a[mid + i];
    l[n1] =  inf;
    r[n2] = inf;
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(l[i] <= r[j]){
            a[k] = l[i];
            i++;
        }else{
            a[k] = r[j];
            j++;
        }
    }
}

void mergesort(int a[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main(){
    int a[5000000], n;
    cnt = 0;
    cin >> n;
    rep(i, n) cin >> a[i];
    mergesort(a, 0, n);
    rep(i, n){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl << cnt << endl;
}
