#include<iostream>
#include<algorithm>
using namespace std;
int SelectionSort(int A[], int N){
  int cnt = 0;
  for(int i = 0; i < N; i++){
    int minj = i;

    for(int j = i; j < N; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }

    swap(A[i],A[minj]);
    if(i != minj) cnt++;
  }
  return cnt;
}
int main(){
  int N,cnt;
  cin >> N;
  int A[N];
  for(int i = 0; i < N; i++)
    cin >> A[i];

  cnt = SelectionSort(A,N);

  for(int i = 0; i < N; i++){
    cout << A[i];
    if(i == N-1) cout << endl;
    else cout << " ";
  }
  cout << cnt << endl;
}
