#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  loop(i,0,n)
#define all(c) c.begin(),c.end()
#define vi vector<int>
#define vl vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>

void Acout(int A[],int N){
    rep(i,N){
        if(i)cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
}

int bubblesort(int A[],int N){
    int flag=1;
    int ns=0;
    int i=0;
    while(flag){
        flag=0;
        for(int j=N-1;j>=i+1;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);flag=1;ns++;
            }
        }
        i++;
    }
    return ns;
}

int main(){
    int N;
    cin>>N;
    int A[N];
    int ns;

    rep(i,N)cin>>A[i];
    ns = bubblesort(A,N);
    Acout(A,N);
    cout<<ns<<endl;
}
