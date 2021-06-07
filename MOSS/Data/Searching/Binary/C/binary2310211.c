#include<stdio.h>

int a[1000000],b;

int serch(int key){
  int l=0,r=b,mid;
  while(l<r){
    mid=(l+r)/2;
    if(key==a[mid]) return 1;
    if(key>a[mid]) l=mid+1;
    else if(key<a[mid])r=mid;
  }
  return 0;
}

int main(){
  int i,d,e,sum=0;
    scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&d);
  for(i=0;i<d;i++){
    scanf("%d",&e);
    if(serch(e)) sum++;
  }

  printf("%d\n",sum);

    return 0;
}
