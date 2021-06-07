#include<stdio.h>

int linearSearch(int*,int,int);

int main(){
  int n,q,i,j;
  int s[10000],t,f=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(linearSearch(s,t,n))f++;
  }
  
  printf("%d\n",f);
  
  return 0;
}

int linearSearch(int A[],int t,int n){
  int i;
  for(i=0;i<n;i++){
    if(A[i]==t){
      return 1;
    }
  }
  return 0; 
}
