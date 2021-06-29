#include <stdio.h>
void bubbleSort(int *,int );
int main(){
  int a[100],n,i;

  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  bubbleSort(a,n);
  return 0;
}

void bubbleSort(int *a,int n){
  int flag=1,j,v,t=0;
  while(flag){
    flag=0;
    for(j=1;j<n;j++){
      if(a[j]<a[j-1]){
        v=a[j];
        a[j]=a[j-1];
        a[j-1]=v;
        flag=1;
        t++;
      }
    }
  }
  for(j=0;j<n-1;j++){
    printf("%d ",a[j]);
  }
  printf("%d\n%d\n",a[n-1],t);
}

