#include <vector>
#include <iostream>

template <typename T>
void insertion_sort(std::vector<T> &A) {
    for(std::size_t j = 1; j < A.size(); ++j) {
        T key = A[j];
        int i = j - 1;
        while(i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            --i;
        }
        A[i + 1] = key;
        
        for(std::size_t k = 0; k < A.size(); ++k) std::cout << A[k] << (k + 1 == A.size() ? '\n' : ' ');
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for(int i = 0; i < n; ++i) std::cin >> A[i];

    for(std::size_t k = 0; k < A.size(); ++k) std::cout << A[k] << (k + 1 == A.size() ? '\n' : ' ');
    insertion_sort<int>(A);
}
