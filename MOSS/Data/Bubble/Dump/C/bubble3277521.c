#include<stdio.h>
#define N 100
int main(){
  int hako[N];
  int n,i,j;
  int flag = 1;
  int count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&hako[i]);
  }
  while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(hako[j]<hako[j-1]){
	i= hako[j-1];
	hako[j-1]=hako[j];
	hako[j]=i;
	flag =1;
	count++;
      }
    }
  }
  for(i=0;i<n-1;i++) printf("%d ",hako[i]);
  printf("%d\n",hako[n-1]);
  printf("%d\n",count);
  return 0;
}

