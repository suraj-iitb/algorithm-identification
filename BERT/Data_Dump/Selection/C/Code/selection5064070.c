#include <stdio.h>

int main(void){
  int i,j,N,min,tmp,count=0;

  scanf("%d",&N);
  int data[N];
  for(i=0;i<N;i++) scanf("%d",&data[i]);

  for(i=0;i<N;i++){
    min = i;
    for(j=i;j<N;j++)
      if(data[j]<data[min]) min = j;
    
	tmp = data[i];
	data[i] = data[min];
	data[min] = tmp;
	if(i!=min)count++;
  }

  for(i=0;i<N-1;i++) printf("%d ",data[i]);
  printf("%d\n",data[N-1]);
  printf("%d\n",count);
}

