#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int N){
  bool flg =1;
  int count=0;
  while(flg){
    flg =0;
    for(int j=N-1;j>0;j--){
      if(a[j]<a[j-1]) {
        swap(a[j],a[j-1]);
        count++;
        flg=1;
      }

    }
  }

  for(int k=0;k<N;k++){
      if(k==N-1) cout<<a[k]<<endl;
      else cout <<a[k]<<" ";
    }
    cout<<count<<endl;

}

int main() {
  int N;
  cin>>N;
  int a[N];
  for (int j = 0; j < N; j++) cin>>a[j];

  bubbleSort(a,N);
  //for(int k=0;k<N;k++){
    //  if(k==N-1) cout<<a[k]<<endl;
     // else cout <<a[k]<<" ";
    //}

}

