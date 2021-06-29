#include <utility>
#include <vector>

template <typename T>
int selection_sort(std::vector<T> &A) {
    int swap_cnt = 0;

    for(std::size_t j = 0; j + 1 < A.size(); ++j) {
        std::size_t argmin = j;
        for(std::size_t i = j + 1; i < A.size(); ++i) {
            if(A[i] < A[argmin]) argmin = i;
        }
        if(j != argmin) ++swap_cnt;
        std::swap(A[j], A[argmin]);
    }

    return swap_cnt;
}

#include <iostream>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for(int i = 0; i < n; ++i) std::cin >> A[i];
    
    int swap_cnt = selection_sort<int>(A);
    for(std::size_t k = 0; k < A.size(); ++k) std::cout << A[k] << (k + 1 == A.size() ? '\n' : ' ');
    std::cout << swap_cnt << std::endl;
}

