#include<stdio.h>
int main()
{
  int i,j,N,key;
  int count=0;

  scanf("%d",&N);

  int data[N];
  
  for(i=0;i<N;i++) scanf("%d",&data[i]);

  for(i=0;i<N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(data[j] < data[j-1]){
    key = data[j];
    data[j] = data[j-1];
    data[j-1] = key;
    count++;
      }
    }
  }

  
  
    for(i=0;i<N;i++){
      if(i == N-1) printf("%d",data[i]);
      else printf("%d ",data[i]);
    }
    printf("\n");
    printf("%d\n",count);

    return 0;
}
  
      

