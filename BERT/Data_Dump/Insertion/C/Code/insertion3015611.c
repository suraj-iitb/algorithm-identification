#include<stdio.h>
 
int main() {
 
  int i,j,k,v,n,A[100];
 
   
  scanf("%d",&n);
 
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  
  for(i=1;i<=n;i++) {
  	v = A[i];
  	j = i-1;
  		for(k=0;k <=n-1;k++){
  			if(k<n-1) printf("%d ",A[k]);
  			else printf("%d",A[k]);
  		}
  	printf("\n");
  	while(j >=0 && A[j] > v) {
  		A[j+1] = A[j];
  		j--;
  	}
  	A[j+1] = v;
  }
  return 0;
}
