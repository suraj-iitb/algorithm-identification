#include<stdio.h>

#define N 100

int main(){

  int n,i,flag=1,tmp,cnt=0;
  int Sort[N];

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&Sort[i]);

  while(flag){

    flag = 0;

    for(i = 0;i < n;i++){

      if(Sort[i] < Sort[i-1]){
	tmp = Sort[i];
	Sort[i] = Sort[i-1];
	Sort[i-1] = tmp;
	flag = 1;
	cnt++;
      }
    }
  }
  for(i = 0;i < n-1;i++){
    printf("%d ",Sort[i]);
  }
  printf("%d\n",Sort[n-1]);
  printf("%d\n",cnt);
    return 0;
}
