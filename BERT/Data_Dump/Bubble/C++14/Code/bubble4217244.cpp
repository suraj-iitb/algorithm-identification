#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;
    vector<int> as(N);
    rep(i, N) cin>>as[i];

    bool flag = true;
    int cnt = 0;
    while (flag) {
        flag = false;
        rep(i, N - 1) {
            if (as[i] > as[i + 1]) {
                swap(as[i], as[i + 1]);
                flag = true;
                cnt++;
            }
        }
    }

    rep(i, N - 1) cout<<as[i]<<" ";
    cout<<as[N - 1]<<endl;
    cout<<cnt<<endl;
}
