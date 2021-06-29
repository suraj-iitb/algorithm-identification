#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

void selectionSort(vector<int> &a,int n);

int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n){
    cin>>a[i];
  }
  
  selectionSort(a,n);

}

void selectionSort(vector<int> &a,int n){
  int cou=0,minj;
  for(int i=0;i<n;i++){
    minj = i;
    for(int j=i;j<n;j++){
      if (a[j] < a[minj]){
        minj = j;
      }
    }
    if(a[i]!=a[minj]){
       swap(a[i],a[minj]);
       //cout<<i<<a[i]<<a[minj]<<endl;
       cou++;
      }
  }
  rep(i,n-1){
    cout<<a[i]<<" ";
  }
  cout<<a[n-1]<<endl;
  cout<<cou<<endl;
}

