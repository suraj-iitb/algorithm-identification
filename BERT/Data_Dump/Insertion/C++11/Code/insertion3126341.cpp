#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <algorithm>  // std::copy()
#include <functional>  // std::greater<T>()
#include <numeric>  // accumulate(ALL(vec), 0)  0 は初期値
#include <cmath>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
using namespace std;

// macro
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1
#define REPN(i, n) for (int i=1; i <= (int)(n); i++)  // 1 ~ n
#define DESCEND greater<int>()  // sort 降順 大きい順
#define UNIQUE(vec) (vec).erase(unique(ALL((vec))), (vec).end());  // 必ずsortを行なってから
#define MIN(vec) min_element(ALL((vec)))  // 値を取り出すときは * を先頭につける
#define MAX(vec) max_element(ALL((vec)))
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(ALL((vec)), 0)  // 0 は初期値
#define COPY(vec1, vec2) copy(ALL(vec1), back_inserter(vec2))  // vec1をvec2にコピーする
#define zero_pad(num) setfill('0') << std::right << setw(num)  // 直後の要素をパディング
#define space_pad(num) setfill(' ') << std::right << setw(num)  // 直後の要素をパディング


// func declaration
template <class T> void calcVec(vector<T>&, int, char);

void printVec(vector<int>& vec) {
    auto N = vec.size();
    REP(i, N) {
        cout << vec.at(i);
        if (i < N - 1) cout << " ";
    }
    cout << endl;
}

void insertionSort(vector<int>& vec) {
    printVec(vec);
    for (int i = 1; i <= (vec.size() - 1); i++) {
        int key = vec.at(i);  // i: 1 to (N - 1) // most left
        int j = i - 1;  // done-index

        while (j >= 0 && key < vec.at(j)) {  // 左（操作済み）のほうが大きかったら入れ替える
            vec.at(j + 1) = vec.at(j);
            j--;
        }
        vec.at(j + 1) = key;  // 最後のマイナス分1を足す
        printVec(vec);
    }
}

int main() {
    // input
    int N;
    cin >> N;
    vector<int> vec(N);
    REP(i, N) cin >> vec.at(i);
    
    // output
    insertionSort(vec);
    
    return 0;
}

