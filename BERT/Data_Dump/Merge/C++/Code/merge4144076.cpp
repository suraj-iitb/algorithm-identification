#include<iostream>
#include<climits>
using namespace std;

#define N 500000

int count = 0;

void marge(int *, int, int ,int);
void margeSort(int *, int, int);

int main() {
    int a;
    cin>>a;
    int A[N];
    for(int i = 0; i < a; i++) cin>>A[i];
    int left = 0;
    int right = a;
    margeSort(A, left, right);
    
    for(int i = 0; i < a-1; i++) cout<<A[i]<<' ';
    cout<<A[a-1]<<endl;
    cout<<count<<endl;

    return 0;
}

void marge(int *A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1], R[n2+1];
    int i, j;
    for(i = 0; i < n1; i++) L[i] = A[left + i];
    for(j = 0; j < n2; j++) R[j] = A[mid+j];
    
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    
    i = 0;
    j = 0;
    
    for(int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    count++;
    }
}

void margeSort(int *a, int left, int right) {
    if(left+1 < right) {
        int mid = (left + right) /2;
        margeSort(a, left, mid);
        margeSort(a, mid, right);
        marge(a, left, mid, right);
    }
}


