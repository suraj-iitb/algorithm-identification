#include<stdio.h>
#define N 100
int main(){
  int n,array[N],min,k  ,l,j,i,count=0,arr[N],temp;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&array[i]);
  }

  for(i=0;i<n;i++){

    k=i;

    for(j=i+1;j<n;j++){

      if(array[j]<array[k]){
	k=j;


      }
    }

    temp=array[i];
    array[i]=array[k];
    array[k  ]=temp;

    if(array[k  ] != array[i])
	count++;
  }

  for(i=0;i<n-1;i++){
    printf("%d ",array[i]);
  }
  printf("%d\n",array[n-1]);
  printf("%d\n",count);

  return 0;
}
