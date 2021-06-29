// bubble sort alg
// input integer elements, output sorted elements and number of change operations
#include<iostream>
void BubbleSort(int*,int);
int main(){
  int N;
  std::cin >> N;
  int A[N];
  for(int i=0; i<N; i++) std::cin >> A[i];
  BubbleSort(A,N);
  return 0;
}
void BubbleSort(int *B, int N){
  int cnt=0,tmp;
  for(int i=0; i<N-1; i++) for(int j=N-1; j>i; j--) if(B[j] < B[j-1]) tmp = B[j], B[j] = B[j-1], B[j-1] = tmp,cnt++;
  for(int i=0; i<N; i++) std::cout << B[i] << (i < N-1 ? " " : "\n");
  std::cout << cnt << "\n";
}
