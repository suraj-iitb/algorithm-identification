#include <iostream>

#define NMAX 100

int main() {
    int N, A[NMAX], i, j, key;
    std::cin >> N;
    
    for (i=0; i<N; i++) {
        std::cin >> A[i];
    }
    
    for (int k=0; k<N; k++) {
        std::cout << A[k];
        if (k<N-1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }
    
    for (i=1; i<N; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        
        for (int k=0; k<N; k++) {
            std::cout << A[k];
            if (k<N-1) {
                std::cout << " ";
            } else {
                std::cout << std::endl;
            }
        }
    }
}
