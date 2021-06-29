#include<stdio.h>

int main(){
  int a,b,c[10000+1],d,i,f=0;

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&c[i]);
  }
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&d);
    if(search(c,a,d))f++;
  }
  printf("%d\n",f);
}

int search(int A[],int a,int b){
  int i=0;
  A[a]=b;
  while(A[i] != b)i++;
  return i != a;
}
  

