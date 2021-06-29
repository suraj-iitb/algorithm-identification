#include <iostream>
using namespace std;
//cout << fixed << setprecision(15);

//#include <bits/stdc++.h>
//#include <boost/integer/common_factor_rt.hpp>
//const long long INF = 1LL << 60;
//using ll = long long;
//using P = pair<int, int>;

void outPut(int V[], int N, int cnt) {
    for (int i = 0; i < N; ++i) {
        if (i) cout << " ";
        cout << V[i];
    }
    cout <<"\n";
    cout << cnt << "\n";
}

void selectionSort(int V[], int N) {
    int cnt = 0;
    for (int i = 0; i < N - 1; ++i) {
        int minj = i;
        for (int j = i; j < N; ++j) {
            if ( V[j] < V[minj]) {
                minj = j;
            }
        }
        swap(V[i],V[minj]);
        if (i != minj) cnt++;
    }
    outPut(V, N, cnt);
}


int main() {
//    cin.tie(nullptr);
//    ios::sync_with_stdio(false);
    int V[100];

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    selectionSort(V, N);

    return 0;
}
