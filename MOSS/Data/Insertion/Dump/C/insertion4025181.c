#include<stdio.h>
#include<stdlib.h>

#define N 1000

int main(){
  int key,i,j,n,A[N];
    scanf("%d",&n);
    if(n>100)exit(1);
    
    for(i=0;i<n;i++){
      scanf("%d",&A[i]);
      printf("%d",A[i]);
      if(i<n-1)printf(" ");
    }
    printf("\n");
for(j=1;j<=n-1;j++){
    key=A[j];
    i=j-1;
    while(i>=0&&A[i]>key){
        A[i+1]=A[i];
        i=i-1;
        A[i+1]=key; 
    }
    for(i=0;i<n;i++){
	  printf("%d",A[i]);
	  if(i<n-1)printf(" ");
        }
	printf("\n");
        
 }
 return 0;
}

