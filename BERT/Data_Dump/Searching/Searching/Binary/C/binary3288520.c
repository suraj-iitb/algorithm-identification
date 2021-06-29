#include<stdio.h>
int main(){
  int ns,nt,i,sum=0,key,j,flag,l,m,r;
  int s[100000],t[100000];
  scanf("%d",&ns);
  for(i=0;i<ns;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&nt);
  for(i=0;i<nt;i++){
    scanf("%d",&t[i]);
  }
 
  for(i=0;i<nt;i++){
    l=0;
    r=ns;
    flag=0;
    key=t[i];
  while(l<r){
    m=(l+r)/2;
    if(key==s[m]){ flag=1;break; }
    if(key>s[m]){l=m+1;}
    else if(key<s[m]){r=m;}
  }
  if(flag==1) sum++;
  }
  printf("%d\n",sum);


  
  
  return 0;
}

