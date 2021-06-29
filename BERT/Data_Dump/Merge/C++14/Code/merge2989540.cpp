#include <iostream>
#include <vector>

constexpr uint sentinel = 1000000001;

void Merge( std::vector<uint>& v, uint left, uint mid, uint right, int& cmpNum ){
    int n1 = mid - left;
    int n2 = right - mid;
    std::vector<uint> L( n1 + 1 );
    std::vector<uint> R( n2 + 1 );
    int i = 0;
    int j = 0;
    for( ; i < n1; ++i ){
        L[i] = v[left + i];
    }
    for( ; j < n2; ++j ){
        R[j] = v[mid + j];
    }
    L[n1] = sentinel;
    R[n2] = sentinel;

    i = 0;
    j = 0;

    for( int k = left; k < right; ++k ){
        cmpNum++;
        if( L[i] <= R[j] ){
            v[k] = L[i++];
        }else{
            v[k] = R[j++];
        }
    }
}

void MergeSort( std::vector<uint>& v, uint left, uint right, int& cmpNum ){
    if( left + 1 < right ){
        uint mid = ( left + right ) / 2;
        MergeSort( v, left, mid, cmpNum );
        MergeSort( v, mid, right, cmpNum );
        Merge( v, left, mid, right, cmpNum );
    }
}

int main(){
    std::cin.tie(0);
    int n;
    int cmpNum = 0;
    std::cin >> n;
    std::vector<uint> vec(n);
    for( auto& e : vec ){
        std::cin >> e;
    }

    MergeSort( vec, 0, n, cmpNum );

    for( int i = 0; i < n; ++i ){
        std::cout << vec[i] << ( ( i == n - 1 )? "\n" : " " );
    }
    std::cout << cmpNum << "\n";
}
