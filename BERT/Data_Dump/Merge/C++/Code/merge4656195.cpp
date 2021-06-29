#include<iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt = 0;

void merge(int A[], int n, int left, int right, int mid){
    int n1 = mid - left;
    int n2 = right - mid;
    int idx_l = 0;
    int idx_r = 0;
    
    for(int i = 0; i < n1; i++) L[i] = A[left + i];
    for(int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    
    for(int i = left; i < right; i++){
        if(L[idx_l] <= R[idx_r]){
            A[i] = L[idx_l];
            idx_l++;
        }
        else{
            A[i] = R[idx_r];
            idx_r++;
        }
        cnt++;
    }
}

void mergeSort(int A[], int n, int left, int right){
    int mid;
    
    if(left + 1 < right){
        mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, right, mid);
    }
}

int main(){
    int A[MAX], n;
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    
    mergeSort(A, n, 0, n);
    
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    
    cout << cnt << endl;
    
    return 0;
}
