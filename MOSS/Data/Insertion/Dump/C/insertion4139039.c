#include <stdio.h>

#define MAX 1000

void insertion(int *,int);

int main(){
  int A[MAX],key;
  int i=0,j,k;
  int num;

  scanf("%d",&num);
  for(i=0;i<num;i++) scanf("%d",&A[i]);

  insertion(A,num);
  
  /*for(i=1;i<=num;i++){
    key=A[i];
    j=i-1;
    while(j>=0&&A[j]>key){
      A[j+1]=A[j];
	j--;
    }
    A[j+1]=key;
    for(k=1;k<num;k++) printf("%d ",A[k]);
    printf("%d",A[k]);
    printf("\n");
  }
*/
  return 0;
}

//kannsuuka
void insertion(int *A,int len){
  int key;
  int i,j,k;
  
  for(k=0;k<len;k++){
      if(k!=0) printf(" ");
      printf("%d",A[k]);
    }
    printf("\n");
  for(i=1;i<len;i++){
    key=A[i];
    j=i-1;
    while(j>=0&&A[j]>key){
      A[j+1]=A[j];
	j--;
    }
    A[j+1]=key;
    for(k=0;k<len;k++){
      if(k!=0) printf(" ");
      printf("%d",A[k]);
    }
    printf("\n");
  }
}

