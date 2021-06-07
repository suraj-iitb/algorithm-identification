#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 1
#define gun() getchar_unlocked()
#else
#define gun() getchar()
#endif

int bb(){
  int m = 0,c = gun();
  do m = 10 * m + (c & 0xf), c = gun();
  while(c>='0');
  return m;
}

#define DF 0x10101010
#define N 100


int a[N],*b[N];
int c[N][2];
int s,e;
int w[N];

void bump(int n){

  int i,u,v;


  c[0][0]=n;
  c[0][1]=0;
  w[n]=0;
  s=0;
  e=1;


  while(s!=e){
    n=c[s][0];
    u=c[s++][1];
    if(w[n]<u)
      continue;
    for(i=0;i<a[n];i++){
      v=b[n][i];
      if(w[v]>u+1){
	w[v]=u+1;
	c[e][0]=v;
	c[e++][1]=u+1;
      }
    }
  }
}

int main(){
  int i,j,n,l,v;

  n = bb();
  memset(w,DF,n<<2);
  for(i=0;i<=n-1;i++){
    v=bb()-1;
    a[v]=l=bb();
    b[v]=malloc(l<<2);
    for(j=0;j<=l-1;j++)
      b[v][j]=bb()-1;
  }

  bump(0);
  for(i=0;i<=n-1;i++){
    if(w[i]==DF){
      w[i]=-1;
    }
    printf("%d %d\n",i+1,w[i]);
  }
  return 0;
}

