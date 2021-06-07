#include<stdio.h>
#define N 10000
int linsea(int key,int A[],int n);
int main(){
  int a,b,c=0,i;
  int S[N],T[N];
  scanf("%d",&a);
  for(i=0;i<a;i++)scanf("%d",&S[i]);
  scanf("%d",&b);
  for(i=0;i<b;i++)scanf("%d",&T[i]);
  for(i=0;i<b;i++){
  c+=linsea(T[i],S,a);
  }
  printf("%d\n",c);
}
int linsea(int key,int A[],int n){
  int i=0;
  A[n]=key;
  while(key!=A[i]){
    i++;
    if(i==n)return 0;
  }
    return 1;
}

