#include<stdio.h>
int linsearch(int, int A[], int);

int main(){
  int n, i, q, c = 0;
  scanf("%d", &n);
  int S[n];
  for(i = 0; i < n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  int T[q];
  
  for(i = 0; i < q; i++) {
    scanf("%d", &T[i]);
    if(linsearch(n, S, T[i]) == 1) c += 1;
    
  }
  printf("%d\n", c);

  return 0;
}

int linsearch(int n, int A[], int key){
  int i = 0;

  while(1){
    if(A[i] == key) return 1;
    i++;
    if(i == n) break;
  }
  return -1;
}

