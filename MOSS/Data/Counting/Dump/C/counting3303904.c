#include<stdio.h>

void CountSort(int *,int ,int);

int main(){
  int x,i,max=0;
  scanf("%d",&x);
  int a[x+1];
  for(i=1;i<=x;i++){
    scanf("%d",&a[i]);
    if(a[i]>max)
      max=a[i];
  }

  CountSort(a,x,max);
  return 0;
}
void CountSort(int *a,int x,int max){

  int b[max],c[x+1],i;

  for(i=0;i<=max;i++)
    b[i]=0;

  for(i=1;i<=x;i++)
    b[a[i]]++;

  for(i=1;i<=max;i++)
    b[i]=b[i]+b[i-1];

  for(i=x;i>=1;i--){
    c[b[a[i]]]=a[i];
    b[a[i]]--;
  }

  for(i=1;i<=x;i++){
    if(i==x)
      printf("%d\n",c[i]);
    else
      printf("%d ",c[i]);
  }
}

