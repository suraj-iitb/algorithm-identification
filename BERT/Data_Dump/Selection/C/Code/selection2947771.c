#include<stdio.h>
int main(){
  int A[100],k,i,n,minj,chg,j,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=n-2;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj]){
	minj=j;
        
      }
    }
    if(A[i]!=A[minj])count++;
    chg=A[i];
    A[i]=A[minj];
    A[minj]=chg;
    }
 
   for(i=0;i<n;i++){
      if(i==n-1)printf("%d\n",A[i]);
      else printf("%d ",A[i]);
    }
    printf("%d\n",count);
  return 0;
}

