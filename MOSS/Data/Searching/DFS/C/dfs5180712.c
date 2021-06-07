#include<stdio.h>
#define N 100
#define WHT 0
#define GRY 1
#define  BLK 2
int ni, M[N][N];
int col[N], d[N], e[N], pp;
void otozure(int);
void deeeeeeeeeep(void);
int main(){
  int us, basic, k, x, y;
  scanf("%d", &ni);
  for(x=0; x<ni; x++){
    for(y=0; y<ni; y++) M[x][y] = 0;
  }
  for(x=0; x<ni; x++){
    scanf("%d %d", &us, &k);
    us--;
    for(y=0; y<k; y++){
      scanf("%d", &basic);
      basic--;
      M[us][basic] = 1;
    }
  }
  deeeeeeeeeep();
  return 0;
}
void otozure(int mrs){
  int basic;
  col[mrs] = GRY;
  d[mrs] = ++pp;
  for(basic=0; basic<ni; basic++){
    if(M[mrs][basic] == 0) continue;
    if(col[basic] == WHT){
      otozure(basic);
    }
  }
  col[mrs] = BLK;
  e[mrs] = ++pp;
}
void deeeeeeeeeep(){
  int mrs;
  for(mrs=0; mrs<ni; mrs++) col[mrs] = WHT;
  pp = 0;
  for(mrs=0; mrs<ni; mrs++){
    if(col[mrs] == WHT) otozure(mrs);
  }
  for(mrs=0; mrs<ni; mrs++){
    printf("%d %d %d\n", mrs+1, d[mrs],e[mrs]);
  }
}
