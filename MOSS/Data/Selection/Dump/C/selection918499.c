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
  
  int i,j,n[N],mini,length,tmp,count=0,flag;

  
  scanf("%d",&length);
  for(i = 0;i < length;i++){
    
    scanf("%d",&n[i]);
  }
  
  for(i = 0;i <  length;i++){
    flag = 0;
    mini = i;
    for(j = i;j < length;j++){
      
      if(n[j] < n[mini]){
	mini = j;
	flag = 1;	
      }
    }
    if(flag == 1){
  	tmp = n[i];
	n[i] = n[mini];
	n[mini] = tmp;
	count++;  
    }
  }
  
  trace(n,length);

  printf("%d\n",count);
 
  
  return 0;
  
}
