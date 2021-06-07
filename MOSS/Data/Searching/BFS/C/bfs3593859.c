#include <stdio.h>
#include <stdlib.h>

int **vv;
int *kk;
int *dist;

void walk(int k, int d)
{
  int i, j;
  for (j=0; j<kk[k]; j++) {
    i = ((int*)vv[k])[j]-1;
    if (dist[i]<0 || (dist[i]>0 && dist[i]>d))
      dist[i] = d;
    else continue;
    walk(i, d+1);
  }
}

int main()
{
  int i, j, n;
  fscanf(stdin, "%d", &n);

  dist = (int*)malloc(sizeof(int)*n);
  kk =   (int*)malloc(sizeof(int)*n);
  dist[0] = 0;
  for (i=1; i<n; i++)  dist[i] = -1;

  vv = (int **)malloc(sizeof(int*)*n);
  for (i=0; i<n; i++) {
    fscanf(stdin, "%*d %d", &kk[i]);
    vv[i] = (int*)malloc(sizeof(int)*(kk[i]));
    for (j=0; j<kk[i]; j++)  scanf("%d",  &vv[i][j]);
  }

  walk(0, 1);

  for (i=0; i<n; i++)  printf("%d %d\n", i+1, dist[i]);
  return 0;
}
