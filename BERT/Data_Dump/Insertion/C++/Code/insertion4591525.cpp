#include <bits/stdc++.h>
using namespace std;

int main(){

  int N;
  cin >> N;
  vector<int> A(N);
  for( int i = 0; i < N; i++){
    cin >> A[i];
    printf("%d",A[i]);
    if(i == N-1) printf("\n");
    else printf(" ");
  }

  for( int i = 1; i < N; i++){
    int v = A[i];
    int j = i-1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
    
    for( int k = 0; k < N; k++){
      printf("%d",A[k]);
      if(k == N-1) printf("\n");
      else printf(" ");
    } 

  }
  return 0;

}
