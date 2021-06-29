#include <stdio.h>

int main(){
  int i,j,N,tmp,min,cnt=0;

  scanf("%d",&N);

  int S[N];

  for(i=0;i<N;i++)scanf("%d",&S[i]);
  for(i=0;i<N;i++){
    min=i;
    for(j=i+1;j<N;j++){
      if(S[j]<S[min]){
	min=j;
      }
    }
    if(min!=i){
      tmp=S[min];
      S[min]=S[i];
      S[i]=tmp;
      cnt++;
    }
  }

  for(i=0;i<N-1;i++)printf("%d ",S[i]);
  printf("%d\n%d\n",S[N-1],cnt);
  return 0;
}
