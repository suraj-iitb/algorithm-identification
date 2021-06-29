#include<stdio.h>

int main(){
  
  int n;
  int A[1000];
  int a,i=0,j,v,k;

  scanf("%d",&n);
  if((n<1)||(100<n)){
    fprintf(stderr,"error n\n");
    return 0;
  }

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(k=0;k<n;k++){
    if(k==n-1) printf("%d",A[k]);
    else printf("%d ",A[k]);
  }
  printf("\n");
  

  for(i=1;i<n;i++){
    v=A[i];
    j=i-1;
    while((j>=0)&&(A[j]>v)){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    
 for(k=0;k<n;k++){
   if(k==n-1) printf("%d",A[k]);
   else printf("%d ",A[k]);
    
  }
 printf("\n");

  }



  
  return 0;
}

      

