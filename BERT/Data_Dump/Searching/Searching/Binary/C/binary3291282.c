#include<stdio.h>
#define N 100000
int binsea(int key,int A[],int n);
int main(){
  int a,b,c=0,i;
  int S[N],T[N];
  scanf("%d",&a);
  for(i=0;i<a;i++)scanf("%d",&S[i]);
  scanf("%d",&b);
  for(i=0;i<b;i++)scanf("%d",&T[i]);
  for(i=0;i<b;i++){
  c+=binsea(T[i],S,a);
  }
  printf("%d\n",c);
}
int binsea(int key,int A[],int n){
  int l=0,r=n,m;
  while(l<r){
    m=(l+r)/2;
    if(A[m]==key)return 1;
    else if(A[m]>key)r=m;
    else l=m+1;
  }
    return 0;
}

