#include<iostream>
using namespace std;
static const int MAX = 100;

void trace(int A[], int n){
  for(int i=0; i<n; i++ ){
    if(i>0)cout<<' ';
    cout<<A[i];
  }
  cout<<endl;   
}

int selectionSort(int A[],int N){
  int times = 0;
  for (int i=0; i<N; i++ ){
    int minj=i;
    for(int j=i; j<N; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if( i!=minj ){
      swap(A[i],A[minj]);
      times++;
    }
  }
  trace(A,N);
  return times;
}

int main(){
  int n, a[MAX], times;

  cin >> n;

  for( int i=0; i<n; i++ ) cin >> a[i];

  times = selectionSort(a,n);
  cout << times << endl;

  return 0;
}
