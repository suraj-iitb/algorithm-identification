#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int i, j, N;
    cin>>N;
    vector<int> as(N);
    rep(i, N) cin>>as[i];

    int cnt = 0;
    rep(i, N) {
        int minj = i;
        for(int j = i + 1; j < N; ++j) {
            if (as[j] < as[minj]) {
                minj = j;
            }
        }
        if (minj != i) {
            swap(as[i], as[minj]);
            cnt++;
        }
    }

    rep(i, N - 1) cout<<as[i]<<" ";
    cout<<as[N - 1]<<endl;
    cout<<cnt<<endl;
}
