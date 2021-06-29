#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define REPR(i, m, n) for (int i = (int)(m); i >= (int)(n); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
#define MAX 2000001
#define VMAX 10000

short A[MAX];
short B[MAX];

int main(){
  int C[VMAX+1];
  int n;
  scanf("%d", &n);

  rep(i, VMAX+1) C[i] = 0;
  rep(i, n){
    scanf("%hu", &A[i]);
    C[A[i]]++;
  }
  REP(i, 1, VMAX) C[i] += C[i-1];

  rep(i, n){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  REP(i, 1, n){
    if(i != 1) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");

  return 0;
}




