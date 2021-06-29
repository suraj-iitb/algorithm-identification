#include <iostream>
#include <vector>

void myswap( int& a, int& b );

int main(){
    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for( auto& e : vec ){
        std::cin >> e;
    }

    int numOfSwap = 0;
    int i = 0;
    for( ; i < n; ++i ){
        for( int j = n - 1; j > i; --j ){
            if( vec[j] < vec[j-1] ){
                myswap( vec[j], vec[j-1] );
                ++numOfSwap;
            }
        }
    }

    for( i = 0; i < n; ++i ){
        std::cout << vec[i] << ( (i < n - 1)? " " : "" );
    }
    std::cout << '\n' << numOfSwap << '\n';
}

void myswap(int& a, int& b){
    int tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}
