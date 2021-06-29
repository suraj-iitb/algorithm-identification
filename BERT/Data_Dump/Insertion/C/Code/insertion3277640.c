#include <stdio.h>
#include <stdlib.h>

int n,A[100];
void print_seq(void);

int main(){
  int i,j,v;
  
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    print_seq();
    
    for(i=1;i<n;i++){
        v=A[i];
        for(j=i-1;j>=0 && A[j]>v;j--)
            A[j+1]=A[j];
        A[j+1]=v;
	print_seq();
    }
}

void print_seq(void){
  int i;
  for(i=0;i<n;i++){
    if(i<n-1) printf("%d ",A[i]);
    else printf("%d",A[i]);
  }
  printf("\n");
}

