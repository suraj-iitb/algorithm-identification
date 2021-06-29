#include<iostream>
using namespace std;

const int MAX = 500000;
const int SENTINEL = 2000000000;

int *L, *R;
int cnt;

void merge(int a[], int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i=0; i<n1; ++i) L[i] = a[left+i];
    for(int i=0; i<n2; ++i) R[i] = a[mid+i];

    L[n1] = R[n2] = SENTINEL;
    int i=0, j=0;
    for(int k=left; k<right; ++k){
        ++cnt;
        if(L[i] <= R[j]){
            a[k] = L[i++];
        }else{
            a[k] = R[j++];
        }
    }
}

void mergeSort(int a[], int n, int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(a, n, left, mid);
        mergeSort(a, n, mid, right);
        merge(a, n, left, mid, right);
    }
}


int main(){
    int *a, n;
    cnt = 0;

    cin >> n;
    a = new int[n];
    for(int i=0; i<n; ++i) cin >> a[i];

    L = new int[n/2 + 2];
    R = new int[n/2 + 2];
    mergeSort(a, n, 0, n);
    delete[] L, R;

    for(int i=0; i<n; ++i){
        if(i) cout << " ";
        cout << a[i];
    }
    delete[] a;

    cout << endl;

    cout << cnt << endl;
}

