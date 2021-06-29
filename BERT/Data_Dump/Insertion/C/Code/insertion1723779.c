#include<stdio.h>

#define MAX 100

int main(){
  
  int i,j,n,v,a;
  int arr[MAX];
  
  scanf("%d",&n);

  for(a=0;a<n;a++){
    scanf("%d",&arr[a]);
  }
  
  for(a=0;a<n-1;a++){
    printf("%d ",arr[a]);  
  }
  printf("%d\n",arr[n-1]);
  
  
  for(i=1;i<=n-1;i++){
    v = arr[i];
    j = i - 1;
    while(j>=0&&arr[j]>v){
      arr[j+1] = arr[j];
      j--;
      arr[j+1] = v;
    }
    for(a=0;a<n-1;a++){
      printf("%d ",arr[a]);  
    }
    printf("%d\n",arr[n-1]);
  }
  
  return 0;
}
