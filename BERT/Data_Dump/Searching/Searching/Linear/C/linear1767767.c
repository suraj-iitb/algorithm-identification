#include<stdio.h>
#define N 50000

int a[N],n1,n2,number,count=0;

int searchNumber(int);

int searchNumber(int x){
  int i;
  for(i=0;i<n1;i++){
    if( a[i] == x ) return a[i];
  }
  return -1;
}

int main(){

  int i,j;
  int b[500];
  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&b[i]);
  }

  for(i=0;i<n2;i++){
    number = searchNumber(b[i]);
    if( number != -1 ) count++;
  }
  printf("%d\n",count);
  return 0;
}
