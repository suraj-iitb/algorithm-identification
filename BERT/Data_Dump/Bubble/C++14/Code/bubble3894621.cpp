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
  int N; cin>>N;
  vector<int> A(N);
  rep(i,N){
    cin>>A[i];
  }
  //配列の作成
  int count = 0 ;//操作回数
  int flag = 1;
    while(flag){
      flag = 0;
      for(int i = N-1 ; i >= 0; i--){
        int v=A[i];
        if(v<A[i-1]){
          A[i]=A[i-1];
          A[i-1]=v;
          flag = 1;
          count ++;
        }
      } 
    }
    rep(i,N){
      if(i) cout<<" ";
      cout<<A[i];
    }
    cout<<endl;
    cout<<count<<endl;
}

