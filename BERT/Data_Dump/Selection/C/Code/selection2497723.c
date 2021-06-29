#include<stdio.h>
#define N 100

int main(void){
  int n,i,j,k,minj,tmp,count=0,data[N];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&data[i]);

  for(i=0;i<n-1;i++){
    minj=i;
     for(j=i;j<n;j++)if(data[j]<data[minj]) minj=j;

     tmp=data[i];
     data[i]=data[minj];
     data[minj]=tmp;
     if(i!=minj) count++;
  }

  for(i=0;i<n;i++){
    printf("%d",data[i]);
    if(i!=n-1) printf(" ");
  }

  printf("\n%d\n",count);
  return 0;
}
