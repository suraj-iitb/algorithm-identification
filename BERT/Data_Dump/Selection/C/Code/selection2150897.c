#include <stdio.h>

int num[110];

int selectionsort(int num[],int n){

  int i,j,min,tmp,count=0;

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(num[j]<num[min]){
        min=j;
      }
    }
    tmp=num[i];
    num[i]=num[min];
    num[min]=tmp;
    if(min!=i) count++;
  }
  return count;
}

int main(){

  int n,i,ans;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  ans=selectionsort(num,n);
  for(i=0;i<n-1;i++) printf("%d ",num[i]);
  printf("%d\n%d\n",num[n-1],ans);
  return 0;
}
