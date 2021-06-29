#include<bits/stdc++.h>
#define INF 1001001001

int cnt;

void merge(std::vector<int>&A, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    std::vector<int> L(n1+1);
    std::vector<int> R(n2+1);
    for(int i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = INF;
    R[n2] = INF;
    int i = 0;
    int j = 0;

    for(int k = left; k < right; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        cnt++;
    }
    
}

void mergeSort(std::vector<int>&A, int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void){
    int n;
    cnt = 0;
    std::cin >> n;
    std::vector<int> A(n);

    for(int i = 0; i < n; i++){
        std::cin >> A[i];
    }
    

    mergeSort(A, 0, n);

    for(int i = 0; i < n; i++){
        if(i == 0){
            std::cout << A[i];
        }else{
            std::cout << " " << A[i];
        }
        
    }
    std::cout << std::endl;
    std::cout << cnt << std::endl;
    
    return 0;
}
