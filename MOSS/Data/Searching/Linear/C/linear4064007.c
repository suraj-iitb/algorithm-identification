#include<stdio.h>

int search(int A[], int n, int key){
  int i = 0;
  A[n] = key;
  while(A[i] != key) i++;
  return i != n;
}


int main(){
  int i, n,x,key, sum = 0;
  int A[10000];
   scanf("%d", &n);
   for(i = 0; i < n; i++)scanf("%d", &A[i]);

   scanf("%d", &x);
   for(i = 0; i < x; i++){
     scanf("%d", &key);
     if(search(A, n,key))
       sum = sum +1;
   }
   printf("%d\n", sum);
   return 0;
}

