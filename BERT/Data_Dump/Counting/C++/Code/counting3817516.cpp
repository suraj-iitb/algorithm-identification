#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<int> v;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long a=0,b,c,d=0,e=0,f=0,g=0;
  string s,w,q;
  cin >>a;
  for(int n=0;n<a;n++){
    cin >>b;
    v.push_back(b);
  }
  sort(v.begin(),v.end());
  for(int n=0;n<a;n++){
    if(n!=0) cout <<' ';
    cout <<v[n];
  }
  cout <<'\n';
  return (0);
}

