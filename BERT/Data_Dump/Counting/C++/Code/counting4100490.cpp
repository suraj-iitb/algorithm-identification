#include<bits/stdc++.h>
using namespace std;
#define MAX 2000000
#define CMAX 10000

int main(){
  int n,a[MAX],c[CMAX],ans[MAX],i;
  int k=0;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>a[i];
    if(a[i]>k)k=a[i];
  }
  for(i=0;i<=k;i++)c[i]=0;
  for(i=0;i<n;i++){
    c[a[i]]++;
  }

  for(i=1;i<=k;i++)c[i]=c[i]+c[i-1]; 
  for(i=n-1;i>=0;i--){
    ans[c[a[i]]]=a[i];
    c[a[i]]--;
  }

  for(i=1;i<=n;i++){
    cout<<ans[i];
    if(i!=n)cout<<" ";
    else cout<<endl;
  }
  return 0;
}

