#include <iostream>
using namespace std;

int bubbleSort(int *a,int N){
  int flag=1;
  int num,cnt=0;
  while(flag){
    flag=0;
    for(int i=N-1;i>=1;i--){
      if(a[i]<a[i-1]){
        num = a[i-1];
        a[i-1] = a[i];
        a[i] = num;
        flag = 1;
        cnt++;
      }
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
  s=bubbleSort(A,N);
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

