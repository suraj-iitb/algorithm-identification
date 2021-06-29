#include<stdio.h>
#define N 100

int main(void) {
  
  int tmp,n,i,mini,j,A[N],cnt=0;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++) 
    scanf("%d",&A[i]);
  
  for(i=0;i<n;i++) {
    mini = i;
    
    for(j=i;j < n;j++) {
      
      if(A[j] < A[mini])
	mini = j;
      
    }
    if(mini != i){
      tmp = A[i];
      A[i] = A[mini];
      A[mini] = tmp;
  }
    if(i != mini)
      cnt++;
  }  
  
  for(i=0;i<n;i++) {
    if(i > 0)
      printf(" ");
    printf("%d",A[i]);
    
  }   
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}
