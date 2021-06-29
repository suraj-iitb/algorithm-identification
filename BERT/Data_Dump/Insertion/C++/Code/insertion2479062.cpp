#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>

using namespace std;
int n;
int A[108];

void input(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>A[i];
}

void solve(){
  for(int i=0;i<n;i++){
    int v=A[i];
    int j;
    for( j=i;j>0&&A[j-1]>v;j--)A[j]=A[j-1];
    A[j]=v;
    for(int k=0;k<n;k++){
      cout<<A[k];
      if(k==n-1) cout<<endl;
      else cout<<' ';
    }
  }
}
int main(){
  input();
  solve();
}
