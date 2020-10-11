#include<stdio.h>
int main(){
  int n,i,j,min,count=0,w;
  int B[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&B[i]);
  }
  for(i=0;i<=n-1;i++){
    min=i;
    for(j=i;j<=n-1;j++){
      if(B[j]<B[min]){
	min=j;
      }
    }
      if(i != min){
	count++;
	w=B[i];
	B[i]=B[min];
	B[min]=w;
      }}
    for(i=0;i<n-1;i++){
      printf("%d ",B[i]);
			   
	}
    printf("%d",B[n-1]);
    printf("\n");
    printf("%d\n",count);
    return 0;
}

