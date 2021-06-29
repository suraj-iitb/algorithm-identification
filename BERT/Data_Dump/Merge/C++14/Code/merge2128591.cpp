#include <iostream>
#include <vector>

#define MAXNUM 500000
#define MAXVALUE 2000000000
int n;
int cnt;
int S[MAXNUM];
int L[MAXNUM/2 + 2];
int R[MAXNUM/2 + 2];


void merge(int *A, int left, int mid, int right){
    int nl = mid - left;
    int nr = right - mid;
    for (int i = 0; i < nl; i++) {
        L[i] = A[left+i];
    }
    for (int i = 0; i < nr; i++) {
        R[i] = A[mid+i];
    }
    L[nl] = MAXVALUE;
    R[nr] = MAXVALUE;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++){
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


void mergesort(int *A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
//         std::cout << "==========" << std::endl;
//         std::cout << mid << std::endl;
//         std::cout << "==========" << std::endl;
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    }
}



int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    }
    mergesort(S, 0, n);
    for (int i = 0; i < n; i++) {
        std::cout << S[i];
        if (i < n-1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl << cnt << std::endl;
}
