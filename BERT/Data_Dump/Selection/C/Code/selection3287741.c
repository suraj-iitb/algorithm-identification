#include<stdio.h>
int main(){
  int i,j,minj,temp,count,N;
  int A[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])minj=j;
    }
        temp=A[i];
        A[i]=A[minj];
        A[minj]=temp;
        if(i!=minj)count++;
    }
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
printf("\n%d\n",count);
return 0;
}

