#include<stdio.h>
int main(){
  int a,A[100],N,i,j,minj,cnt=0;
  scanf("%d",&N);
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=N-1;i++){
  
    
  for(j=minj=i;j<=N-1;j++){
    if(A[j]<A[minj])minj=j;
  }
  if(A[i]>A[minj]){
     
    //A[i]toA[minj]wokoukan
    a=A[i];
    A[i]=A[minj];
    A[minj]=a;
      if(i!=minj)cnt++;
  }
    
  }
  
  
  
 
 

for(j=0;j<N-1;j++){
  printf("%d ",A[j]);
 }
printf("%d\n",A[N-1]);
  printf("%d\n",cnt);
return 0;
}


