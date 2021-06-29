#include <bits/stdc++.h>
#include <iostream>
//#include <vector>
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
 
int main(){
    int n,v,j;
    cin>>n;
    
    vector<int> a(n);
    rep(i,n)cin>>a.at(i);
    
    rep(i,n){
      v=a.at(i);
      j=i-1;
      
      while(j>=0&&a.at(j)>v){
          a.at(j+1)=a.at(j);
          j--;
          a.at(j+1)=v;
      }
      rep(i,n-1)cout<<a.at(i)<<" ";
      cout<<a.at(n-1)<<endl;
    }
    
    
    
    
    
}
  


