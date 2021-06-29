#include <stdio.h>
#define NUL -1

int u[100][100];//u[id][k v]
int l[100];

void search(int a,int d){
  int i,t,q;
  if(l[a]==NUL || (l[a]!=NUL && l[a] > d)){
    //printf("%d %d\n",l[a],d);
    l[a] = d;
    t = u[a][0];
    for(i=1;i<=t;i++){
      q = u[a][i];
      search(q,d+1);    
    }
  }
}



int main(){
  int n,i,ii,t,kk,c;
  int a;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&t);
    scanf("%d",&u[t][0]);
    for(ii=1;ii<=u[t][0];ii++)
      scanf("%d",&u[t][ii]);
    l[i]=NUL;
  }


  search(1,0);

  /*
  for(i=1;i<=n;i++)
    if(l[i]==NUL)
      search(i);
  */

  

  for(i=1;i<=n;i++)
    printf("%d %d\n",i,l[i]);
  
  
  return 0;
}

