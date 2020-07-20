#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> p;

int n,ans=0;
int a[114514];

void bubbleSort(int n){
  bool flag=1;
  while(flag){
    flag=0;
    for(int j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	swap(a[j], a[j-1]);
	flag=1;
	ans++;
      }
    }
  }
}

int main(){
  int n;
  cin>>n; 
  for(int i=0;i<n;i++)cin>>a[i];
  bubbleSort(n);
  for(int i=0;i<n;i++){
      if(i!=n-1)cout<<a[i]<<" ";
      else cout<<a[i]<<endl;
  }
  cout<<ans<<endl;
}


