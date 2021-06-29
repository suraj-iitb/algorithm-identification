#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (int i = m; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> ar(n);
    rep(i,n){
        cin >> ar[i];
    }
    queue<int> q;
    queue<int> ans;
    priority_queue<int> p;
    int fr;
    rep(j,n){
        q.push(ar[j]);
    }
    rep(k,n){
        rep(l,k+1){
            fr = q.front();
            p.push(-fr);
            q.pop();
        }
        while (!p.empty()){
            fr = p.top();
            ans.push(-fr);
            p.pop();
        }
        while (!q.empty()){
            ans.push(q.front());
            q.pop();
        }
        rep(a,n-1){
            cout << ans.front() << " ";
            q.push(ans.front());
            ans.pop();
        }
        cout << ans.front() << endl;
        q.push(ans.front());
        ans.pop();
    }
}
