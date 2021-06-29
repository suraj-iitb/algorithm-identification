#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
const long long mod = 1e9 + 7;

struct card{int num; char suit;};
card a[100000];
#define inf 1000000001
void merge(card a[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    card l[n1 + 1], r[n2 + 1];
    rep(i, n1) l[i] = a[left + i];
    rep(i, n2) r[i] = a[mid + i];
    l[n1].num =  inf;
    r[n2].num = inf;
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        if(l[i].num <= r[j].num){
            a[k] = l[i];
            i++;
        }else{
            a[k] = r[j];
            j++;
        }
    }
}

void mergesort(card a[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int partition(int p, int r){
    int x = a[r].num;
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(a[j].num <= x){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i + 1;
}

void quicksort(int p, int r){
    if(p < r){
        int q = partition(p, r);
        quicksort(p, q-1);
        quicksort(q+1, r);
    }
}

int main(){
    int n;
    cin >> n;
    card b[n];
    rep(i, n) cin >> a[i].suit >> a[i].num;
    rep(i, n) b[i] = a[i];
    quicksort(0, n-1);
    mergesort(b, 0, n);
    bool ans = true;
    rep(i, n){
        if(a[i].suit != b[i].suit) ans = false;
    }
    if(ans) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    rep(i, n){
        cout << a[i].suit << " " << a[i].num << endl;
    }
}


