#include <stdio.h>
#define NOT -1

int u[100][100];//u[id][k v]
int time = 0;
int d[100];
int f[100];

void search(int a){
  int i,k,q;
  time++;
  d[a] = time; 
  k = u[a][0];
  if(k > 0){
    for(i=1;i<=k;i++){
      q = u[a][i];
      if(d[q]==NOT){
	search(q);   
      }
    }
  }
  time++;
  f[a]=time;
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
    d[i]=NOT;
  }



  search(1);
  
  for(i=1;i<=n;i++)
    if(d[i]==NOT)
      search(i);


  

  for(i=1;i<=n;i++)
    printf("%d %d %d\n",i,d[i],f[i]);
  
  
  return 0;
}

