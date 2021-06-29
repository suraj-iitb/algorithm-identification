#include <stdio.h>
#define N 100

int main(){
  int a,b,i,j,c,v,minj;
  int A[N];

	scanf("%d",&b);
	for(i=0;i<b;i++){
		scanf("%d",&A[i]);
		v=A[i];}
	for(i=0;i<b-1;i++){
	  minj = i;
	  for(j=i;j<b;j++){
	    if(A[j] < A[minj])
	      minj = j;
	  }
	      v=A[i];
	      A[i]=A[minj];
	      A[minj]=v;
	      if(i != minj)c++;
	}
	for(j=0;j<b;j++){
	  printf("%d",A[j]);
	  if(j<b-1) printf(" ");
	}
	printf("\n");
	printf("%d\n",c);
	return 0;
}
