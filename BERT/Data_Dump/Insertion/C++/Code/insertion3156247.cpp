#include <stdio.h>
#include <iostream>
using namespace std;
static const int MAX = 100;


int main(){
  int n, A[MAX];
  cin >> n;
  for(int i = 0;i < n;i++) cin >> A[i];
  int v,j;
  for(int i = 0;i < n;i++){
       if(i > 0) printf(" ");
       printf("%d", A[i]);      
       } 
       printf("\n");
  for(int i = 1; i < n; i++){
     /* for(int k = 0;k < n;k++){
       if(k > 0) printf(" ");
       printf("%d", A[k]);      
       } 
       printf("\n"); */
      v = A[i];
      j = i-1;
    while((j >= 0) && (A[j] > v)){
       A[j+1] = A[j];
       j--;
    }
    A[j+1] = v;
   for(int i = 0;i < n;i++){
      if(i > 0) printf(" ");
      printf("%d", A[i]);      
   } 
    printf("\n"); 
  }  
  return 0;
}
