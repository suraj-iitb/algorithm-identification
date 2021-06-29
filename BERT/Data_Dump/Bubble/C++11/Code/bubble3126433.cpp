#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <algorithm>  // std::copy()
#include <functional>  // std::greater<T>()
#include <utility>  // std::swap()
#include <numeric>  // accumulate(ALL(vec), 0)  0 は初期値
#include <cmath>
#include <climits>  // INT_MIN
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

void printVec(vector<int> &vec) {
    int N = vec.size();
    REP(i, N) {
        cout << vec.at(i);
        if (i < N - 1) cout << " ";
    }
    cout << endl;
}

int BubbleSort(vector<int> &vec) {
    int N = vec.size();
    int end = N - 1;
    int count = 0;
    REP(i, N) {
        for (int j = end; i + 1 <= j; --j) {
            if (vec.at(j - 1) > vec.at(j)) {
                swap(vec.at(j - 1), vec.at(j));
                // printVec(vec);
                count++;
            }
        }
    }
    return count;
}

int main() {
    // input
    int N;
    cin >> N;
    vector<int> vec(N);
    REP(i, N) cin >> vec.at(i);
    
    // output
    int count = BubbleSort(vec);
    printVec(vec);
    cout << count << endl;

    return 0;
}


// function
template <class T> void calcVec(vector<T> &vec, int num, char ch) {
    // vec全体への演算
    switch (ch) {
        case '+':
            REP(i, vec.size()) vec.at(i) += num; break;
        case '-':
            REP(i, vec.size()) vec.at(i) -= num; break;
        case '*':
            REP(i, vec.size()) vec.at(i) *= num; break;
        case '/':
            REP(i, vec.size()) vec.at(i) /= num; break;
        case '%':
            REP(i, vec.size()) vec.at(i) %= num; break;
        default:
            cout << "Incorrect Operator" << endl;
    }
}

