#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,j,N,k = 0,flag = 1,*p;
  scanf("%d",&N);
  if(N < 1 || N >100)exit(1);
  
  p = malloc(N * sizeof(int));

  for(i=0;i < N;i++){
    scanf("%d",&p[i]);
    if(p[i] < 0 || p[i] >100)exit(2);
  }
  while(flag){
    flag = 0;
    for(i = N - 1;i >= 1;i--){
      if(p[i] < p[i-1]){
	j = p[i];
	p[i] = p[i-1];
	p[i-1] = j;
	k++;
	flag = 1;
      }
    }
  }
  for(i=0;i < N;i++){
    if(i != N-1)printf("%d ",p[i]);
    else printf("%d\n",p[i]);
  }
  printf("%d\n",k);
  return 0;
}

