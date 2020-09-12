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
      int min = i;
      for(int j=i; j<N; j++){
        if(A[j] < A[min]) min = j;
      }
      if(min != i){
        int t = A[min];
        A[min] = A[i];
        A[i] = t;
        count++;
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
