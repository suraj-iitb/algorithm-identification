#include<stdio.h>
#define N 100
int main(){
  int i,j,A[N],minj,a,n,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    for(i=0;i<n;i++){
        minj = i;	
	for(j=i;j<n;j++){
	  if(A[j]<A[minj])   minj=j;
	}
	  a=A[i];
	  A[i]=A[minj];
	  A[minj]=a;
	  if(A[i]!=A[minj]) count++;
	
    }
    
     for(j=0;j<n-1;j++){
        printf("%d ",A[j]);
    }
    printf("%d\n",A[n-1]);
    printf("%d\n",count);
    return 0;
    
}

