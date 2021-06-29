#include<bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using Lint=long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    const int MAX=10000;
    vector<int> cnt(MAX+1);
    
    int N; cin>>N;
    for(int i=0;i<N;i++){
        int a; cin>>a;
        cnt[a]++;
    }

    vector<int> a;
    for(int i=0;i<=MAX;i++){
        while(cnt[i]--) a.push_back(i);
    }

    for(int i=0;i<N;i++){
        cout<<a[i]<<(i==N-1? '\n':' ');
    }
    return 0;
}
