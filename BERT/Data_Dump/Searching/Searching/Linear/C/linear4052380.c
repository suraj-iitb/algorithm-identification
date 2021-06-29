#include<stdio.h>
#define M 10000

int main(){
  int n, S[M], q, T[M], i ,j, count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  
  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(S[i]==S[j])
	S[j]=-1;
    }
  }

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(T[i]==T[j])
	T[j]=-1;
    }
  }
  
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j])count++;
    }
  }

  printf("%d\n",count);
  
  return 0;
}

