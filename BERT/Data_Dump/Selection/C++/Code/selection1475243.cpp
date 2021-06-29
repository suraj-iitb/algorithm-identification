#include<iostream>
using namespace std;

int selectionsort(int A[] ,int N){
  int i,j,sw=0,minj;

  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj]){
	minj=j;
      }
    }
    swap(A[i],A[minj]);
    if(i!=minj){
      sw++;
    }
  }
  return sw;
}

int main(){
  int A[100],sw,i,j,N;

  cin >> N;

  for(i=0;i<N;i++){
    cin >> A[i];
  }
  sw=selectionsort(A,N);
  for(i=0;i<N;i++){
    if(i)cout << " ";
    cout << A[i];
}
  cout << endl;
  cout << sw<<endl;
}
