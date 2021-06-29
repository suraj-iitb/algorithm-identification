#include<stdio.h>
 
int main(){
  int A[100],i,j,v,a,b;
   
  scanf("%d",&a);
 
 for(i=0;i<=a-1;i++){
	scanf("%d",&A[i]);
	}

 for(b=0;b<=a-1;b++){
    printf("%d",A[b]);
    if(b<=a-2)printf(" ");
	}
      printf("\n");
   
  for(i=1;i<=a-1;i++){
	v=A[i];
	j=i-1;
		while(j >= 0 && A[j] > v){
			A[j+1]=A[j];
			j--;
			A[j+1]=v;
	}
  for(b=0;b<=a-1;b++){
	printf("%d",A[b]);
	if(b<=a-2) printf(" ");
	}
  printf("\n");
 }
return 0;
}
