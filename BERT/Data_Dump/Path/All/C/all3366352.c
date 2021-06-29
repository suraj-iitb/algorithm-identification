#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const long INF=2000000000;
const long SIZE=110;
long V,E,from,to,dist,table[SIZE][SIZE],i,j,k;
bool flag;

void warshall_floyd(){
  for(k=0;k<V;k++){
    for(i=0;i<V;i++){
      if(table[i][k]==INF)continue;
      for(j=0;j<V;j++){
        if(table[k][j]==INF)continue;
        table[i][j]=min(table[i][j],table[i][k]+table[k][j]);
      }
    }
  }
}

int main(){
  scanf("%ld %ld",&V,&E);

  for(i=0;i<V;i++){
    for(j=0;j<V;j++){
      if(i!=j)table[i][j]=INF;
      else table[i][j]=0;
    }
  }

  for(i=0;i<E;i++){
    scanf("%ld %ld %ld",&from,&to,&dist);
    table[from][to]=dist;
  }

  warshall_floyd();

  for(i=0;i<V;i++){
    if(table[i][i]<0){
      flag=true;
      break;
    }
  }

  if(flag)printf("NEGATIVE CYCLE\n");
  else{
    for(i=0;i<V;i++){
      if(table[i][0]==INF)printf("INF");
      else{
        printf("%ld",table[i][0]);
      }
      for(j=1;j<V;j++){
        if(table[i][j]==INF)printf(" INF");
        else{
          printf(" %ld",table[i][j]);
        }
      }
      printf("\n");
    }
  }

  return 0;
}

