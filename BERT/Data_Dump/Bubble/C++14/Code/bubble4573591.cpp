#include <iostream>
#include <algorithm>
#include <vector>

template <typename Tp> void println(const std::vector<Tp>& A){
    for(auto itr = A.cbegin(); itr != A.cend(); ){ 
        std::cout << (*itr++); std::cout << (itr == A.cend() ? '\n' : ' ');
    }
}

int main(void){
    std::cin.tie(nullptr); std::cin.sync_with_stdio(false); std::cout.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> A(n); for(int i = 0; i < n; ++i) std::cin >> A[i];
    int cnt = 0;
    {
        bool continuous = true;
        while(continuous){
            continuous = false;
            for(int i = 0, j = 1; j < n; ++i, ++j) if(A[i] > A[j]){ std::swap(A[i], A[j]); ++cnt; continuous = true;}
        }
    }
    println(A);
    std::cout << cnt << '\n';
    return 0;
}
