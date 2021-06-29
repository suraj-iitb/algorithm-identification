#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int N){
  for(int i=1;i<N;i++){
    int v =a[i];
    int j = i-1;
    while(j>=0 && a[j]>v){
      a[j+1] =a[j];
      j--;
    }
    a[j+1]=v;
    for(int k=0;k<N;k++){
      if(k==N-1) cout<<a[k]<<endl;
      else cout <<a[k]<<" ";
    }
  }
}

int main() {
  int N;
  cin>>N;
  int a[N];
  for (int j = 0; j < N; j++) cin>>a[j];

  for(int k=0;k<N;k++){
      if(k==N-1) cout<<a[k]<<endl;
      else cout <<a[k]<<" ";
    }
  insertionSort(a,N);

  }

