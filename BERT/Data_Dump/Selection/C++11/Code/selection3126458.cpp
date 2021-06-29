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
template <class T> void printVec(vector<T>&);
template <class T> void print2DVec(vector< vector<T> >&);
template <class T> void calcVec(vector<T>&, int, char);
bool checkMultiple(vector<int>&, int);
int ctoi(const char);  // char to int

// const
const int INF = 10000000;

/*MEMO
・辞書順
abc < abcd, atcoder < atlas
・イテレータ
std::vector<int>::iterator とタイプするのは面倒なので、
 通常は型推論の auto を使用する。
 auto iter = max_element(ALL(vec));
・2次元配列
vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}}
・20×10の配列
vector<vector<int>> vec(20, vector<int>(10, 0));
・(n, m)の多次元配列
vector< vector<int> > vec(n, vector<int>(m, 0))  // 0で初期化
*/

int SelectionSort(vector<int> &vec) {
    int count = 0;
    REP(i, vec.size()){
        // 最小値を求める
        int min_idx = i;
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec.at(min_idx) > vec.at(j)) {
                min_idx = j;
            }
        }
        if (!(min_idx == i)) {
            // min_idxが変化していたら
            swap(vec.at(i), vec.at(min_idx));
            // printVec(vec);
            count++;
        }
    }

    return count;
}

int main() {
    // input
    int N, count;
    cin >> N;
    vector<int> vec(N);
    REP(i, N) cin >> vec.at(i);
    
    // calculation
    /*
     * 選択ソート
     * 線形探索して最小値を探し、左端と入れ替える
     */
    count = SelectionSort(vec);
    printVec(vec);
    cout << count << endl;
    
    return 0;
}


// function
template <class T> void printVec(vector<T>& vec) {
    // 1要素ずつ、空白・改行なしで出力
    REP(i, vec.size()) {
        if (i) cout << " ";
        cout << vec.at(i);
    }
    cout << endl;
}

template <class T> void print2DVec(vector< vector<T> >& vec) {
    REP(i, vec.size()) {
        REP(j, vec.front().size()) {
            cout << vec.at(i).at(j);
        }
        cout << endl;
    }
}

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

bool checkMultiple(vector<int> &vec, int num) {
    // vecの中身が、全てnumの倍数かどうかのチェック
    int count = 0;
    REP(i, vec.size()) {
        if (vec.at(i)%num != 0) count++;
    }
    return (count == 0);
}

int ctoi(const char c) {
    if('0' <= c && c <= '9') return (c-'0');
    return -1;
}

