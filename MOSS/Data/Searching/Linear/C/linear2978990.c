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
  int y;
  scanf("%d",&y);
  int b[y];
  for(i=0;i<y;i++)scanf("%d",&b[i]);
  for(j=0;j<y;j++){
    i=0;
    while(i!=n){
      if(a[i]==b[j]){
	cont++;
	break;
      }
      i++;
    }
  }
  printf("%d\n",cont);
  return 0;
}

