#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;
#define rep(i,n) REP(i,0,n)
#define REP(i,x,n) for(int i=x;i<n;++i)

///////////////////////////////////////////////////
// -------------------- I/O -------------------- //
///////////////////////////////////////////////////
// https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
template<typename T> void outputVec(const std::vector<T>& vec, const int precision = 0) {
    if (precision > 0) std::cout << std::fixed << std::setprecision(precision);
    for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end() - 1; ++it) { std::cout << *it << " "; }
    std::cout << *(vec.end() - 1) << "\n";
}
template<typename T> void outputVal(const T& res, const int precision = 0) {
    if (precision > 0) std::cout << std::fixed << std::setprecision(precision);
    std::cout << res << "\n";
}
template<typename T> T inputVal() { T a; std::cin >> a; return a; }
template<typename T> std::vector<T> inputVec(T N) {
    std::vector<T> vec(N);
    for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it) { std::cin >> *it; }
    return vec;
}
template<typename T> void inputVec(std::vector<T>& vec) {
    for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it) { std::cin >> *it; }
}

///////////////////////////////////////////////////
// ------------------- utils ------------------- //
///////////////////////////////////////////////////
// change min/max
template<class T> inline bool chMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

///////////////////////////////////////////////////
// ------------------- main -------------------- //
///////////////////////////////////////////////////
void Main() {
    const int N = inputVal<int>();
    vector<int> vec = inputVec<int>(N);

    for (int i = 0; i < N; ++i) {
        const int thisNb = vec[i];
        int j = i -1;
        for ( ; j >= 0; --j) {
            if ( vec[j] > thisNb ) {
                vec[j+1] = vec[j];
            }
            else {
                break;
            }
        }
        vec[j+1] = thisNb;
        outputVec(vec);
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(15);
    Main();

    return 0;
}
