#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cctype>
#define rep(i,a,b) for(int i=(a);i<b;i++)
#define INF 1000000000
#define MAX_N 100000000
#define MAX 
using namespace std;
bool debug=false;

int main(){
  int n,a[105],cnt=0;
  cin>>n;
  rep(i,0,n)cin>>a[i];

  rep(i,0,n){
    int mini=i;
    rep(j,i,n){
      if(a[mini]>a[j])mini=j;
    }
    if(mini!=i){
      swap(a[i],a[mini]);
      cnt++;
    }
  }
  
  rep(i,0,n){
    cout<<a[i];
    if(i==n-1)cout<<endl;
    else cout<<" ";
  }
  cout<<cnt<<endl;
  return 0;
}
