#include<stdio.h>
#define N 101

int d[N],f[N],color[N],list[N][N];

void dfp(int);
void visit(int,int);

int main(){
  int num,i,j,k,v;
  
  scanf("%d",&num);
  
  for(i=1; i<=num; i++){
    for(j=1; j<=num; j++){
      list[i][j] = 0;
    }
  }
  
  for(i=1; i<=num; i++){
    scanf("%d%d",&k,&j);
    for(j; j>0; j--){
      scanf("%d",&v);
      list[k][v] = 1;
    } 
  }
  
    dfp(num);
    
     for(i=1; i<=num; i++) printf("%d %d %d\n",i,d[i],f[i]);
    
  return 0;
}


void dfp(int num){
  int i;
  for(i=1; i<=num; i++) color[i]=0;
  for(i=1; i<=num; i++){
    if(color[i] == 0)  visit(i,num);
  }
}

void visit(int r,int num){
  int k=1,S[N],i,u,v,j;
  static int time=0;
  S[k]=r;
  color[r] = 1;
  d[r] = ++time;
  v = r;
  while(&S[k] != &S[0]){
    u = S[k];
    j=v;
    v=0;
    for(i=1; i<=num; i++){
      if(list[j][i] == 1 && color[i] == 0){
	v = i;
	break;
      }
    }
    
    if(v!=0){
      if(color[v] == 0){
	k++;
	S[k] = v;
	color[v] = 1;
	d[v] = ++time;
      }
    }
      else {
	k--;
	color[u] = 2;
	f[u] = ++time;
	v = S[k];
      }  
  } 
}
