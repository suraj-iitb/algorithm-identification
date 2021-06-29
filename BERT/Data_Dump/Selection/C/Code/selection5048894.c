#include<stdio.h>
int main()
{
  int i,j,N,key,mini;
  int count=0;

  scanf("%d",&N);
  int data[N];

  for(i=0;i<N;i++) scanf("%d",&data[i]);

  for(i=0;i<=N-1;i++){
    mini = i;
    for(j=i;j<=N-1;j++){
      if(data[j] < data[mini]){
	mini = j;
      }
    }
    key = data[i];
    data[i] = data[mini];
    data[mini] = key;
    if(mini != i) count++;
  }
  
  for(i=0;i<N;i++){
    if(i != N-1) printf("%d ",data[i]);
    else printf("%d",data[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

