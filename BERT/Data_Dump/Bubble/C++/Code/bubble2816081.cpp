#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#define FI first
#define SE second
#define VE vector<int>
#define PB push_back
#define PA pair<int,int>
#define MA make_pair
#define LL long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
using namespace std;
//
const int INF=1e9+7;
//
int main(){
  int N;
  int A[100];
  cin>>N;
  FOR(i,0,N){
    cin>>A[i];
  }
  bool F=true;
  int ans=0;
  while(F){
    F=false;
    ROF(i,1,N){
      if(A[i]<A[i-1]){
        swap(A[i],A[i-1]);
        ans++;
        F=true;
      }
    }
  }
  FOR(i,0,N){
    if(i!=0){
      cout<<" ";
    }
    cout<<A[i];
  }
  cout<<endl;
  cout<<ans<<endl;
  return 0;
}
