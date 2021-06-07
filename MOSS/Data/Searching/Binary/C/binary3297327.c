#include<stdio.h>

int a[1000000],b;

int binarysearch(int c){
  int d=0;
  int e=b;
  int f;

  while(d<e){
    f=(d+e)/2;
    if(c==a[f])return 1;
    if(c>a[f])d=f+1;
    else if(c<a[f])e=f;
  }
  return 0;
}

int main(){
  int d,c,i,k=0;
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&d);
  for(i=0;i<d;i++){
    scanf("%d",&c);
    if(binarysearch(c))k=k+1;
  }
  printf("%d\n",k);
  return 0;
}

