#include <cstdio>
#include <iostream>
using namespace std;
int cnt;
void selection_sort(int *A,int N){
  for(int i=0;i<N;i++){
    int minj=i;
    for(int j=i;j<N;j++){
      if(A[j]<A[minj])minj=j;
    }
    if(i!=minj)cnt++;
    int temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
   
  }
}
int main(){
  int N;
  int A[101];
  cin >> N;
  for(int i=0;i<N;i++)cin >> A[i];
  selection_sort(A,N);
  for(int i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1)printf(" ");
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}
