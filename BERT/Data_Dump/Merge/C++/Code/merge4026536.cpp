#include<bits/stdc++.h>
using namespace std;
#define Max 500100

int n,S[Max],c;
void merge(int A[], int left, int mid, int right);
void mergeSort(int A[], int left, int right);

int main(){
    //
    cin >> n;
    for(int i = 0; i < n; i++) cin >> S[i];
    c = 0;
    mergeSort(S, 0, n);
    for(int i = 0; i < n; i++){
        cout << S[i];
        if(i != n-1) cout << " ";
        else cout << endl;
    }
    cout << c << endl;
}

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;

    int L[n1+10], R[n2+10];

    // 右側と左側に分割
    for(int i = 0; i < n1; i++){
        L[i] = A[left+i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid+i];
    }
    L[n1] = INT_MAX; R[n2] = INT_MAX;

    // 右側と左側の小さい方を取ってきて並べ替え
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        c++;
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
    if(left+1 < right){
        int mid = (left + right) /2;
        // 左側整頓
        mergeSort(A, left, mid);
        // 右側整頓
        mergeSort(A,mid, right);
        // まとめる
        merge(A,left, mid, right);
    }
}
