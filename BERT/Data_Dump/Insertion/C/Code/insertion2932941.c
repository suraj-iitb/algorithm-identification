#include <stdio.h>
int main(){
  int n,i,v,j,A[100],k;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;i<n;i++){
    for(k=0;k<n;k++){
      printf("%d",A[k]);
      if(k!=n-1)printf(" ");
    }
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;	
	}
      printf("\n");
  }
  for(k=0;k<n;k++){
      printf("%d",A[k]);
      if(k!=n-1)printf(" ");
    }
   printf("\n");
  return 0;
}

