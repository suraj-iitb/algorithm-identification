#include<bits/stdc++.h>


std::vector<int> CountingSort(std::vector<int> A, int k, int n){
    std::vector<int> B(n);
    std::vector<int> C(k, 0);



    for(int i = 0; i < n; i++){
        C[A[i]]++;
    }

    for(int i = 0; i < k; i++){
        C[i] = C[i] + C[i-1];
    }

    for(int i = 0; i < k; i++){
        C[i]--;
    }

    for(int i = n-1; i >= 0; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    

    
    return B;
}

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    int k = 10000;
    std::vector<int> B;
    //std::vector<int> C(k, 0);


    for(int i = 0; i < n; i++){
        std::cin >> A[i];
        //std::cout << A[i] << std::endl;
    }

    B = CountingSort(A, k, n);

    for(int i = 0; i < n; i++){
        if(i != 0) std::cout << " ";
        std::cout << B[i];
    }
    std::cout << std::endl;

    return 0;
}
