#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

void CountingSort(std::vector<int>& A, std::vector<int>& B, int k) {
    std::array<int, 10001> C = {};
    for (int i=0; i<k; ++i) {
        C[A[i]]++;
        B.push_back(-1);
    }
    
    for (int i=1; i<=10001; ++i) {
        C[i] += C[i-1];
    }
    
    for (int i=k-1; i>=0; --i) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
}

int main() {
    int N, temp;
    std::cin >> N;
    
    std::vector<int> A, B;
    for (int i=0; i<N; i++) {
        std::cin >> temp;
        A.push_back(temp);
    }
    
    CountingSort(A, B, N);
    
    for (auto i=B.begin(); i!=B.end(); i++) {
        std::cout << *i;
        if (std::next(i, 1) != B.end()) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }
}
