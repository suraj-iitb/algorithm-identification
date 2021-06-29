#include<cstdlib>
#include<iostream>
#define INFTY 1e9

int cnt;

void merge(int *A, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int *L, *R;
    L = (int *) malloc(sizeof(int)*(n1+1));
    R = (int *) malloc(sizeof(int)*(n2+1));
    for(int i=0; i<n1; ++i)
        L[i] = A[left+i];
    for(int i=0; i<n2; ++i)
        R[i] = A[mid+i];
    L[n1] = INFTY;
    R[n2] = INFTY;
    int i = 0, j = 0;
    for(int k=left; k<right; ++k){
        ++cnt;
        if(L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
    std::free(L);
    std::free(R);
}

void mergeSort(int *A, int left, int right){
    if(left+1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int N; std::cin >> N;
    int *A;
    A = (int *) malloc(sizeof(int) * N);
    for(int n=0; n<N; ++n) std::cin >> A[n];
    mergeSort(A, 0, N);
    for(int i=0; i<N; ++i) std::cout << A[i] << (i == N-1 ? '\n' : ' ');
    std::cout << cnt << std::endl;

    std::free(A);
    return 0;
}
