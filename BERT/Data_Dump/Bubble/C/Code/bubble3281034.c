# include <stdio.h>
#define N 100
 

int main(){
int A[N];
int n;
 int i,j,count=0,tmp;
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
     }
  
  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
     if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
     
	count++;
     }
    }
  }
     
    
  

  
  
  for(i=0;i<n-1;i++)printf("%d ",A[i]);
 
  
  printf("%d\n%d\n",A[n-1],count);


  return 0;
}

