#include<stdio.h>

int linearSearch(int,int*,int);

int main(){
  int n,s[10000],q,key,i,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    sum+=linearSearch(n,s,key);
  }
  printf("%d\n",sum);

  return 0;
}

int linearSearch(int n,int a[],int key){
  int i=0;
  a[n]=key;
  while(a[i]!= key){
    i++;
      }
  if(i==n)return 0;
  else return 1;
}

