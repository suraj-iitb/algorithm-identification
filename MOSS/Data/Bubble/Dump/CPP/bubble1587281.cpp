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
      int n,a[100],ans=0;
      bool f=true;
      cin>>n;
      REP(i,n)cin>>a[i];
      while(f){
            f=false;
            for(int j=n-1;j>=0;j--){
                  if(a[j]<a[j-1]){
                        swap(a[j],a[j-1]);
                        f=true;
                        ans++;
                  }
            }
      }
      REP(i,n)printf("%d%c",a[i],i==n-1?'\n':' ');
      cout<<ans<<endl;
}
