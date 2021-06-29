
#include <stdio.h>
#include <ctype.h>

#define MAX_N 2000001
#define MAX_K 10001

char buf[MAX_N*5];

int getInteger();
void countingSort(int,int*);

int main(){
  int a,i;
  static int A[MAX_N];
  fread(buf,1,MAX_N*5,stdin);
  a = getInteger();
  for(i = 0 ; i < a ; i++){
    A[i] = getInteger();
  }
  countingSort(a,A);
  return 0;
}

int getInteger(){
  int res = 0;
  static int c = 0;
  while(isdigit(buf[c])){
    res *= 10;
    res += (buf[c++]-'0');
  }
  c++;
  return res;
}

void countingSort(int a,int *A){
  int i,C[MAX_K] = {0};
  static int B[MAX_N];
  
  for(i = 0; i < a;i++){
    C[A[i]]++;
  }
  for(i = 1;i < MAX_K;i++){
    C[i] += C[i-1];
  }
  for(i = a-1 ; i >= 0 ; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  for(i = 0;i < a;i++){
    printf("%d%c",B[i+1],i < a-1 ? ' ' : '\n');
  }
}

