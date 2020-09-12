#include <iostream>
#include <cstring>
using namespace std;
int A[100];
int main()
{
  int N;
  while(cin >> N){
    memset(A,0,sizeof(A));
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    int count = 0;
    for(int i=0; i<N; i++){
      for(int j=N-1; j>i; j--){
        if(A[j] < A[j-1]){
          int t = A[j];
          A[j] = A[j-1];
          A[j-1] = t;
          count++;
        }
      }
    }
    for(int i=0; i<N; i++){
      if(i!=0) cout << " ";
      cout << A[i];
    }
    cout << endl;
    cout << count << endl;
  }
  return 0;
}
