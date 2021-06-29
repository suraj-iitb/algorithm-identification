#include <stdio.h>

int judge_same(int, int, int*);

int main(){
  int ns,nt,i,j,count,judge;
  scanf("%d",&ns);

  int s[ns];

  for(i=0;i<ns;i++) scanf("%d",&s[i]);

  scanf("%d",&nt);

  int t[nt];

  for(i=0;i<nt;i++) scanf("%d",&t[i]);

  for(i=0;i<ns;i++){

    judge=judge_same(i,ns,s);
    
    if(judge==1) continue;

    for(j=0;j<nt;j++){
      if(s[i]==t[j]) count++;
    }
  }

  printf("%d\n",count);

  return 0;
}

int judge_same(int x,int ns,int *s){
  int i,a=0;
  for(i=x+1;i<ns;i++){
    if(s[x]==s[i]){
      a=1;
    }
  }

  return a;
}
    
    
    

