#include<stdio.h>
int main(){

int A[100],i,j,minj,count=0,N,temp;

scanf("%d",&N);
for(i=0;i<N;i++){
scanf("%d",&A[i]);
}
 for(i=0;i<N;i++){
  minj=i;
  for(j=i+1;j<N;j++){
    if(A[j]<A[minj]){
      minj=j;
    }
  }
  if(minj!=i){
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
    count=count+1;
  }
}
for(i=0;i<N;i++){
  if(i!=N-1)printf("%d ",A[i]);
  else printf("%d\n",A[i]);
}
printf("%d\n",count);
return 0;
}

