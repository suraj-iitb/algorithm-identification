#include<stdio.h>
 
#define N 100
 
 
 
 
int main(){
 
  int i,j,mini,n,t;
  int A[N];
  int count = 0;
 
  scanf("%d",&n);
  for(i =0;i<n;i++){
    scanf("%d",&A[i]);
  }
 
 
  for(i =0;i<=n-1;i++){
     mini =i;
    for(j = i;j<=n-1;j++){
      if(A[j] < A[mini]){
    mini = j;
      }
    }
    if(A[mini]<A[i]) count++;
    t = A[i];
    A[i] = A[mini];
    A[mini] = t;
     
  }
     
 
 
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
