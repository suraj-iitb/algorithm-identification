#include<stdio.h>
#define N 100

int m[N][N], n, d[N], f[N], count=0;
char color[N];
void dfs(int);



int main(){
  int i, j, a, b, c;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      m[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&a,&b);
    a--;
    for(j=0;j<b;j++){
      scanf("%d",&c);
      c--;
      m[a][c] = 1;
    }
  }

  for(i=0;i<n;i++) color[i] = 'w';
  for(i=0;i<n;i++){
    if(color[i] == 'w'){
      dfs(i);
    }
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}


void dfs(int x){
  int i;

  color[x] = 'g';
  ++count;
  d[x] = count;

  for(i=0;i<n;i++){
    if(m[x][i] == 0){
      continue;
    }
    if(color[i] == 'w'){
      dfs(i);
    }
  }
  color[x] = 'b';
  count++;
  f[x] = count;
}


