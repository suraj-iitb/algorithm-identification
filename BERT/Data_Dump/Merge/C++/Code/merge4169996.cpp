#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;
#define INF 2000000000
#define MAX 500000

int L[MAX /2 + 2], R[MAX / 2 + 2];
int cnt;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    //L[n1],R[n2]を生成
    for(int i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = INF;
    R[n2] = INF;

    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right){
    if(left + 1 < right){
        int mid = (left +right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n, A[MAX];
    cnt = 0;

    cin >> n;

    rep(i,n) cin >> A[i];

    mergeSort(A, 0, n);

    rep(i,n){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << cnt << endl;

    return 0;
}
