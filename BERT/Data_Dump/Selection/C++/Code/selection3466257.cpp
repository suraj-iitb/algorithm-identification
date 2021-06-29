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

int selectionsort(int A[],int N){
    int ns=0;
    rep(i,N-1){
        int min=i;
        for(int j=i;j<N-1;j++){
            for(int j=i;j<N;j++){
            if(A[min]>A[j])min=j;
            }   
        swap(A[i],A[min]);
        if(i!=min)ns++;
        }
    }
    return ns;
}

int main(){
    int N;
    cin>>N;
    int A[N];
    rep(i,N)cin>>A[i];
    int ns;

     ns = selectionsort(A,N);
     Acout(A,N);
     cout<<ns<<endl;
}
