#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int se(int*,int,int);

int main(){
  int i,j,s,t,n[1000000],q[50000],cnt=0;
  scanf("%d",&s);
  for(i=0;i<s;i++){
    scanf("%d",&n[i]);
  }
  scanf("%d",&t);
  for(i=0;i<t;i++){
    scanf("%d",&q[i]);
    //printf("%d ",q[s]);
  }
  for(j=0;j<t;j++){
    if (se(n,q[j],s)) cnt++; 
  }
  printf("%d\n",cnt);

  
  
}
int se(int *n,int key,int s){
  int l,r,m;
  l=0;
  r=s;
  m=s/2;
  while(n[m] != key){
    if(key <n[l] ||key >n[r-1]) return 0;
    if(n[m]>key)r=m;
    else l=m+1;
    m=(l+r)/2;
  }
  //  printf("%d %d - \n",n[m],key);
  return 1;
  
}
