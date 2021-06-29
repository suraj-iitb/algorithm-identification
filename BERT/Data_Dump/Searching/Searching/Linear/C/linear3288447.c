#include<stdio.h>
int main(){
  int ns,nt,i,sum=0,key,j,flag;
  int s[10000],t[10000];
  scanf("%d",&ns);
  for(i=0;i<ns;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&nt);
  for(i=0;i<nt;i++){
    scanf("%d",&t[i]);
  }
  
  for(i=0;i<nt;i++){
    j=0;
    flag=0;
    key=t[i];
    while(s[j]!=key){
      j++;
      if(j==ns){flag=1; break;}
    }
    if(flag==0) {sum++;}
  }
  printf("%d\n",sum);
  return 0;
}

