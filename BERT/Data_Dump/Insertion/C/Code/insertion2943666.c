#include<stdio.h>

int main(){
  int i=0,j=0,A[100],b,v,k=0;
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&A[i]);
  }

  for(i=1;i<=b;i++){
    v=A[i];
    j=i-1;
    for(k=0;k<=b-1;k++){
      if(k<b-1){
        printf("%d ",A[k]);
      }
      else{
        printf("%d",A[k]);
      }
    }
    printf("\n");
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1] = v;
    }
  }
  return 0;
}

