#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

void bubbleSort(vector<int> &a,int n);

int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n){
    cin>>a[i];
  }
  
bubbleSort(a,n);
  
}

void bubbleSort(vector<int> &a,int n){
  bool flag =1;  //逆の隣接要素
  int count=0;
  while(flag){
    flag=0;
    for(int i=n-1;i>0;i--){
      if(a[i]<a[i-1]){
        flag=1;
        swap(a[i],a[i-1]);
        count++;
      }
    }
    

  }
  rep(i,n){
    if(i>0)cout<<" ";
    cout<<a[i];
  }
  cout<<endl;
  cout<<count<<endl;
}

