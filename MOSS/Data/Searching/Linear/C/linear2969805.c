#include<stdio.h>
#include<stdlib.h>
int Lsearch(int[],int,int);

int main(){
  int data[10001],n,q,key,i,total=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(Lsearch(data,n,key)!=n)total++;
  }
  printf("%d\n",total);
  return 0;
}

int Lsearch(int data[],int n,int key){
  int i=0;
  data[n]=key;
  while(data[i]!=key){
    i++;
  }
  return i;
}


