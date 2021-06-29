#include <stdio.h>
#define A 100
int main(){
  int i,j,n,flag,hozon,count=0;
  int sort[A];
  int minj;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&sort[i]);
  }

  for(i=0;i<=n-1;i++){
    flag=0;
    minj = i;
    for(j=i;j<=n-1;j++){
      if(sort[j]<sort[minj]){
	minj = j;
	flag=1;
      }
    }
    if(flag==1){
      hozon = sort[i];
      sort[i] = sort[minj];
      sort[minj] = hozon;
      count++;
    }
  }
  
  for(i=0;i<=n-1;i++){
    if(i==n-1){
      printf("%d",sort[i]);
    }
    else printf("%d ",sort[i]);
  }
  printf("\n%d\n",count);

  return 0;
}
  
  

