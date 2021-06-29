#include <bits/stdc++.h>
using namespace std;
typedef float fl;
typedef long long ll;
#define INF 10000000001;
int S[500001];
int cnt = 0;

void merge(int a[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    ll L[n1+1], R[n2+1];
    for(int i =0; i < n1; i++){
        L[i] = a[left+i];
    }
    for(int i =0; i < n2; i++){
        R[i] = a[mid+i];
    }
    L[n1] = INF;
    R[n2] = INF;
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(L[i]<=R[j]){
            a[k] = L[i++];
        }
        else{
            a[k] = R[j++];
        }
    }
}

void mergeSort(int a[], int left, int right){
    if((left + 1) < right){
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> S[i];
    mergeSort(S,0,n);
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << S[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
