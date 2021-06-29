//Selection Sort

#include <iostream>
#include <vector>

void myswap( int& a, int& b );

int main(){
    //----Input Section----
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for( auto& e : vec ){
        std::cin >> e;
    }

    //----Sort Section----
    int i = 0;
    int numOfSwap = 0;
    int minj;
    int j;
    for( ; i < n; ++i ){
        minj = i;
        for( j = i; j < n; ++j ){
            if( vec[j] < vec[minj] ){
                minj = j;
            }
        }
        if( i != minj ){
            myswap( vec[i], vec[minj] );
            ++numOfSwap;
        }
    }

    //----Output Section----
    for( i = 0; i < n; ++i ){
        std::cout << vec[i] << ( (i < n - 1)? " " : "" );
    }
    std::cout << '\n' << numOfSwap << '\n';

}

void myswap( int& a, int& b ){
    int tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}
