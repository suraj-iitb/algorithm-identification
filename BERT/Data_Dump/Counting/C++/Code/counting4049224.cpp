#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(obj) (obj).begin(),(obj).end()
typedef long long llong;
llong mod=1e9+7;

void Count(vector<int> A,vector<int> &B,int n){
  vector<int> C(10000,0);
  for(int i=0;i<n;i++){
    C.at(A.at(i))++;
  }
  for(int i=1;i<10000;i++){
    C.at(i)+=C.at(i-1);
  }
  for(int i=n-1;i>=0;i--){
    B.at(C.at(A.at(i))-1)=A.at(i);
    C.at(A.at(i))--;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
 int n;
 cin>>n;
vector<int> A(n),B(n);
for(int i=0;i<n;i++)cin>>A.at(i);
Count(A,B,n);
for(int i=0;i<n;i++){
  cout<<B.at(i);
  if(i!=n-1)cout<<" ";
}
cout<<endl;
return 0;
}


