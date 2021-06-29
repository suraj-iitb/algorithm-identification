#include<stdio.h>
#include<stdlib.h>

#define N 1000

void insert(int *,int);

int main(){
  int i,j;
  int A[N],num;
  
  scanf("%d",&num);

  if(num<1 || 100<num){
    printf("実行できません\n");
    exit(1);
  }

  for(i=0; i<num; i++){
    scanf("%d",&A[i]);
    if(A[i]<0 || 1000<A[i])exit(2);
  }

  insert(A,num);
    /*
    for(j=0; j<num; j++){
      printf("%d ",A[j]);
    }
    */

  return 0;
}

void insert(int *A,int num){
  int i,j,k;
  int key;
  
  for(i=0; i<num; i++){
    key=A[i];
    j=i-1;

    while(j>=0 && A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
    
    for(k=0; k<num; k++){
      printf("%d",A[k]);
      if(k!=num-1)printf(" ");
    }
    //if(i!=num-1)
    printf("\n");
  }

}

