#include<stdio.h>
int linearSearch(int );
int main(){
  int x,i,j;
  int cont=0;
  scanf("%d",&x);
  int n;
  n=x+1;
  int a[n];
  for(i=0;i<x;i++)scanf("%d",&a[i]);
  int y,l,r,mid;
  scanf("%d",&y);
  int b[y];
  for(i=0;i<y;i++)scanf("%d",&b[i]);
  for(j=0;j<y;j++){
    l=0;
    r=x;
    while(l<r){
      mid=(l+r)/2;
      if(a[mid]==b[j]){
	cont++;
	break;
      }
      else if(b[j]<a[mid])r=mid;
      else l=mid+1;
    }
  }
  printf("%d\n",cont);
  return 0;
}

