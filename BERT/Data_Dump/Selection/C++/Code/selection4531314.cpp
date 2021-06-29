#include <iostream>
using namespace std;

int selectionSort(int *a,int N){
  int minj,cnt=0;
  for(int i=0;i<N;i++){
    minj = i;
    for(int j=i;j<N;j++){
      if(a[j]<a[minj]){
        minj = j;
      }
    }
    if(minj != i){
      int num=a[minj];
      a[minj] = a[i];
      a[i] = num;
      cnt++;
    }
  }
  return cnt;
}

int main(){
  int N;
  cin >> N;

  int A[N];
  for(int i=0;i<N;i++){
    cin >> A[i] ;
  }
  int s;
  s=selectionSort(A,N);
  for(int i=0;i<N;i++){
    if(i!=N-1){
      cout << A[i] << " ";
    }else{
      cout << A[i] << endl;
    }
  }

  cout << s << endl;
  return 0;
}

