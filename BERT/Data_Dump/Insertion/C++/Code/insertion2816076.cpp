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
  FOR(i,0,N){
    sort(A,A+i+1);
    FOR(j,0,N){
      if(j!=0){
        cout<<" ";
      }
      cout<<A[j];
    }
    cout<<endl;
  }
  return 0;
}
