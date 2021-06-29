#include <bits/stdc++.h>
using namespace std;
void print() {
    cout << endl;
}
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
    cout << head;
    if (sizeof...(tail) != 0)
        cout << " ";
    print(forward<Tail>(tail)...);
}
template <class T>
void print(vector<T> &vec) {
    for (auto &a : vec) {
        cout << a;
        if (&a != &vec.back())
            cout << " ";
    }
    cout << endl;
}
template <class T>
void print(vector<vector<T>> &df) {
    for (auto &vec : df) {
        print(vec);
    }
}
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define xrep(i, a, b) for (int i = int(a); i < int(b); ++i)
#define zrep(i, a, b, c) for (int i = int(a); i < int(b); i+=int(c))
using ll = long long;
const int INF = 1001001001;

void BubbleSort(vector<int> &A) {
    int N = A.size();
    int cnt = 0;
    int flag = 1;
    while(flag) {
        flag = 0;
        for(int i=N-1; i>0; i--) {
            if(A[i]<A[i-1]) {
                swap(A[i], A[i-1]);
                cnt++;
                flag = 1;
            }
        }
    }
    print(A);
    print(cnt);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    BubbleSort(A);



    return 0;
}
