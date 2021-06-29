#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
  int n;
  cin >>n;
  vector <int> a(n+1);
  rep(i,n)cin >>a.at(i);

  int v =a.at(0);
  rep(i,n-1)cout<<a.at(i)<<" ";
  printf("%d\n",a.at(n-1));

  for(int i =1;i<n;i++){
    v = a.at(i);
    int j = i-1;
    //cout<<"v = "<<v <<endl;
    while(j>=0 && a.at(j) >v){
      a.at(j+1)=a.at(j);//大きい値をずらす作業
      j--;
    }
    a.at(j+1) = v;
    rep(i,n-1)cout<<a.at(i)<<" ";
    printf("%d\n",a.at(n-1));

  }
}

