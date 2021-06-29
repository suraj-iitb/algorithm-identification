#include<iostream>
using namespace std;
#define INFTY 1000000001
int cnt = 0;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1], R[n2+1];
    for(int i=0; i<n1; i++) L[i] = A[left + i];
    for(int i=0; i<n2; i++) R[i] = A[mid + i];
    L[n1] = INFTY;
    R[n2] = INFTY;

    int i=0, j=0;
    for(int k=left; k<right; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
            cnt++;
        }
        else{
            A[k] = R[j];
            j++;
            cnt++;
        }
    }
}

void mergeSort(int A[], int left, int right){
    //要素が1で終わり
    if(left+1 == right) return;
    else{
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n;
    cin >> n;
    int A[500000];
    for(int i=0; i<n; i++) cin >> A[i];
    mergeSort(A, 0, n);
    for(int i=0; i<n; i++){
        if(i == n-1) cout << A[i] << endl;
        else cout << A[i] << " ";
    }
    cout << cnt << endl;
}
