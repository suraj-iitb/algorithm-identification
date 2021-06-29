#include<stdio.h>
int main(){

  int arr[1024];
  int a=0,i,l,m,n,temp;
  int v,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

 for(i=0;i<n;i++){
    printf("%d",arr[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");

  for(i=1;i<=n-1;i++){
    v=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>v){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=v;

 for(l=0;l<n;l++){
    printf("%d",arr[l]);
    if(l<n-1)printf(" ");
  }
  printf("\n");

  }

  return 0;
}
