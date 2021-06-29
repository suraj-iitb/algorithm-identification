// selection sort alg
// input integer elements, output sorted elements and number of change operations
#include<iostream>
void SelectionSort(int*,int);
int main(){
  int N;
  std::cin >> N;
  int A[N];
  for(int i=0; i<N; i++) std::cin >> A[i];
  SelectionSort(A,N);
  return 0;
}
void SelectionSort(int *S, int N){
  int cnt=0,tmp;
  for(int i=0,min; i<N-1; i++){
    min = i;
    for(int j=i; j<N; j++) if(S[j] < S[min]) min = j;
    if(S[i] != S[min]) tmp = S[i], S[i] = S[min], S[min] = tmp, cnt++;
  }
  for(int i=0; i<N; i++) std::cout << S[i] << (i < N-1 ? " " : "\n");
  std::cout << cnt << "\n";
}
