#include<stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void search(int);
void search_in();

int n, G[MAX][MAX];
int color[MAX],first_count[MAX],second_count[MAX];
int counter;

int main(){
  
  int num,sum,bin,ain;
  int a,b;
  
  scanf("%d",&n);
  
  for(a=0;a<n;a++){
    for(b=0;b<n;b++)G[a][b]=0;
  }
  
  for(a=0;a<n;a++){
    scanf("%d%d",&bin,&sum);
    bin--;
    for(b=0;b<sum;b++){
      scanf("%d",&ain);
      ain--;
      G[bin][ain]=1;
    }
  }
  
  search_in();
  
  for(a=0;a<n;a++)printf("%d %d %d\n",a+1,first_count[a],second_count[a]);
  
  return 0;
}

void search(int u){
  
  int a;
  
  color[u]=GRAY;
  counter++;
  first_count[u]=counter;
  
  for(a=0;a<n;a++){
    if (G[u][a]==0)continue;
    if(color[a]==WHITE)search(a);
  }
  color[u]=BLACK;
  counter++;
  second_count[u]=counter;
}

void search_in(){
  
  int  a;
  for(a=0;a<n;a++)color[a]=WHITE;
  
  counter=0;
  
  for(a=0;a<n;a++){
    if(color[a]==WHITE)search(a);
  }
}


