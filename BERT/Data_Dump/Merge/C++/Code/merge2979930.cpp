#include <iostream>
#define INFTY 1000000001

using namespace std;

int count = 0;

void merge(int *A, int left, int mid, int right){
    int i, j;
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1], R[n2+1];
    for(i = 0; i < n1; i++) L[i] = A[left + i];
    for(i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = INFTY;
    R[n2] = INFTY;
    i = 0;
    j = 0;
    for(int k = left; k < right; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        count++;
    }
}

void mergeSort(int *A, int left, int right){
    int mid;
    if(left + 1 < right){
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n, i;
    cin >> n;
    int A[n];
    for(i = 0; i < n; i++){
        cin >> A[i];       
    }
    mergeSort(A, 0, n);

    for(i = 0; i < n-1; i++) cout << A[i] << " ";
    cout << A[i] << endl;
    cout << count << endl;

    return 0;
}
