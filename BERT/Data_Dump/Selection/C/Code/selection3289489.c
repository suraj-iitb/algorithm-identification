#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,j,k,s = 0,N,minj,*p;
  scanf("%d",&N);
  if(N < 1 || N > 100)exit(1);
  
  p = malloc(N * sizeof(int));

  for(i=0;i < N;i++){
    scanf("%d",&p[i]);
    if(p[i] < 0 || p[i] > 100)exit(2);
  }
  for(i = 0;i < N;i++){
    minj = i;
    for(j = i;j < N;j++){
      if(p[j] < p[minj])minj = j;
    }
    if(minj != i){
      k = p[i];
      p[i] = p[minj];
      p[minj] = k;
      s++;
    }
  }
  for(i=0;i < N;i++){
    if(i != N-1)printf("%d ",p[i]);
    else printf("%d\n",p[i]);
  }
  printf("%d\n",s);
  return 0;
    
  }

