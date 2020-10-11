#include<stdio.h>
void Swap(int*,int*);

int main(){
  int A[100],i,N,s;
  int flag=1,scount=0,j;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
 
  while(flag){
    flag = 0;
    for(j=N-1;j>s;j--){
      if(A[j] < A[j-1]){
	Swap(&A[j],&A[j-1]);

	/*
	for(i=0;i<N;i++){
	  if(i) printf(" ");
	  printf("%d",A[i]);
	}
	printf("\n");
	*/
	scount++;		
      }
      
      flag = 1;
     
    }
    s++;
  }
  for(i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",A[i]);
  }
  
  printf("\n");
  printf("%d\n",scount);

    return 0;
    }

void Swap(int *x,int *y){
  int work;

  work = *x;
  *x = *y;
  *y = work;
}

