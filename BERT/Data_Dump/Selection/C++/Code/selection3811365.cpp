#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int N){
  bool flg =1;
  int count=0;
  for(int i=0;i<N;i++){
    int minj=i;
    for(int j=i;j<N;j++){
        if(a[j]<a[minj]){
          minj =j;
        }

    }
    swap(a[i],a[minj]);
    if(i!=minj) count++;
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

  selectionSort(a,N);


}

