#include <bits/stdc++.h>
#include <cstdlib>  // abs() for integer 驍ｨ・ｶ陝・ｽｾ陋滂ｽ､雎弱ｅ・∫ｹｧ繝ｻ笆ｽ
#include <cmath>    // abs() for float, and fabs()
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i = 0; i < (n);i++)
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
using namespace std;
#define INF 2000000000
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define che(a,string) cout<<"//"<<string <<"=="<<(a)<<"//" <<endl;

int main(){
  int N; cin >> N;
  vector<int> A(N);
  rep(i,N){
    cin>>A[i];
  }
  rep(i,N){
    if(i) cout<<" ";
    cout<<A[i];
  }
  cout<<endl;
  for(int i = 1 ; i <= N-1; i++){
    int v = A[i];
    int j = i-1;
    while(j>=0 && A[j] >v){
      A[j+1]=A[j];
      A[j]=v;
      j--;
     v=A[j+1];
    }
    rep(k,N){
      if(k) cout<<" ";
      cout<<A[k];
    } 
    cout<<endl;
  }
} 

