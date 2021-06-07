#include <stdio.h>
int search(int s[],int n,int t);

int search(int s[],int n,int t){
  int i=0;
  s[n]=t;
  while(s[i]!=t) i++;
  return i!=n;
}

int main(){
  int i,j,sum1,sum2,sum3=0,s[10000],t=0;
  scanf("%d",&sum1);
  for(i=0;i<sum1;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&sum2);
  for(j=0;j<sum2;j++){
    scanf("%d",&t);
    if(search(s,sum1,t)!=0) sum3++;
  }
  printf("%d\n",sum3);
  
  return 0;
}
