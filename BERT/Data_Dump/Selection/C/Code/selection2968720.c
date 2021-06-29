#include<stdio.h>
  int main(){
    int N,num[101]={0},i,j,count=0,min,temp;
    scanf("%d",&N);
    for(i=0;i<N;i++){
      scanf("%d",&num[i]);
    }

    for(i=0;i<N;i++){
      min=i;
      for(j=i;j<N;j++){
        if(num[j]<num[min]){
          min=j;
        }
      }
      if(num[i]>num[min]){
        temp=num[i];
        num[i]=num[min];
        num[min]=temp;
        count++;
      }
    }

    for(i=0;i<N;i++){
      printf("%d",num[i]);
      if(i!=N-1)printf(" ");
    }

  printf("\n%d\n",count);
  return 0;
}

