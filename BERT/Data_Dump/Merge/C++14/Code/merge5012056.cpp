#include<iostream>
using namespace std;
#define max 500000
#define sentinel 2000000000

int cnt;

void merge(int n, int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[max], R[max];
    for(int i=0; i<n1; i++) L[i] = A[left+i];
    for(int i=0; i<n2; i++) R[i] = A[mid+i];
    L[n1] = sentinel;
    R[n2] = sentinel;
    int i = 0;
    int j = 0;
    for(int k=left; k<right; k++){
        cnt++;
        if(L[i]<=R[j]){
            A[k] = L[i];
            i = i + 1;
        }
        else{
            A[k] = R[j];
            j = j+1;
        }
    }
}

void mergeSort(int n, int A[], int left, int right){
    if(left+1<right){
        int mid = (left + right) / 2;
        mergeSort(n, A, left, mid);
        mergeSort(n, A, mid, right);
        merge(n, A, left, mid, right);
    }
}

int main(){
    int n, A[max];
    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];
    mergeSort(n, A, 0, n);
    for(int i=0; i<n; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
}


