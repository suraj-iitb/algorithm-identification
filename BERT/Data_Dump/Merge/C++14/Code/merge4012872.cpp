#include<bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using Lint=long long;
const int INF=2e9;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin>>N;
    vector<int> a(N);
    for(int i=0;i<N;i++) cin>>a[i];

    int cnt=0;
    auto merge=[&](int l,int m,int r)
    {
        vector<int> x(m-l+1,INF),y(r-m+1,INF);
        for(int i=0;i<m-l;i++) x[i]=a[l+i];
        for(int i=0;i<r-m;i++) y[i]=a[m+i];
        int i=0,j=0;
        for(int k=l;k<r;k++){
            cnt++;
            if(x[i]<y[j]) a[k]=x[i++];
            else a[k]=y[j++];
        }
    };
    function<void(int,int)> merge_sort=[&](int l,int r)
    {
        if(r-l>1){
            int m=(l+r)/2;
            merge_sort(l,m);
            merge_sort(m,r);
            merge(l,m,r);
        }
    };
    merge_sort(0,N);
    for(int i=0;i<N;i++){
        cout<<a[i]<<(i==N-1? '\n':' ');
    }
    cout<<cnt<<endl;
    return 0;
}
