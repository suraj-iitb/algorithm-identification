#include<iostream>
using namespace std;
static const int MAX = 100;

void insertionSort(int A[],int N){
  for(int i=0;i<N;i++){
    int v=A[i];
    int j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    cout<<A[0];
    for(int k=1;k<N;k++){
      cout<<" "<<A[k];
    }
    cout<<endl;
  }
}

int main(){
  int A[MAX],N;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  insertionSort(A,N);
  return 0;
}
