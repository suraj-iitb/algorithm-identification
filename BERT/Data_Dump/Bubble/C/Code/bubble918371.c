#include<stdio.h>
#define N 100

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){
  
  int length,n[N],i,j,tmp,count=0;
  
  scanf("%d",&length);
  
  for(i = 0;i < length;i++){
    
    scanf("%d",&n[i]);
  }
  
  for(i = 0;i < length;i++){
    for(j = length - 1;j > i;j--){
      
      if(n[j] < n[j - 1]){
	tmp = n[j];
	n[j] = n[j-1];
	n[j-1] = tmp;
	count++;
      }
    } 
  } 

  trace(n,length);

  printf("%d\n",count);

  return 0;
}
