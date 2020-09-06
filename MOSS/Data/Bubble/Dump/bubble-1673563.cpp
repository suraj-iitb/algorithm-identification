#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N;
int A[100];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];
    
    int counter=0;
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=N-1;i>0;i--){
            if(A[i]<A[i-1]){
                swap(A[i],A[i-1]);
                counter++;
                flag=true;
            }
        }
    }
    
    rep(i,N){
        if(i)cout<<" ";
        cout<<A[i];
    }cout<<endl;
    cout<<counter<<endl;
    return 0;
}
