#include <iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

void mSort(int*, int, int, int);
void merge(int*, int, int, int, int);

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt;

int main(void){
    int A[MAX], n, i;
    cnt = 0;

    cin >> n;
    for(i = 0; i < n; i++) cin >> A[i];

    mSort(A, n, 0, n);

    for(i = 0; i < n; i++){
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}

void mSort(int* A, int n, int left, int right){
    if (left + 1 >= right) return;
    int mid = (left + right) / 2;
    mSort(A, n, left, mid);
    mSort(A, n, mid, right);
    merge(A, n, left, mid, right);
}

void merge(int* A, int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++) L[i] = A[left + i];
    for(int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = R[n2] = SENTINEL;
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i];    
            i++;            
        }                  
        else{              
            A[k] = R[j];  
            j++;
        }
    }
}

