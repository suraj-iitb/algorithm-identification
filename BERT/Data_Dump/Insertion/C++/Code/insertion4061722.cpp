#include <bits/stdc++.h>
using namespace std;

void Insertion_Sort(int N,int A[]){
  int v;
  for(int i=1;i<N;i++){
    v = A[i];
    int j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(int k=0;k<N;k++){
          if(k ==0){
              cout << A[k];
          }else{
              cout << " " << A[k];
          }
      }
      cout << endl;
  }

}


int main(){
  int N;
  cin >> N;
  int A[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int k=0;k<N;k++){
        if(k ==0){
            cout << A[k];
        }else{
            cout << " " << A[k];
        }
    }
    cout << endl;
  Insertion_Sort(N,A);
}

