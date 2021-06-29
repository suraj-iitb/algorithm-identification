#include<stdio.h>
int main(){
  int n,a[100],i,j,turn=0,temp,min;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(a[j]<a[min])min=j;
    }
    if(i!=min){
      temp=a[i];
      a[i]=a[min];
      a[min]=temp;
      turn++;
    }
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",turn);
  return(0);
}
