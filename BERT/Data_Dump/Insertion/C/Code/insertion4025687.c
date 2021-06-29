
#include<stdio.h>
void insertSort (int[],int );
int main(){
  int i,N=0,v,l;
  int A[100];
  scanf("%d",&N);
  if(N<1 || N>100) return 0;
  for(i=0;i<N;i++){
    scanf(" %d",&A[i]);
  }
  insertSort (A,N);
  return 0;
}

void insertSort(int A[],int N){
 int i,j,v,l;
 
    for(j=1;j<N;j++){
      v=A[j];
      i=j-1;
             printf("%d",A[0]);
       for(l=1;l<N;l++){
	printf(" %d",A[l]);
       }
      printf("\n");
       
      while(i>=0 && A[i]>v){
	A[i+1]=A[i];
	i--;
	A[i+1]=v;
	
      }

 

    }
    printf("%d",A[0]);
       for(l=1;l<N;l++){
	printf(" %d",A[l]);
       }
       printf("\n");
   
}
  


