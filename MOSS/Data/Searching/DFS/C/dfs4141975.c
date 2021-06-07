#include<stdio.h>
#define N 100
#define S 0
#define G 1
#define K 2

int kazu,Max[N][N];

int d[N],f[N];
int temp;

int data[N];

void visit(int x){
  int i;
  data[x]=G;
  d[x]=++temp;
  for(i=0;i <kazu; i++){
    if(Max[x][i]==0){
      continue;}
    
    if(data[i]==S){
      visit(i);
    }
  }
  data[x]=K;
  f[x]=++temp;
}
void cal(){
  int x;
  for(x=0;x<kazu;x++){data[x]=S;
  }
  temp=0;
  for(x=0; x<kazu;x++){
    if(data[x]==S)visit(x);
  }
  
  for(x=0; x<kazu;x++){
    printf("%d %d %d\n", x+1,d[x], f[x]);

  }
}


int main()
{
  int x,v,k,i,j;
  
  scanf("%d",&kazu);

  for(i=0;i<kazu;i++){
    for( j=0; j<kazu; j++ ) {
      Max[i][j]=0;
    }
    
  }
  
  for(i=0;i <kazu;i++){

    scanf("%d %d",&x,&k);
    
    x--;
    for(j=0;j<k;j++){
      
      scanf("%d",&v);
      v--;
      
      Max[x][v]=1;
    }
  }
  cal();
  return 0;
}

