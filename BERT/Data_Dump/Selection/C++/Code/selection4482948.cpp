#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> p;

int n,ans=0;
int a[114514];

void selectionSort(int n){
  for(int i=0;i<n;i++){
    int minj=i;
    bool flag=false;
    for(int j=i;j<n;j++){
      if(a[j]<a[minj])minj=j,flag=true;;
    }
    swap(a[i],a[minj]);
    if(flag)ans++;
  }
}

int main(){
  int n;
  cin>>n; 
  for(int i=0;i<n;i++)cin>>a[i];
  selectionSort(n);
  for(int i=0;i<n;i++){
      if(i!=n-1)cout<<a[i]<<" ";
      else cout<<a[i]<<endl;
  }
  cout<<ans<<endl;
}

