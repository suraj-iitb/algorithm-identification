#include <iostream>
#include <vector>

template <typename Tp> void println(const std::vector<Tp>& A){
    for(auto itr = A.cbegin(); itr != A.cend(); ){ 
        std::cout << (*itr++); std::cout << (itr == A.cend() ? '\n' : ' ');
    }
}

int main(void){
    std::cin.tie(nullptr); std::cin.sync_with_stdio(false);
    int n; std::cin >> n; 
    std::vector<int> A(n); for(int i = 0; i < n; ++i) std::cin >> A[i];

    std::cout.tie(nullptr);
    println(A);
    for(int i = 1; i < n; ++i){
        int v = A[i];
        int j;
        for(j = i - 1; j >= 0 and A[j] > v; --j) A[j + 1] = A[j];
        A[j + 1] = v;
        println(A);
    }

    return 0;
}
