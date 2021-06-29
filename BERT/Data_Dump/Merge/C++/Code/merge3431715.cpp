#include<iostream>
#include<cstdio>
using namespace std;
#define INFTY (1000000001)

int times = 0;

void merge(int A[], int left, int mid, int right){
    int n1, n2, i, j;
    n1 = mid - left;
    n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    for(i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;
    i = 0; j = 0;
    for(int k = left; k < right; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
            times++;
        }else{
            A[k] = R[j];
            j++;
            times++;
        }
    }
}

void mergeSort(int A[], int left, int right){
    int times;
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int S[n];
    for(int i = 0; i < n; i++){
        scanf("%d" , &S[i]);
    }
    mergeSort(S, 0, n);
    for(int i = 0; i < n; i++){
        if(i != 0) cout << " ";
        cout << S[i];
    }
    cout << endl;
    cout << times << endl;
    return 0;
}
