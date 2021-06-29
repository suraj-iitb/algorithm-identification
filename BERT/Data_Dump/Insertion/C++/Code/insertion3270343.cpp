#include<stdio.h>
#define N 100
int main(){
  int n,i,j,k,data[N];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&data[i]);
   for(k=0;k<n-1;k++)
    printf("%d ",data[k]);
   printf("%d",data[n-1]);
  printf("\n");
  for(j=1;j<n;j++){
    k = data[j];
    i = j - 1;
    while(i >= 0 && data[i] > k){
      data[i+1] = data[i];
      i--;
	}
      data[i+1] = k;
      for(k=0;k<n-1;k++)
    printf("%d ",data[k]);
      printf("%d",data[n-1]);
  printf("\n");
  }
  return 0;
}
