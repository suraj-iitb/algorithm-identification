#include<bits/stdc++.h>
using namespace std;
#define INF 1000000001

int cnt;

void merge(int a[], int left, int mid, int right){
    int l[mid-left+1], r[right-mid+1];
    l[mid-left] = INF;
    r[right-mid] = INF;
    for(int i = 0; i < mid - left; i++) l[i] = a[left + i];
    for(int i = 0; i < right - mid; i++) r[i] = a[mid + i];
    int j = 0, k = 0;
    for(int i = left; i < right; i++){
        l[j] <= r[k] ? a[i] = l[j++] : a[i] = r[k++];
        cnt++;
    }
}

void mergeSort(int a[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main(){
    int n; cin >> n;
    int a[n];
    
    for(int i = 0; i < n; i++) cin >> a[i];
    
    mergeSort(a, 0, n);

    for(int i = 0; i < n; i++)
        i != n-1 ? cout << a[i] << " " : cout << a[i] << endl;
    
    cout << cnt << endl;
    
    return 0;
}
