#include <stdio.h>
#define N 100000
 
int A1[N];
char A2[N];
int input1[N];
char input2[N];
 
void swap1(int* a, int* b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
 
void swap2(char* a, char* b){
  char tmp = *a;
  *a = *b;
  *b = tmp;
}
 
int partition(int p, int r){
  int x = A1[r];
  int i = p - 1, j;
  for(j=p;j<r;j++){
    if(A1[j] <= x){
      i++;
      swap1(&A1[i], &A1[j]);
      swap2(&A2[i], &A2[j]);
    }
  }
  swap1(&A1[i+1], &A1[r]);
  swap2(&A2[i+1], &A2[r]);
  return i+1;
}
 
void quic_sort(int p, int r){
  if(p < r){
    int q = partition(p, r);
    quic_sort(p, q-1);
    quic_sort(q+1, r);
  }
}
 
int check(int n){
  int i, j;
  for(i=1;i<n;i++){
    if(A1[i-1] == A1[i]){
      int a, b;
      for(j=0;j<n;j++){
        if(A1[i-1] == input1[j] && A2[i-1] == input2[j]) a = j;
        if(A1[i] == input1[j] && A2[i] == input2[j]) b = j;
      }
      if(a > b) return 0;
    }
  }
  return 1;
}
 
main(){
  int n, i;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    getchar();
    scanf("%c%d", &A2[i], &A1[i]);
  }
  for(i=0;i<n;i++){
    input1[i] = A1[i];
    input2[i] = A2[i];
  }
  quic_sort(0, n-1);
  printf("%s\n", (check(n) ? "Stable" : "Not stable"));
  for(i=0;i<n;i++) printf("%c %d\n", A2[i], A1[i]);
  return 0;
}
