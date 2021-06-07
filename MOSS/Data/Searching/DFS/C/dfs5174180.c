#include <stdio.h>
#include <stdlib.h>
#define N 101
typedef struct{
  int t1;
  int t2;
  int u[N];
  int k[N];
  int v[N];
  char color;
}num;
void visit(num *a, int i){
  int j;
  static int time = 0;
  time++;
  a[i].t1 = time;
  a[i].color = 'G';
  for(j = 0; j < a[i].k[i]; j++){
    if(a[a[i].v[j]].color == 'W' ){
      a[a[i].v[j]].color = 'B';
      visit(a,a[i].v[j]);

    }
  }

  time++;
  a[i].t2 = time;
  return;
}

int main()
{
  int n,i,j;
  num a[N];
  scanf("%d",&n);
  for(i = 1; i <= n; i++){
    scanf("%d%d",&a[i].u[i],&a[i].k[i]);
    if(a[i].k[i] != 0){
      for(j = 0; j < a[i].k[i]; j++)
        scanf("%d",&a[i].v[j]);
    }
  }

  for(i = 1; i <= n; i++)
    a[i].color = 'W';

  for(i = 1; i <= n; i++)
    if(a[i].color == 'W' )
      visit(a,i);
  for(i = 1; i <= n; i++){
    printf("%d %d %d\n",a[i].u[i],a[i].t1,a[i].t2);
  }
  return 0;
}

