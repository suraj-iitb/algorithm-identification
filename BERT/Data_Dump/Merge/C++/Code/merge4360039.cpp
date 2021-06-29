#include <iostream>

#define MAX 500000
#define SENTINEL 2000000000
int R[MAX/2+2], L[MAX/2+2];
int cnt;

void merge(int A[],int left ,int mid,int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = R[n2] = SENTINEL;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
            
        } else {
            A[k] = R[j++];
        }
    }
}

void mergesort(int A[],int left,int right) {
    if (left + 1 < right) {
        int mid = (left+right)/2;
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void){
    int A[MAX], n;
    cnt = 0;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
       std::cin >> A[i];
    }
    
    mergesort(A, 0, n);
    
    for (int i = 0; i < n; i++) {
        if (i != 0) std::cout << " ";
        std::cout << A[i];
    }
    std::cout << "\n";
    
    std::cout << cnt << std::endl;
    
    return 0;
}

