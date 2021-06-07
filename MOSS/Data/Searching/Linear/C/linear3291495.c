#include<stdio.h>

int main(){
  int i,j,key,nq,ns,as[10000],aq[500],c=0;

  scanf("%d",&ns);
  for(i=0;i<ns;i++) scanf("%d",&as[i]);
  
  scanf("%d",&nq);
  for(i=0;i<nq;i++) scanf("%d",&aq[i]);

  for(j=0;j<nq;j++){
    as[ns]=key=aq[j];
    for(i=0;as[i]!=key;i++){}
    if(i!=ns) c++;
  }

  printf("%d\n",c);

  return 0;
}
  
  

