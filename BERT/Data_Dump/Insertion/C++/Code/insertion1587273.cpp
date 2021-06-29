#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF=1e9;
int main(){
      int n,a[100];
      cin>>n;
      REP(i,n)cin>>a[i];
      bool update=true;
      REP(i,n){
            cout<<a[i];
            if(i==n-1)cout<<endl;
            else cout<<" ";
      }
      while(update){
            update=false;
            for(int i=1;i<n;i++){
                  int v=a[i];
                  int j=i-1;
                  while(j>=0&&a[j]>v){
                        a[j+1]=a[j];
                        j--;
                  }
                  a[j+1]=v;
                  REP(i,n){
                        cout<<a[i];
                        if(i==n-1)cout<<endl;
                        else cout<<" ";
                  }
            }
      }
}
