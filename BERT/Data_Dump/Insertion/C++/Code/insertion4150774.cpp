#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

void insertionSort(vector<int> &a,int n);

int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n){
    cin>>a[i];
  }
  
insertionSort(a,n);
  
}

void insertionSort(vector<int> &a,int n){
  int v;
  rep(k,n-1){
      cout<<a[k]<<" ";
    }
    cout<<a[n-1];
  for(int i=1;i<n;i++){
    cout<<endl;
    v=a[i];
    int j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
     a[j+1]=v;
     rep(k,n-1){
      cout<<a[k]<<" ";
    }
    cout<<a[n-1];
  }
  cout<<endl;
}

