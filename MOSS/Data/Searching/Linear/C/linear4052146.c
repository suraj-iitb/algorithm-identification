#include<stdio.h>

int search(int s[],int n,int t){
  int i;
  for(i=0;i<n;i++){
    if(s[i]==t){
      return 1;
    }
  }
      return 0;
}

int main(){

  int i,n,s[10001],q,t,count=0,flag;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    flag=search(s,n,t);
    if(flag==1){
      count++;
      flag=0;
    }
  }

  printf("%d\n",count);
  
  return 0;
}

