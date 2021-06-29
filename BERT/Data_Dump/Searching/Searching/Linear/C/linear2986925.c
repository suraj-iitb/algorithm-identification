#include<stdio.h>

#define MAX 10000
#define NOT_FOUND 0 

int n,q;
int A[MAX],T[MAX];

int i,j;
int C=0;
int linerSearch(){
  for(i=0;i<n;i++){
    if(A[i]==T[j])return 1;
  }
  return NOT_FOUND;
}





int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);

  scanf("%d",&q);

  for(j=0;j<q;j++){
    
    scanf("%d",&T[j]);
	
    C+=linerSearch();
  }


  printf("%d\n",C);

  return 0;
}






	   

