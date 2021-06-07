#include <stdio.h>
#include <stdlib.h>

#define white 2
#define gray 1 
#define black 0

#define N 100

int n ,M[N][N], ID[N], judge[N], f[N], t;

void dps_visit(int a);
void dps(void);

int main(){
  int i, j, k, id, num;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      M[i][j] = 0;

  for(i = 0; i < n; i++){
    scanf("%d%d", &id, &k);

    id--;

    for(j = 0; j < k; j++){
      scanf("%d", &num);
      num--;

      M[id][num] = 1;
    }
  }

  dps();

  return 0;
}

void dps_visit(int a){
  int i;

  judge[a] = gray;

  ID[a] = ++t;

  for(i = 0; i < n; i++){
    if(M[a][i] == 0)
      continue;

    if(judge[i] == white)
      dps_visit(i);
  }

  judge[a] = black;
  f[a] = ++t;
}

void dps(){
  int i;

  for(i = 0; i < n; i++)
    judge[i] = white;
  
  t = 0;

  for(i = 0; i < n; i++)
    if(judge[i] == white)
      dps_visit(i);

  for(i = 0; i < n; i++)
    printf("%d %d %d\n", i + 1, ID[i], f[i]);
}



